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
	Fade::Start(false, 90);
	//	�e�N�X�`���̃��[�h
	LoadTexture();
	// ������
	m_LineMgr.Set();
	m_StageEditor.Init();
}

//	�Q�[���̏I������
void SceneGame::Uninit()
{
	m_StageEditor.Uninit();
	//	�e�N�X�`���̃A�����[�h
	m_Texture.UnLoadTexture(texture);
}

//	�Q�[���̍X�V����
void SceneGame::Update()
{
	m_StageEditor.Update();
	EndCheck();
}

//	�Q�[���̕`�揈��
void SceneGame::Draw()
{
	DrawBg();
	m_StageEditor.Draw();
}

/// <summary>
///	Init()�̃w���p�[�֐�
///	</summary>
//	�e�N�X�`���̃��[�h
void SceneGame::LoadTexture()
{
	texture = m_Texture.LoadTexture("Rom/Texture/GameBG.png");	// �Q�[���w�i
}

/// <summary>
/// Update()�̃w���p�[�֐�
/// </summary>
//	�Q�[���I���`�F�b�N
void SceneGame::EndCheck()
{
	if (m_bEnd == false)
	{
		//	���w�S�[���̓��������烊�U���g
		if (m_StageEditor.GameEnd() == true)
		{
			Fade::Start(true, 30);
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
	m_Bg.Draw(m_Texture.SetTexture(texture));
}

/// <summary>
///	 Getter
/// </summary>

LineManager * SceneGame::GetLineMgr()
{
	return &m_LineMgr;
}

StageEditor * SceneGame::GetStageEditor()
{
	return &m_StageEditor;
}


