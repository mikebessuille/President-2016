// view.cpp : implementation of the CPresView class
//

#include "stdafx.h"
#include "President.h"

#include "map.h"
#include "doc.h"
#include "view.h"
#include "ids.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPresView

IMPLEMENT_DYNCREATE(CPresView, CScrollView)

BEGIN_MESSAGE_MAP(CPresView, CScrollView)
	//{{AFX_MSG_MAP(CPresView)
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPresView construction/destruction


/******************************************************************************

	Function:	CPresView() constructor

	Action:

	Params:

	Returns:

	Comments:

******************************************************************************/
CPresView::CPresView()
{
	// TODO: add construction code here

}


/******************************************************************************

	Function:	~CPresView() destructor

	Action:

	Params:

	Returns:

	Comments:

******************************************************************************/
CPresView::~CPresView()
{
}


/******************************************************************************

	Function:	PreCreateWindow()

	Action:

	Params:

	Returns:

	Comments:

******************************************************************************/
BOOL CPresView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}


/////////////////////////////////////////////////////////////////////////////
// CPresView drawing


/******************************************************************************

	Function:	OnDraw() handler

	Action:		draws part or all of the view

	Params:

	Returns:

	Comments:

******************************************************************************/
void CPresView::OnDraw(CDC* pDC)
{
	CPresDoc* pDoc = GetDocument();
	ASSERT_VALID( pDoc );

	if( pDoc->m_pMap )
	{
		CRect	rectClip;
		pDC->GetClipBox( &rectClip );
		pDoc->m_pMap->DrawMapRect( pDC, &rectClip );
	}
}


/******************************************************************************

	Function:	OnInitialUpdate

	Action:		Called before the first update; sets the scrolling info
						(and mapping mode??)

	Params:

	Returns:

	Comments:

******************************************************************************/
void CPresView::OnInitialUpdate()
{
	CRect rect;		// size of view, in Log coords

	CScrollView::OnInitialUpdate();

	GetClientRect( &rect );
	UpdateScrollValues( LWIDTH( rect ), LHEIGHT( rect ));
}


/******************************************************************************

	Function:	UpdateScrollValues

	Action:		Sets the scrolling amount based on the CWorldMap object.

	Params:

	Returns:

	Comments:

******************************************************************************/
void CPresView::UpdateScrollValues( INT nWidth, INT nHeight )
{
	CPresDoc* pDoc = GetDocument();
	CRect rect;		// size of view, in Log coords
	CSize sizeTotal;
	CSize sizePage;
	CSize sizeLine;

	ASSERT_VALID( pDoc );

	sizeTotal.cx = sizeTotal.cy = 0;
	sizePage.cx = sizePage.cy = 0;
	sizeLine.cx = sizeLine.cy = 0;
	rect.left = 0;
	rect.right = rect.left + nWidth - 1;
	rect.top = 0;
	rect.bottom = rect.top + nHeight - 1;

	if( pDoc->m_pMap )
	{
		pDoc->m_pMap->GetLogSize( &sizeTotal, &sizePage, &sizeLine, &rect );
	}

	SetScrollSizes( MM_TEXT, sizeTotal, sizePage, sizeLine );
}


/////////////////////////////////////////////////////////////////////////////
// CPresView diagnostics


#ifdef _DEBUG
void CPresView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPresView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);	
}

CPresDoc* CPresView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPresDoc)));
	return (CPresDoc*)m_pDocument;
}
#endif //_DEBUG



/////////////////////////////////////////////////////////////////////////////
// CPresView message handlers


/******************************************************************************

	Function:	OnUpdate

	Action:		Takes a hint, and invalidates the correct portion of the screen

	Params:		The hint must be passed to any call to UpdateAllViews( view,
						0L, m_WorldMap );

	Returns:

	Comments:	This function must convert from DEV (map) coords to LOG (screen)
						coords.

******************************************************************************/
void CPresView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// If there's a hint, use it.
	if( pHint )
	{
		if( pHint->IsKindOf( RUNTIME_CLASS( CWorldMap )))
		{
			// If the hint has been stored in the CWorldMap class,
			// use it.
			CPresDoc* pDoc = GetDocument();
			if( pDoc->m_pMap )
			{
				// convert to client (scrolled-screen) coords
				CRect				rect;
				CClientDC		dc( this );

				rect = pDoc->m_pMap->GetLogUpdateRect();
				OnPrepareDC( &dc );
				dc.LPtoDP( &rect );

				InvalidateRect( &rect );
			}
			return;
		}
	}

	// If no hint, invalidate the whole thing
	Invalidate();
	return;	
}


/******************************************************************************

	Function:	OnSize()

	Action:		Gets called when the view size changes.

	Params:

	Returns:

	Comments:

******************************************************************************/
void CPresView::OnSize(UINT nType, int cx, int cy) 
{
	CScrollView::OnSize(nType, cx, cy);
	
	UpdateScrollValues( cx, cy );	
}


/******************************************************************************

	Function:	OnLButtonDown()

	Action:		Parent handler for L button-down message.  Dispatches the message to
						the current tool.

	Params:

	Returns:

	Comments:	Tool sets and releases capture.

******************************************************************************/
void CPresView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CPresDoc* pDoc = GetDocument();
	CClientDC dc( this );

	ASSERT_VALID( pDoc );

	// convert between coord spaces
	OnPrepareDC( &dc );
	dc.DPtoLP( &point );


	// Now pass the point to the current tool.  The point is in GDI coords.


	// ZAZ test stuff!
	CHAR	pStr[100];
	sprintf_s(	pStr, "X %d		Y %d\n",
						point.x, point.y );
	OutputDebugString( pStr );

	// ZAZ Test stuff!
	if( pDoc->m_pMap )
	{
		pDoc->m_pMap->SetBackground( BKGND_GRASS, &point );
		pDoc->UpdateAllViews( this, 0L, pDoc->m_pMap );
		// ZAZ This shouldn't be!  How do other people tell the system to redraw
		// a portion of the map?  Just use InvalidateRect??  I think only the
		// framework should be calling OnUpdate()...
		OnUpdate( this, 0L, pDoc->m_pMap );
	}

	CScrollView::OnLButtonDown( nFlags, point );
}


/******************************************************************************

	Function:	OnLButtonUp()

	Action:		Parent handler for L button-up message.  Dispatches the message to
						the current tool.

	Params:

	Returns:

	Comments:	

******************************************************************************/
void CPresView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if( GetCapture() != this )
		return;

	CClientDC dc( this );
	OnPrepareDC( &dc );
	dc.DPtoLP( &point );
	
	// Call tool button-up handler

	CScrollView::OnLButtonUp(nFlags, point);
}


/******************************************************************************

	Function:	OnMouseMove()

	Action:		Parent handler for mouse-move message.  Dispatches the message to
						the current tool.

	Params:

	Returns:

	Comments:

******************************************************************************/
void CPresView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if( GetCapture() != this )
		return;

	CClientDC dc( this );
	OnPrepareDC( &dc );
	dc.DPtoLP( &point );
	
	// Call tool mouse-move handler
	
	CScrollView::OnMouseMove(nFlags, point);
}
