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
	Texture m_Texture;
	unsigned int m_Balltexture;
	AABB2d m_aabb;
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	AABB2d* GetCollision();
private:
	// ƒwƒ‹ƒp[ŠÖ”
	void Collision();
	bool HitLine(const AABB2d * pObject);
};
