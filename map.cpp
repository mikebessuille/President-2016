
/******************************************************************************

	Class:		CWorldMap

	Action:		Contains and displays the map information

	Params:

	Returns:

	Comments:	Created by Mike Bessuille			April 20, 1996

******************************************************************************/

/*
**	Includes
*/
#include "stdafx.h"
#include "president.h"
#include "map.h"
#include "doc.h"
#include "ids.h"


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

IMPLEMENT_SERIAL( CWorldMap, CObject, 1 /* Schema number */ )
// IMPLEMENT_DYNCREATE( CWorldMap, CObject )


/******************************************************************************

	Function:	CWorldMap() constructor

	Action:

	Params:

	Returns:

	Comments:

******************************************************************************/
CWorldMap::CWorldMap()
{
	m_pImageList = NULL;
	m_pBackImgList = NULL;
	m_pBaseImgList = NULL;
	m_pUnitImgList = NULL;
	m_pBitmap = NULL;

	m_pDoc = NULL;
	m_pMapArray = NULL;

	m_nWidth = 0;
	m_nHeight = 0;
	
	ZERO_RECT( m_rUpdate );

	// Mapping mode stuff
	m_nDevXExt = 1;
	m_nDevYExt = 1;
	m_nLogXExt = 1;
	m_nLogYExt = 1;
	m_ptDevOrigin.x = 0;
	m_ptDevOrigin.y = 0;
	m_ptLogOrigin.x = 0;
	m_ptLogOrigin.y = 0;
}


/******************************************************************************

	Function:	~CWorldMap() destructor

	Action:

	Params:

	Returns:

	Comments:

******************************************************************************/
CWorldMap::~CWorldMap()
{
	// Delete image lists
	if( m_pImageList )
		delete m_pImageList;

	if( m_pBackImgList )
		delete m_pBackImgList;
	if( m_pBaseImgList )
		delete m_pBaseImgList;
	if( m_pUnitImgList )
		delete m_pUnitImgList;

	// Delete bitmaps
	if( m_pBitmap )
		delete m_pBitmap;
	
	m_pDoc = NULL;
	
	// Delete main map (MAP_ELEMENT array)
	if( m_pMapArray )
		free( m_pMapArray );
}


/******************************************************************************

	Function:	InitMap()

	Action:		Initializes a new CWorldMap object; sets up the graphic objects
						needed in drawing the map, and the mapping mode between the screen
						and the device (map).

	Params:

	Returns:

	Comments:	width, height must have already been set up by now.

******************************************************************************/
BOOL CWorldMap::InitMap( CPresDoc *pDoc )
{
	COLORREF		crClr;
	INT					nNumImages;
	INT					nNumNewImages;
	INT					nWidth;

	if( !pDoc )
		return( FALSE );
	m_pDoc = pDoc;


	ASSERT( m_nWidth > 0 && m_nHeight > 0 );
	if( m_nWidth <= 0 || m_nHeight <= 0 )
		return( FALSE );


	/*
	**	Method 1: Use an Image List
	*/
	m_pImageList = new CImageList;
	nNumNewImages = 0;
	nWidth = SQUARE_WIDTH;

	// crMask = PALETTEINDEX( 0 );	// Index 0 of the palette of the bitmap
																	// is reserved for the mask colour.
	crClr = RGB( 255, 255, 0 );
	if( !m_pImageList->Create(	IDB_BITMAP1, nWidth, nNumNewImages, crClr ))
	{
		return( FALSE );
	}
	m_pImageList->SetBkColor( CLR_NONE );	// Images are transparent
	nNumImages = m_pImageList->GetImageCount();
	if( nNumImages == 0 )
		return( FALSE );


	/*
	**	Method 2: Use individual device-dependent Bitmaps.
	*/
	m_pBitmap = new CBitmap;
	m_pBitmap->LoadBitmap( IDB_STICKMAN );



	/*
	**	Load the background bitmaps
	*/
	m_pBackImgList = new CImageList;
	nNumNewImages = 0;
	nWidth = SQUARE_WIDTH;

	if( !m_pBackImgList->Create( IDB_BACKGROUND, nWidth, nNumNewImages, CLR_NONE ))
	{
		return( FALSE );
	}
	crClr = RGB( 0, 128, 0 );	// Dark green
	m_pImageList->SetBkColor( crClr );
	nNumImages = m_pBackImgList->GetImageCount();
	if( nNumImages == 0 )
		return( FALSE );

	// Set up the mapping mode from Dev (map) to Log (screen) coords.
	// Must be done AFTER m_nWidth, m_nHeight are set!
	SetupMappingMode();

	return( TRUE );
}


/******************************************************************************

	Function:	GenerateMap()

	Action:		Generates a new (random) map.

	Params:

	Returns:

	Comments:

******************************************************************************/
BOOL CWorldMap::GenerateMap()
{
	MAP_ELEMENT	*pMap;
	INT					nX, nY;
	

	/*
	**	Load the map
	*/
	m_pMapArray = (MAP_ELEMENT *)malloc(	m_nWidth * m_nHeight *
																				sizeof( MAP_ELEMENT ));
	if( !m_pMapArray )
		return( FALSE );


	// Set all values to reasonable values.
	pMap = m_pMapArray;
	for( nY = 0; nY < m_nHeight; nY++ )
	{
		for( nX = 0; nX < m_nWidth; nX++ )
		{
			pMap->pUnit = NULL;
			pMap->pBase = NULL;
			pMap->nBackground = BKGND_GRASS;
			if( !(( nX + nY ) % 7 ))
				pMap->nBackground = BKGND_WATER;
			if( !(( nX + nY ) % 3 ))
				pMap->nBackground = BKGND_FOREST;
			if( !(( nX + nY ) % 11 ))
				pMap->nBackground = BKGND_DESERT;
			pMap++;
		}
	}

	return( TRUE );
}


/******************************************************************************

	Function:	Serializes the map object

	Action:		Just loads and saves a map (with unit ID's on that map, not the
						actual full unit definitions).  Does not load or save any game
						information.  See Document's serialize function.

	Params:		

	Returns:

	Comments:

******************************************************************************/
void CWorldMap::Serialize( CArchive &ar )
{
	MAP_ELEMENT	*pMap;
	WORD				w;
	INT					nX, nY;

	if( ar.IsStoring())
	{
		/*
		**	Save the map ***********************************
		*/

		ar << (WORD)m_nWidth;
		ar << (WORD)m_nHeight;

		pMap = m_pMapArray;
		for( nY = 0; nY < m_nHeight; nY++ )
		{
			for( nX = 0; nX < m_nWidth; nX++ )
			{
				/*
				if( pMap->pUnit )
					ar << (WORD)pMap->pUnit->nID;
				else
				*/
					ar << (WORD)0;

				/*
				if( pMap->pBase )
					ar << (WORD)pMap->pBase->nID;
				else
				*/
					ar << (WORD)0;

				ar << (BYTE)pMap->nBackground;
				pMap++;
			}
		}
	}
	else
	{
		/*
		**	Load the map ***********************************
		*/

		ar >> w;		m_nWidth = w;
		ar >> w;		m_nHeight = w;

		m_pMapArray = (MAP_ELEMENT *)malloc(	m_nWidth * m_nHeight *
																					sizeof( MAP_ELEMENT ));
		if( !m_pMapArray )
			return;

		pMap = m_pMapArray;
		for( nY = 0; nY < m_nHeight; nY++ )
		{
			for( nX = 0; nX < m_nWidth; nX++ )
			{
				// ZAZ actually load the real unit pointers here, based on
				// the ID's stored in the file!
				ar >> w;		// Temporarily waste this byte
				pMap->pUnit = NULL;
				ar >> w;		// Temporarily waste this byte
				pMap->pBase = NULL;
				ar >> pMap->nBackground;
				pMap++;
			}
		}
	}
}


/******************************************************************************

	Function:	SetDevSize

	Action:		Sets the width and height of the map.

	Params:

	Returns:

	Comments:

******************************************************************************/
void CWorldMap::SetDevSize( INT nWidth, INT nHeight )
{
	m_nWidth = nWidth;
	m_nHeight = nHeight;
}


/******************************************************************************

	Function:	DrawMapRect()

	Action:		Draws a portion of the map

	Params:		rect, in LOG (screen) coords.

	Returns:

	Comments:	Must convert to and from DEV (map) coords.  The map contains
						the mapping mode.

******************************************************************************/
void CWorldMap::DrawMapRect( CDC *pDC, CRect *prect )
{
	// CDC						dcMem;
	// CBitmap				*pbmOld;
	// BITMAP				bm;
	MAP_ELEMENT		*pMap;
	CRect					rDev;
	CRect					rLog;
	INT						nX, nY;

	LogRectToDevRect( &rDev, prect );
	// DevRectToLargestLogRect( &rLog, &rDev );

	for( nY = rDev.bottom; nY <= rDev.top; nY++ )
	{
		for( nX = rDev.left; nX <= rDev.right; nX++ )
		{
			rLog = GetLogRectFromMap( nX, nY );

			pMap = MAP( nX, nY );
			m_pBackImgList->Draw( pDC, pMap->nBackground,
														CPoint( rLog.left, rLog.top ),
														ILD_NORMAL );
		}
	}
}


/******************************************************************************

	Function:	SetBackground()

	Action:		Sets the background value at the current GDI position.

	Params:		nX, nY in GDI coords

	Returns:	nothing

	Comments:

******************************************************************************/
void CWorldMap::SetBackground( BYTE nBackground, CPoint *pptLog )
{
	CPoint ptDev;
	MAP_ELEMENT	*pMap;

	ptDev = *pptLog;
	LogPtToDevPt( &ptDev );
	pMap = MAP( ptDev.x, ptDev.y );
	pMap->nBackground = nBackground;
	m_rUpdate.left = m_rUpdate.right = ptDev.x;
	m_rUpdate.bottom = m_rUpdate.top = ptDev.y;
}


/******************************************************************************

	Function:	

	Action:		

	Params:		

	Returns:

	Comments:

******************************************************************************/
