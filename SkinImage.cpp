#include "stdafx.h"
#include "SkinImage.h"


CSkinImage::CSkinImage()
{
}


CSkinImage::~CSkinImage()
{
}

//͸���滭
bool CSkinImage::AlphaDrawImage(CDC * pDestDC, int xDest, int yDest, COLORREF crTrans)
{
	return AlphaDrawImage(pDestDC, xDest, yDest, GetWidth(), GetHeight(), 0, 0, crTrans);
}

//͸���滭
bool CSkinImage::AlphaDrawImage(CDC * pDestDC, int xDest, int yDest, int cxDest, int cyDest, int xSrc, int ySrc, COLORREF crTrans)
{
	//Ч��״̬
	if (IsNull()) return false;

	//���� DC
	CDC DCImage;
	DCImage.CreateCompatibleDC(pDestDC);
	DCImage.SelectObject(HBITMAP(*this));
	DCImage.SetBkColor(crTrans);
	DCImage.SetBkMode(TRANSPARENT);

	//��������ͼ
	CDC DCMask;
	CBitmap BMPMask;
	BMPMask.CreateBitmap(cxDest, cyDest, 1, 1, NULL);
	DCMask.CreateCompatibleDC(pDestDC);
	DCMask.SelectObject(&BMPMask);
	DCMask.BitBlt(0, 0, cxDest, cyDest, &DCImage, xSrc, ySrc, SRCCOPY);

	//�滭Ŀ��ͼ
	CDC DCDest;
	CBitmap BMPDest;
	DCDest.CreateCompatibleDC(pDestDC);
	BMPDest.CreateCompatibleBitmap(pDestDC, cxDest, cyDest);
	DCDest.SelectObject(&BMPDest);
	DCDest.BitBlt(0, 0, cxDest, cyDest, pDestDC, xDest, yDest, SRCCOPY);
	DCDest.BitBlt(0, 0, cxDest, cyDest, &DCImage, xSrc, ySrc, SRCINVERT);
	DCDest.BitBlt(0, 0, cxDest, cyDest, &DCMask, 0, 0, SRCAND);
	DCDest.BitBlt(0, 0, cxDest, cyDest, &DCImage, xSrc, ySrc, SRCINVERT);
	pDestDC->BitBlt(xDest, yDest, cxDest, cyDest, &DCDest, 0, 0, SRCCOPY);

	//������Դ
	DCMask.DeleteDC();
	DCDest.DeleteDC();
	DCImage.DeleteDC();
	BMPMask.DeleteObject();
	BMPDest.DeleteObject();

	return true;
}

//͸���滭
bool CSkinImage::AlphaDrawImageEx(CDC * pDestDC, int xDest, int yDest, COLORREF crTrans)
{
	return AlphaDrawImageEx(pDestDC, xDest, yDest, GetWidth(), GetHeight(), 0, 0, crTrans);
}

//͸���滭
bool CSkinImage::AlphaDrawImageEx(CDC * pDestDC, int xDest, int yDest, int cxDest, int cyDest, int xSrc, int ySrc, COLORREF crTrans)
{
	//Ч��״̬
	if (IsNull()) return false;

	//���� DC
	CDC DCImage;
	DCImage.CreateCompatibleDC(pDestDC);
	DCImage.SelectObject(HBITMAP(*this));
	DCImage.SetBkColor(crTrans);
	DCImage.SetBkMode(TRANSPARENT);

	//��������ͼ
	CDC DCMask;
	CBitmap BMPMask;
	BMPMask.CreateBitmap(cxDest, cyDest, 1, 1, NULL);
	DCMask.CreateCompatibleDC(pDestDC);
	DCMask.SelectObject(&BMPMask);
	DCMask.BitBlt(0, 0, cxDest, cyDest, &DCImage, xSrc, ySrc, SRCCOPY);

	//�滭Ŀ��ͼ
	pDestDC->BitBlt(xDest, yDest, cxDest, cyDest, pDestDC, xDest, yDest, SRCCOPY);
	pDestDC->BitBlt(xDest, yDest, cxDest, cyDest, &DCImage, xSrc, ySrc, SRCINVERT);
	pDestDC->BitBlt(xDest, yDest, cxDest, cyDest, &DCMask, 0, 0, SRCAND);
	pDestDC->BitBlt(xDest, yDest, cxDest, cyDest, &DCImage, xSrc, ySrc, SRCINVERT);

	//������Դ
	DCMask.DeleteDC();
	DCImage.DeleteDC();
	BMPMask.DeleteObject();

	return true;
}


//��������
HRGN CSkinImage::CreateImageRegion(COLORREF cTranColor)
{
	//�ж�״̬
	if (IsNull() == true) return NULL;

	//��������
	HRGN hRgn = NULL;
	HDC hMemDC = ::CreateCompatibleDC(NULL);
	if (hMemDC != NULL)
	{
		void * pbits32 = NULL;
		HBITMAP hBitmap = (HBITMAP)this;
		BITMAPINFOHEADER RGB32BITSBITMAPINFO = { sizeof(BITMAPINFOHEADER),GetWidth(),GetHeight(),1,32,BI_RGB,0,0,0,0,0 };
		HBITMAP hbm32 = CreateDIBSection(hMemDC, (BITMAPINFO *)&RGB32BITSBITMAPINFO, DIB_RGB_COLORS, &pbits32, NULL, 0);
		if (hbm32)
		{
			HBITMAP holdBmp = (HBITMAP)SelectObject(hMemDC, hbm32);
			HDC hDC = CreateCompatibleDC(hMemDC);
			if (hDC)
			{
				BITMAP bm32;
				GetObject(hbm32, sizeof(bm32), &bm32);
				while (bm32.bmWidthBytes % 4) bm32.bmWidthBytes++;
				HBITMAP holdBmp = (HBITMAP)SelectObject(hDC, hBitmap);
				::BitBlt(hMemDC, 0, 0, GetWidth(), GetHeight(), hDC, 0, 0, SRCCOPY);
				DWORD maxRects = 100;
				HANDLE hData = GlobalAlloc(GMEM_MOVEABLE, sizeof(RGNDATAHEADER) + (sizeof(RECT)*maxRects));
				RGNDATA *pData = (RGNDATA *)GlobalLock(hData);
				pData->rdh.dwSize = sizeof(RGNDATAHEADER);
				pData->rdh.iType = RDH_RECTANGLES;
				pData->rdh.nCount = pData->rdh.nRgnSize = 0;
				SetRect(&pData->rdh.rcBound, MAXLONG, MAXLONG, 0, 0);
				BYTE hr = GetRValue(cTranColor);
				BYTE hg = GetGValue(cTranColor);
				BYTE hb = GetBValue(cTranColor);
				BYTE * p32 = (BYTE *)bm32.bmBits + (bm32.bmHeight - 1)*bm32.bmWidthBytes;
				for (int y = 0; y<GetHeight(); y++)
				{
					for (int x = 0; x<GetWidth(); x++)
					{
						int x0 = x;
						LONG *p = (LONG *)p32 + x;
						while (x<GetWidth())
						{
							BYTE b = GetRValue(*p);
							if ((b >= hr) && (b <= hr))
							{
								b = GetGValue(*p);
								if (b >= hg&&b <= hg)
								{
									b = GetBValue(*p);
									if (b >= hb&&b <= hb) break;
								}
							}
							p++;
							x++;
						}
						if (x>x0)
						{
							if (pData->rdh.nCount >= maxRects)
							{
								GlobalUnlock(hData);
								maxRects += 100;
								hData = GlobalReAlloc(hData, sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects), GMEM_MOVEABLE);
								pData = (RGNDATA *)GlobalLock(hData);
							}
							RECT * pr = (RECT *)&pData->Buffer;
							SetRect(&pr[pData->rdh.nCount], x0, y, x, y + 1);
							if (x0<pData->rdh.rcBound.left)	pData->rdh.rcBound.left = x0;
							if (y<pData->rdh.rcBound.top) pData->rdh.rcBound.top = y;
							if (x>pData->rdh.rcBound.right) pData->rdh.rcBound.right = x;
							if (y + 1>pData->rdh.rcBound.bottom) pData->rdh.rcBound.bottom = y + 1;
							pData->rdh.nCount++;
							if (pData->rdh.nCount == 2000)
							{
								HRGN h = ExtCreateRegion(NULL, sizeof(RGNDATAHEADER) + (sizeof(RECT)*maxRects), pData);
								if (hRgn)
								{
									CombineRgn(hRgn, hRgn, h, RGN_OR);
									DeleteObject(h);
								}
								else hRgn = h;
								pData->rdh.nCount = 0;
								SetRect(&pData->rdh.rcBound, MAXLONG, MAXLONG, 0, 0);
							}
						}
					}
					p32 -= bm32.bmWidthBytes;
				}
				HRGN h = ExtCreateRegion(NULL, sizeof(RGNDATAHEADER) + (sizeof(RECT)*maxRects), pData);
				if (hRgn)
				{
					CombineRgn(hRgn, hRgn, h, RGN_OR);
					DeleteObject(h);
				}
				else hRgn = h;
				GlobalFree(hData);
				SelectObject(hDC, holdBmp);
				DeleteDC(hDC);
			}
			DeleteObject(SelectObject(hMemDC, holdBmp));
		}
		DeleteDC(hMemDC);
	}
	return hRgn;
}
