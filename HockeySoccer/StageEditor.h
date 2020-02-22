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
#include "Effect_Explosion.h"
#include "Effect_HitPlayer.h"
#include "Effect_Goal.h"

#define ENEMY_MAX 3 

// ステージ
enum Stage
{
	STAGE_CLEAR,
	STAGE_1,
	STAGE_2,
	STAGE_3,
	STAGE_4,
	STAGE_5,
	STAGE_6,
	STAGE_7,
	STAGE_8,
	STAGE_9,
	STAGE_10,
	STAGE_11,
	STAGE_12,
	STAGE_13,
	STAGE_14,
	STAGE_15,
	STAGE_16,
	GAME_END,
	STAGE_END
};

class StageEditor
{
private:
	Texture		m_Texture;
	Stage		m_Stage;			// ステージ
	Player		m_Player;			// プレイヤー
	Enemy		m_Enemy[ENEMY_MAX];	// エネミー
	Ball		m_Ball;				// ボール
	Goal		m_Goal;				// ゴール
	EnemyGoal	m_EnemyGoal;		// 相手側のゴール
	GameBG		m_StageBG;			// ステージクリア背景
	UI			m_Ui;				// UI
	Explosion	m_E_Ex;				// 爆発エフェクト
	HitPlayer	m_E_HitPlayer;		// ヒットエフェクト

	static const int number = 5; // テクスチャの数
	unsigned int texture[number]; // テクスチャを格納
	int	m_StageCount;		 // ステージをカウント
	int m_Frame;			 // フレームカウント
	float m_FramePosition;	 // 枠の位置
	bool m_NextSelect;		 //	選択フラグ(true->次、false->終了)
	bool m_Retry;			 // リトライ選択フラグ(true->リトライする、false->リトライしない)
			
	///	<summry>
	/// Init()のヘルパー関数
	/// </summary>
	void InitObject(int Stage);			// オブジェクトの初期化
	void InitGoal();					// ゴールの初期化	

	/// <summary>
	/// Uninit()のヘルパー関数
	/// </summary>
	void UninitObject();	//	オブジェクトの終了処理

	///	<summary>
	///	Update()のヘルパー関数
	/// </summary>
	void UpdateObject();				// オブジェクトの更新処理
	void UpdateEnemy(int EnemyNum = 1); // エネミーの更新（エネミーの数：デフォルト１）
	void UpdateStageClear();			// ステージクリアの更新
	void UpdateRetry();					// リトライの更新
	void UpdateFrame(bool Flag);		// 枠の位置の更新(引数でフラグを指定)
	
	//	UpdateObjectのヘルパー関数
	void EnemyGoalEnd();	// 相手ゴールに入れたとき
	void GoalEnd();			// 自陣ゴールに入ったとき
	void UpdateEffect();	// エフェクトの更新処理
	void CreateEffect(int number);	// エフェクト再生

	/// <summary>
	///　Draw()のヘルパー関数
	/// </summary>
	void DrawObject();					// オブジェクトの描画処理
	void DrawEnemy(int EnemyNum = 1);	// エネミーの描画（エネミーの数：デフォルト１）
	void DrawStageClear();				// ステージクリアの描画
	void DrawRetry();					// リトライの描画

public:
	void Init();	// 初期化処理
	void Uninit();	// 終了処理
	void Update();	// 更新処理
	void Draw();	// 描画処理
	bool GameEnd();	// ゲームエンドチェック

	//	Getter
	Player* GetPlayer();
	Enemy* GetEnemy();
	Goal* GetGoal();
	EnemyGoal* GetEnemyGoal();
	Ball* GetBall();
};

