/*=========================================================

	[EnemyGoal.h]
	Author : �o���đ�

=========================================================*/

#include "EnemyGoal.h"
#include "ObjectManager.h"

void EnemyGoal::Init()
{
	m_Position = D3DXVECTOR2(SCREEN_WIDTH - 68.0f, 540.0f);
	m_Position = D3DXVECTOR2(0.0f + 33.0f, 540.0f);
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
	m_aabb.cx = m_Position.x;
	m_aabb.cy = m_Position.y;
	//	Ball�Ƃ̓����蔻��
	Ball* p_Ball = ObjectManager::GetBall();
	if (AABB_2d(m_aabb, p_Ball->GetCollision()) == true)
	{
		//	�G�l�~�[���x���A�b�v

	}
}

void EnemyGoal::Draw(LPDIRECT3DTEXTURE9 Texture)
{
	D3DXCOLOR color = D3DCOLOR_RGBA(255, 0, 255, 255);
	m_Sprite.Draw(Texture, m_Position.x - 32.0f, m_Position.y - 128.0f, 100.0f, 256.0f, color);
}

AABB2d * EnemyGoal::GetCollision()
{
	return &m_aabb;
}

int EnemyGoal::GetCount()
{
	int EnemyLv = 0;
	EnemyLv++;
	return EnemyLv;
}