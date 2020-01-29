/*==============================================

	[Goal.h]
	Author : �o���đ�

===============================================*/

#pragma once
#include "Player.h"
#include "Collision.h"

class Goal : public Actor
{
private:
	AABB2d m_aabb;
public:
	void Init();
	void Uninit();
	void Update();
	void Draw(LPDIRECT3DTEXTURE9 Texture);
};

