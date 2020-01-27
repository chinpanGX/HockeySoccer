/*==================================

	[SceneGame.cpp]
	Author : �o���đ�

===================================*/

#include "SceneGame.h"
#include "SceneManager.h"

//	�Q�[���̏���������
void SceneGame::Init()
{
	m_Bg.Init();
	m_Player.Init();
}

//	�Q�[���̏I������
void SceneGame::Uninit()
{
	m_Player.Uninit();
	m_Bg.Uninit();
}

//	�Q�[���̍X�V����
void SceneGame::Update()
{
	m_Player.Update();
}

//	�Q�[���̕`�揈��
void SceneGame::Draw()
{
	m_Bg.Draw();
	m_Player.Draw();
}

bool SceneGame::EndCheck()
{
	return false;
}

