/*==========================================================

	[Collision.h]
	Author : 出合翔太

===========================================================*/
#pragma once
#include "main.h"

struct Circle2d
{
	float cx, cy; // 中心座標
	float radian; // 半径
};

struct AABB2d
{
	float cx, cy; // 中心座標
	float sx, sy; // 短径サイズ
};

struct Circle3d
{
	float cx, cy, cz; // 中心座標
	float radian;	  // 半径
};

struct AABB3d
{
	float cx, cy, cz; // 中心座標
	float sx, sy, sz; // 短形サイズ
};

bool Hit(const Circle2d* pObject_A, const Circle2d* pObject_B);	 // 2Dサークルコリジョン
bool Hit(const AABB2d* pOject_A, const AABB2d* pObject_B);		 //	2DAABBコリジョン
bool Hit(const Circle3d* pObject_A, const Circle3d* pObject_B);	 // 3Dサークルコリジョン	
bool Hit(const AABB3d* pObject_A, const AABB3d* pObject_B);		 //	3DAABBコリジョン