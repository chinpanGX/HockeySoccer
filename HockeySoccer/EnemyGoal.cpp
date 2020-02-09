/*=========================================================

	[EnemyGoal.h]
	Author : èoçá„ƒëæ

=========================================================*/

#include "EnemyGoal.h"
#include "ObjectManager.h"

void EnemyGoal::Init()
{
	m_Position = D3DXVECTOR2(SCREEN_WIDTH - 65.0f, 540.0f);
	m_Velocity = D3DXVECTOR2(0.0f, 0.0f);
	m_aabb.cx = 0.0f;
	m_aabb.cy = 0.0f;
	m_aabb.sx = 30.0f;
	m_aabb.sy = 128.0f;
}

void EnemyGoal::Init(float Speed)
{
	m_Position = D3DXVECTOR2(SCREEN_WIDTH - 65.0f, 540.0f);
	m_Velocity = D3DXVECTOR2(0.0f, Speed);
	m_aabb.cx = 0.0f;
	m_aabb.cy = 0.0f;
	m_aabb.sx = 30.0f;
	m_aabb.sy = 128.0f;
}

void EnemyGoal::Uninit()
{
}

void EnemyGoal::Update()
{
	m_Position += m_Velocity;
	m_aabb.cx = m_Position.x;
	m_aabb.cy = m_Position.y;
}

void EnemyGoal::Draw(LPDIRECT3DTEXTURE9 Texture)
{
	D3DXCOLOR color = D3DCOLOR_RGBA(150, 150, 150, 255);
	m_Sprite.Draw(Texture, m_Position.x - 32.0f, m_Position.y - 128.0f, 100.0f, 256.0f, color);
}

AABB2d * EnemyGoal::GetCollision()
{
	return &m_aabb;
}
