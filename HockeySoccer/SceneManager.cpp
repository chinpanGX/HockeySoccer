/*==============================================

	[SceneManager.cpp]	
	ゲームループを管理するクラス
	Author : 出合翔太

===============================================*/
#include "main.h"
#include "SceneManager.h"
#include "SceneGame.h"

//	スタティック変数
SceneBase			*SceneManager::m_Scene;	//	シーンのインスタンスを格納[シーンの配列]
//SCENE_STATE			SceneManager::m_SceneState;	//	シーンのステートマシン（シーンの状態を格納）
LPDIRECT3DDEVICE9	SceneManager::m_pDevice;	//	デバイス

//	初期化処理
void SceneManager::Init()
{
	m_pDevice = GetD3DDevice();			//	デバイスの取得

	//	メモリの確保			
	m_Scene = new SceneGame;			

	//m_sceneState = SCENE_TITLE;			//	初期シーンの設定(ゲームを起動したときの最初のシーン)
	m_Scene->Init();		//	初期シーンの初期化
}

//	終了処理
void SceneManager::Uninit()
{
						
	//	各シーンのUninit関数を呼び出す
	m_Scene->Uninit();

	//	各シーンのメモリの解放
	delete m_Scene;
}

//	更新処理
void SceneManager::Update()
{
	m_Scene->Update();	//	各シーンのUpdate関数の呼び出し
}

//	描画処理
void SceneManager::Draw()
{
	m_Scene->Draw();		//	各シーンのDraw関数の呼び出し
}

SceneBase * SceneManager::SetSceneGame()
{
	return m_Scene;
}

/*
//	シーン遷移処理
void SceneManager::ChangeSceneState()
{
	switch (m_sceneState)
	{
	case SCENE_TITLE:
		m_scene[m_sceneState]->Uninit();
		m_sceneState = SCENE_GAME;
		m_scene[m_sceneState]->Init();
		break;
	case SCENE_GAME:
		m_scene[m_sceneState]->Uninit();
		m_sceneState = SCENE_RESULT;		//	リザルトへ遷移
		m_scene[m_sceneState]->Init();
		break;
	case SCENE_RESULT:
		m_scene[m_sceneState]->Uninit();
		m_sceneState = SCENE_TITLE;			//	タイトルへ遷移
		m_scene[m_sceneState]->Init();
		break;
	}
}

SceneBase * SceneManager::SetSceneGame()
{
	return m_scene[1];
}
*/