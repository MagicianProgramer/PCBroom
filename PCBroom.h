// PCBroom.h : main header file for the PCBROOM application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

class CMainFrame;
class CMainWndHandler;

/////////////////////////////////////////////////////////////////////////////
// CPCBroomApp:
// See PCBroom.cpp for the implementation of this class
//

class CPCBroomApp : public CWinApp
{
public:
	CPCBroomApp();

public:
	BOOL IsCallLibUIDKMsgMap();

// Overrides
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	DECLARE_MESSAGE_MAP()

private:
	BOOL m_bCallLibUIDKMsgMap;
	CUIWnd *m_pMainFrame;
	CMainWndHandler *m_pMainWndHandler;
};

