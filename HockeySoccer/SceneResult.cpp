/*===================================================

	[SceneResult.cpp]
	Author : �o���đ�

====================================================*/

#include "SceneResult.h"
#include "SceneManager.h"
#include "Controller.h"

//	�X�^�e�B�b�N�ϐ�
int  SceneResult::m_Ranking[5];

void SceneResult::Init()
{
	Fade::Start(false,90);
	m_bEnd = false;
}

void SceneResult::Uninit()
{

}

void SceneResult::Update()
{
	if (!m_bEnd)
	{
		if (KeyBoard::IsTrigger(DIK_R))
		{
			Fade::Start(true, 90);
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

void SceneResult::Draw()
{
	//m_Sprite.Draw(TEXTURE_RESULT, 0.0f, 0.0f);
}

void SceneResult::Sort(int Score)
{
	for (int i = 0; i < 5; i++)
	{//1�ʂ����r
		//���̏��ʂ���������΂��ꂪ����̏��ʂƂȂ�
		//(1�ʂ�荂�����1�ʁA1�ʂ��Ⴍ2�ʂ�荂�����2�ʁA�c)
		if (Score > m_Ranking[i])
		{
			for (int j = 5 - 1; j > i; j--) //����̏��ʈȍ~�̃X�R�A�����炷
			{
				m_Ranking[j] = m_Ranking[j - 1];
			}
			m_Ranking[i] = Score;//����̃X�R�A���L��
			break;//�ȍ~�̏��ʂ͒��ׂȂ�
		}
	}
}
