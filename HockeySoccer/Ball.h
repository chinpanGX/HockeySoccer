/*========================================================

	[Ball.h]
	Author : o‡ ãÄ‘¾

========================================================*/

#pragma once
#include "Actor.h"
#include "Collision.h"

class Ball : public Actor
{
private:
	AABB2d m_aabb;

	// Update()‚Ìƒwƒ‹ƒp[ŠÖ”
	void Collision();

public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
	AABB2d* GetCollision();
};
