/*=========================================================

	[StageEditor.h]
	Author : �o���đ�

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
	Player		m_Player;	// �v���C���[
	Enemy		m_Enemy;	// �G�l�~�[
	Ball		m_Ball;		// �{�[��
	Goal		m_Goal;		// �S�[��
	EnemyGoal	m_EnemyGoal;// ���葤�̃S�[��

	unsigned int texture[2];
	
	//	Init()�̃w���p�[�֐�
	void LoadTexture();

	//	Update()�̃w���p�[�֐�

	//Draw()�̃w���p�[�֐�
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

