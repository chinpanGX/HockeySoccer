/*=========================================================

	[Player.cpp]
	プレイヤーを管理する
	Author : 出合翔太

==========================================================*/

#include "Player.h"
#include "Controller.h"
#include "CollisionManager.h" 

void Player::Init()
{
	m_Playertexture = m_Texture.LoadTexture("Rom/Texture/Bar.png");
	m_Position = D3DXVECTOR2((SCREEN_WIDTH * 0.25f), (SCREEN_HEIGHT * 0.5));
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
}

void Player::Collision()
{
	m_aabb.cx = m_Position.x; // コリジョンの更新
	m_aabb.cy = m_Position.y;
	if (Collision_Player_vs_Line() == true)
	{
		m_Velocity *= -1.1f;
		m_Position += m_Velocity;
	}
}


void Player::Draw()
{
	D3DXCOLOR color = D3DCOLOR_RGBA(0,255,255,255);
	m_Sprite.Draw(m_Texture.SetTexture(m_Playertexture),m_Position.x,m_Position.y - 128.0f,64.0f,256.0f,color);
}

AABB2d * Player::GetCollision()
{
	return &m_aabb;
}
