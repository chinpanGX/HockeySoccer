/*==========================================================

	[Collision.h]
	Author : 出合翔太

===========================================================*/
#pragma once
#include "main.h"

struct Circle
{
	float cx, cy, cz;	//	中心座標
	float radian;		//	座標
	static bool Hit(const Circle* pObject_A, const Circle* pObject_B);
};

struct AABB
{
	float cx, cy, cz;	//	中心座標
	float sx, sy, sz;	//	短形サイズ
	static bool Hit(const AABB* pObject_A, const AABB* pObject_B);
};

struct Collision
{
	bool HitMapPlayer();	//	プレイヤーとマップの当たり判定
	bool HitMapBullet();
};