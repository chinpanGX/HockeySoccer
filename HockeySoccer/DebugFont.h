
//
// デバッグ表示処理 [debugproc.h]
// Author : 
//

#pragma once

class DebugFont
{
	static LPD3DXFONT			g_pD3DXFont;		// フォントへのポインタ
	static char					g_aStrDebug[1024];	// デバッグ情報
	static LPDIRECT3DDEVICE9	pDevice;
public:
	static HRESULT Init();
	static void Uninit();
	static void Draw();
	static void Print(char *fmt,...);
};