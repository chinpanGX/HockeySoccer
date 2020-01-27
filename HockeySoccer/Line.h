/*=======================================================

	[TopLine.h]
	Author : èoçá„ƒëæ

========================================================*/

#pragma once
#include "Collision.h"

class Line
{
private:
	AABB2d m_aabb2d;
public:
	void SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y);
	AABB2d* GetCollision();
};

