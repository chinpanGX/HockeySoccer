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
	m_Position = D3DXVECTOR2(450.0f, 540.0f);
	m_Speed = 1.0f;
	m_Component.m_aabb.sx = 16.0f;
	m_Component.m_aabb.sy = 128.0f;
	m_Component.m_circle.radian = 128.0f;
	m_Component.m_Point[0].px = -16.0f;
	m_Component.m_Point[0].py = -128.0f;
	m_Component.m_Point[1].px = 16.0f;
	m_Component.m_Point[1].py = -128.0f;
	m_Component.m_Point[2].px = -16.0f;
	m_Component.m_Point[2].py = 128.0f;
	m_Component.m_Point[3].px = 16.0f;
	m_Component.m_Point[3].py = 128.0f;
}

void Player::Init(float Speed)
{
	m_Position = D3DXVECTOR2(450.0f, 540.0f);
	m_Speed = Speed;
	m_Component.m_aabb.sx = 16.0f;
	m_Component.m_aabb.sy = 128.0f;
	m_Component.m_circle.radian = 128.0f;
	m_Component.m_Point[0].px = -16.0f;
	m_Component.m_Point[0].py = -128.0f;
	m_Component.m_Point[1].px = 16.0f;
	m_Component.m_Point[1].py = -128.0f;
	m_Component.m_Point[2].px = -16.0f;
	m_Component.m_Point[2].py = 128.0f;
	m_Component.m_Point[3].px = 16.0f;
	m_Component.m_Point[3].py = 128.0f;
}

void Player::Uninit()
{
	
}

void Player::Update()
{
	m_Velocity = D3DXVECTOR2(0.0f, 0.0f);	//	ベクトルの初期化
	Action();
	Move();
	Collision();
}

void Player::Draw(LPDIRECT3DTEXTURE9 Texture)
{
	D3DXCOLOR color = D3DCOLOR_RGBA(200, 0, 200, 255);
	m_Sprite.Draw(Texture, m_Position.x - 16.0f, m_Position.y - 128.0f, 32.0f, 256.0f,color);
}

void Player::Action()
{
	if (KeyBoard::IsPress(DIK_UPARROW) || GamePad::IsPress(0, LEFTSTICK_UP))
	{
		m_Velocity.y -= 5.0f;
	}
	if (KeyBoard::IsPress(DIK_DOWNARROW) || GamePad::IsPress(0, LEFTSTICK_DOWN))
	{
		m_Velocity.y += 5.0f;
	}
}

void Player::Move()
{
	m_Position += m_Velocity * m_Speed; // Positionの更新
	m_Component.m_aabb.cx = m_Position.x;
	m_Component.m_aabb.cy = m_Position.y;
	m_Component.m_circle.cx = m_Position.x;
	m_Component.m_circle.cy = m_Position.y;
	m_Component.m_Point[0].px = m_Position.x + -16.0f;
	m_Component.m_Point[0].py = m_Position.y + -128.0f;
	m_Component.m_Point[1].px = m_Position.x + 16.0f;
	m_Component.m_Point[1].py = m_Position.y + -128.0f;
	m_Component.m_Point[2].px = m_Position.x + -16.0f;
	m_Component.m_Point[2].py = m_Position.y + 128.0f;
	m_Component.m_Point[3].px = m_Position.x + 16.0f;
	m_Component.m_Point[3].py = m_Position.y + 128.0f;
}

void Player::Collision()
{
	Topline* p_topline = ObjectManager::GetTopLine();
	if (Intercept(m_Component.m_aabb,p_topline->GetCollision()->GetAABB()) == true)
	{
		m_Position.y = 128.0f + 28.f;
		m_Velocity.y *= -1;
	}
	Underline* p_underline = ObjectManager::GetUnderLine();
	if (Intercept(m_Component.m_aabb,p_underline->GetCollision()->GetAABB()) == true)
	{
		m_Position.y = SCREEN_HEIGHT - 128.0f - 28.f;
		m_Velocity.y *= -1;
	}
	m_Position += m_Velocity;
}

Component2D * Player::GetCollision()
{
	return &m_Component;
}

D3DXVECTOR2 Player::GetPosition()
{
	return m_Position;
}

D3DXVECTOR2 Player::GetVector()
{
	return m_Velocity;
}

