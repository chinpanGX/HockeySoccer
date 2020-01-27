/*==================================

	[SceneGame.cpp]
	Author : 出合翔太

===================================*/

#include "SceneGame.h"
#include "SceneManager.h"

//	ゲームの初期化処理
void SceneGame::Init()
{
	m_Bg.Init();
	m_Player.Init();
	m_Ball.Init();
}

//	ゲームの終了処理
void SceneGame::Uninit()
{
	m_Ball.Uninit();
	m_Player.Uninit();
	m_Bg.Uninit();
}

//	ゲームの更新処理
void SceneGame::Update()
{
	m_Player.Update();
	m_Ball.Update();
}

//	ゲームの描画処理
void SceneGame::Draw()
{
	m_Bg.Draw();
	m_Player.Draw();
	m_Ball.Draw();
}

bool SceneGame::EndCheck()
{
	return false;
}

