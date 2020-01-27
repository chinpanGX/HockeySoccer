/*========================================================

	[Collsion.cpp]
	Author : 出合翔太

========================================================*/

#include "Collision.h"

bool Hit(const Circle2d * pObject_A, const Circle2d * pObject_B)
{
	//引数からベクトル型の変数を作る
	D3DXVECTOR2 dst1(pObject_A->cx, pObject_A->cy);
	D3DXVECTOR2 dst2(pObject_B->cx, pObject_B->cy);
	//二点間のベクトルを作る
	D3DXVECTOR2 distance = dst2 - dst1;
	//作ったベクトルの長さを求める
	float length = D3DXVec2Length(&distance);
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

bool Hit(const AABB2d * pObject_A, const AABB2d * pObject_B)
{
	D3DXVECTOR2 minA, minB;	//	最小点
	D3DXVECTOR2 maxA, maxB;	//	最大点

	//	Aのbox最小点
	minA.x = pObject_A->cx - pObject_A->sx;
	minA.y = pObject_A->cy - pObject_A->sy;

	//	Aのbox最大点
	maxA.x = pObject_A->cx + pObject_A->sx;
	maxA.y = pObject_A->cy + pObject_A->sy;

	//	Bのbox最小点
	minB.x = pObject_B->cx - pObject_B->sx;
	minB.y = pObject_B->cy - pObject_B->sy;

	//	Bのbox最大点 
	maxB.x = pObject_B->cx + pObject_B->sx;
	maxB.y = pObject_B->cy + pObject_B->sy;
	//	X軸の比較
	if (maxA.x > minB.x && minA.x < maxB.x)
	{
		//	Y軸の比較
		if (maxA.y > minB.y && minA.y < maxB.y)
		{
			return true;
		}
	}
	return false;
}

bool Hit(const Circle3d * pObject_A, const Circle3d * pObject_B)
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

bool Hit(const AABB3d * pObject_A, const AABB3d * pObject_B)
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
				return true;
			}
		}
	}
	return false;
} 
