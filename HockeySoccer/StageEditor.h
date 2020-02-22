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
#include "Effect_Explosion.h"
#include "Effect_HitPlayer.h"
#include "Effect_Goal.h"

#define ENEMY_MAX 3 

// �X�e�[�W
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
	Stage		m_Stage;			// �X�e�[�W
	Player		m_Player;			// �v���C���[
	Enemy		m_Enemy[ENEMY_MAX];	// �G�l�~�[
	Ball		m_Ball;				// �{�[��
	Goal		m_Goal;				// �S�[��
	EnemyGoal	m_EnemyGoal;		// ���葤�̃S�[��
	GameBG		m_StageBG;			// �X�e�[�W�N���A�w�i
	UI			m_Ui;				// UI
	Explosion	m_E_Ex;				// �����G�t�F�N�g
	HitPlayer	m_E_HitPlayer;		// �q�b�g�G�t�F�N�g

	static const int number = 5; // �e�N�X�`���̐�
	unsigned int texture[number]; // �e�N�X�`�����i�[
	int	m_StageCount;		 // �X�e�[�W���J�E���g
	int m_Frame;			 // �t���[���J�E���g
	float m_FramePosition;	 // �g�̈ʒu
	bool m_NextSelect;		 //	�I���t���O(true->���Afalse->�I��)
	bool m_Retry;			 // ���g���C�I���t���O(true->���g���C����Afalse->���g���C���Ȃ�)
			
	///	<summry>
	/// Init()�̃w���p�[�֐�
	/// </summary>
	void InitObject(int Stage);			// �I�u�W�F�N�g�̏�����
	void InitGoal();					// �S�[���̏�����	

	/// <summary>
	/// Uninit()�̃w���p�[�֐�
	/// </summary>
	void UninitObject();	//	�I�u�W�F�N�g�̏I������

	///	<summary>
	///	Update()�̃w���p�[�֐�
	/// </summary>
	void UpdateObject();				// �I�u�W�F�N�g�̍X�V����
	void UpdateEnemy(int EnemyNum = 1); // �G�l�~�[�̍X�V�i�G�l�~�[�̐��F�f�t�H���g�P�j
	void UpdateStageClear();			// �X�e�[�W�N���A�̍X�V
	void UpdateRetry();					// ���g���C�̍X�V
	void UpdateFrame(bool Flag);		// �g�̈ʒu�̍X�V(�����Ńt���O���w��)
	
	//	UpdateObject�̃w���p�[�֐�
	void EnemyGoalEnd();	// ����S�[���ɓ��ꂽ�Ƃ�
	void GoalEnd();			// ���w�S�[���ɓ������Ƃ�
	void UpdateEffect();	// �G�t�F�N�g�̍X�V����
	void CreateEffect(int number);	// �G�t�F�N�g�Đ�

	/// <summary>
	///�@Draw()�̃w���p�[�֐�
	/// </summary>
	void DrawObject();					// �I�u�W�F�N�g�̕`�揈��
	void DrawEnemy(int EnemyNum = 1);	// �G�l�~�[�̕`��i�G�l�~�[�̐��F�f�t�H���g�P�j
	void DrawStageClear();				// �X�e�[�W�N���A�̕`��
	void DrawRetry();					// ���g���C�̕`��

public:
	void Init();	// ����������
	void Uninit();	// �I������
	void Update();	// �X�V����
	void Draw();	// �`�揈��
	bool GameEnd();	// �Q�[���G���h�`�F�b�N

	//	Getter
	Player* GetPlayer();
	Enemy* GetEnemy();
	Goal* GetGoal();
	EnemyGoal* GetEnemyGoal();
	Ball* GetBall();
};

