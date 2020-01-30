/*=========================================================

	[Ball.cpp]
	Author : 出合 翔太

========================================================*/

#include "Ball.h"
#include "Line.h"
#include "ObjectManager.h"

void Ball::Init()
{
	m_Position = D3DXVECTOR2(SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f - 100.0f);
	m_Velocity = D3DXVECTOR2(-7.0f, 0.0f);//D3DXVECTOR2(7.0f,-7.5f);
	m_aabb.cx = 0.0f;
	m_aabb.cy = 0.0f;
	m_aabb.sx = 32.0f;
	m_aabb.sy = 32.0f;
}

void Ball::Uninit()
{
	
}

void Ball::Update()
{
	//	移動
	m_Position += m_Velocity;
	m_aabb.cx = m_Position.x;
	m_aabb.cy = m_Position.y;
	//	当たり判定
	PlayerCollision();
	EnemyCollision();
	LineCollsion();
}

void Ball::Draw(LPDIRECT3DTEXTURE9 Texture)
{
	m_Sprite.Draw(Texture, m_Position.x, m_Position.y, 32.0f, 32.0f);
}

/// <summary>
/// Update()のヘルパー関数
/// </summary>

//	プレイヤーとの当たり判定
void Ball::PlayerCollision()
{
	Player* p_Player = ObjectManager::GetPlayer();
	if (AABB_2d(m_aabb, p_Player->GetCollision()) == true)
	{
		m_Velocity.x *= -1;
	}
}

//	エネミーとの当たり判定
void Ball::EnemyCollision()
{
	Enemy* p_Enemy = ObjectManager::GetEnemy();
	if (AABB_2d(m_aabb, p_Enemy->GetCollision()) == true)
	{
		m_Velocity.x *= -1;
	}
}

//	ラインとの当たり判定
void Ball::LineCollsion()
{
	//	Lineとの当たり判定
	Topline* p_topline = ObjectManager::GetTopLine();
	Underline* p_underline = ObjectManager::GetUnderLine();
	Leftline* p_leftline = ObjectManager::GetLeftLine();
	Rightline* p_rightline = ObjectManager::GetRightLine();
	if (AABB_2d(m_aabb, p_topline->GetCollision()) == true || AABB_2d(m_aabb, p_underline->GetCollision()) == true)
	{
		m_Velocity.y *= -1;
	}
	if (AABB_2d(m_aabb, p_leftline->GetCollision()) == true || AABB_2d(m_aabb, p_rightline->GetCollision()) == true)
	{
		m_Velocity.x *= -1;
	}
}

AABB2d * Ball::GetCollision()
{
	return &m_aabb;
}

bool Ball::GetGameEnd()
{
	return true;
}

