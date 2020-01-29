/*=========================================================

	[Ball.cpp]
	Author : o‡ ãÄ‘¾

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
	//	Line‚Æ‚Ì“–‚½‚è”»’è
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
	
	//	Player‚Æ‚Ì“–‚½‚è”»’è
	Player* p_Player = ObjectManager::GetPlayer();
	if (AABB_2d(m_aabb, p_Player->GetCollision()) == true)
	{
		m_Velocity.x *= -1;
	}
	
	//	Goal‚ÌƒRƒŠƒWƒ‡ƒ“
}


void Ball::Draw()
{
	m_Sprite.Draw(m_Texture.SetTexture(m_Balltexture),m_Position.x,m_Position.y,32.0f,32.0f);
}

AABB2d * Ball::GetCollision()
{
	return &m_aabb;
}

