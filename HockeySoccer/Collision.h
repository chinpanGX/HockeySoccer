/*==========================================================

	[Collision.h]
	Author : 出合翔太

===========================================================*/
#pragma once
#include "main.h"
#include "math.h"

// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//		コリジョン構造体と当たり判定処理のテンプレート
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■

// 2D線分
struct Line2d
{
	float px, py;
};

// 3D線分
struct Line3d
{
	float sx, sy,sz; // 始点ベクトル
	float ex, ey,ez; // 終点ベクトル
};

//	2Dサークル
struct Circle2d
{
	float cx, cy; // 中心座標
	float radian; // 半径
};

//	3Dサークル
struct Circle3d
{
	float cx, cy, cz; // 中心座標
	float radian;	  // 半径
};

//	2DAABB
struct AABB2d
{
	float cx, cy; // 中心座標
	float sx, sy; // 短径サイズ
};

//	3DAABB
struct AABB3d
{
	float cx, cy, cz; // 中心座標
	float sx, sy, sz; // 短形サイズ
};

template <class Type>
bool Intercept(const Circle2d Collision,const Type* start, const Type* end)
{
	// ベクトルをつくる
	D3DXVECTOR2 startcenter = D3DXVECTOR2(Collision.cx - start->px, Collision.cy - start->py);
	D3DXVECTOR2 endcenter = D3DXVECTOR2(Collision.cx - end->px, Collision.cy - end->py);
	D3DXVECTOR2 startend = D3DXVECTOR2(end->px - start->px, end->py - start->py);
	D3DXVECTOR2 normal;
	// 単位ベクトル化
	D3DXVec2Normalize(&normal, &startend);
	// 始点と円の中心で外積を行う
	float distance = startcenter.x * normal.y - normal.x * startcenter.y;
	// 射影の長さが半径よりも小さい
	if (fabs(distance) < Collision.radian)
	{
		// 始点=>終点と始点=>円の中心の内積を計算
		float dot1 = startcenter.x * startend.x + startcenter.y * startend.y;
		// 始点=>終点と始点=>円の中心の内積を計算
		float dot2 = endcenter.x * startend.x + endcenter.y * startend.y;
		// 内積の積の結果が結果が0以下なら
		if (dot1 * dot2 <= 0.0f)
		{
			return true;
		}
		//	線分上にないとき、始点=>円の中心の長さor終点=>円の中心の長さが円の半径より短い
		else if (D3DXVec2Length(&startcenter) < Collision.radian || D3DXVec2Length(&endcenter) < Collision.radian)
		{
			return true;
		}
	}
	return false;
}

//	2Dサークルコリジョン
template <class Type> 
bool Circle_2d(const Type Collision, const Type *p_Collision)
{
	//引数からベクトル型の変数を作る
	D3DXVECTOR2 dst1(Collision.cx, Collision.cy);
	D3DXVECTOR2 dst2(p_Collision->cx, p_Collision->cy);
	//二点間のベクトルを作る
	D3DXVECTOR2 distance = dst2 - dst1;
	//作ったベクトルの長さを求める
	float length = D3DXVec2Length(&distance);
	//お互いの半径を足した値を求める
	float size = Collision.radian + p_Collision->radian;

	//ベクトルの長さとお互いの半径を足した値を比較する → ベクトルの長さの方が小さければヒット
	if (length < size)
	{
		return true;
	}
	//ヒットしていなかった
	return false;
}

//	3Dサークルコリジョン
template <class Type>
bool Circle_3d(const Type Collision, const Type * p_Collision)
{
	//引数からベクトル型の変数を作る
	D3DXVECTOR3 dst1(Collision.cx, Collision.cy, Collision.cz);
	D3DXVECTOR3 dst2(p_Collision->cx, p_Collision->cy, p_Collision->cz);
	//二点間のベクトルを作る
	D3DXVECTOR3 distance = dst2 - dst1;
	//作ったベクトルの長さを求める
	float length = D3DXVec3Length(&distance);
	//お互いの半径を足した値を求める
	float size = Collision.radian + p_Collision->radian;

	//ベクトルの長さとお互いの半径を足した値を比較する → ベクトルの長さの方が小さければヒット
	if (length < size)
	{
		return true;
	}
	//ヒットしていなかった
	return false;
}

// AABB2Dコリジョン
template <class Type>
bool AABB_2d(const Type Collision, const Type * p_Collision)
{
	D3DXVECTOR2 minA, minB;	//	最小点
	D3DXVECTOR2 maxA, maxB;	//	最大点

	//	Aのbox最小点
	minA.x = Collision.cx - Collision.sx;
	minA.y = Collision.cy - Collision.sy;

	//	Aのbox最大点
	maxA.x = Collision.cx + Collision.sx;
	maxA.y = Collision.cy + Collision.sy;

	//	Bのbox最小点
	minB.x = p_Collision->cx - p_Collision->sx;
	minB.y = p_Collision->cy - p_Collision->sy;

	//	Bのbox最大点 
	maxB.x = p_Collision->cx + p_Collision->sx;
	maxB.y = p_Collision->cy + p_Collision->sy;
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

// AABB3Dコリジョン
template <class Type>
bool AABB_3d(const Type Collision, const Type * p_Collision)
{
	D3DXVECTOR3 minA, minB;	//	最小点
	D3DXVECTOR3 maxA, maxB;	//	最大点

	//	Aのbox最小点
	minA.x = Collision->cx - Collision->sx;
	minA.y = Collision->cy - Collision->sy;
	minA.z = Collision->cz - Collision->sz;

	//	Aのbox最大点
	maxA.x = Collision->cx + Collision->sx;
	maxA.y = Collision->cy + Collision->sy;
	maxA.z = Collision->cz + Collision->sz;

	//	Bのbox最小点
	minB.x = p_Collision->cx - p_Collision->sx;
	minB.y = p_Collision->cy - p_Collision->sy;
	minB.z = p_Collision->cz - p_Collision->sz;

	//	Bのbox最大点 
	maxB.x = p_Collision->cx + p_Collision->sx;
	maxB.y = p_Collision->cy + p_Collision->sy;
	maxB.z = p_Collision->cz + p_Collision->sz;

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
