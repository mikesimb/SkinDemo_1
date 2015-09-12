#pragma once
class CSkinImage :public CImage
{
public:
	CSkinImage();
	virtual ~CSkinImage();

	//´´½¨ÇøÓò
	HRGN CreateImageRegion(COLORREF cTranColor);
	//Í¸Ã÷»æ»­
	bool AlphaDrawImage(CDC * pDestDC, int xDest, int yDest, COLORREF crTrans);
	//Í¸Ã÷»æ»­
	bool AlphaDrawImage(CDC * pDestDC, int xDest, int yDest, int cxDest, int cyDest, int xSrc, int ySrc, COLORREF crTrans);
	//Í¸Ã÷»æ»­
	bool AlphaDrawImageEx(CDC * pDestDC, int xDest, int yDest, COLORREF crTrans);
	//Í¸Ã÷»æ»­
	bool AlphaDrawImageEx(CDC * pDestDC, int xDest, int yDest, int cxDest, int cyDest, int xSrc, int ySrc, COLORREF crTrans);

};

