/*========================================================

	[Collsion.cpp]
	Author : 出合翔太

========================================================*/

#include "Collision.h"
#include "MapManager.h"
#include "ObjectManager.h"

bool Circle::Hit(const Circle * pObject_A, const Circle * pObject_B)
{
	//引数からベクトル型の変数を作る
	D3DXVECTOR3 dst1(pObject_A->cx, pObject_A->cy, pObject_A->cz);
	D3DXVECTOR3 dst2(pObject_B->cx, pObject_B->cy, pObject_B->cz);
	//二点間のベクトルを作る
	D3DXVECTOR3 distance = dst2 - dst1;
	//作ったベクトルの長さを求める
	float length = D3DXVec3Length(&distance);
	//お互いの半径を足した値を求める
	float size = pObject_A->radian + pObject_B->radian;

	//ベクトルの長さとお互いの半径を足した値を比較する → ベクトルの長さの方が小さければヒット
	if (length < size) 
	{
		return true;
	}
	//ヒットしていなかった
	return false;
}

bool AABB::Hit(const AABB * pObject_A, const AABB * pObject_B)
{
	D3DXVECTOR3 minA, minB;	//	最小点
	D3DXVECTOR3 maxA, maxB;	//	最大点

	//	Aのbox最小点
	minA.x = pObject_A->cx - pObject_A->sx;
	minA.y = pObject_A->cy - pObject_A->sy;
	minA.z = pObject_A->cz - pObject_A->sz;

	//	Aのbox最大点
	maxA.x = pObject_A->cx + pObject_A->sx;
	maxA.y = pObject_A->cy + pObject_A->sy;
	maxA.z = pObject_A->cz + pObject_A->sz;

	//	Bのbox最小点
	minB.x = pObject_B->cx - pObject_B->sx;
	minB.y = pObject_B->cy - pObject_B->sy;
	minB.z = pObject_B->cz - pObject_B->sz;

	//	Bのbox最大点 
	maxB.x = pObject_B->cx + pObject_B->sx;
	maxB.y = pObject_B->cy + pObject_B->sy;
	maxB.z = pObject_B->cz + pObject_B->sz;

	//	X軸の比較
	if (maxA.x > minB.x && minA.x < maxB.x)
	{
		//	Y軸の比較
		if (maxA.y > minB.y && minA.y < maxB.y)
		{
			//	Z軸の比較
			if (maxA.z > minB.z && minA.z < maxB.z)
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}

bool Collision::HitMapPlayer()
{
	bool hit = false;
	Player *pPlayer;
	pPlayer = ObjectManager::GetPlayer();
	Wall *pWall;	//	Zプラス壁
	Wall2 *pWall2;	//	Zマイナス壁
	Wall3 *pWall3;	//	Xマイナス壁
	Wall4 *pWall4;	//	Xプラス壁
	pWall = ObjectManager::GetWall();
	pWall2 = ObjectManager::GetWall2();
	pWall3 = ObjectManager::GetWall3();
	pWall4 = ObjectManager::GetWall4();

	if (AABB::Hit(pPlayer->GetCollision(), pWall->GetCollision()))
	{
		hit = true;
	}
	if (AABB::Hit(pPlayer->GetCollision(), pWall2->GetCollision()))
	{
		hit = true;
	}
	if (AABB::Hit(pPlayer->GetCollision(), pWall3->GetCollision()))
	{
		hit = true;
	}
	if (AABB::Hit(pPlayer->GetCollision(), pWall4->GetCollision()))
	{
		hit = true;
	}

	return hit;
}

bool Collision::HitMapBullet()
{
	//	壁の当たり判定
	bool hit = false;
	Bullet* pBullet = ObjectManager::GetBullet();
	pBullet = pBullet->GetBullet();
	Wall *pWall;	//	Zプラス壁
	Wall2 *pWall2;	//	Zマイナス壁
	Wall3 *pWall3;	//	Xマイナス壁
	Wall4 *pWall4;	//	Xプラス壁
	pWall = ObjectManager::GetWall();
	pWall2 = ObjectManager::GetWall2();
	pWall3 = ObjectManager::GetWall3();
	pWall4 = ObjectManager::GetWall4();
	for (int nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		// 弾は有効か？
		if (pBullet->IsEnable(nCntBullet) == false)
		{
			continue;
		}

		if (AABB::Hit(pBullet->GetAABB(nCntBullet), pWall->GetCollision()))
		{
			hit = true;
			break;
		}
		else if (AABB::Hit(pBullet->GetAABB(nCntBullet), pWall2->GetCollision()))
		{
			hit = true;
			break;
		}
		else if (AABB::Hit(pBullet->GetAABB(nCntBullet), pWall3->GetCollision()))
		{
			hit = true;
			break;
		}
		else if (AABB::Hit(pBullet->GetAABB(nCntBullet), pWall4->GetCollision()))
		{
			hit = true;
			break;
		}
	}
	return hit;
}
