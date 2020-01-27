/*========================================================

	[Collsion.cpp]
	Author : �o���đ�

========================================================*/

#include "Collision.h"

bool Hit(const Circle2d * pObject_A, const Circle2d * pObject_B)
{
	//��������x�N�g���^�̕ϐ������
	D3DXVECTOR2 dst1(pObject_A->cx, pObject_A->cy);
	D3DXVECTOR2 dst2(pObject_B->cx, pObject_B->cy);
	//��_�Ԃ̃x�N�g�������
	D3DXVECTOR2 distance = dst2 - dst1;
	//������x�N�g���̒��������߂�
	float length = D3DXVec2Length(&distance);
	//���݂��̔��a�𑫂����l�����߂�
	float size = pObject_A->radian + pObject_B->radian;

	//�x�N�g���̒����Ƃ��݂��̔��a�𑫂����l���r���� �� �x�N�g���̒����̕�����������΃q�b�g
	if (length < size)
	{
		return true;
	}
	//�q�b�g���Ă��Ȃ�����
	return false;
}

bool Hit(const AABB2d * pObject_A, const AABB2d * pObject_B)
{
	D3DXVECTOR2 minA, minB;	//	�ŏ��_
	D3DXVECTOR2 maxA, maxB;	//	�ő�_

	//	A��box�ŏ��_
	minA.x = pObject_A->cx - pObject_A->sx;
	minA.y = pObject_A->cy - pObject_A->sy;

	//	A��box�ő�_
	maxA.x = pObject_A->cx + pObject_A->sx;
	maxA.y = pObject_A->cy + pObject_A->sy;

	//	B��box�ŏ��_
	minB.x = pObject_B->cx - pObject_B->sx;
	minB.y = pObject_B->cy - pObject_B->sy;

	//	B��box�ő�_ 
	maxB.x = pObject_B->cx + pObject_B->sx;
	maxB.y = pObject_B->cy + pObject_B->sy;
	//	X���̔�r
	if (maxA.x > minB.x && minA.x < maxB.x)
	{
		//	Y���̔�r
		if (maxA.y > minB.y && minA.y < maxB.y)
		{
			return true;
		}
	}
	return false;
}

bool Hit(const Circle3d * pObject_A, const Circle3d * pObject_B)
{
	//��������x�N�g���^�̕ϐ������
	D3DXVECTOR3 dst1(pObject_A->cx, pObject_A->cy, pObject_A->cz);
	D3DXVECTOR3 dst2(pObject_B->cx, pObject_B->cy, pObject_B->cz);
	//��_�Ԃ̃x�N�g�������
	D3DXVECTOR3 distance = dst2 - dst1;
	//������x�N�g���̒��������߂�
	float length = D3DXVec3Length(&distance);
	//���݂��̔��a�𑫂����l�����߂�
	float size = pObject_A->radian + pObject_B->radian;

	//�x�N�g���̒����Ƃ��݂��̔��a�𑫂����l���r���� �� �x�N�g���̒����̕�����������΃q�b�g
	if (length < size) 
	{
		return true;
	}
	//�q�b�g���Ă��Ȃ�����
	return false;
}

bool Hit(const AABB3d * pObject_A, const AABB3d * pObject_B)
{
	D3DXVECTOR3 minA, minB;	//	�ŏ��_
	D3DXVECTOR3 maxA, maxB;	//	�ő�_

	//	A��box�ŏ��_
	minA.x = pObject_A->cx - pObject_A->sx;
	minA.y = pObject_A->cy - pObject_A->sy;
	minA.z = pObject_A->cz - pObject_A->sz;

	//	A��box�ő�_
	maxA.x = pObject_A->cx + pObject_A->sx;
	maxA.y = pObject_A->cy + pObject_A->sy;
	maxA.z = pObject_A->cz + pObject_A->sz;

	//	B��box�ŏ��_
	minB.x = pObject_B->cx - pObject_B->sx;
	minB.y = pObject_B->cy - pObject_B->sy;
	minB.z = pObject_B->cz - pObject_B->sz;

	//	B��box�ő�_ 
	maxB.x = pObject_B->cx + pObject_B->sx;
	maxB.y = pObject_B->cy + pObject_B->sy;
	maxB.z = pObject_B->cz + pObject_B->sz;

	//	X���̔�r
	if (maxA.x > minB.x && minA.x < maxB.x)
	{
		//	Y���̔�r
		if (maxA.y > minB.y && minA.y < maxB.y)
		{
			//	Z���̔�r
			if (maxA.z > minB.z && minA.z < maxB.z)
			{
				return true;
			}
		}
	}
	return false;
} 
