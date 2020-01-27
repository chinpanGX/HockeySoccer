/*=========================================================

	[Player.cpp]
	プレイヤーを管理する
	Author : 出合翔太

==========================================================*/

#include "Player.h"
#include "Controller.h"

void Player::Init()
{
	m_Playertexture = m_Texture.LoadTexture("ASSET/TEXTURE/player.tga");
	m_Position = D3DXVECTOR2(SCREEN_WIDTH * 0.5f - 144.0f, 540.0f);
}

void Player::Uninit()
{
	m_Texture.UnLoadTexture(m_Playertexture);
}

void Player::Update()
{
	m_Velocity = D3DXVECTOR2(0.0f, 0.0f);
	if (KeyBoard::IsPress(DIK_LEFTARROW))
	{
		m_Velocity.x -= 5.0f;
	}
	if (KeyBoard::IsPress(DIK_RIGHTARROW))
	{
		m_Velocity.x += 5.0f;
	}
	
	m_Position += m_Velocity;
}

void Player::Draw()
{
	m_Sprite.Draw(m_Texture.SetTexture(m_Playertexture),m_Position.x,m_Position.y,256.0f,64.0f);
}
