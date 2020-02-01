/*=========================================================

	[StageEditor.cpp]
	Author : �o���đ�

==========================================================*/

#include "StageEditor.h"

//	����������
void StageEditor::Init()
{
	LoadTexture();
	m_Stage = STAGE_1;
	InitObject(STAGE_1);
	m_StageCount = 1;
}

//	�I������
void StageEditor::Uninit()
{
	m_Ball.Uninit();
	m_Enemy.Uninit();
	m_Player.Uninit();
	m_Goal.Uninit();
	m_EnemyGoal.Uninit();
	m_Texture.UnLoadTexture(texture[1]);
	m_Texture.UnLoadTexture(texture[0]);
}

//	�X�V����
void StageEditor::Update()
{
	switch (m_Stage)
	{
	case STAGE_CLEAR:
		m_StageCount++;		   // �X�e�[�W�J�E���g�����Z����
		InitObject(m_StageCount);
		m_Stage = (Stage)m_StageCount; // �L���X�g���Ď��̃X�e�[�W�֐i��
		break;
	case STAGE_1:
		UpdateObject();
		GoalEnd();
		break;
	case STAGE_2: 
		UpdateObject();
		GoalEnd();
		break;
	case STAGE_3:
		UpdateObject();
		GoalEnd();
	case STAGE_END:
		break;
	}
}

//	�`�揈��
void StageEditor::Draw()
{
	DrawObject();
	if (m_Stage == STAGE_CLEAR)
	{
		
	}
}

//	���w�S�[���ɓ��������ǂ���
bool StageEditor::GameEnd()
{
	if (m_Goal.GameEnd() == true || m_Stage == STAGE_END)
	{
		return true;
	}
	return false;
}

/// <summary>
///	Init()�̃w���p�[�֐�
/// </summary>
//	�e�N�X�`���̃��[�h
void StageEditor::LoadTexture()
{
	texture[0] = m_Texture.LoadTexture("Rom/Texture/Ball.png"); // �{�[��
	texture[1] = m_Texture.LoadTexture("Rom/Texture/Bar.png");	// Player&Goal
}
//	�I�u�W�F�N�g�̏�����
void StageEditor::InitObject(int Stage)
{
	m_EnemyGoal.Init();
	m_Goal.Init();
	m_Player.Init();
	switch (Stage)
	{
	case STAGE_1:
		m_Enemy.Init();
		m_Ball.Init();
		break;
	case STAGE_2:
		m_Enemy.Init(7.0f);
		m_Ball.Init(D3DXVECTOR2(-8.0f, 6.5f));
		break;
	case STAGE_3:
		m_Enemy.Init(6.0f, D3DXVECTOR2(960.0f + 320.0f, 360.0f));
		m_Ball.Init(D3DXVECTOR2(-5.0f, 9.5f));
		break;
	}
}

//	�X�e�[�W�Q
void StageEditor::InitStage_2()
{
	m_EnemyGoal.Init();
	m_Goal.Init();
	m_Player.Init();
	m_Enemy.Init();
	m_Ball.Init(D3DXVECTOR2(-7.0f,5.0f));
}

//�@�X�e�[�W�R
void StageEditor::InitStage_3()
{
	m_EnemyGoal.Init();
	m_Goal.Init();
	m_Player.Init();
	m_Enemy.Init();
	m_Ball.Init(D3DXVECTOR2(8.5f, -4.0f));
}

/// <summary>
/// Update()�̃w���p�[�֐�
/// </summary>
//	�I�u�W�F�N�g�̍X�V
void StageEditor::UpdateObject()
{
	m_Goal.Update();
	m_EnemyGoal.Update();
	m_Ball.Update();
	m_Player.Update();
	m_Enemy.Update();
}

//	�S�[���ɓ��ꂽ�Ƃ��̏���
void StageEditor::GoalEnd()
{
	if (m_EnemyGoal.GetGoalFlag() == true)
	{
		m_Stage = STAGE_CLEAR; // �X�e�[�g���X�V
	}
}


/// <summary>
/// Draw()�̃w���p�[�֐�
/// </summary>
//	�I�u�W�F�N�g�̕`��
void StageEditor::DrawObject()
{
	m_Player.Draw(m_Texture.SetTexture(texture[1]));
	m_Enemy.Draw(m_Texture.SetTexture(texture[1]));
	m_Ball.Draw(m_Texture.SetTexture(texture[0]));
	m_Goal.Draw(m_Texture.SetTexture(texture[1]));
	m_EnemyGoal.Draw(m_Texture.SetTexture(texture[1]));
}

/// <summary>
///  Getter
///	</summary>
Player * StageEditor::GetPlayer()
{
	return &m_Player;
}

Enemy * StageEditor::GetEnemy()
{
	return &m_Enemy;
}

Ball * StageEditor::GetBall()
{
	return &m_Ball;
}
