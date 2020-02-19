/*=========================================================

	[Ball.cpp]
	Author : �o�� �đ�

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
	/*
	Effect* p_Effcet = ObjectManager::GetEffect();
	if (p_Effcet->GetUse() == true)
	{
		if (p_Effcet->GetFrame() >= 20)
		{
			m_EffectFlag = -1;
		}
	}*/
	if (m_EffectFlag != -1)
	{
		m_EffectFlag = -1;
	}

	//	�ړ�
	m_Position += m_Velocity * 1.1f;
	m_Component.m_aabb.cx = m_Position.x;
	m_Component.m_aabb.cy = m_Position.y;
	m_Component.m_circle.cx = m_Position.x;
	m_Component.m_circle.cy = m_Position.y;

	//	�����蔻��
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
/// Update()�̃w���p�[�֐�
/// </summary>
//	�v���C���[�Ƃ̓����蔻��
void Ball::PlayerCollision()
{
	Player* p_Player = ObjectManager::GetPlayer();
	// AABB���m�̏Փˌ��m
	if (AABB_2d(m_Component.m_aabb, p_Player->GetCollision()->GetAABB()) == true)
	{
		// ���a�Ɛ����̏Փˌ��m
		// �v���C���[�̏�
		if (Intercept(m_Component.m_circle,p_Player->GetCollision()->GetLine(0), p_Player->GetCollision()->GetLine(1))== true)
		{
			m_Velocity.y *= -1;
			Sound::Play(S_SE_BALL);
		}
		// �v���C���[�̉�
		if (Intercept(m_Component.m_circle,p_Player->GetCollision()->GetLine(2), p_Player->GetCollision()->GetLine(3)) == true)
		{
			m_Velocity.y *= -1;
			Sound::Play(S_SE_BALL);
		}
		// �v���C���[�̍�
		if (Intercept(m_Component.m_circle,p_Player->GetCollision()->GetLine(0), p_Player->GetCollision()->GetLine(2)) == true)
		{
			m_Velocity.x *= -1;
			Sound::Play(S_SE_BALL);
		}
		// �E
		if (Intercept(m_Component.m_circle,p_Player->GetCollision()->GetLine(1), p_Player->GetCollision()->GetLine(3)) == true)
		{
			m_Velocity.x *= -1;
			Sound::Play(S_SE_BALL);
		}
	}
}

//	�G�l�~�[�Ƃ̓����蔻��
void Ball::EnemyCollision()
{
	Enemy* p_Enemy = ObjectManager::GetEnemy();
	if (AABB_2d(m_Component.m_aabb, p_Enemy->GetCollision()->GetAABB()) == true)
	{
		// ��
		if (Intercept(m_Component.m_circle,p_Enemy->GetCollision()->GetLine(0), p_Enemy->GetCollision()->GetLine(1)) == true)
		{
			m_Velocity.y *= -1;
			Sound::Play(S_SE_BALL);
		}
		// ��
		if (Intercept(m_Component.m_circle,p_Enemy->GetCollision()->GetLine(2), p_Enemy->GetCollision()->GetLine(3)) == true)
		{
			m_Velocity.y *= -1;
			Sound::Play(S_SE_BALL);
		}
		// ��
		if (Intercept(m_Component.m_circle,p_Enemy->GetCollision()->GetLine(0), p_Enemy->GetCollision()->GetLine(2)) == true)
		{
			m_Velocity.x *= -1;
			Sound::Play(S_SE_BALL);
		}
		// �E
		if (Intercept(m_Component.m_circle,p_Enemy->GetCollision()->GetLine(1), p_Enemy->GetCollision()->GetLine(3)) == true)
		{
			m_Velocity.x *= -1;
			Sound::Play(S_SE_BALL);
		}
	}
}

//	���C���Ƃ̓����蔻��
void Ball::LineCollsion()
{
	//	Line�Ƃ̓����蔻��
	Topline* p_topline = ObjectManager::GetTopLine();
	Underline* p_underline = ObjectManager::GetUnderLine();
	Leftline* p_leftline = ObjectManager::GetLeftLine();
	Rightline* p_rightline = ObjectManager::GetRightLine();
	if (AABB_2d(m_Component.m_aabb, p_topline->GetCollision()->GetAABB()) == true || AABB_2d(m_Component.m_aabb, p_underline->GetCollision()->GetAABB()) == true)
	{
		m_EffectFlag = EXPLOSION;
		m_Velocity.y *= -1;
		Sound::Play(S_SE_BALL);
	}
	if (AABB_2d(m_Component.m_aabb, p_leftline->GetCollision()->GetAABB()) == true || AABB_2d(m_Component.m_aabb, p_rightline->GetCollision()->GetAABB()) == true)
	{
		m_EffectFlag = EXPLOSION;
		m_Velocity.x *= -1;
		Sound::Play(S_SE_BALL);
	}
}

//	���w�S�[���Ƃ̓����蔻��
void Ball::GoalCollsion()
{
	//	Ball�Ƃ̓����蔻��
	Goal * p_Goal = ObjectManager::GetGoal();
	if (AABB_2d(m_Component.m_aabb, p_Goal->GetCollision()->GetAABB()) == true)
	{
		Sound::Play(S_SE_WHISTIL);
		m_GameEnd = true;
	}
}

//	���葤�S�[���Ƃ̓����蔻��
void Ball::EnemyGoalCollision()
{
	EnemyGoal* p_EnemyGoal = ObjectManager::GetEnemyGoal();
	if (AABB_2d(m_Component.m_aabb, p_EnemyGoal->GetCollision()->GetAABB()) == true)
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

