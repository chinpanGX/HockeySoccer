/*=========================================================

	[Player.h]
	�v���C���[���Ǘ�����
	Author : �o���đ�

==========================================================*/

#pragma once
#include "Actor.h"
#include "Collision.h "

class Player : public Actor
{
private:
	AABB2d m_aabb;			 // AABB�R���W����
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
	AABB2d* GetCollision();
	D3DXVECTOR2 GetPosition();
private:
	// Update()�̃w���p�[�֐�
	void Action();		//	���͂̏���
	void Move();		//	�ړ��̍X�V����
	void Collision();	//	�Փ˔���
};

