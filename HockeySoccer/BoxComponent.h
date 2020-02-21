/*================================================

	[Component.h]
	Author : �o���đ�

================================================*/	

#pragma once
#include "Collision.h"

struct Component2D
{
	Point m_Point[4];
	AABB2d m_aabb;
	Circle2d m_circle;
	AABB2d * GetAABB()
	{
		return &m_aabb;
	}
	Circle2d * GetCircle()
	{
		return &m_circle;
	}
	Point * GetPoint(int point)
	{
		return &m_Point[point];
	}
};
