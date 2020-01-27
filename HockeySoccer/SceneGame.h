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
#include "LineManager.h"

//#	SceneGame�N���X:���ۃN���X,SceneBase���p�������q�N���X
class SceneGame : public SceneBase
{
private:
	Background	m_Bg;		// �Q�[���w�i
	LineManager m_LineMgr;	// ���C���̃R���W����
	Player		m_Player;	// �v���C���[
	Ball		m_Ball;		// �{�[��
	
	bool EndCheck(); // �Q�[���I���`�F�b�N

public:
	void Init()override;	
	void Uninit()override;
	void Update()override;
	void Draw()override;
	// Getter
	LineManager* GetLineMgr();
	Player* GetPlayer();
	Ball* GetBall();
};
