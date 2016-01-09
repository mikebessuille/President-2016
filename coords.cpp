/******************************************************************************

	Class:		CWorldMap

	Action:		Contains methods for coordinate conversion within the CWorldMap
						object.  (Dev <--> Log) conversions.

						DEV is always MAP coords.  LOG is always Windows Screen Coords.

	Params:

	Returns:

	Comments:	Created by Mike Bessuille			May 2, 1996

******************************************************************************/

/*
**	Includes
*/
#include "stdafx.h"
#include "president.h"
#include "map.h"


/*
**	Defines
*/

/*
**	Prototypes
*/


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/******************************************************************************

	Function:	SetupMappingMode

	Action:		Sets up the LOG (screen) <---> DEV (map) mapping mode.

	Params:		

	Returns:

	Comments:	Must also set up the origin mapping, since Log origin is top-left
						while Dev origin is bottom-left.

******************************************************************************/
void CWorldMap::SetupMappingMode()
{
	// 20 log units to 1 dev unit.  Same as width of one tile.
	m_nLogXExt = SQUARE_WIDTH;		
	m_nLogYExt = -SQUARE_HEIGHT;
	m_nDevXExt = 1;
	m_nDevYExt = 1;

	m_ptDevOrigin.x = 0;
	m_ptDevOrigin.y	= 0;
	m_ptLogOrigin.x = DEV_TO_LOGH( 0 );
	m_ptLogOrigin.y = DEV_TO_LOGV( m_nHeight );
}


/******************************************************************************

	Function:	GetLogSize

	Action:		Returns the LOG (screen) size of the current map.

	Params:		CSize *

	Returns:

	Comments:	sizePage, sizeLine optional
						if psizePage then you must also have prectView.

******************************************************************************/
void CWorldMap::GetLogSize(	CSize *psizeTotal, CSize *psizePage,
														CSize *psizeLine, CRect *prectView )
{
	psizeTotal->cx = DEV_TO_LOGH( m_nWidth );
	psizeTotal->cy = DEV_TO_LOGV( m_nHeight );

	if( psizePage && prectView )
	{
		// scroll by the number of visible map elements on the screen
		psizePage->cx = (LONG) LWIDTH( *prectView ) / DEV_TO_LOGH( 1 );
		psizePage->cy = (LONG) LHEIGHT( *prectView ) / DEV_TO_LOGV( 1 );
		
		psizePage->cx = DEV_TO_LOGH( psizePage->cx );
		psizePage->cy = DEV_TO_LOGV( psizePage->cy );
	}

	if( psizeLine )
	{
		// scroll by one map element at a time.
		psizeLine->cx = DEV_TO_LOGH( 1 );
		psizeLine->cy = DEV_TO_LOGV( 1 );
	}
}


/******************************************************************************

	Function:	GetLogUpdateRect

	Action:		Returns the current update rect, WRT windows log coords
						(GDI coords).

	Params:		CRect

	Returns:

	Comments:	

******************************************************************************/
CRect	CWorldMap::GetLogUpdateRect()
{
	CRect rect;

	DevRectToLargestLogRect( &rect, &m_rUpdate );
	// Log rects are not inclusive!  ZAZ really this should be part of
	// above function??
	rect.right++;
	rect.bottom++;
	return( &rect );
}


/******************************************************************************

	Function:	DevPtToLogPt

	Action:		

	Params:		

	Returns:

	Comments:	Maps to the middle of the Log pts that map back to this dev pt.

******************************************************************************/
void CWorldMap::DevPtToLogPt( CPoint *pt )
{
	DOUBLE dVal;

	dVal = ( pt->x - m_ptDevOrigin.x + 0.5 );
	dVal /= m_nDevXExt;
	dVal *= m_nLogXExt;
	dVal += m_ptLogOrigin.x;
	pt->x = (LONG)floor( dVal );

	dVal = ( pt->y - m_ptDevOrigin.y + 0.5 );
	dVal /= m_nDevYExt;
	dVal *= m_nLogYExt;
	dVal += m_ptLogOrigin.y;
	pt->y = (LONG)floor( dVal );
}


/******************************************************************************

	Function:	LogPtToDevPt

	Action:		

	Params:		

	Returns:

	Comments:

******************************************************************************/
void CWorldMap::LogPtToDevPt( CPoint *pt )
{
	DOUBLE dVal;

	dVal = ( pt->x - m_ptLogOrigin.x + 0.5 );
	dVal /= m_nLogXExt;
	dVal *= m_nDevXExt;
	dVal += m_ptDevOrigin.x;
	pt->x = (LONG)floor( dVal );

	if( m_nLogYExt < 0 )
	{
		dVal = ( m_ptLogOrigin.y - pt->y - 0.5 );
		dVal /= abs( m_nLogYExt );
		dVal *= m_nDevYExt;
		dVal += m_ptDevOrigin.y;
		pt->y = (LONG)floor( dVal );
	}
	else
	{
		ASSERT( 0 ); // untested!
		dVal = ( pt->y - m_ptLogOrigin.y );
		dVal /= m_nLogYExt;
		dVal += 0.5;
		dVal *= m_nDevYExt;
		dVal += m_ptDevOrigin.y;
		pt->y = (LONG)floor( dVal );
	}
}




/******************************************************************************

	Function:	DevRectToLogRect()

	Action:		

	Params:		

	Returns:

	Comments:

******************************************************************************/
void CWorldMap::DevRectToLogRect( CRect *prLog, CRect *prDev )
{
	CPoint pt;

	pt.x = prDev->left;
	pt.y = prDev->bottom;

	DevPtToLogPt( &pt );

	prLog->left = pt.x;
	prLog->bottom = pt.y;

	pt.x = prDev->right;
	pt.y = prDev->top;

	DevPtToLogPt( &pt );

	prLog->right = pt.x;
	prLog->top = pt.y;
}


/******************************************************************************

	Function:	LogRectToDevRect

	Action:		

	Params:		

	Returns:

	Comments:

******************************************************************************/
void CWorldMap::LogRectToDevRect( CRect *prDev, CRect *prLog )
{
	CPoint pt;

	pt.x = prLog->left;
	pt.y = prLog->bottom;

	LogPtToDevPt( &pt );

	prDev->left = pt.x;
	prDev->bottom = pt.y;

	pt.x = prLog->right;
	pt.y = prLog->top;

	LogPtToDevPt( &pt );

	prDev->right = pt.x;
	prDev->top = pt.y;
}


/******************************************************************************

	Function:	DevRectToLargestLogRect

	Action:		

	Params:		

	Returns:

	Comments:	This is currently a specialized function that makes assumptions
						about our current mapping mode (ie that LogExtY is negative and all
						others are positive, and that Windows rects have 0,0 at the top
						left).

******************************************************************************/
void CWorldMap::DevRectToLargestLogRect( CRect *prLog, CRect *prDev )
{
	DevRectToLogRect( prLog, prDev );
	// expand this point by the range of one square.

	prLog->left		-= (m_nLogXExt / 2 );
	prLog->right	+= ( m_nLogXExt / 2 ) - 1;
	prLog->top		-= ( abs( m_nLogYExt ) / 2 );
	prLog->bottom += ( abs( m_nLogYExt ) / 2 ) - 1;
}


/******************************************************************************

	Function:	GetLogRectFromMap

	Action:		

	Params:		

	Returns:

	Comments:

******************************************************************************/
CRect CWorldMap::GetLogRectFromMap( INT nX, INT nY )
{
	CRect rect;

	rect.left = nX;
	rect.right = nX;
	rect.top = nY;
	rect.bottom = nY;

	DevRectToLargestLogRect( &rect, &rect );

	return( rect );	
}

