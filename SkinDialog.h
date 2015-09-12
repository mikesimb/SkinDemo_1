#pragma once
#include "afxwin.h"
class CSkinDialog :
	public CDialog
{
public:
	CSkinDialog();
	virtual ~CSkinDialog();
public:
	//初始化消息
	virtual BOOL OnInitDialog();
protected:
	//消息映射
	//激活消息
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	//应用激活消息
	afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadID);
	//鼠标左键按下消息
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//鼠标左键双击消息
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//鼠标左键抬起消息
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//鼠标右键双击消息
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	//鼠标右键按下消息
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//鼠标右键抬起消息
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//鼠标移动消息
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//窗口绘制消息
	afx_msg void OnPaint();
	//窗口设置改变消息
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	//背景擦除消息
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//窗口位置变化消息
	afx_msg void OnWindowPosChanged(WINDOWPOS * lpwndpos);
	//控件颜色改变消息
	afx_msg HBRUSH onCtlColor(CDC* pDC, CWnd *pWnd, UINT nCtlColor);
	//设置标题消息
	LRESULT OnSetTextMessage(WPARAM wParam, LPARAM lParam);
	


	DECLARE_MESSAGE_MAP();
	DECLARE_DYNAMIC(CSkinDialog);

private:
	BOOL m_bActived;
	BOOL m_bMaxSize;
	
	CRect  m_rcButton[3];

	void DrawWindow();
	void DrawSkinWindow(CDC * pdc);
	void OnLButtonDownEvent(CPoint Point);
	void OnLButtonUpEvent(CPoint Point);
	void OnLButtonDblClkEvent(CPoint Point);

	void OnRButtonDownEvent(CPoint Point);
	void OnRButtonUpEvent(CPoint Point);
	void OnRButtonDblClkEvent(CPoint Point);

	void OnMouseMoveEvent(CPoint point);

	void OnSettingChangeEvent();
	//调整标题栏按钮
	void AdjustTitleButton(int cx, int cy);
};

