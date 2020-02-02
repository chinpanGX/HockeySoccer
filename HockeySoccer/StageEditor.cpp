/*=========================================================

	[StageEditor.cpp]
	�T�v �F �X�e�[�W�G�f�B�^
	Author : �o���đ�

==========================================================*/

#include "StageEditor.h"
#include "Controller.h"
#include "Fade.h"
#include "ObjectManager.h"

//	����������
void StageEditor::Init()
{
	LoadTexture();	//	�e�N�X�`���̃��[�h
	m_Stage = STAGE_1;	//	�������X�e�[�W
	InitObject(STAGE_1);	
	m_StageCount = m_Stage;	//	�X�e�[�W�J�E���g�֑��
}

//	�I������
void StageEditor::Uninit()
{
	UninitObject();
	m_Ui.Uninit();
	m_Texture.UnLoadTexture(texture[2]);
	m_Texture.UnLoadTexture(texture[1]);
	m_Texture.UnLoadTexture(texture[0]);
}

//	�X�V����
void StageEditor::Update()
{
	switch (m_Stage)
	{
	case STAGE_CLEAR:
		UpdateFrame();
		UpdateStageClear();
		break;
	case STAGE_1:
		UpdateObject();
		break;
	case STAGE_2:
		UpdateObject();
		break;
	case STAGE_3:
		UpdateObject();
		break;
	case STAGE_END:
		GameEnd();
		break;
	}
}

//	�`�揈��
void StageEditor::Draw()
{
	switch (m_Stage)
	{
	case STAGE_CLEAR:
		DrawStageClear();
		break;
	case STAGE_1:
		DrawObject();
		break;
	case STAGE_2:
		DrawObject();
		break;
	case STAGE_3:
		DrawObject();
		break;
	case STAGE_END:
		break;
	}
}

//	�Q�[���I��
bool StageEditor::GameEnd()
{
	if (m_Ball.GetGameEnd() == true) // ���w�S�[���ɓ���
	{
		return true;
	}
	if (m_Stage == STAGE_END) // �X�e�[�W���I���B
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
	texture[0] = m_Texture.LoadTexture("Rom/Texture/Ball.png");  // �{�[��
	texture[1] = m_Texture.LoadTexture("Rom/Texture/Bar.png");	 // Player&Goal
	texture[2] = m_Texture.LoadTexture("Rom/Texture/BG.png"); // �N���A���
	m_Ui.Init();	//	UI�e�N�X�`��
}
//	�I�u�W�F�N�g�̏�����
void StageEditor::InitObject(int Stage)
{
	switch (Stage)
	{
	case STAGE_CLEAR:
		m_NextSelect = true; //	�I���t���O��true�ɂ��Ă���
		break;
	case STAGE_1:
		m_EnemyGoal.Init();
		m_Goal.Init();
		m_Player.Init();
		m_Enemy.Init();
		m_Ball.Init();
		break;
	case STAGE_2:
		m_EnemyGoal.Init();
		m_Goal.Init();
		m_Player.Init();
		m_Enemy.Init(6.0f);
		m_Ball.Init();
		break;
	case STAGE_3:
		m_EnemyGoal.Init();
		m_Goal.Init();
		m_Player.Init();
		m_Enemy.Init(6.0f, D3DXVECTOR2(960.0f + 320.0f, 360.0f));
		m_Ball.Init(D3DXVECTOR2(-7.0f, 10.5f));
		break;
	case STAGE_END:
		m_Stage = STAGE_END;
		break;
	}
}

/// <summry>
///	Uninit()�̃w���p�[�֐�
/// </summary>
//	�I�u�W�F�N�g�̏I������
void StageEditor::UninitObject()
{
	m_Ball.Uninit();
	m_Enemy.Uninit();
	m_Player.Uninit();
	m_Goal.Uninit();
	m_EnemyGoal.Uninit();
}

/// <summary>
/// Update()�̃w���p�[�֐�
/// </summary>
//	�I�u�W�F�N�g�̍X�V
void StageEditor::UpdateObject()
{
	m_Goal.Update();
	m_EnemyGoal.Update();
	m_Player.Update();
	m_Enemy.Update();
	m_Ball.Update();
	EnemyGoalEnd();	//	�S�[���ɓ��ꂽ�Ƃ��̏���
}

//	�S�[���ɓ��ꂽ�Ƃ��̏���
void StageEditor::EnemyGoalEnd()
{
	if (m_Ball.GetGoalFlag() == true)
	{
		Fade::Start(false, 30);
		m_Stage = STAGE_CLEAR; // �X�e�[�g���X�V
		InitObject(m_Stage);
	}
}

void StageEditor::UpdateStageClear()
{
	if (KeyBoard::IsTrigger(DIK_UPARROW))
	{
		m_NextSelect = true;
	}
	else if (KeyBoard::IsTrigger(DIK_DOWNARROW))
	{
		m_NextSelect = false;
	}
	if (KeyBoard::IsTrigger(DIK_RETURN))
	{
		if (m_NextSelect == true)
		{
			m_StageCount++;		   // �X�e�[�W�J�E���g�����Z���� 
			InitObject(m_StageCount);
			m_Stage = (Stage)m_StageCount; //	�L���X�g���ăJ�E���g����
			Fade::Start(false, 60);
		}
		else
		{
			m_Stage = STAGE_END;
		}
	}
}

//	�g�̈ʒu�̍X�V
void StageEditor::UpdateFrame()
{
	if (m_NextSelect == true)
	{
		m_FramePosition = SCREEN_HEIGHT * 0.5f - 100.0f;
	}
	else if (m_NextSelect == false)
	{
		m_FramePosition = SCREEN_HEIGHT * 0.5f + 100.0f;
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

void StageEditor::DrawStageClear()
{
	m_Bg.Draw(m_Texture.SetTexture(texture[2]));
	m_Ui.Draw(SCREEN_WIDTH * 0.5 - 400.0f, SCREEN_HEIGHT * 0.5f - 100.0f, 1);
	m_Ui.Draw(SCREEN_WIDTH * 0.5 - 400.0f, SCREEN_HEIGHT * 0.5f + 100.0f, 2);
	m_Ui.Draw(SCREEN_WIDTH * 0.5 - 400.0f, m_FramePosition, 0);
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

Goal * StageEditor::GetGoal()
{
	return &m_Goal;
}

EnemyGoal * StageEditor::GetEnemyGoal()
{
	return &m_EnemyGoal;
}

Ball * StageEditor::GetBall()
{
	return &m_Ball;
}

