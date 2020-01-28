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

bool Collision_Player_vs_Line()
{
	bool hit = false;

	//	オブジェクトポインタ
	Player* p_Player = ObjectManager::GetPlayer();
	Topline* p_Topline = ObjectManager::GetTopLine();
	Underline* p_Underline = ObjectManager::GetUnderLine();

	//	PlayerとLineの衝突判定
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
