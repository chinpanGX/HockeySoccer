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

bool LineCollision()
{
	//	オブジェクトポインタ
	Player* p_Player = ObjectManager::GetPlayer();
	Line* p_Line[4];
	p_Line[0] = ObjectManager::GetLine(0);
	p_Line[1] = ObjectManager::GetLine(1);
	p_Line[2] = ObjectManager::GetLine(2);
	p_Line[3] = ObjectManager::GetLine(3);
	//	PlayerとLineの衝突判定
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
