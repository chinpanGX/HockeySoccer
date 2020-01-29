/*==========================================================

	[Collision.h]
	Author : �o���đ�

===========================================================*/
#pragma once
#include "main.h"

struct Circle2d
{
	float cx, cy; // ���S���W
	float radian; // ���a
};

struct AABB2d
{
	float cx, cy; // ���S���W
	float sx, sy; // �Z�a�T�C�Y
};

struct Circle3d
{
	float cx, cy, cz; // ���S���W
	float radian;	  // ���a
};

struct AABB3d
{
	float cx, cy, cz; // ���S���W
	float sx, sy, sz; // �Z�`�T�C�Y
};

bool Hit(const Circle2d* pObject_A, const Circle2d* pObject_B);	 // 2D�T�[�N���R���W����
bool Hit(const AABB2d* pOject_A, const AABB2d* pObject_B);		 //	2DAABB�R���W����
bool Hit(const Circle3d* pObject_A, const Circle3d* pObject_B);	 // 3D�T�[�N���R���W����	
bool Hit(const AABB3d* pObject_A, const AABB3d* pObject_B);		 //	3DAABB�R���W����