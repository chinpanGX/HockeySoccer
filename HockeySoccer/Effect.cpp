/*====================================================

	[Effect.cpp]
	Author : 出合翔太

=====================================================*/

#include "Effect.h"

void Effect::Init()
{
	m_Use = false;
	m_Frame = 0;
	FrameSize = 192.0f;
}

void Effect::Uninit()
{
	
}

void Effect::Update()
{
	if (m_Use == true) 
	{
		m_Frame++;
		if (m_Frame >= 20)
		{
			m_Use = false;
		}
	}
}

void Effect::Draw(LPDIRECT3DTEXTURE9 Texture)
{
	if (m_Use == true)
	{
		// 現在表示するべきパターン番号から切り取り座標を算出する
		float tx = FrameSize * (m_Frame % 5);
		float ty = FrameSize * (m_Frame / 5);
		m_Sprite.Draw(Texture, m_Position.x - (FrameSize * 0.5f), m_Position.y - (FrameSize * 0.5f), 960.0f, 768.0f, tx, ty, FrameSize, FrameSize);
	}
}

void Effect::Set(float x, float y)
{
	if (m_Use == false)
	{
		m_Position.x = x;
		m_Position.y = y;
		m_Frame = 0;
		m_Use = true;
	}
}

