/*=========================================================

	[EnemyGoal.h]
	Author : �o���đ�

==========================================================*/

#pragma once
#include "Actor.h"
#include "BoxComponent.h"

class EnemyGoal : public Actor
{
private:
	Component2D m_Component;
public:
	void Init()override;
	void Init(float Speed);
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
	Component2D* GetCollision();
};

