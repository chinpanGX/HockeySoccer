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

void Player::Init(float Speed)
{
	m_Position = D3DXVECTOR2(450.0f, 540.0f);
	m_Speed = Speed;
	m_aabb[Up].cx = 0.0f;
	m_aabb[Up].cy = 0.0f - 124.0f;
	m_aabb[Up].sx = 16.0f;
	m_aabb[Up].sy = 4.0f;
	m_aabb[Center].cx = 0.0f;
	m_aabb[Center].cy = 0.0f;
	m_aabb[Center].sx = 16.0f;
	m_aabb[Center].sy = 120.0f;
	m_aabb[Down].cx = 0.0f;
	m_aabb[Down].cy = 0.0f + 124.0f;
	m_aabb[Down].sx = 16.0f;
	m_aabb[Down].sy = 4.0f;
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
	m_aabb[Up].cx = m_Position.x;
	m_aabb[Up].cy = m_Position.y - 124.0f;
	m_aabb[Center].cx = m_Position.x;
	m_aabb[Center].cy = m_Position.y;
	m_aabb[Down].cx = m_Position.x;
	m_aabb[Down].cy = m_Position.y + 124.0f;
}

void Player::Collision()
{
	Topline* p_topline = ObjectManager::GetTopLine();
	if (AABB_2d(m_aabb[Up],p_topline->GetCollision()) == true)
	{
		m_Position.y = 128.0f + 28.f;
		m_Velocity.y *= -1;
	}
	Underline* p_underline = ObjectManager::GetUnderLine();
	if (AABB_2d(m_aabb[Down],p_underline->GetCollision()) == true)
	{
		m_Position.y = SCREEN_HEIGHT - 128.0f - 28.f;
		m_Velocity.y *= -1;
	}
	m_Position += m_Velocity;
}

AABB2d * Player::GetCollision(int i)
{
	return &m_aabb[i];
}

D3DXVECTOR2 Player::GetPosition()
{
	return m_Position;
}
