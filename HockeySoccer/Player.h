/*=========================================================

	[Player.h]
	�v���C���[���Ǘ�����
	Author : �o���đ�

==========================================================*/

#pragma once
#include "Actor.h"
#include "BoxComponent.h"

enum ColliderType
{
	center,
	up,
	down,
	circle,
};

class Player : public Actor
{
private:
	Component2D m_Component;
	float m_Speed; // �␳�X�s�[�h�l

	// Update()�̃w���p�[�֐�
	void Action();		//	���͂̏���
	void Move();		//	�ړ��̍X�V����
	void Collision();	//	�Փ˔���
public:
	void Init()override;
	void Init(float Speed);	// �␳�X�s�[�h�̕ύX
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
	Component2D* GetCollision();
	D3DXVECTOR2 GetPosition();
	D3DXVECTOR2 GetVector();
};

