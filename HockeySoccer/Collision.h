/*==========================================================

	[Collision.h]
	Author : �o���đ�

===========================================================*/
#pragma once
#include "main.h"

struct Circle
{
	float cx, cy, cz;	//	���S���W
	float radian;		//	���W
	static bool Hit(const Circle* pObject_A, const Circle* pObject_B);
};

struct AABB
{
	float cx, cy, cz;	//	���S���W
	float sx, sy, sz;	//	�Z�`�T�C�Y
	static bool Hit(const AABB* pObject_A, const AABB* pObject_B);
};

struct Collision
{
	bool HitMapPlayer();	//	�v���C���[�ƃ}�b�v�̓����蔻��
	bool HitMapBullet();
};