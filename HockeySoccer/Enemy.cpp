/*=========================================================

	[Enemy.cpp]
	Author : 出合翔太

==========================================================*/

#include "Enemy.h"
#include "Line.h"
#include "ObjectManager.h"

void Enemy::Init()
{
	m_Position = D3DXVECTOR2((480.0f * 3) - 32.0f, 540.0f);
	m_Velocity = D3DXVECTOR2(0.0f, 5.0f);	//	ベクトルの初期化
	m_Component[center].m_aabb.sx = 16.0f;
	m_Component[center].m_aabb.sy = 120.0f;
	m_Component[up].m_aabb.sx = 16.0f;
	m_Component[up].m_aabb.sy = 4.0f;
	m_Component[down].m_aabb.sx = 16.0f;
	m_Component[down].m_aabb.sy = 4.0f;
	m_Component[circle].m_circle.radian = 128.0f;
}

void Enemy::Init(float Speed, D3DXVECTOR2 Position)
{
	m_Position = Position;
	m_Velocity = D3DXVECTOR2(0.0f, Speed);	//	ベクトルの初期化
	m_Component[center].m_aabb.sx = 16.0f;
	m_Component[center].m_aabb.sy = 120.0f;
	m_Component[up].m_aabb.sx = 16.0f;
	m_Component[up].m_aabb.sy = 4.0f;
	m_Component[down].m_aabb.sx = 16.0f;
	m_Component[down].m_aabb.sy = 4.0f;
	m_Component[circle].m_circle.radian = 128.0f;
}

void Enemy::Uninit()
{
}

void Enemy::Update()
{
	Move();
	Collision();
}

void Enemy::Draw(LPDIRECT3DTEXTURE9 Texture)
{
	D3DXCOLOR color = D3DCOLOR_RGBA(255, 155, 155, 255);
	m_Sprite.SetColor(0, 255, 255, 255);
	m_Sprite.Draw(Texture, m_Position.x - 16.0f, m_Position.y - 128.0f, 32.0f, 256.0f, color);
}

Component2D * Enemy::GetCollision(int i)
{
	return &m_Component[i];
}

D3DXVECTOR2 Enemy::GetPosition()
{
	return m_Position;
}

void Enemy::Move()
{
	m_Position += m_Velocity; // Positionの更新
	m_Component[center].m_aabb.cx = m_Position.x;
	m_Component[center].m_aabb.cy = m_Position.y;
	m_Component[up].m_aabb.cx = m_Position.x;
	m_Component[up].m_aabb.cy = m_Position.y - 124.0f;
	m_Component[down].m_aabb.cx = m_Position.x;
	m_Component[down].m_aabb.cy = m_Position.y + 124.0f;
	m_Component[circle].m_circle.cx = m_Position.x;
	m_Component[circle].m_circle.cy = m_Position.y;
}

void Enemy::Collision()
{
	Topline* p_topline = ObjectManager::GetTopLine();
	if (AABB_2d(m_Component[up].m_aabb, p_topline->GetCollision()->GetAABB()) == true)
	{
		m_Position.y = 128.0f + 30.f;
		m_Velocity.y *= -1;
	}
	Underline* p_underline = ObjectManager::GetUnderLine();
	if (AABB_2d(m_Component[down].m_aabb, p_underline->GetCollision()->GetAABB()) == true)
	{
		m_Position.y = SCREEN_HEIGHT - 128.0f - 30.f;
		m_Velocity.y *= -1;
	}
	m_Position += m_Velocity;
}


