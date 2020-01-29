/*=========================================================

	[Player.cpp]
	プレイヤーを管理する
	Author : 出合翔太

==========================================================*/

#include "Player.h"
#include "Controller.h"
#include "Line.h"
#include "ObjectManager.h"

void Player::Init()
{
	m_Playertexture = m_Texture.LoadTexture("Rom/Texture/Bar.png");
	m_Position = D3DXVECTOR2(480.0f - 32.0f, 540.0f - 128.0f);
	m_aabb.cx = 0.0f;
	m_aabb.cy = 0.0f;
	m_aabb.sx = 32.0f;
	m_aabb.sy = 128.0f;
}

void Player::Uninit()
{
	m_Texture.UnLoadTexture(m_Playertexture);
}

void Player::Update()
{
	m_Velocity = D3DXVECTOR2(0.0f, 0.0f);	//	ベクトルの初期化
	Action();
	Move();
	Collision();
}

void Player::Action()
{
	if (KeyBoard::IsPress(DIK_UPARROW))
	{
		m_Velocity.y -= 5.0f;
	}
	if (KeyBoard::IsPress(DIK_DOWNARROW))
	{
		m_Velocity.y += 5.0f;
	}   
}

void Player::Move()
{
	m_Position += m_Velocity; // Positionの更新
	m_aabb.cx = m_Position.x; // コリジョンの更新
	m_aabb.cy = m_Position.y;
}

void Player::Collision()
{
	Topline* p_topline = ObjectManager::GetTopLine();
	if (AABB_2d(m_aabb,p_topline->GetCollision()) == true)
	{
		m_Velocity.y *= -1.1f;
	}
	Underline* p_underline = ObjectManager::GetUnderLine();
	if (AABB_2d(m_aabb,p_underline->GetCollision()) == true)
	{
		m_Velocity.y *= -1.1f;
	}
	m_Position += m_Velocity;
}
/*
bool Player::HitLine(const AABB2d* p_Object)
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
	minB.x = p_Object->cx - p_Object->sx;
	minB.y = p_Object->cy - p_Object->sy;

	//	Bのbox最大点 
	maxB.x = p_Object->cx + p_Object->sx;
	maxB.y = p_Object->cy + p_Object->sy;
	//	X軸の比較
	if (maxA.x > minB.x && minA.x < maxB.x)
	{
		//	Y軸の比較
		if (maxA.y > minB.y && minA.y < maxB.y)
		{
			return true;
		}
	}
	return false;
}*/

void Player::Draw()
{
	D3DXCOLOR color = D3DCOLOR_RGBA(0,255,255,255);
	m_Sprite.Draw(m_Texture.SetTexture(m_Playertexture),m_Position.x - 32.0f,m_Position.y-128.0f,80.0f,256.0f,color);
}

AABB2d * Player::GetCollision()
{
	return &m_aabb;
}

D3DXVECTOR2 Player::GetPosition()
{
	return m_Position;
}
