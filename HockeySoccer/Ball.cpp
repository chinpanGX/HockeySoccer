/*=========================================================

	[Ball.cpp]
	Author : 出合 翔太

========================================================*/

#include "Ball.h"
#include "Line.h"
#include "ObjectManager.h"
#include "Sound.h"

void Ball::Init()
{
	m_Position = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f + 100.0f);
	m_Velocity = D3DXVECTOR2(8.0f, 7.0f);
	m_Component.m_aabb.sx = 16.0f;
	m_Component.m_aabb.sy = 16.0f;
	m_Component.m_circle.radian = 16.0f;
	m_GameEnd = false;
	m_GoalFlag = false;
	m_EffectFlag = -1;
}

void Ball::Init(D3DXVECTOR2 Velocity)
{
	m_Position = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f - 100.0f);
	m_Velocity = Velocity;
	m_Component.m_aabb.sx = 16.0f;
	m_Component.m_aabb.sy = 16.0f;
	m_Component.m_circle.radian = 16.0f;
	m_GameEnd = false;
	m_GoalFlag = false;
	m_EffectFlag = -1;
}

void Ball::Uninit()
{

}

void Ball::Update()
{

	if (m_EffectFlag != -1)
	{
		m_EffectFlag = -1;
	}

	//	移動
	m_Position += m_Velocity * 1.1f;
	m_Component.m_aabb.cx = m_Position.x;
	m_Component.m_aabb.cy = m_Position.y;
	m_Component.m_circle.cx = m_Position.x;
	m_Component.m_circle.cy = m_Position.y;

	//	当たり判定
	EnemyGoalCollision();
	GoalCollsion();
	PlayerCollision();
	EnemyCollision();
	LineCollsion();
}

void Ball::Draw(LPDIRECT3DTEXTURE9 Texture)
{
	m_Sprite.Draw(Texture, m_Position.x - 16.0f, m_Position.y - 16.0f, 32.0f, 32.0f);
}


/// <summary>
/// Update()のヘルパー関数
/// </summary>
//	プレイヤーとの当たり判定
void Ball::PlayerCollision()
{
	Player* p_Player = ObjectManager::GetPlayer();
	// AABB同士の衝突検知
	if (Intercept(m_Component.m_aabb, p_Player->GetCollision()->GetAABB()) == true)
	{
		D3DXVECTOR2 tmp = m_Position;
		D3DXVECTOR2 tmp2 = p_Player->GetPosition();
		// 半径と線分の衝突検知
		// プレイヤーの上
		if (Intercept(m_Component.m_circle, p_Player->GetCollision()->GetPoint(0), p_Player->GetCollision()->GetPoint(1)) == true)
		{
			m_EffectFlag = HITPLAYER;
			m_Position = tmp;
			p_Player->GetPosition() = tmp2;
			m_Velocity.y *= -1;
			Sound::Play(S_SE_BALL);
		}
		// プレイヤーの下
		if (Intercept(m_Component.m_circle, p_Player->GetCollision()->GetPoint(2), p_Player->GetCollision()->GetPoint(3)) == true)
		{
			m_EffectFlag = HITPLAYER;
			m_Position = tmp;
			p_Player->GetPosition() = tmp2;
			m_Velocity.y *= -1;
			Sound::Play(S_SE_BALL);
		}
		// プレイヤーの左
		if (Intercept(m_Component.m_circle, p_Player->GetCollision()->GetPoint(0), p_Player->GetCollision()->GetPoint(2)) == true)
		{
			m_EffectFlag = HITPLAYER;
			m_Position = tmp;
			p_Player->GetPosition() = tmp2;
			m_Velocity.x *= -1;
			Sound::Play(S_SE_BALL);	
		}
		// プレイヤーの右
		if(Intercept(m_Component.m_circle, p_Player->GetCollision()->GetPoint(1), p_Player->GetCollision()->GetPoint(3)) == true)
		{
			m_EffectFlag = HITPLAYER;
			m_Position = tmp;
			p_Player->GetPosition() = tmp2;
			m_Velocity.x *= -1;
			Sound::Play(S_SE_BALL);
		}
	}
}

//	エネミーとの当たり判定
void Ball::EnemyCollision()
{
	Enemy* p_Enemy = ObjectManager::GetEnemy();
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		// AABB同士の衝突検知
		if (Intercept(m_Component.m_aabb, p_Enemy[i].GetCollision()->GetAABB()) == true)
		{
			D3DXVECTOR2 tmp = m_Position;
			D3DXVECTOR2 tmp2 = p_Enemy[i].GetPosition();
			// 上
			if (Intercept(m_Component.m_circle, p_Enemy[i].GetCollision()->GetPoint(0), p_Enemy[i].GetCollision()->GetPoint(1)) == true)
			{
				m_EffectFlag = HITPLAYER;
				m_Position = tmp;
				p_Enemy[i].GetPosition() = tmp2;
				m_Velocity.y *= -1;
				Sound::Play(S_SE_BALL);
			}
			// 下
			if (Intercept(m_Component.m_circle, p_Enemy[i].GetCollision()->GetPoint(2), p_Enemy[i].GetCollision()->GetPoint(3)) == true)
			{
				m_EffectFlag = HITPLAYER;
				m_Position = tmp;
				p_Enemy[i].GetPosition() = tmp2;
				m_Velocity.y *= -1;
				Sound::Play(S_SE_BALL);
			}
			// 左
			if (Intercept(m_Component.m_circle, p_Enemy[i].GetCollision()->GetPoint(0), p_Enemy[i].GetCollision()->GetPoint(2)) == true)
			{
				m_EffectFlag = HITPLAYER;
				m_Position = tmp;
				p_Enemy[i].GetPosition() = tmp2;
				m_Velocity.x *= -1;
				Sound::Play(S_SE_BALL);
			}
			// 右
			if (Intercept(m_Component.m_circle, p_Enemy[i].GetCollision()->GetPoint(1), p_Enemy[i].GetCollision()->GetPoint(3)) == true)
			{
				m_EffectFlag = HITPLAYER;
				m_Position = tmp;
				p_Enemy[i].GetPosition() = tmp2;
				m_Velocity.x *= -1;
				Sound::Play(S_SE_BALL);
			}
		}
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
	if (Intercept(m_Component.m_aabb, p_topline->GetCollision()->GetAABB()) == true || Intercept(m_Component.m_aabb, p_underline->GetCollision()->GetAABB()) == true)
	{
		m_EffectFlag = EXPLOSION;
		m_Velocity.y *= -1;
		Sound::Play(S_SE_BALL);
	}
	if (Intercept(m_Component.m_aabb, p_leftline->GetCollision()->GetAABB()) == true || Intercept(m_Component.m_aabb, p_rightline->GetCollision()->GetAABB()) == true)
	{
		m_EffectFlag = EXPLOSION;
		m_Velocity.x *= -1;
		Sound::Play(S_SE_BALL);
	}
}

//	自陣ゴールとの当たり判定
void Ball::GoalCollsion()
{
	//	Ballとの当たり判定
	Goal * p_Goal = ObjectManager::GetGoal();
	if (Intercept(m_Component.m_aabb, p_Goal->GetCollision()->GetAABB()) == true || m_Position.y < 16.0f || m_Position.y > SCREEN_HEIGHT - 16.0f)
	{
		Sound::Play(S_SE_WHISTIL);
		m_GameEnd = true;
	}
}

//	相手側ゴールとの当たり判定
void Ball::EnemyGoalCollision()
{
	EnemyGoal* p_EnemyGoal = ObjectManager::GetEnemyGoal();
	if (Intercept(m_Component.m_aabb, p_EnemyGoal->GetCollision()->GetAABB()) == true)
	{
		Sound::Play(S_SE_WHISTIL);
		m_GoalFlag = true;
	}
}

Component2D * Ball::GetCollision()
{
	return &m_Component;
}

bool Ball::GetGameEnd()
{
	return m_GameEnd;
}

bool Ball::GetGoalFlag()
{
	return m_GoalFlag;
}

D3DXVECTOR2 Ball::GetPosition()
{
	return m_Position;
}

int Ball::GetEffect()
{
	return m_EffectFlag;
}

