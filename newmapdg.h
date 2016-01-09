// newmapdg.h : header file
//

#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// CNewMapDlg dialog

class CNewMapDlg : public CDialog
{
// Construction
public:
	CNewMapDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewMapDlg)
	enum { IDD = IDD_NEWMAP };
	CSpinButtonCtrl m_SpinW;
	CSpinButtonCtrl m_SpinH;
	int		m_nHeight;
	int		m_nWidth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewMapDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewMapDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
