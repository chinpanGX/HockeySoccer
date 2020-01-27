/*==================================

	[SceneGame.h]
	Author : �o���đ�

===================================*/

#pragma once
#include "main.h"
#include "SceneBase.h"
#include "Background.h"
#include "Player.h"
#include "Ball.h"

//#	SceneGame�N���X:���ۃN���X,SceneBase���p�������q�N���X
class SceneGame : public SceneBase
{
private:
	Background	m_Bg;		//	�Q�[���w�i
	Player		m_Player;	//	�v���C���[
	Ball		m_Ball;		//	�{�[��

	bool EndCheck();

public:
	void Init()override;	//	�Q�[���̏���������	
	void Uninit()override;	//	�Q�[���̏I������
	void Update()override;	//	�Q�[���̍X�V����
	void Draw()override;	//	�Q�[���̕`�揈��
};
