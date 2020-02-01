/*========================================================

	[ClearBG.cpp]
	Author : èoçá„ƒëæ

=========================================================*/

#include "ClearBG.h"

void ClearBG::Init()
{
}

void ClearBG::Uninit()
{
}

void ClearBG::Update()
{
}

void ClearBG::Draw(LPDIRECT3DTEXTURE9 Texture)
{
	m_Sprite.Draw(Texture, 0.0f, 0.0f, 1920.0f, 1080.0f);
}
