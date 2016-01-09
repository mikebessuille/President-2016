
/******************************************************************************

	File:			doc.h

	Action:		Definition of the CPresDoc class

	Params:

	Returns:

	Comments:

******************************************************************************/

#ifndef _DOC_H
#define _DOC_H

/*
**	Includes
*/

class CWorldMap;	// Defined in map.h


class CPresDoc : public CDocument
{
protected: // create from serialization only
	CPresDoc();
	DECLARE_DYNCREATE( CPresDoc );


/*
** Attributes
*/
public:
	CWorldMap		*m_pMap;


/*
** Operations
*/
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPresDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL


/*
** Implementation
*/
public:
	virtual ~CPresDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void		InitDocument();

/*
** Generated message map functions
*/
protected:
	//{{AFX_MSG(CPresDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif // _DOC_H
