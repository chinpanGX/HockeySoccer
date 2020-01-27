/*========================================================

	[Background.h]
	ƒQ[ƒ€”wŒi‚ğ•`‰æ
	Author : o‡ ãÄ‘¾

=========================================================*/

#include "Background.h"

void Background::Init()
{
	m_Bgtexture = m_Texture.LoadTexture("ASSET/TEXTURE/bg.tga");
}

void Background::Uninit()
{
	m_Texture.UnLoadTexture(m_Bgtexture);
}

void Background::Draw()
{
	m_Sprite.Draw(m_Texture.SetTexture(m_Bgtexture),0.0f,0.0f,1920.0f,1080.0f);
}
