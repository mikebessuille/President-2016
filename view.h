// view.h : interface of the CPresView class
//
/////////////////////////////////////////////////////////////////////////////

class CPresView : public CScrollView
{
protected: // create from serialization only
	CPresView();
	DECLARE_DYNCREATE( CPresView )

// Attributes
public:
	CPresDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPresView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPresView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void UpdateScrollValues( INT nWidth, INT nHeight );

// Generated message map functions
protected:
	//{{AFX_MSG(CPresView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in view.cpp
inline CPresDoc* CPresView::GetDocument()
   { return (CPresDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
