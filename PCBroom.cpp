// PCBroom.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "PCBroom.h"
#include "MainWndHandler.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CPCBroomApp

BEGIN_MESSAGE_MAP(CPCBroomApp, CWinApp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPCBroomApp construction

CPCBroomApp::CPCBroomApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_bCallLibUIDKMsgMap = TRUE;
	m_pMainFrame = NULL;
	m_pMainWndHandler = NULL;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPCBroomApp object

CPCBroomApp theApp;

//////////////////////////////////////////////////////////////////////////
// public

BOOL CPCBroomApp::IsCallLibUIDKMsgMap()
{
	return m_bCallLibUIDKMsgMap;
}

/////////////////////////////////////////////////////////////////////////////
// CPCBroomApp initialization

BOOL CPCBroomApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	// Change the path under which your skin files are stored.
	int nRet = CUIMgr::SetUIPath(_T("..\\..\\Bin\\Skins\\PCBroom\\the.xui"));
	if (nRet != 0)
	{
		AfxMessageBox(_T("Failed to set the ui path or the ui path isn't exist!"));
		return FALSE;
	}

	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object.
	m_pMainWndHandler = new CMainWndHandler(IDW_MAIN);
	m_pMainFrame = CUIMgr::LoadFrame(IDR_MAINFRAME, WS_VISIBLE | WS_POPUP,
			IDW_MAIN, m_pMainWndHandler);
	if (m_pMainFrame == NULL)
	{
		// Search the error code in LibUIDK.h, the first error code is E_LOADBMPB.
		DWORD dwLastError = m_pMainFrame->GetLastCreateError();
		return FALSE;
	}

	m_pMainFrame->CenterWindow();

	// The one and only window has been initialized, so show and update it.
	m_pMainFrame->ShowWindow(SW_SHOW);
	m_pMainFrame->UpdateWindow();

	m_pMainWnd = m_pMainFrame;

	return TRUE;
}

int CPCBroomApp::ExitInstance()
{
	if (m_pMainFrame != NULL)
	{
		SafeDelete(m_pMainFrame);
	}

	SafeDelete(m_pMainWndHandler);

	CUIMgr::ReleaseSkin();

	// TODO: Add your specialized code here and/or call the base class

	return CWinApp::ExitInstance();
}

/////////////////////////////////////////////////////////////////////////////
// CPCBroomApp message handlers

