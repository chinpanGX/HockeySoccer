/*=========================================================

	[StageEditor.h]
	概要 ： ステージエディタ
	Author : 出合翔太

==========================================================*/

#pragma once
#include "Texture.h"
#include "Player.h"
#include "Enemy.h"
#include "Ball.h"
#include "Goal.h"
#include "EnemyGoal.h"
#include "GameBG.h"
#include "UI.h"

enum Stage
{
	STAGE_CLEAR,
	STAGE_1,
	STAGE_2,
	STAGE_3,
	GAME_END,
	STAGE_END
};

class StageEditor
{
private:
	Texture		m_Texture;
	Player		m_Player;	// プレイヤー
	Enemy		m_Enemy;	// エネミー
	Ball		m_Ball;		// ボール
	Goal		m_Goal;		// ゴール
	EnemyGoal	m_EnemyGoal;// 相手側のゴール
	Stage		m_Stage;	// ステージ
	GameBG		m_StageBG;	// ステージクリア背景
	GameBG		m_RetryBG;	// リトライ背景
	UI			m_Ui;		// UI

	unsigned int texture[4]; // テクスチャを格納
	int	m_StageCount;		 // ステージをカウント
	float m_FramePosition;	 // 枠の位置
	bool m_NextSelect;		 //	選択フラグ(true->次、false->終了)
	bool m_Retry;
			
	///	<summry>
	/// Init()のヘルパー関数
	/// </summary>
	void LoadTexture();			// テクスチャのロード
	void InitObject(int Stage);	// オブジェクトの初期化

	/// <summary>
	/// Uninit()のヘルパー関数
	/// </summary>
	void UninitObject();

	///	<summary>
	///	Update()のヘルパー関数
	/// </summary>
	void UpdateObject();	// オブジェクトの更新処理
	void EnemyGoalEnd();	// 相手ゴールに入れたとき
	void GoalEnd();
	void UpdateStageClear();// ステージクリアの更新
	void UpdateFrame(bool flag);	// 枠の位置の更新
	void UpdateRetry();		// リトライの更新

	/// <summary>
	///　Draw()のヘルパー関数
	/// </summary>
	void DrawObject();		// オブジェクトの描画処理
	void DrawStageClear();	// ステージクリアの描画
	void DrawRetry();		// リトライの描画

public:
	void Init();
	void Uninit();
	void Update();
	void Draw();
	bool GameEnd();

	//	Getter
	Player* GetPlayer();
	Enemy* GetEnemy();
	Goal* GetGoal();
	EnemyGoal* GetEnemyGoal();
	Ball* GetBall();
};

