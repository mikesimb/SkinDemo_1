#pragma once
#include "SkinImage.h"
#include "ZQIniFile.h"

//**************************************************************
//本单元主要是抽象的基本窗口数据类型。
//这些属性可以作为配置文件来加载
//并可以回写到配置文件中去
//首先确定我们用类型的文件来做  目前暂定位用INI文件
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
	COLORREF   m_crBackFrame;   //框的颜色
	COLORREF   m_crBackGround;  //窗口的背景颜色

	COLORREF   m_crInsideBorder;//边框的内框颜色
	COLORREF   m_crCaptionText; //标题颜色

	CString    m_strMinButtonFile;    //最大化按钮图片文件名
	CString    m_strMaxButtonFile;	  //最小化按钮图片文件名
	CString	   m_strCloseButtonFile;  //关闭按钮的图片文件名
	CString    m_strIconFile;		  //ICON图片文件名

	CString    m_strTitleLeftFile;   //标题的左边图片文件名
	CString    m_strTitleRightFile;  //标题的中间图片文件名
	CString    m_strTitleMidFile;	 //标题的右边图片文件名

	CSkinImage   m_Img_ButtonMax;  //最大化按钮图片文件
	CSkinImage   m_Img_ButtonMin;  //最小化按钮图片文件
	CSkinImage   m_Img_ButtonClose;//关闭按钮的图片文件
	CSkinImage   m_Img_Icon;       //ICON图片文件

	CSkinImage   m_Img_TitleLeft;   //标题的左边图片文件
	CSkinImage   m_Img_TitleMid;    //标题的中间图片文件
	CSkinImage   m_Img_TitleRight;  //标题的右边图片文件

public:
	void LoadConfigFile(LPCTSTR lpcszFile);
	void SaveConfigFile(LPCTSTR lpcszFile);

};

