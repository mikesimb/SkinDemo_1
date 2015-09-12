#include "stdafx.h"
#include "SkinDialogData.h"


CSkinDialogData::CSkinDialogData()
{
}


CSkinDialogData::~CSkinDialogData()
{
}

void CSkinDialogData::LoadConfigFile(LPCTSTR lpcszFile)
{
	char *pFilename = new char[256];
	WideCharToMultiByte(CP_OEMCP, NULL, lpcszFile, -1, pFilename, 256, NULL, FALSE);
	m_IniFile = new CZQIniFile(pFilename);
	//首先加载独立配置
	m_crBackFrame = m_IniFile->ReadInteger("Setting", "crBackFrame", 0xFFFFFFFF);
	m_crBackGround = m_IniFile->ReadInteger("Setting", "crBackGround", 0xFFFFFFFF);
	m_crInsideBorder = m_IniFile->ReadInteger("Setting", "crInsideBorder", 0xFFFFFFFF);
	m_crCaptionText = m_IniFile->ReadInteger("Setting", "crCaptionText", 0xFFFFFFFF);
	//m_strCloseButtonFile  = m_IniFile->ReadString("Setting",m_str)
	

}
