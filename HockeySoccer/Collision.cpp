/*========================================================

	[Collsion.cpp]
	Author : �o���đ�

========================================================*/

#include "Collision.h"
#include "MapManager.h"
#include "ObjectManager.h"

bool Circle::Hit(const Circle * pObject_A, const Circle * pObject_B)
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

bool AABB::Hit(const AABB * pObject_A, const AABB * pObject_B)
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
	Wall *pWall;	//	Z�v���X��
	Wall2 *pWall2;	//	Z�}�C�i�X��
	Wall3 *pWall3;	//	X�}�C�i�X��
	Wall4 *pWall4;	//	X�v���X��
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
	//	�ǂ̓����蔻��
	bool hit = false;
	Bullet* pBullet = ObjectManager::GetBullet();
	pBullet = pBullet->GetBullet();
	Wall *pWall;	//	Z�v���X��
	Wall2 *pWall2;	//	Z�}�C�i�X��
	Wall3 *pWall3;	//	X�}�C�i�X��
	Wall4 *pWall4;	//	X�v���X��
	pWall = ObjectManager::GetWall();
	pWall2 = ObjectManager::GetWall2();
	pWall3 = ObjectManager::GetWall3();
	pWall4 = ObjectManager::GetWall4();
	for (int nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		// �e�͗L�����H
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
