/*==============================================

	[Goal.h]
	Author : 出合翔太

===============================================*/

#include "Goal.h"
#include "ObjectManager.h"

void Goal::Init()
{
	m_Position = D3DXVECTOR2(0.0f + 33.0f, 540.0f);
	m_Velocity = D3DXVECTOR2(0.0f, 0.0f);
	m_Component.m_aabb.cx = 0.0f;
	m_Component.m_aabb.cy = 0.0f;
	m_Component.m_aabb.sx = 33.0f;
	m_Component.m_aabb.sy = 128.0f;
}

void Goal::Init(float Speed)
{
	m_Position = D3DXVECTOR2(0.0f + 33.0f, 540.0f);
	m_Velocity = D3DXVECTOR2(0.0f, Speed);
	m_Component.m_aabb.cx = 0.0f;
	m_Component.m_aabb.cy = 0.0f;
	m_Component.m_aabb.sx = 33.0f;
	m_Component.m_aabb.sy = 128.0f;
}

void Goal::Uninit()
{
}

void Goal::Update()
{
	m_Position += m_Velocity;
	//	コリジョン位置の更新
	m_Component.m_aabb.cx = m_Position.x;
	m_Component.m_aabb.cy = m_Position.y;
	Topline* p_topline = ObjectManager::GetTopLine();
	if (Intercept(m_Component.m_aabb, p_topline->GetCollision()->GetAABB()) == true)
	{
		m_Position.y = 128.0f + 30.f;
		m_Velocity.y *= -1;
	}
	Underline* p_underline = ObjectManager::GetUnderLine();
	if (Intercept(m_Component.m_aabb, p_underline->GetCollision()->GetAABB()) == true)
	{
		m_Position.y = SCREEN_HEIGHT - 128.0f - 30.f;
		m_Velocity.y *= -1;
	}
	m_Position += m_Velocity;
}

void Goal::Draw(LPDIRECT3DTEXTURE9 Texture)
{
	D3DXCOLOR color = D3DCOLOR_RGBA(150, 150, 150, 255);
	m_Sprite.Draw(Texture, m_Position.x - 32.0f, m_Position.y - 128.0f, 100.0f, 256.0f, color);
}

Component2D * Goal::GetCollision()
{
	return &m_Component;
}

