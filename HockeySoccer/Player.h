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
	Texture m_Texture;
	unsigned int m_Playertexture;
	AABB2d m_aabb;			 // AABB�R���W����
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	AABB2d* GetCollision();
private:
	// Update()�̃w���p�[�֐�
	void Action();		//	���͂̏���
	void Move();		//	�ړ��̍X�V����
	void Collision();	//	�Փ˔���

	//	�R���W�����̃w���p�[�֐�
	bool HitLine(const AABB2d* p_Object);
};

