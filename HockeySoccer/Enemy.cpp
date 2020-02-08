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
	m_aabb[Up].cx = 0.0f;
	m_aabb[Up].cy = 0.0f;
	m_aabb[Up].sx = 16.0f;
	m_aabb[Up].sy = 4.0f;
	m_aabb[Center].cx = 0.0f;
	m_aabb[Center].cy = 0.0f;
	m_aabb[Center].sx = 16.0f;
	m_aabb[Center].sy = 120.0f;
	m_aabb[Down].cx = 0.0f;
	m_aabb[Down].cy = 0.0f;
	m_aabb[Down].sx = 16.0f;
	m_aabb[Down].sy = 4.0f;
}

void Enemy::Init(float Speed, D3DXVECTOR2 Position)
{
	m_Position = Position;
	m_Velocity = D3DXVECTOR2(0.0f, Speed);	//	ベクトルの初期化
	m_aabb[Up].cx = 0.0f;
	m_aabb[Up].cy = 0.0f;
	m_aabb[Up].sx = 16.0f;
	m_aabb[Up].sy = 4.0f;
	m_aabb[Center].cx = 0.0f;
	m_aabb[Center].cy = 0.0f;
	m_aabb[Center].sx = 16.0f;
	m_aabb[Center].sy = 120.0f;
	m_aabb[Down].cx = 0.0f;
	m_aabb[Down].cy = 0.0f;
	m_aabb[Down].sx = 16.0f;
	m_aabb[Down].sy = 4.0f;
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

AABB2d * Enemy::GetCollision(int i)
{
	return &m_aabb[i];
}

D3DXVECTOR2 Enemy::GetPosition()
{
	return m_Position;
}

void Enemy::Move()
{
	m_Position += m_Velocity; // Positionの更新
	m_aabb[Up].cx = m_Position.x;
	m_aabb[Up].cy = m_Position.y - 124.0f;
	m_aabb[Center].cx = m_Position.x;
	m_aabb[Center].cy = m_Position.y;
	m_aabb[Down].cx = m_Position.x;
	m_aabb[Down].cy = m_Position.y + 124.0f;
}

void Enemy::Collision()
{
	Topline* p_topline = ObjectManager::GetTopLine();
	if (AABB_2d(m_aabb[Up], p_topline->GetCollision()) == true)
	{
		m_Position.y = 128.0f + 30.f;
		m_Velocity.y *= -1;
	}
	Underline* p_underline = ObjectManager::GetUnderLine();
	if (AABB_2d(m_aabb[Down], p_underline->GetCollision()) == true)
	{
		m_Position.y = SCREEN_HEIGHT - 128.0f - 30.f;
		m_Velocity.y *= -1;
	}
	m_Position += m_Velocity;
}


