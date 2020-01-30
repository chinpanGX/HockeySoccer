/*==================================

	[SceneGame.cpp]
	Author : 出合翔太

===================================*/

#include "SceneGame.h"
#include "SceneManager.h"

//	ゲームの初期化処理
void SceneGame::Init()
{
	//	テクスチャのロード
	LoadTexture();
	// 初期化
	m_LineMgr.Set();
	m_EnemyGoal.Init();
	m_Goal.Init();
	m_Player.Init();
	m_Ball.Init();
}

//	ゲームの終了処理
void SceneGame::Uninit()
{
	m_Ball.Uninit();
	m_Player.Uninit();
	m_Goal.Uninit();
	m_EnemyGoal.Uninit();
	//	テクスチャのアンロード
	for (int i = 2; i >= 0; i--)
	{
		m_Texture.UnLoadTexture(i);
	}
}

//	ゲームの更新処理
void SceneGame::Update()
{
	m_Player.Update();
	m_Ball.Update();
	m_Goal.Update();
	m_EnemyGoal.Update();
}

//	ゲームの描画処理
void SceneGame::Draw()
{
	DrawBg();
	DrawPlayer();
	DrawBall();
	DrawGoal();
	DrawEnemyGoal();
}

/// <summary>
///	Init()のヘルパー関数
///	</summary>
//	テクスチャのロード
void SceneGame::LoadTexture()
{
	texture[0] = m_Texture.LoadTexture("Rom/Texture/BG.png");	// ゲーム背景
	texture[1] = m_Texture.LoadTexture("Rom/Texture/Bar.png");	// Player&Goal
	texture[2] = m_Texture.LoadTexture("Rom/TExture/Ball.png"); // ボール
}
/// <summary>
/// Update()のヘルパー関数
/// </summary>
//	ゲーム終了チェック
bool SceneGame::EndCheck()
{
	return false;
}
/// <summary>
///	Draw()のヘルパー関数
/// </summary>
// 背景描画
void SceneGame::DrawBg()
{
	m_Bg.Draw(m_Texture.SetTexture(texture[0]));
}

// プレイヤー描画
void SceneGame::DrawPlayer()
{
	m_Player.Draw(m_Texture.SetTexture(texture[1]));
}

//	ボール描画
void SceneGame::DrawBall()
{
	m_Ball.Draw(m_Texture.SetTexture(texture[2]));
}

void SceneGame::DrawGoal()
{
	m_Goal.Draw(m_Texture.SetTexture(texture[1]));
}

void SceneGame::DrawEnemyGoal()
{
	m_EnemyGoal.Draw(m_Texture.SetTexture(texture[1]));
}

//	Getter
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

