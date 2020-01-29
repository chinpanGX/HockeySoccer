/*=========================================================

	[Ball.cpp]
	Author : 出合 翔太

========================================================*/

#include "Ball.h"
#include "CollisionManager.h"
#include "Line.h"
#include "ObjectManager.h"
#include "DebugFont.h"

void Ball::Init()
{
	m_Balltexture = m_Texture.LoadTexture("Rom/Texture/Ball.png");
	m_Position = D3DXVECTOR2(SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f);
	m_Velocity = D3DXVECTOR2(5.0f,-3.5f);
	m_aabb.cx = 0.0f;
	m_aabb.cy = 0.0f;
	m_aabb.sy = 16.0f;
	m_aabb.sy = 16.0f;
}

void Ball::Uninit()
{
	m_Texture.UnLoadTexture(m_Balltexture);
}

void Ball::Update()
{
	m_Position += m_Velocity;
	Collision();
}

void Ball::Collision()
{
	if (m_Position.y < 20.0f)
	{
		m_Position.y = 20.0f;
		m_Velocity.y *= -1;
	}
	if (m_Position.y >  SCREEN_HEIGHT - 49.5f)
	{
		m_Position.y = SCREEN_HEIGHT - 49.5f;
		m_Velocity.y *= -1;
	}
	if (m_Position.x < 90.0f + 15.0f)
	{
		m_Position.x = 90.0f + 15.0f;
		m_Velocity.x *= -1;
	}
	if (m_Position.x > SCREEN_WIDTH - 90.0f - 45.0f)
	{
		m_Position.x = SCREEN_WIDTH - 90.0f - 45.0f;
		m_Velocity.x *= -1;
	}
}

void Ball::Draw()
{
	m_Sprite.Draw(m_Texture.SetTexture(m_Balltexture),m_Position.x,m_Position.y,32.0f,32.0f);
}

bool Ball::HitLine(const AABB2d * pObject)
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
	if (maxA.x > minB.x && minA.x < maxB.x)
	{
		//	Y軸の比較
		if (maxA.y > minB.y && minA.y < maxB.y)
		{
			return true;
			DebugFont::Print((char*)"あたっている\n");
		}
	}
	return false;
}

AABB2d * Ball::GetCollision()
{
	return &m_aabb;
}

