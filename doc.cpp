// doc.cpp : implementation of the CPresDoc class
//

#include "stdafx.h"
#include "President.h"

#include "map.h"
#include "doc.h"
#include "newmapdg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPresDoc

IMPLEMENT_DYNCREATE(CPresDoc, CDocument)

BEGIN_MESSAGE_MAP(CPresDoc, CDocument)
	//{{AFX_MSG_MAP(CPresDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPresDoc construction/destruction


/******************************************************************************

	Function:	CPresDoc() constructor

	Action:

	Params:

	Returns:

	Comments:

******************************************************************************/
CPresDoc::CPresDoc()
{
	// TODO: add one-time construction code here
	m_pMap = NULL;
}


/******************************************************************************

	Function: ~CPresDoc() destructor

	Action:

	Params:

	Returns:

	Comments:

******************************************************************************/
CPresDoc::~CPresDoc()
{
	if( m_pMap )
	{
		ASSERT( 0 );
		delete m_pMap;
	}
}


/******************************************************************************

	Function:	OnNewDocument()

	Action:

	Params:

	Returns:

	Comments:

******************************************************************************/
BOOL CPresDoc::OnNewDocument()
{	
	INT nWidth, nHeight;
	BOOL bRC = FALSE;

	if( !CDocument::OnNewDocument())
		return( FALSE );
	InitDocument();

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	// Generate the map object
	m_pMap = new CWorldMap;
	if( !m_pMap )
		return( FALSE );

	// Bring up dialog here, to determine size of map.
	{
		CNewMapDlg dlg;
		nWidth = MAP_DEFAULT_WIDTH;
		nHeight =  MAP_DEFAULT_HEIGHT;
		dlg.m_nWidth = nWidth;
		dlg.m_nHeight = nHeight;

		if( dlg.DoModal() == IDOK )
		{
			nWidth = dlg.m_nWidth;
			nHeight = dlg.m_nHeight;
		}
	}
	m_pMap->SetDevSize( nWidth, nHeight );

	bRC = m_pMap->InitMap( this );
	bRC |= m_pMap->GenerateMap();
	
	return( bRC );
}


/******************************************************************************

	Function:	OnOpenDocument

	Action:		Loads a current game (map and other game data).

	Params:

	Returns:

	Comments:

******************************************************************************/
BOOL CPresDoc::OnOpenDocument( LPCTSTR lpszPathName ) 
{
	BOOL bRC = FALSE;

	// This calls Serialize().
	if( !CDocument::OnOpenDocument( lpszPathName ))
		return( FALSE );
	InitDocument();

	bRC = m_pMap->InitMap( this );

	return( bRC );
}


/******************************************************************************

	Function:	InitDocument()

	Action:		Inits various game aspects

	Params:

	Returns:

	Comments:

******************************************************************************/
void CPresDoc::InitDocument()
{
}


/////////////////////////////////////////////////////////////////////////////
// CPresDoc serialization

/******************************************************************************

	Function:	Serialize

	Action:		Stores and retrieves a document (a particular saved game).

	Params:

	Returns:

	Comments:

******************************************************************************/
void CPresDoc::Serialize( CArchive& ar )
{
	if( ar.IsStoring())
	{
		ASSERT_VALID( m_pMap );

		// TODO: add storing code here
	}
	else
	{
		// Generate the map object
		m_pMap = new CWorldMap;
		if( !m_pMap )
			return;

		// TODO: add loading code here
	}

	// ZAZ make sure to serialize the Units list FIRST!
	// The map object points into it!
	m_pMap->Serialize( ar );
}


/////////////////////////////////////////////////////////////////////////////
// CPresDoc diagnostics

#ifdef _DEBUG
void CPresDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPresDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG



/////////////////////////////////////////////////////////////////////////////
// CPresDoc commands

/******************************************************************************

	Function:	DeleteContents()

	Action:		This is called whenever the DOC is closed (if a new doc is created
						or loaded) since in an SDI app the DOC object is reused.
						Make sure everything is reset here!

	Params:

	Returns:

	Comments:

******************************************************************************/
void CPresDoc::DeleteContents() 
{
	if( m_pMap )
		delete m_pMap;
	m_pMap = NULL;
	
	CDocument::DeleteContents();
}


/******************************************************************************

	Function:

	Action:

	Params:

	Returns:

	Comments:

******************************************************************************/
