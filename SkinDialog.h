#pragma once
#include "afxwin.h"
class CSkinDialog :
	public CDialog
{
public:
	CSkinDialog();
	virtual ~CSkinDialog();
public:
	//��ʼ����Ϣ
	virtual BOOL OnInitDialog();
protected:
	//��Ϣӳ��
	//������Ϣ
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	//Ӧ�ü�����Ϣ
	afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadID);
	//������������Ϣ
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//������˫����Ϣ
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//������̧����Ϣ
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//����Ҽ�˫����Ϣ
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	//����Ҽ�������Ϣ
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//����Ҽ�̧����Ϣ
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//����ƶ���Ϣ
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//���ڻ�����Ϣ
	afx_msg void OnPaint();
	//�������øı���Ϣ
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	//����������Ϣ
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//����λ�ñ仯��Ϣ
	afx_msg void OnWindowPosChanged(WINDOWPOS * lpwndpos);
	//�ؼ���ɫ�ı���Ϣ
	afx_msg HBRUSH onCtlColor(CDC* pDC, CWnd *pWnd, UINT nCtlColor);
	//���ñ�����Ϣ
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
	//������������ť
	void AdjustTitleButton(int cx, int cy);
};

