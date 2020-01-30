/*===================================================

	[SceneTitle.cpp]
	Author : o‡ãÄ‘¾

====================================================*/

#include "SceneTitle.h"
#include "SceneManager.h"
#include "Controller.h"
#include "Fade.h"

void SceneTitle::Init()
{
	Fade::Start(false,90,D3DCOLOR_RGBA(0,0,0,0));
	m_bEnd = false;
}

void SceneTitle::Uninit()
{

}

void SceneTitle::Update()
{
	if (!m_bEnd)
	{
		//	ゲームへ遷移
		if (KeyBoard::IsTrigger(DIK_R))
		{
			Fade::Start(true, 30, D3DCOLOR_RGBA(0,0,0,0));
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

void SceneTitle::Draw()
{
	
	m_Sprite.Draw(TEXTURE_TITLE, 0.0f, 0.0f);
}
