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

void LineCollision()
{
	Player* p_Player = ObjectManager::GetPlayer();
	Line* p_Line[4];
	for (int nCntLine = 0; nCntLine < 4; nCntLine++)
	{
		p_Line[nCntLine] = ObjectManager::GetLine(nCntLine);
		p_Line[nCntLine]->GetCollision();
	}
}
