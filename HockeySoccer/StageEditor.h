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
	Player		m_Player;	// �v���C���[
	Enemy		m_Enemy;	// �G�l�~�[
	Ball		m_Ball;		// �{�[��
	Goal		m_Goal;		// �S�[��
	EnemyGoal	m_EnemyGoal;// ���葤�̃S�[��
	Stage		m_Stage;	// �X�e�[�W

	unsigned int texture[2];
	int	m_StageCount;
	
	///	<summry>
	/// Init()�̃w���p�[�֐�
	/// </summary>
	void LoadTexture();	// �e�N�X�`���̃��[�h
	void InitObject(int Stage);	// �I�u�W�F�N�g�̏�����
	void InitStage_2(); // �X�e�[�W�Q
	void InitStage_3(); // �X�e�[�W�R

	///	<summary>
	///	Update()�̃w���p�[�֐�
	/// </summary>
	void UpdateObject(); //	�I�u�W�F�N�g�̍X�V����
	void GoalEnd();

	/// <summary>
	///�@Draw()�̃w���p�[�֐�
	/// </summary>
	void DrawObject(); // �I�u�W�F�N�g�̕`�揈��

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

