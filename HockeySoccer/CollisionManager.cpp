/*=========================================================

	[CollisionManager.cpp]
	Author : �o���đ�

==========================================================*/

#include "CollisionManager.h"
#include "ObjectManager.h"
#include "SceneGame.h"

// �v���g�^�C�v�錾

void UpdateCollision()
{

}

bool Collision_Player_vs_Line()
{
	bool hit = false;

	//	�I�u�W�F�N�g�|�C���^
	Player* p_Player = ObjectManager::GetPlayer();
	Topline* p_Topline = ObjectManager::GetTopLine();
	Underline* p_Underline = ObjectManager::GetUnderLine();

	//	Player��Line�̏Փ˔���
	if (Hit(p_Player->GetCollision(), p_Topline->GetCollision()))
	{
		hit = true;
	}

	if (Hit(p_Player->GetCollision(), p_Underline->GetCollision()))
	{
		hit = true;
	}
	return hit;
}

bool Collision_Ball_vs_Line()
{
	bool hit = false;
	Ball* p_Ball = ObjectManager::GetBall();
	return hit;
}
