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
	m_Position = D3DXVECTOR2(SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f - 100.0f);
	m_Velocity = D3DXVECTOR2(-7.0f, 0.0f); // �f�o�b�O
	//m_Velocity = D3DXVECTOR2(7.0f, -7.5f);
	m_aabb.cx = 0.0f;
	m_aabb.cy = 0.0f;
	m_aabb.sx = 32.0f;
	m_aabb.sy = 32.0f;
	m_GameEnd = false;
	m_GoalFlag = false;
}

void Ball::Init(D3DXVECTOR2 Velocity)
{
	m_Position = D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f - 100.0f);
	m_Velocity = Velocity;
	m_aabb.cx = 0.0f;
	m_aabb.cy = 0.0f;
	m_aabb.sx = 32.0f;
	m_aabb.sy = 32.0f;
	m_GameEnd = false;
	m_GoalFlag = false;
}

void Ball::Uninit()
{
	
}

void Ball::Update()
{
	//	�ړ�
	m_Position += m_Velocity;
	m_aabb.cx = m_Position.x;
	m_aabb.cy = m_Position.y;
	
	//	�����蔻��
	EnemyGoalCollision();
	GoalCollsion();
	PlayerCollision();
	EnemyCollision();
	LineCollsion();
}

void Ball::Draw(LPDIRECT3DTEXTURE9 Texture)
{
	m_Sprite.Draw(Texture, m_Position.x - 32.0f, m_Position.y - 32.0f, 32.0f, 32.0f);
}


/// <summary>
/// Update()�̃w���p�[�֐�
/// </summary>

//	�v���C���[�Ƃ̓����蔻��
void Ball::PlayerCollision()
{
	Player* p_Player = ObjectManager::GetPlayer();
	if (AABB_2d(m_aabb, p_Player->GetCollision()) == true)
	{
		Sound::Play(S_SE_BALL);
		m_Velocity.x *= -1;
	}
}

//	�G�l�~�[�Ƃ̓����蔻��
void Ball::EnemyCollision()
{
	Enemy* p_Enemy = ObjectManager::GetEnemy();
	if (AABB_2d(m_aabb, p_Enemy->GetCollision()) == true)
	{
		Sound::Play(S_SE_BALL);
		m_Velocity.x *= -1;
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
	if (AABB_2d(m_aabb, p_topline->GetCollision()) == true || AABB_2d(m_aabb, p_underline->GetCollision()) == true)
	{
		Sound::Play(S_SE_BALL);
		m_Velocity.y *= -1;
	}
	if (AABB_2d(m_aabb, p_leftline->GetCollision()) == true || AABB_2d(m_aabb, p_rightline->GetCollision()) == true)
	{
		Sound::Play(S_SE_BALL);
		m_Velocity.x *= -1;
	}
}

//	���w�S�[���Ƃ̓����蔻��
void Ball::GoalCollsion()
{
	//	Ball�Ƃ̓����蔻��
	Goal * p_Goal = ObjectManager::GetGoal();
	if (AABB_2d(m_aabb, p_Goal->GetCollision()) == true)
	{
		Sound::Play(S_SE_WHISTIL);
		//�Q�[���I��
		m_GameEnd = true;
	}
}

//	���葤�S�[���Ƃ̓����蔻��
void Ball::EnemyGoalCollision()
{
	EnemyGoal* p_EnemyGoal = ObjectManager::GetEnemyGoal();
	if (AABB_2d(m_aabb, p_EnemyGoal->GetCollision()) == true)
	{
		Sound::Play(S_SE_WHISTIL);
		m_GoalFlag = true;
	}
}

AABB2d * Ball::GetCollision()
{
	return &m_aabb;
}

bool Ball::GetGameEnd()
{
	return m_GameEnd;
}

bool Ball::GetGoalFlag()
{
	return m_GoalFlag;
}

