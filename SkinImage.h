#pragma once
class CSkinImage :public CImage
{
public:
	CSkinImage();
	virtual ~CSkinImage();

	//��������
	HRGN CreateImageRegion(COLORREF cTranColor);
	//͸���滭
	bool AlphaDrawImage(CDC * pDestDC, int xDest, int yDest, COLORREF crTrans);
	//͸���滭
	bool AlphaDrawImage(CDC * pDestDC, int xDest, int yDest, int cxDest, int cyDest, int xSrc, int ySrc, COLORREF crTrans);
	//͸���滭
	bool AlphaDrawImageEx(CDC * pDestDC, int xDest, int yDest, COLORREF crTrans);
	//͸���滭
	bool AlphaDrawImageEx(CDC * pDestDC, int xDest, int yDest, int cxDest, int cyDest, int xSrc, int ySrc, COLORREF crTrans);

};

