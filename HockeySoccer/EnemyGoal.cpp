/*=========================================================

	[EnemyGoal.h]
	Author : o‡ãÄ‘¾

=========================================================*/

#include "EnemyGoal.h"
#include "ObjectManager.h"

void EnemyGoal::Init()
{
	m_Position = D3DXVECTOR2(SCREEN_WIDTH - 65.0f, 540.0f);
	m_Velocity = D3DXVECTOR2(0.0f, 0.0f);
	m_Component.m_aabb.sx = 32.0f;
	m_Component.m_aabb.sy = 128.0f;
}

void EnemyGoal::Init(float Speed)
{
	m_Position = D3DXVECTOR2(SCREEN_WIDTH - 65.0f, 540.0f);
	m_Velocity = D3DXVECTOR2(0.0f, Speed);
	m_Component.m_aabb.sx = 32.0f;
	m_Component.m_aabb.sy = 128.0f;
}

void EnemyGoal::Uninit()
{
}

void EnemyGoal::Update()
{
	m_Position += m_Velocity;
	m_Component.m_aabb.cx = m_Position.x;
	m_Component.m_aabb.cy = m_Position.y;
	Topline* p_topline = ObjectManager::GetTopLine();
	if (AABB_2d(m_Component.m_aabb, p_topline->GetCollision()->GetAABB()) == true)
	{
		m_Position.y = 128.0f + 30.f;
		m_Velocity.y *= -1;
	}
	Underline* p_underline = ObjectManager::GetUnderLine();
	if (AABB_2d(m_Component.m_aabb, p_underline->GetCollision()->GetAABB()) == true)
	{
		m_Position.y = SCREEN_HEIGHT - 128.0f - 30.f;
		m_Velocity.y *= -1;
	}
	m_Position += m_Velocity;
}

void EnemyGoal::Draw(LPDIRECT3DTEXTURE9 Texture)
{
	D3DXCOLOR color = D3DCOLOR_RGBA(150, 150, 150, 255);
	m_Sprite.Draw(Texture, m_Position.x - 34.0f, m_Position.y - 128.0f, 100.0f, 256.0f, color);
}

Component2D * EnemyGoal::GetCollision()
{
	return &m_Component;
}
