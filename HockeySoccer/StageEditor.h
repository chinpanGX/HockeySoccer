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
#include "ClearBG.h"

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
	ClearBG		m_Clear;	// �Q�[���N���A�w�i

	unsigned int texture[3]; // �e�N�X�`�����i�[
	int	m_StageCount;		 // �X�e�[�W���J�E���g
	
	///	<summry>
	/// Init()�̃w���p�[�֐�
	/// </summary>
	void LoadTexture();	// �e�N�X�`���̃��[�h
	void InitObject(int Stage);	// �I�u�W�F�N�g�̏�����

	/// <summary>
	/// Uninit()�̃w���p�[�֐�
	/// </summary>
	void UninitObject();

	///	<summary>
	///	Update()�̃w���p�[�֐�
	/// </summary>
	void UpdateObject(); //	�I�u�W�F�N�g�̍X�V����
	void EnemyGoalEnd();

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
	Goal* GetGoal();
	EnemyGoal* GetEnemyGoal();
	Ball* GetBall();
};

