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

class StageEditor
{
private:
	Texture		m_Texture;
	Player		m_Player;	// プレイヤー
	Enemy		m_Enemy;	// エネミー
	Ball		m_Ball;		// ボール
	Goal		m_Goal;		// ゴール
	EnemyGoal	m_EnemyGoal;// 相手側のゴール

	unsigned int texture[2];
	
	//	Init()のヘルパー関数
	void LoadTexture();

	//	Update()のヘルパー関数

	//Draw()のヘルパー関数
	void DrawPlayer();
	void DrawEnemy();
	void DrawBall();
	void DrawGoal();
	void DrawEnemyGoal();

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

