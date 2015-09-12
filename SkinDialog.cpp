#include "stdafx.h"
#include "SkinDialog.h"


//**************************************************
//消息映射
IMPLEMENT_DYNAMIC(CSkinDialog, CDialog)

BEGIN_MESSAGE_MAP(CSkinDialog, CDialog)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_CTLCOLOR()
	ON_WM_ACTIVATE()
	ON_WM_ACTIVATEAPP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	ON_WM_SETTINGCHANGE()
	ON_WM_WINDOWPOSCHANGED()
	ON_MESSAGE(WM_SETTEXT, OnSetTextMessage)
END_MESSAGE_MAP()
//**********************************************************

CSkinDialog::CSkinDialog()
{
}


CSkinDialog::~CSkinDialog()
{
}

BOOL CSkinDialog::OnInitDialog()
{
	__super::OnInitDialog();
	
	SetClassLong(m_hWnd, GCL_HBRBACKGROUND, NULL);
	return true;
	
}

void CSkinDialog::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	__super::OnActivate(nState, pWndOther, bMinimized);
	m_bActived = (nState != WA_ACTIVE);
	//在这里做第一次绘制
	DrawSkinWindow(NULL);
}

void CSkinDialog::OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
	__super::OnActivateApp(bActive, dwThreadID);
	m_bActived = bActive;
	DrawSkinWindow(NULL);
	return;
}

void CSkinDialog::OnLButtonDown(UINT nFlags, CPoint point)
{
	__super::OnLButtonDown(nFlags, point);
	OnLButtonDownEvent(point);
}

void CSkinDialog::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	__super::OnLButtonDblClk(nFlags, point);
	OnLButtonDblClkEvent(point);
}

void CSkinDialog::OnLButtonUp(UINT nFlags, CPoint point)
{
	__super::OnLButtonUp(nFlags, point);
	OnLButtonUpEvent(point);
}

void CSkinDialog::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	__super::OnRButtonDblClk(nFlags, point);
	OnRButtonDblClkEvent(point);
}

void CSkinDialog::OnRButtonDown(UINT nFlags, CPoint point)
{
	__super::OnRButtonDown(nFlags, point);
	OnRButtonDownEvent(point);
}

void CSkinDialog::OnRButtonUp(UINT nFlags, CPoint point)
{
	__super::OnRButtonDown(nFlags, point);
	OnRButtonUpEvent(point);
}

void CSkinDialog::OnMouseMove(UINT nFlags, CPoint point)
{
	__super::OnMouseMove(nFlags, point);
	OnMouseMoveEvent(point);
}

void CSkinDialog::OnPaint()
{
	CPaintDC dc(this);
	DrawSkinWindow(&dc);
	return;
}

void CSkinDialog::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	__super::OnSettingChange(uFlags, lpszSection);
	OnSettingChangeEvent();
	return;

}

BOOL CSkinDialog::OnEraseBkgnd(CDC* pDC)
{
	Invalidate(FALSE);
	UpdateWindow();
	return TRUE;

}

void CSkinDialog::OnWindowPosChanged(WINDOWPOS * lpwndpos)
{
	__super::OnWindowPosChanged(lpwndpos);

	//调整位置
	CRect rcClient;
	//m_cbNowHotButton = 255;
	//m_cbNowDownButton = 255;
	GetClientRect(&rcClient);
	AdjustTitleButton(rcClient.Width(), rcClient.Height());

	//重画界面
	DrawSkinWindow(NULL);

	return;
}

HBRUSH CSkinDialog::onCtlColor(CDC* pDC, CWnd *pWnd, UINT nCtlColor)
{
	switch (nCtlColor)
	{
	case CTLCOLOR_DLG:
	case CTLCOLOR_STATIC:
		{
			pDC->SetBkMode(TRANSPARENT);
			pDC->SetBkColor(m_SkinAttribute.m_crBackGround);
			pDC->SetTextColor(m_SkinAttribute.m_crControlTXColor);
			return m_SkinAttribute.m_brBackGround;
		}
	}
	return __super::OnCtlColor(pDC,pWnd,nCtlColor);
}

LRESULT CSkinDialog::OnSetTextMessage(WPARAM wParam, LPARAM lParam)
{
	LRESULT lResult = DefWindowProc(WM_SETTEXT, wParam, lParam);
	DrawSkinWindow(NULL);
	return lResult;
}

void CSkinDialog::DrawWindow()
{

}

void CSkinDialog::DrawSkinWindow(CDC * pdc)
{

}

void CSkinDialog::OnLButtonDownEvent(CPoint Point)
{

}

void CSkinDialog::OnSettingChangeEvent()
{

}

void CSkinDialog::AdjustTitleButton(int cx, int cy)
{
	for (int i = 0; i < 3; i++)
	{
		int nYPos = 6;
		int nXPos = cx - m_SkinAttribute.m_nButtonWidth*(i + 1) - i * 2 - 8;
		m_rcButton[i].left = nXPos;
		m_rcButton[i].top = nYPos;
		m_rcButton[i].right = nXPos + m_SkinAttribute.m_nButtonWidth;
		m_rcButton[i].bottom = nYPos + m_SkinAttribute.m_nButtonHeigth;
	}

	return;
}
