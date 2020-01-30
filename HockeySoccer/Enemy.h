/*=========================================================

	[Enemy.h]
	Author : o‡ãÄ‘¾

==========================================================*/

#pragma once
#include "Player.h"

class Enemy : public Player
{
private:
	AABB2d	m_aabb;

	// Update()‚Ìƒwƒ‹ƒp[ŠÖ”
	void Move();
	void Collision();

public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
	AABB2d* GetCollision();
};

