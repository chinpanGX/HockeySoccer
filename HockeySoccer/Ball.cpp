/*=========================================================

	[Ball.cpp]
	Author : èoçá „ƒëæ

========================================================*/

#include "Ball.h"

void Ball::Init()
{
	m_Balltexture = m_Texture.LoadTexture("Rom/Texture/Ball.png");
	m_Position = D3DXVECTOR2(SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f);
	m_Velocity = D3DXVECTOR2(10.0f,-10.0f);
}

void Ball::Uninit()
{
	m_Texture.UnLoadTexture(m_Balltexture);
}

void Ball::Update()
{
}

void Ball::Draw()
{
	m_Sprite.Draw(m_Texture.SetTexture(m_Balltexture),m_Position.x,m_Position.y,32.0f,32.0f);
}
