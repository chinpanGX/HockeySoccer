/*=========================================================

	[StageEditor.cpp]
	�T�v �F �X�e�[�W�G�f�B�^
	Author : �o���đ�

==========================================================*/

#include "StageEditor.h"
#include "Controller.h"
#include "Fade.h"
#include "ObjectManager.h"
#include "Sound.h"

//	����������
void StageEditor::Init()
{
	//	�e�N�X�`���̃��[�h
	texture[0] = m_Texture.LoadTexture("Rom/Texture/Ball.png");			// �{�[��
	texture[1] = m_Texture.LoadTexture("Rom/Texture/Bar.png");			// �S�[��
	texture[2] = m_Texture.LoadTexture("Rom/Texture/Explosion.png");	// �����G�t�F�N�g
	texture[3] = m_Texture.LoadTexture("Rom/Texture/PlayerEffect.png"); // �q�b�g�G�t�F�N�g
	texture[4] = m_Texture.LoadTexture("Rom/Texture/Goal.png");
	m_Ui.Init();//	UI�e�N�X�`��
	// �X�e�[�W
	m_Stage = STAGE_1;		//	�������X�e�[�W
	InitObject(STAGE_1);
	m_StageCount = m_Stage;	//	�X�e�[�W�J�E���g�֑��
}

//	�I������
void StageEditor::Uninit()
{
	UninitObject();
	
	// �e�N�X�`���̃A�����[�h
	m_Ui.Uninit();
	for (int i = number - 1; i >= 0; i--)
	{
		m_Texture.UnLoadTexture(texture[i]);
	}
}

//	�X�V����
void StageEditor::Update()
{
	switch (m_Stage)
	{
	case STAGE_CLEAR:
		UpdateFrame(m_NextSelect);
		UpdateStageClear();
		break;
	case STAGE_1:
		UpdateObject();
		UpdateEnemy();
		break;
	case STAGE_2:
		UpdateObject();
		UpdateEnemy();
		break;
	case STAGE_3:
		UpdateObject();
		UpdateEnemy();
		break;
	case STAGE_4:
		UpdateObject();
		UpdateEnemy();
		break;
	case STAGE_5:
		UpdateObject();
		UpdateEnemy();
		break;
	case STAGE_6:
		UpdateObject();
		UpdateEnemy(2);
		break;
	case STAGE_7:
		UpdateObject();
		UpdateEnemy(2);
		break;
	case STAGE_8:
		UpdateObject();
		UpdateEnemy(2);
		break;
	case STAGE_9:
		UpdateObject();
		UpdateEnemy(2);
		break;
	case STAGE_10:
		UpdateObject();
		UpdateEnemy(2);
		break;
	case STAGE_11:
		UpdateObject();
		UpdateEnemy(2);
		break;
	case STAGE_12:
		UpdateObject();
		UpdateEnemy(2);
		break;
	case STAGE_13:
		UpdateObject();
		UpdateEnemy(2);
		break;
	case STAGE_14:
		UpdateObject();
		UpdateEnemy(3);
		break;
	case STAGE_15:
		UpdateObject();
		UpdateEnemy(3);
		break;
	case STAGE_16:
		UpdateObject();
		UpdateEnemy(3);
		break;
	case GAME_END:
		break;
	case STAGE_END:
		UpdateFrame(m_Retry);
		UpdateRetry();	//	���g���C�̍X�V
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
		DrawEnemy();
		break;
	case STAGE_2:
		DrawObject();
		DrawEnemy();
		break;
	case STAGE_3:
		DrawObject();
		DrawEnemy();
		break;
	case STAGE_4:
		DrawObject();
		DrawEnemy();
		break;
	case STAGE_5:
		DrawObject();
		DrawEnemy();
		break;
	case STAGE_6:
		DrawObject();
		DrawEnemy(2);
		break;
	case STAGE_7:
		DrawObject();
		DrawEnemy(2);
		break;
	case STAGE_8:
		DrawObject();
		DrawEnemy(2);
		break;
	case STAGE_9:
		DrawObject();
		DrawEnemy(2);
		break;
	case STAGE_10:
		DrawObject();
		DrawEnemy(2);
		break;
	case STAGE_11:
		DrawObject();
		DrawEnemy(2);
		break;
	case STAGE_12:
		DrawObject();
		DrawEnemy(2);
		break;
	case STAGE_13:
		DrawObject();
		DrawEnemy(2);
		break;
	case STAGE_14:
		DrawObject();
		DrawEnemy(3);
		break;
	case STAGE_15:
		DrawObject();
		DrawEnemy(3);
		break;
	case STAGE_16:
		DrawObject();
		DrawEnemy(3);
	case GAME_END:
		break;
	case STAGE_END:
		DrawRetry();
		break;
	}
}

//	�Q�[���I��
bool StageEditor::GameEnd()
{
	if (m_Stage == GAME_END) // �Q�[���G���h�ŏI��
	{
		return true;
	}
	return false;
}

/// <summary>
///	Init()�̃w���p�[�֐�
/// </summary>
//	�I�u�W�F�N�g�̏�����
void StageEditor::InitObject(int Stage)
{
	switch (Stage)
	{
	case STAGE_CLEAR:
		m_NextSelect = true; //	�I���t���O��true�ɂ��Ă���
		break;
	case STAGE_1:
		InitGoal();
		m_Player.Init();
		m_Enemy[0].Init();
		m_Ball.Init();
		break;
	case STAGE_2:
		InitGoal();
		m_Player.Init();
		m_Enemy[0].Init(6.0f);
		m_Ball.Init(D3DXVECTOR2(-8.0f, 8.5f));
		break;
	case STAGE_3:
		InitGoal();
		m_Player.Init(1.5f);
		m_Enemy[0].Init(5.0f, D3DXVECTOR2(960.0f + 300.0f, 800.0f));
		m_Ball.Init(D3DXVECTOR2(-10.0f, -7.5f));
		break;
	case STAGE_4:
		InitGoal();
		m_Player.Init();
		m_Enemy[0].Init(9.0f, D3DXVECTOR2(960.0f + 100.0f, 100.0f));
		m_Ball.Init(D3DXVECTOR2(-14.0f, 5.5f));
		break;
	case STAGE_5:
		InitGoal();
		m_Player.Init(1.5f);
		m_Enemy[0].Init(7.0f, D3DXVECTOR2(960.0f + 400.0f, 360.0f));
		m_Enemy[1].Init(2.0f, D3DXVECTOR2(960.0f + 400.0f, 360.0f));
		m_Ball.Init(D3DXVECTOR2(14.0f, -8.5f));
		break;
	case STAGE_6:
		InitGoal();
		m_Player.Init(0.8f);
		m_Enemy[1].Init(2.0f, D3DXVECTOR2(960.0f + 550.0f, 300.0f));
		m_Enemy[0].Init(-7.0f, D3DXVECTOR2(960.0f + 300.0f, 300.0f));
		m_Ball.Init(D3DXVECTOR2(-15.0f, 7.5f));
		break;
	case STAGE_7:
		InitGoal();
		m_Player.Init(1.3f);
		m_Enemy[1].Init(-2.0f, D3DXVECTOR2(960.0f + 550.0f, 600.0f));
		m_Enemy[0].Init(0.0f, D3DXVECTOR2(960.0f + 250.0f, 800.0f));
		m_Ball.Init(D3DXVECTOR2(-17.0f, 10.5f));
		break;
	case STAGE_8:
		m_EnemyGoal.Init(1.0f);
		m_Goal.Init();
		m_Player.Init(2.0f);
		m_Enemy[1].Init(5.0f, D3DXVECTOR2(960.0f + 550.0f, 300.0f));
		m_Enemy[0].Init(2.0f, D3DXVECTOR2(960.0f + 300.0f, 800.0f));
		m_Ball.Init(D3DXVECTOR2(17.0f, -12.5f));
		break;
	case STAGE_9:
		m_EnemyGoal.Init(1.0f);
		m_Goal.Init(1.0f);
		m_Player.Init(2.0f);
		m_Enemy[0].Init(10.0f, D3DXVECTOR2(960.0f + 450.0f, 800.0f));
		m_Ball.Init(D3DXVECTOR2(-9.0f, -15.5f));
		break;
	case STAGE_10:
		m_EnemyGoal.Init(-2.0f);
		m_Goal.Init(1.0f);
		m_Player.Init(1.0f);
		m_Enemy[1].Init(-3.5f, D3DXVECTOR2(960.0f + 500.0f, 300.0f));
		m_Enemy[0].Init(3.5f, D3DXVECTOR2(960.0f + 300.0f, 800.0f));
		m_Ball.Init(D3DXVECTOR2(-19.0f, 7.5f));
		break;
	case STAGE_11:
		m_EnemyGoal.Init(3.0f);
		m_Goal.Init(3.0f);
		m_Player.Init(1.4f);
		m_Enemy[1].Init(8.0f, D3DXVECTOR2(960.0f + 550.0f, 600.0f));
		m_Enemy[0].Init(4.0f, D3DXVECTOR2(960.0f + 300.0f, 300.0f));
		m_Ball.Init(D3DXVECTOR2(-14.0f, 7.5f));
		break;
	case STAGE_12:
		m_EnemyGoal.Init(-1.0f);
		m_Goal.Init(3.0f);
		m_Player.Init(3.0f);
		m_Enemy[1].Init(2.0f, D3DXVECTOR2(960.0f + 550.0f, 800.0f));
		m_Enemy[0].Init(-7.0f, D3DXVECTOR2(960.0f + 300.0f, 200.0f));
		m_Ball.Init(D3DXVECTOR2(-15.0f, -8.5f));
		break;
	case STAGE_13:
		m_EnemyGoal.Init(2.0f);
		m_Goal.Init(-2.0f);
		m_Player.Init(2.0f);
		m_Enemy[1].Init(2.0f, D3DXVECTOR2(960.0f + 700.0f, 300.0f));
		m_Enemy[0].Init(-2.0f, D3DXVECTOR2(960.0f + 300.0f, 300.0f));
		m_Ball.Init(D3DXVECTOR2(-12.0f, -7.5f));
		break;
	case STAGE_14:
		m_EnemyGoal.Init(2.0f);
		m_Goal.Init(0.0f);
		m_Player.Init(2.0f);
		m_Enemy[2].Init(0.0f, D3DXVECTOR2(960.0f + 700.0f, 800.0f));
		m_Enemy[1].Init(5.0f, D3DXVECTOR2(960.0f + 300.0f, 500.0f));
		m_Enemy[0].Init(-5.0f, D3DXVECTOR2(960.0f + 0.0f, 300.0f));
		m_Ball.Init(D3DXVECTOR2(-8.0f, 6.5f));
		break;
	case STAGE_15:
		m_EnemyGoal.Init(-2.0f);
		m_Goal.Init(2.0f);
		m_Player.Init(1.0f);
		m_Enemy[2].Init(5.0f, D3DXVECTOR2(960.0f + 600.0f, 300.0f));
		m_Enemy[1].Init(9.0f, D3DXVECTOR2(960.0f + 300.0f, 300.0f));
		m_Enemy[0].Init(-5.0f, D3DXVECTOR2(960.0f + 0.0f,  300.0f));
		m_Ball.Init(D3DXVECTOR2(13.0f, 5.0f));
		break;
	case STAGE_16:
		m_EnemyGoal.Init(-5.0f);
		m_Goal.Init(5.0f);
		m_Player.Init(2.0f);
		m_Enemy[2].Init(8.0f, D3DXVECTOR2(960.0f + 500.0f, 600.0f));
		m_Enemy[1].Init(10.0f, D3DXVECTOR2(960.0f + 200.0f, 0.0f));
		m_Enemy[0].Init(-8.0f, D3DXVECTOR2(960.0f - 100.0f, 300.0f));
		m_Ball.Init(D3DXVECTOR2(-15.0f, 7.0f));
		break;
	case GAME_END:
		break;
	case STAGE_END:
		Sound::Stop();
		Sound::Play(S_BGM_GAMEEND);
		m_Retry = true;
		break;
	}
}

// ���ʂ̏�����
void StageEditor::InitGoal()
{
	m_EnemyGoal.Init();
	m_Goal.Init();
	// �G�t�F�N�g����
	m_E_Ex.Init();
	m_E_HitPlayer.Init();
}

/// <summry>
///	Uninit()�̃w���p�[�֐�
/// </summary>
//	�I�u�W�F�N�g�̏I������
void StageEditor::UninitObject()
{
	Sound::Stop();
	m_Ball.Uninit();
	m_Enemy[2].Uninit();
	m_Enemy[1].Uninit();
	m_Enemy[0].Uninit();
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
	if (GamePad::IsTrigger(0, BUTTON_3))
	{
		m_Stage = STAGE_END;
	}
	m_Goal.Update();
	m_EnemyGoal.Update();
	m_Player.Update();
	m_Ball.Update();
	UpdateEffect(); // �G�t�F�N�g�̍X�V����
	EnemyGoalEnd();	// �S�[���ɓ��ꂽ�Ƃ��̏���
	GoalEnd();		//�S�[���ɓ������Ƃ��̏���
}

// �G�l�~�[�̍X�V
void StageEditor::UpdateEnemy(int EnemyNum)
{
	for (int i = 0; i < EnemyNum; i++)
	{
		m_Enemy[i].Update();
	}
}

/// <summary>
/// UpdateObject()�̃w���p�[�֐�
/// </summary>
//	�S�[���ɓ��ꂽ�Ƃ��̏���
void StageEditor::EnemyGoalEnd()
{
	if (m_Ball.GetGoalFlag() == true)
	{
		CreateEffect(GOAL);
		if (m_StageCount == GAME_END - 1)
		{
			m_Stage = GAME_END;	//	�Q�[���G���h�X�e�[�g��
		}
		else
		{
			Fade::Start(false, 30);
			m_Stage = STAGE_CLEAR; // �X�e�[�g���X�V
			InitObject(m_Stage);
		}
	}
}

//	���w�S�[���̏���
void StageEditor::GoalEnd()
{
	if (m_Ball.GetGameEnd() == true) // ���w�S�[���ɓ���
	{
		CreateEffect(GOAL);
		Fade::Start(false, 30);
		m_Stage = STAGE_END; // �X�e�[�g���X�V
		InitObject(m_Stage);
	}
}

// �G�t�F�N�g�̍X�V����
void StageEditor::UpdateEffect()
{
	EffectNumber number;
	m_E_Ex.Update();
	m_E_HitPlayer.Update();
	number = (EffectNumber)m_Ball.GetEffect();
	switch (number)
	{
	case EXPLOSION: // �����G�t�F�N�g
		CreateEffect(m_Ball.GetEffect());
		break;
	case HITPLAYER: // �q�b�g�G�t�F�N�g
		CreateEffect(m_Ball.GetEffect());
		break;
	}
}

// �G�t�F�N�g�Đ�
void StageEditor::CreateEffect(int number)
{
	switch (number)
	{
	case EXPLOSION:
		m_E_Ex.Set(m_Ball.GetPosition().x, m_Ball.GetPosition().y);
		break;
	case HITPLAYER:
		m_E_HitPlayer.Set(m_Ball.GetPosition().x, m_Ball.GetPosition().y);
		break;
	}
}

//	�Q�[���N���A�̍X�V����
void StageEditor::UpdateStageClear()
{
	if (KeyBoard::IsTrigger(DIK_UPARROW) || GamePad::IsTrigger(0,LEFTSTICK_UP))
	{
		Sound::Play(S_SE_BUTTON);
		m_NextSelect = true;
	}
	else if (KeyBoard::IsTrigger(DIK_DOWNARROW) || GamePad::IsTrigger(0,LEFTSTICK_DOWN))
	{
		Sound::Play(S_SE_BUTTON);
		m_NextSelect = false;
	}
	if (KeyBoard::IsTrigger(DIK_RETURN) || GamePad::IsTrigger(0,BUTTON_2))
	{
		Sound::Play(S_SE_ANSWER);
		if (m_NextSelect == true)
		{
			m_StageCount++;					// �X�e�[�W�J�E���g�����Z����
			InitObject(m_StageCount);		// ���̃X�e�[�W��������	
			m_Stage = (Stage)m_StageCount;	// �L���X�g���ăJ�E���g����
			Fade::Start(false, 60);
		}
		else
		{
			m_Stage = GAME_END;	//	�Q�[���G���h�X�e�[�g��
		}
	}
}

//	���g���C�̍X�V
void StageEditor::UpdateRetry()
{
	if (KeyBoard::IsTrigger(DIK_UPARROW) || GamePad::IsTrigger(0, LEFTSTICK_UP))
	{
		Sound::Play(S_SE_BUTTON);
		m_Retry = true;
	}
	else if (KeyBoard::IsTrigger(DIK_DOWNARROW) || GamePad::IsTrigger(0, LEFTSTICK_DOWN))
	{
		Sound::Play(S_SE_BUTTON);
		m_Retry = false;
	}
	if (KeyBoard::IsTrigger(DIK_RETURN) || GamePad::IsTrigger(0, BUTTON_2))
	{
		Sound::Play(S_SE_ANSWER);
		if (m_Retry == true)	//	���g���C����
		{
			Sound::Stop();
			InitObject(m_StageCount);		// �X�e�[�W�J�E���g�͉��Z���Ȃ���Init()
			m_Stage = (Stage)m_StageCount;	// �L���X�g���ăJ�E���g����
			Sound::Play(S_BGM_GAME);
			Fade::Start(false, 60);
		}
		else // ���g���C���Ȃ�
		{
			m_Stage = GAME_END; // �G���h�X�e�[�g��
		}
	}
}

//	�g�̈ʒu�̍X�V
void StageEditor::UpdateFrame(bool Flag)
{	
	if (Flag == true)
	{
		m_FramePosition = SCREEN_HEIGHT * 0.5f - 115.0f;
	}
	else if (Flag == false)
	{
		m_FramePosition = SCREEN_HEIGHT * 0.5f + 115.0f;
	}
}

/// <summary>
/// Draw()�̃w���p�[�֐�
/// </summary>
//	�I�u�W�F�N�g�̕`��
void StageEditor::DrawObject()
{
	m_Player.Draw(m_Texture.SetTexture(texture[1]));
	m_Goal.Draw(m_Texture.SetTexture(texture[1]));
	m_EnemyGoal.Draw(m_Texture.SetTexture(texture[1]));
	m_Ball.Draw(m_Texture.SetTexture(texture[0]));
	m_E_Ex.Draw(m_Texture.SetTexture(texture[2]));
	m_E_HitPlayer.Draw(m_Texture.SetTexture(texture[3]));
}

//  �G�l�~�[�̕`��
void StageEditor::DrawEnemy(int EnemyNum)
{
	for (int i = 0; i < EnemyNum; i++)
	{
		m_Enemy[i].Draw(m_Texture.SetTexture(texture[1]));
	}
}

//	�Q�[���N���A�̕`�揈��
void StageEditor::DrawStageClear()
{
	m_Ui.Draw(SCREEN_WIDTH * 0.5 - 432.0f, SCREEN_HEIGHT * 0.5f - 400.0f, 7);
	m_Ui.Draw(SCREEN_WIDTH * 0.5 - 432.0f, SCREEN_HEIGHT * 0.5f - 115.0f, 1);
	m_Ui.Draw(SCREEN_WIDTH * 0.5 - 432.0f, SCREEN_HEIGHT * 0.5f + 115.0f, 2);
	m_Ui.Draw(SCREEN_WIDTH * 0.5 - 432.0f, m_FramePosition, 0);
}

//	���g���C��ʂ̕`�揈��
void StageEditor::DrawRetry()
{
	m_Ui.Draw(SCREEN_WIDTH * 0.5 - 432.0f, SCREEN_HEIGHT * 0.5f - 400.0f, 6);
	m_Ui.Draw(SCREEN_WIDTH * 0.5 - 432.0f, SCREEN_HEIGHT * 0.5f - 115.0f, 4);
	m_Ui.Draw(SCREEN_WIDTH * 0.5 - 432.0f, SCREEN_HEIGHT * 0.5f + 115.0f, 5);
	m_Ui.Draw(SCREEN_WIDTH * 0.5 - 432.0f, m_FramePosition, 0);
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
	return &m_Enemy[0];
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

