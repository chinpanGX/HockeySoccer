/*==================================

	[SceneGame.cpp]
	Author : �o���đ�

===================================*/

#include "SceneGame.h"
#include "SceneManager.h"

// �Q�[���I���`�F�b�N
bool SceneGame::EndCheck()
{
	return false;
}

//	�Q�[���̏���������
void SceneGame::Init()
{
	m_Bg.Init();
	m_Player.Init();
	m_Ball.Init();
}

//	�Q�[���̏I������
void SceneGame::Uninit()
{
	m_Ball.Uninit();
	m_Player.Uninit();
	m_Bg.Uninit();
}

//	�Q�[���̍X�V����
void SceneGame::Update()
{
	m_Player.Update();
	m_Ball.Update();
}

//	�Q�[���̕`�揈��
void SceneGame::Draw()
{
	m_Bg.Draw();
	m_Player.Draw();
	m_Ball.Draw();
}

LineManager * SceneGame::GetLineMgr()
{
	return &m_LineMgr;
}

Player * SceneGame::GetPlayer()
{
	return &m_Player;
}

Ball * SceneGame::GetBall()
{
	return &m_Ball;
}

