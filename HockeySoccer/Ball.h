/*========================================================

	[Ball.h]
	Author : �o�� �đ�

========================================================*/

#pragma once
#include "Actor.h"
#include "Collision.h"

class Ball : public Actor
{
private:
	AABB2d m_aabb;

	// Update()�̃w���p�[�֐�
	void PlayerCollision();
	void EnemyCollision();
	void LineCollsion();

public:
	void Init()override;
	void Init(D3DXVECTOR2 Velocity);
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
	AABB2d* GetCollision();
	bool GetGameEnd();
};
