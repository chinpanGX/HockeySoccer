/*==================================

	[SceneGame.h]
	Author : 出合翔太

===================================*/

#pragma once
#include "main.h"
#include "SceneBase.h"
#include "Texture.h"
#include "LineManager.h"
#include "GameBG.h"
#include "Player.h"
#include "Enemy.h"
#include "Ball.h"
#include "Goal.h"
#include "EnemyGoal.h"

//#	SceneGameクラス:抽象クラス,SceneBaseを継承した子クラス
class SceneGame : public SceneBase
{
private:
	Texture		m_Texture;	// テクスチャ
	LineManager m_LineMgr;	// ラインのコリジョン
	GameBG		m_Bg;		// 背景
	Player		m_Player;	// プレイヤー
	Enemy		m_Enemy;	// エネミー
	Ball		m_Ball;		// ボール
	Goal		m_Goal;		// ゴール
	EnemyGoal	m_EnemyGoal;// 相手側のゴール

	unsigned int texture[3]; //	テクスチャの番号を格納
	
	//	Init()のヘルパー関数
	void LoadTexture();		// テクスチャのロード
	//	Update()のヘルパー関数
	bool EndCheck();		// ゲーム終了チェック
	// Draw()のヘルパー関数
	void DrawBg();			
	void DrawPlayer();
	void DrawEnemy();
	void DrawBall();
	void DrawGoal();
	void DrawEnemyGoal();

public:
	void Init()override;	
	void Uninit()override;
	void Update()override;
	void Draw()override;

	// Getter
	LineManager* GetLineMgr();
	Player* GetPlayer();
	Enemy* GetEnemy();
	Ball* GetBall();
};
