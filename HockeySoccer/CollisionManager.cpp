/*=========================================================

	[CollisionManager.cpp]
	Author : 出合翔太

==========================================================*/

#include "CollisionManager.h"
#include "ObjectManager.h"
#include "SceneGame.h"

// プロトタイプ宣言

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
