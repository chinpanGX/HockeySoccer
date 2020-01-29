/*=========================================================

	[Ball.cpp]
	Author : 出合 翔太

========================================================*/

#include "Ball.h"
#include "Line.h"
#include "ObjectManager.h"
#include "DebugFont.h"

void Ball::Init()
{
	m_Balltexture = m_Texture.LoadTexture("Rom/Texture/Ball.png");
	m_Position = D3DXVECTOR2(SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f);
	m_Velocity = D3DXVECTOR2(7.0f,-7.5f);
	m_aabb.cx = 0.0f;
	m_aabb.cy = 0.0f;
	m_aabb.sx = 32.0f;
	m_aabb.sy = 32.0f;
}

void Ball::Uninit()
{
	m_Texture.UnLoadTexture(m_Balltexture);
}

void Ball::Update()
{
	m_Position += m_Velocity;
	m_aabb.cx = m_Position.x;
	m_aabb.cy = m_Position.y;
	Collision();
}

void Ball::Collision()
{
	//	Lineとの当たり判定
	Topline* p_topline = ObjectManager::GetTopLine();
	Underline* p_underline = ObjectManager::GetUnderLine();
	Leftline* p_leftline = ObjectManager::GetLeftLine();
	Rightline* p_rightline = ObjectManager::GetRightLine();
	if (AABB_2d(m_aabb, p_topline->GetCollision()) == true || AABB_2d(m_aabb,p_underline->GetCollision()) == true)
	{
		m_Velocity.y *= -1;
	}
	if (AABB_2d(m_aabb, p_leftline->GetCollision()) == true || AABB_2d(m_aabb, p_rightline->GetCollision()) == true)
	{
		m_Velocity.x *= -1;
	}
	
	//	Playerとの当たり判定
	Player* p_Player = ObjectManager::GetPlayer();
	HitPlayer(p_Player->GetCollision());

	
	//	Goalのコリジョン
}


void Ball::Draw()
{
	m_Sprite.Draw(m_Texture.SetTexture(m_Balltexture),m_Position.x,m_Position.y,32.0f,32.0f);
}

void Ball::HitPlayer(const AABB2d * pObject)
{
	D3DXVECTOR2 minA, minB;	//	最小点
	D3DXVECTOR2 maxA, maxB;	//	最大点

	//	Aのbox最小点
	minA.x = m_aabb.cx - m_aabb.sx;
	minA.y = m_aabb.cy - m_aabb.sy;

	//	Aのbox最大点
	maxA.x = m_aabb.cx + m_aabb.sx;
	maxA.y = m_aabb.cy + m_aabb.sy;

	//	Bのbox最小点
	minB.x = pObject->cx - pObject->sx;
	minB.y = pObject->cy - pObject->sy;

	//	Bのbox最大点 
	maxB.x = pObject->cx + pObject->sx;
	maxB.y = pObject->cy + pObject->sy;
	//	X軸の比較
	if (maxA.x < minB.x)
	{
		m_Velocity.x *= -1;
	}
	if (minA.x > maxB.x)
	{
		m_Velocity.x *= -1;
	}
	//	Y軸の比較
	if (maxA.y < minB.y)
	{
		m_Velocity.y *= -1;
	}
	if (minA.y > maxB.y)
	{
		m_Velocity.y *= -1;
	}
	
	m_Position += m_Velocity;
}

AABB2d * Ball::GetCollision()
{
	return &m_aabb;
}

