
/* *************************************************************************
**		FROM MAP.CPP
** ********************************************************************** */

#if 0
	// TEST MRB: For testing coordinate conversions!
	{
	CPoint				pt;

	pt.x = rect->left;
	pt.y = rect->top;
	LogPtToDevPt( &pt );

	pt.x = rect->right;
	pt.y = rect->bottom;
	LogPtToDevPt( &pt );


	// Origin stuff  LOG--->DEV
	pt = m_ptLogOrigin;
	LogPtToDevPt( &pt );

	pt = m_ptLogOrigin;
	pt.y -= 1;
	LogPtToDevPt( &pt );

	pt = m_ptLogOrigin;
	pt.y -= 19;
	LogPtToDevPt( &pt );

	pt = m_ptLogOrigin;
	pt.y -= 20;
	LogPtToDevPt( &pt );

	pt = m_ptLogOrigin;
	pt.y -= 39;
	LogPtToDevPt( &pt );

	pt = m_ptLogOrigin;
	pt.y -= 40;
	LogPtToDevPt( &pt );

	pt = m_ptLogOrigin;
	pt.y -= 41;
	LogPtToDevPt( &pt );

	pt = m_ptLogOrigin;
	pt.y -= 59;
	LogPtToDevPt( &pt );

	pt = m_ptLogOrigin;
	pt.y -= 60;
	LogPtToDevPt( &pt );
	
	pt = m_ptLogOrigin;
	pt.y -= 61;
	LogPtToDevPt( &pt );


	// Test
	pt.x = 0;
	pt.y = 5;
	DevPtToLogPt( &pt );

	// Multiple conversions
	pt.x = m_nWidth - 1;
	pt.y = m_nHeight - 1;
	DevPtToLogPt( &pt );
	LogPtToDevPt( &pt );
	DevPtToLogPt( &pt );
	LogPtToDevPt( &pt );
	}
	// END TEST
#endif


#if 0
	/*
	** Using CImageList to draw transparent bitmaps
	*/
	// BOOL Draw( CDC* pdc, int nImage, POINT pt, UINT nStyle );
	m_pImageList->Draw( pDC, 0, CPoint(0,0), ILD_TRANSPARENT );
	m_pImageList->Draw( pDC, 1, CPoint(0,0), ILD_TRANSPARENT );


	/*
	** Using a CBitmap into a CDC to use BitBlt()
	** See books: Petzold, and Animation Techniques in Win32
	*/
	m_pBitmap->GetObject( sizeof( bm ), &bm );
	// Create a mem DC compatible to the display dc
	dcMem.CreateCompatibleDC( pDC );
	// Select Bitmap into memory DC
	pbmOld = dcMem.SelectObject( m_pBitmap );

	// BLIT!
	pDC->BitBlt(	100, 100,
								bm.bmWidth,
								bm.bmHeight,
								&dcMem,
								0, 0,
								SRCCOPY );

	// Cleanup
	dcMem.SelectObject( pbmOld );
#endif

#if 0
	/*
	CHAR	pStr[100];
	sprintf(	pStr, "rDev: T %d, L %d, B %d, R %d\n",
						rDev.top, rDev.left, rDev.bottom, rDev.right );
	OutputDebugString( pStr );
	sprintf(	pStr, "(LOG) T %d, L %d, B %d, R %d\n",
						prect->top, prect->left, prect->bottom, prect->right );
	OutputDebugString( pStr );
 	*/
#endif