#pragma once
#include "SkinImage.h"
#include "ZQIniFile.h"

//**************************************************************
//����Ԫ��Ҫ�ǳ���Ļ��������������͡�
//��Щ���Կ�����Ϊ�����ļ�������
//�����Ի�д�������ļ���ȥ
//����ȷ�����������͵��ļ�����  Ŀǰ�ݶ�λ��INI�ļ�
//**************************************************************
class CSkinDialogData
{
public:
	CSkinDialogData();
	virtual ~CSkinDialogData();

private:
	CString  m_strConfigFileName;
	CZQIniFile * m_IniFile;

public:
	COLORREF   m_crBackFrame;   //�����ɫ
	COLORREF   m_crBackGround;  //���ڵı�����ɫ

	COLORREF   m_crInsideBorder;//�߿���ڿ���ɫ
	COLORREF   m_crCaptionText; //������ɫ

	CString    m_strMinButtonFile;    //��󻯰�ťͼƬ�ļ���
	CString    m_strMaxButtonFile;	  //��С����ťͼƬ�ļ���
	CString	   m_strCloseButtonFile;  //�رհ�ť��ͼƬ�ļ���
	CString    m_strIconFile;		  //ICONͼƬ�ļ���

	CString    m_strTitleLeftFile;   //��������ͼƬ�ļ���
	CString    m_strTitleRightFile;  //������м�ͼƬ�ļ���
	CString    m_strTitleMidFile;	 //������ұ�ͼƬ�ļ���

	CSkinImage   m_Img_ButtonMax;  //��󻯰�ťͼƬ�ļ�
	CSkinImage   m_Img_ButtonMin;  //��С����ťͼƬ�ļ�
	CSkinImage   m_Img_ButtonClose;//�رհ�ť��ͼƬ�ļ�
	CSkinImage   m_Img_Icon;       //ICONͼƬ�ļ�

	CSkinImage   m_Img_TitleLeft;   //��������ͼƬ�ļ�
	CSkinImage   m_Img_TitleMid;    //������м�ͼƬ�ļ�
	CSkinImage   m_Img_TitleRight;  //������ұ�ͼƬ�ļ�

public:
	void LoadConfigFile(LPCTSTR lpcszFile);
	void SaveConfigFile(LPCTSTR lpcszFile);

};

