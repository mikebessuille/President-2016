
/******************************************************************************

	File:			map.h

	Action:		Definition of the CMap object

	Params:

	Returns:

	Comments:

******************************************************************************/
#ifndef _MAP_H
#define _MAP_H

#include "math.h"
#include "types.h"


/*
** Defines
*/
#define SQUARE_WIDTH	40
#define SQUARE_HEIGHT	40

#define MAP_DEFAULT_WIDTH		100
#define MAP_DEFAULT_HEIGHT	100


/*
**	Structures
*/

class CPresDoc;		// Defined in doc.h
class CUnit;			// Defined in unit.h

typedef struct
{
	CUnit *pUnit;	// Moving unit
	CUnit *pBase;	// Non-moving unit
	BYTE	nBackground;		// Index : background type.
}	MAP_ELEMENT;
// DEFINE_PTRS( MAP_ELEMENT );


/*
**	MACROS for accessing m_pMapArray as an array
**	These macros don't do any bounds checking!!
*/
#define MAP( x, y )		( m_pMapArray + ( x ) + ( (y) * m_nHeight ))
#define LEFT( pos )		( (PMAP_ELEMENT)( pos ) - 1 )
#define RIGHT( pos )	( (PMAP_ELEMENT)( pos ) + 1 )
#define UP( pos )			( (PMAP_ELEMENT)( pos ) + m_nHeight )
#define DOWN( pos )		( (PMAP_ELEMENT)( pos ) - m_nHeight )



/*
**	Mapping mode macros
*/
// Dev to Log *********************
// Horizontal scalar
#define DEV_TO_LOGH( x ) ((INT) ((x) * abs( m_nLogXExt ) / abs( m_nDevXExt )))
// Vertical scalar
#define DEV_TO_LOGV( y ) ((INT) ((y) * abs( m_nLogYExt ) / abs( m_nDevYExt )))

// Log to Dev *********************
// Horizontal scalar
#define LOG_TO_DEVH( x ) ((INT) floor((DOUBLE)((x) * \
													abs( m_nDevXExt ) / abs( m_nLogXExt ))))
// Vertical scalar
#define LOG_TO_DEVV( y ) ((INT) floor((DOUBLE)((y) * \
													abs( m_nDevYExt )/ abs( m_nLogYExt ))))


/*
** Rectangle macros  (Take CRect objects or RECT structures )
*/
// Logical
#define LWIDTH( rect )	( (rect).right - (rect).left + 1 )
#define LHEIGHT( rect )	( (rect).bottom - (rect).top + 1 )
// Device
#define DWIDTH( rect )	( (rect).right - (rect).left + 1 )
#define DHEIGHT( rect )	( (rect).top - (rect).bottom + 1 )
// Macro for zero'ing a CRect or RECT
#define ZERO_RECT( rect ) ( (rect).top = (rect).bottom = \
														(rect).left = (rect).right = 0 )

/* --------------------------------------------------------------------------
**
**	CWorldMap class definition
**
** ----------------------------------------------------------------------- */
class CWorldMap : public CObject
{
protected: // create from serialization only
	DECLARE_SERIAL( CWorldMap )
	// DECLARE_DYNCREATE( CWorldMap ) // included in above macro


/*
** Attributes
*/
public:
	CImageList		*m_pImageList;			// test image list
	CImageList		*m_pBackImgList;		// Background image list
	CImageList		*m_pBaseImgList;		// Base Image list
	CImageList		*m_pUnitImgList;		// Unit Image list

	CBitmap				*m_pBitmap;
	CPresDoc			*m_pDoc;				// Pointer back to the parent document
	MAP_ELEMENT		*m_pMapArray;		// Varialble size; use macros to access it!

	CRect					m_rUpdate;						// Region to be updated, in DEV coords.
	INT						m_nWidth, m_nHeight;	// Width and height of map (Dev coords)

protected:


/*
** Implementation
*/
public:
	CWorldMap();	// constructor
	virtual	~CWorldMap();	// destructor
	BOOL		InitMap( CPresDoc *pDoc );
	BOOL		GenerateMap();

	// Drawing and view stuff
	void		DrawMapRect( CDC *pDC, CRect *prect );
	CRect		GetLogUpdateRect();
	void		SetDevSize( INT nWidth, INT nHeight );
	void		GetLogSize( CSize *psizeTotal, CSize *psizePage,
											CSize *psizeLine, CRect *prectView );

	// Map Editing tools
	void		SetBackground( BYTE nBackground, CPoint *pptLog );

	// Serialization
	virtual void Serialize( CArchive &ar );


protected:


/*
**	Mapping stuff	(implemented in coords.cpp)
*/
protected:
	INT			m_nDevXExt;
	INT			m_nDevYExt;
	INT			m_nLogXExt;
	INT			m_nLogYExt;
	CPoint	m_ptDevOrigin;
	CPoint	m_ptLogOrigin;

protected:
	void	SetupMappingMode();
	void	DevPtToLogPt( CPoint *pt );
	void	LogPtToDevPt( CPoint *pt );
	void	DevRectToLogRect( CRect *prLog, CRect *prDev );
	void	LogRectToDevRect( CRect *prLog, CRect *prDev );
	void	DevRectToLargestLogRect( CRect *prLog, CRect *prDev );

	CRect	GetLogRectFromMap( INT nX, INT nY );

}; // class CWorldMap


#endif
