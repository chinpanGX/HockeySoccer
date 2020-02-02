/*=========================================================

	[StageEditor.h]
	�T�v �F �X�e�[�W�G�f�B�^
	Author : �o���đ�

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
	GameBG		m_Bg;		// �X�e�[�W�N���A�w�i
	UI			m_Ui;		// UI

	unsigned int texture[3]; // �e�N�X�`�����i�[
	int	m_StageCount;		 // �X�e�[�W���J�E���g
	float m_FramePosition;	 // �g�̈ʒu
	bool m_NextSelect;		 //	�I���t���O(true->���Afalse->�I��)
			
	///	<summry>
	/// Init()�̃w���p�[�֐�
	/// </summary>
	void LoadTexture();			// �e�N�X�`���̃��[�h
	void InitObject(int Stage);	// �I�u�W�F�N�g�̏�����

	/// <summary>
	/// Uninit()�̃w���p�[�֐�
	/// </summary>
	void UninitObject();

	///	<summary>
	///	Update()�̃w���p�[�֐�
	/// </summary>
	void UpdateObject();	// �I�u�W�F�N�g�̍X�V����
	void EnemyGoalEnd();	// ����S�[���ɓ��ꂽ�Ƃ�	
	void UpdateStageClear();// �X�e�[�W�N���A�̍X�V
	void UpdateFrame();		// �g�̈ʒu�̍X�V

	/// <summary>
	///�@Draw()�̃w���p�[�֐�
	/// </summary>
	void DrawObject();		// �I�u�W�F�N�g�̕`�揈��
	void DrawStageClear();	// �X�e�[�W�N���A�̕`��

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

