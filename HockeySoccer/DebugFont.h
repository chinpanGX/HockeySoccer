
//
// �f�o�b�O�\������ [debugproc.h]
// Author : 
//

#pragma once

class DebugFont
{
	static LPD3DXFONT			g_pD3DXFont;		// �t�H���g�ւ̃|�C���^
	static char					g_aStrDebug[1024];	// �f�o�b�O���
	static LPDIRECT3DDEVICE9	pDevice;
public:
	static HRESULT Init();
	static void Uninit();
	static void Draw();
	static void Print(char *fmt,...);
};