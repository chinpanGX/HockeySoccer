/*===================================================

	[SceneResult.cpp]
	Author : 出合翔太

====================================================*/

#include "SceneResult.h"
#include "SceneManager.h"
#include "Controller.h"

//	スタティック変数
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
	{//1位から比較
		//今の順位よりも高ければそれが今回の順位となる
		//(1位より高ければ1位、1位より低く2位より高ければ2位、…)
		if (Score > m_Ranking[i])
		{
			for (int j = 5 - 1; j > i; j--) //今回の順位以降のスコアをずらす
			{
				m_Ranking[j] = m_Ranking[j - 1];
			}
			m_Ranking[i] = Score;//今回のスコアを記憶
			break;//以降の順位は調べない
		}
	}
}
