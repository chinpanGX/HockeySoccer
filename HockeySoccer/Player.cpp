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
	m_Component[center].m_aabb.sx = 16.0f;
	m_Component[center].m_aabb.sy = 120.0f;
	m_Component[up].m_aabb.sx = 16.0f;
	m_Component[up].m_aabb.sy = 4.0f;
	m_Component[down].m_aabb.sx = 16.0f;
	m_Component[down].m_aabb.sy = 4.0f;
	m_Component[circle].m_circle.radian = 128.0f;
}

void Player::Init(float Speed)
{
	m_Position = D3DXVECTOR2(450.0f, 540.0f);
	m_Speed = Speed;
	m_Component[center].m_aabb.sx = 16.0f;
	m_Component[center].m_aabb.sy = 120.0f;
	m_Component[up].m_aabb.sx = 16.0f;
	m_Component[up].m_aabb.sy = 4.0f;
	m_Component[down].m_aabb.sx = 16.0f;
	m_Component[down].m_aabb.sy = 4.0f;
	m_Component[circle].m_circle.radian = 128.0f;
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
	m_Component[center].m_aabb.cx = m_Position.x;
	m_Component[center].m_aabb.cy = m_Position.y;
	m_Component[up].m_aabb.cx = m_Position.x;
	m_Component[up].m_aabb.cy = m_Position.y - 124.0f;
	m_Component[down].m_aabb.cx = m_Position.x;
	m_Component[down].m_aabb.cy = m_Position.y + 124.0f;
	m_Component[circle].m_circle.cx = m_Position.x;
	m_Component[circle].m_circle.cy = m_Position.y;
}

void Player::Collision()
{
	Topline* p_topline = ObjectManager::GetTopLine();
	if (AABB_2d(m_Component[up].m_aabb,p_topline->GetCollision()->GetAABB()) == true)
	{
		m_Position.y = 128.0f + 28.f;
		m_Velocity.y *= -1;
	}
	Underline* p_underline = ObjectManager::GetUnderLine();
	if (AABB_2d(m_Component[down].m_aabb,p_underline->GetCollision()->GetAABB()) == true)
	{
		m_Position.y = SCREEN_HEIGHT - 128.0f - 28.f;
		m_Velocity.y *= -1;
	}
	m_Position += m_Velocity;
}

Component2D * Player::GetCollision(int i)
{
	return &m_Component[i];
}

D3DXVECTOR2 Player::GetPosition()
{
	return m_Position;
}
