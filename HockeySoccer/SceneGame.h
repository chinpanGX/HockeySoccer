/*==================================

	[SceneGame.h]
	Author : �o���đ�

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

//#	SceneGame�N���X:���ۃN���X,SceneBase���p�������q�N���X
class SceneGame : public SceneBase
{
private:
	Texture		m_Texture;	// �e�N�X�`��
	LineManager m_LineMgr;	// ���C���̃R���W����
	GameBG		m_Bg;		// �w�i
	Player		m_Player;	// �v���C���[
	Enemy		m_Enemy;	// �G�l�~�[
	Ball		m_Ball;		// �{�[��
	Goal		m_Goal;		// �S�[��
	EnemyGoal	m_EnemyGoal;// ���葤�̃S�[��

	unsigned int texture[3]; //	�e�N�X�`���̔ԍ����i�[
	
	//	Init()�̃w���p�[�֐�
	void LoadTexture();		// �e�N�X�`���̃��[�h
	//	Update()�̃w���p�[�֐�
	bool EndCheck();		// �Q�[���I���`�F�b�N
	// Draw()�̃w���p�[�֐�
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
