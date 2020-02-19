/*====================================================

	[Effect.cpp]
	Author : �o���đ�

=====================================================*/

#include "Effect.h"

void Effect::Init()
{
	m_Effecttexture = m_Texture.LoadTexture("Rom/Texture/Explosion.png");
	m_Use = false;
	m_Frame = 0;
	FrameSize = 192.0f;
	AnimeMax = 20;
}

void Effect::Uninit()
{
	m_Texture.UnLoadTexture(m_Effecttexture);
}

void Effect::Update()
{
	if (m_Use == true) 
	{
		m_Frame++;
		if (m_Frame >= AnimeMax)
		{
			m_Use = false;
		}
	}
}

void Effect::Draw(LPDIRECT3DTEXTURE9 Texture)
{
	
}

void Effect::Draw()
{
	// ���ݕ\������ׂ��p�^�[���ԍ�����؂�����W���Z�o����
	float tx = FrameSize * (m_Frame % 5);
	float ty = FrameSize * (m_Frame / 5);
	m_Sprite.Draw(m_Texture.SetTexture(m_Effecttexture), m_Position.x, m_Position.y, 960.0f, 768.0f, tx, ty, FrameSize, FrameSize);
}

void Effect::Set(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Frame = 0;
	m_Use = true;
}


