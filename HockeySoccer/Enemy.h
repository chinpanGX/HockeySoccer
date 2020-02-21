/*=========================================================

	[Enemy.h]
	Author : �o���đ�

==========================================================*/

#pragma once
#include "Player.h"
#include "BoxComponent.h"

class Enemy : public Player
{
private:
	Component2D m_Component;

	// Update()�̃w���p�[�֐�
	void Move();
	void Collision();

public:
	void Init()override;
	void Init(float Speed,D3DXVECTOR2 Position = D3DXVECTOR2((480.0f * 3) - 32.0f, 540.0f)); //	Y���̈ړ��X�s�[�h,�����ʒu�̕ύX
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
	Component2D * GetCollision();
	D3DXVECTOR2 GetVector();
};

