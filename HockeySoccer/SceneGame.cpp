/*==================================

	[SceneGame.cpp]
	Author : �o���đ�

===================================*/

#include "SceneGame.h"
#include "SceneManager.h"

//	�Q�[���̏���������
void SceneGame::Init()
{
	m_bEnd = false;
	Fade::Start(false, 90, D3DCOLOR_RGBA(0, 0, 0, 0));
	//	�e�N�X�`���̃��[�h
	LoadTexture();
	// ������
	m_LineMgr.Set();
	m_EnemyGoal.Init();
	m_Goal.Init();
	m_Player.Init();
	m_Enemy.Init();
	m_Ball.Init();
}

//	�Q�[���̏I������
void SceneGame::Uninit()
{
	m_Ball.Uninit();
	m_Enemy.Uninit();
	m_Player.Uninit();
	m_Goal.Uninit();
	m_EnemyGoal.Uninit();
	//	�e�N�X�`���̃A�����[�h
	for (int i = 2; i >= 0; i--)
	{
		m_Texture.UnLoadTexture(i);
	}
}

//	�Q�[���̍X�V����
void SceneGame::Update()
{
	m_Player.Update();
	m_Enemy.Update();
	m_Ball.Update();
	m_Goal.Update();
	m_EnemyGoal.Update();
	EndCheck();
}

//	�Q�[���̕`�揈��
void SceneGame::Draw()
{
	DrawBg();
	DrawPlayer();
	DrawEnemy();
	DrawBall();
	DrawGoal();
	DrawEnemyGoal();
}

/// <summary>
///	Init()�̃w���p�[�֐�
///	</summary>
//	�e�N�X�`���̃��[�h
void SceneGame::LoadTexture()
{
	texture[0] = m_Texture.LoadTexture("Rom/Texture/BG.png");	// �Q�[���w�i
	texture[1] = m_Texture.LoadTexture("Rom/Texture/Bar.png");	// Player&Goal
	texture[2] = m_Texture.LoadTexture("Rom/TExture/Ball.png"); // �{�[��
}
/// <summary>
/// Update()�̃w���p�[�֐�
/// </summary>
//	�Q�[���I���`�F�b�N
void SceneGame::EndCheck()
{
	if (m_bEnd == false)
	{
		if (m_Goal.GameEnd() == true)
		{
			Fade::Start(true, 30, D3DCOLOR_RGBA(0, 0, 0, 0));
			m_bEnd = true;
		}
	}
	else
	{
		if (!Fade::IsFade())
		{
			SceneManager::ChangeSceneState();
		}
	}
}
/// <summary>
///	Draw()�̃w���p�[�֐�
/// </summary>
// �w�i�`��
void SceneGame::DrawBg()
{
	m_Bg.Draw(m_Texture.SetTexture(texture[0]));
}

// �v���C���[�`��
void SceneGame::DrawPlayer()
{
	m_Player.Draw(m_Texture.SetTexture(texture[1]));
}

//	�G�l�~�[�`��
void SceneGame::DrawEnemy()
{
	m_Enemy.Draw(m_Texture.SetTexture(texture[1]));
}

//	�{�[���`��
void SceneGame::DrawBall()
{
	m_Ball.Draw(m_Texture.SetTexture(texture[2]));
}

//�@�S�[���`��
void SceneGame::DrawGoal()
{
	m_Goal.Draw(m_Texture.SetTexture(texture[1]));
}

//	���葤�S�[���`��
void SceneGame::DrawEnemyGoal()
{
	m_EnemyGoal.Draw(m_Texture.SetTexture(texture[1]));
}
/// <summary>
///	 Getter
/// </summary>

LineManager * SceneGame::GetLineMgr()
{
	return &m_LineMgr;
}

Player * SceneGame::GetPlayer()
{
	return &m_Player;
}

Enemy * SceneGame::GetEnemy()
{
	return &m_Enemy;
}

Ball * SceneGame::GetBall()
{
	return &m_Ball;
}



