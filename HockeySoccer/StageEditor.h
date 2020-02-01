/*=========================================================

	[StageEditor.h]
	Author : 出合翔太

==========================================================*/

#pragma once
#include "Texture.h"
#include "Player.h"
#include "Enemy.h"
#include "Ball.h"
#include "Goal.h"
#include "EnemyGoal.h"

enum Stage
{
	STAGE_CLEAR,
	STAGE_1,
	STAGE_2,
	STAGE_3,
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

	unsigned int texture[2];
	int	m_StageCount;
	
	///	<summry>
	/// Init()のヘルパー関数
	/// </summary>
	void LoadTexture();	// テクスチャのロード
	void InitObject(int Stage);	// オブジェクトの初期化
	void InitStage_2(); // ステージ２
	void InitStage_3(); // ステージ３

	///	<summary>
	///	Update()のヘルパー関数
	/// </summary>
	void UpdateObject(); //	オブジェクトの更新処理
	void GoalEnd();

	/// <summary>
	///　Draw()のヘルパー関数
	/// </summary>
	void DrawObject(); // オブジェクトの描画処理

public:
	void Init();
	void Uninit();
	void Update();
	void Draw();
	bool GameEnd();

	Player* GetPlayer();
	Enemy* GetEnemy();
	Ball* GetBall();
};

