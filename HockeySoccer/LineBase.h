/*=========================================================

	[LineBase.h]
	Author : èoçá„ƒëæ 

==========================================================*/

#pragma once
#include "main.h"
#include "Collision.h"

class LineBase
{
protected:
	D3DXVECTOR2 m_Position;
	AABB2d m_aabb2d;
public:
	virtual void SetLine() = 0;
};

