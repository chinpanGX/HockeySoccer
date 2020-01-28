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

bool LineCollision()
{
	//	�I�u�W�F�N�g�|�C���^
	Player* p_Player = ObjectManager::GetPlayer();
	Line* p_Line[4];
	p_Line[0] = ObjectManager::GetLine(0);
	p_Line[1] = ObjectManager::GetLine(1);
	p_Line[2] = ObjectManager::GetLine(2);
	p_Line[3] = ObjectManager::GetLine(3);
	//	Player��Line�̏Փ˔���
	if (Hit(p_Player->GetCollision(), p_Line[0]->GetCollision()))
	{
		return true;
	}
	if (Hit(p_Player->GetCollision(), p_Line[1]->GetCollision()))
	{
		return true;
	}
	if (Hit(p_Player->GetCollision(), p_Line[2]->GetCollision()))
	{
		return true;
	}
	if (Hit(p_Player->GetCollision(), p_Line[3]->GetCollision()))
	{
		return true;
	}

	return false;
}
