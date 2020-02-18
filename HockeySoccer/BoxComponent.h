/*================================================

	[Component.h]
	Author : �o���đ�

================================================*/	

#pragma once
#include "Collision.h"

struct Component2D
{
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
};

struct Component3D
{
	AABB3d m_aabb;
	Circle3d m_circle;
	AABB3d * GetAABB()
	{
		return &m_aabb;
	}
	Circle3d * GetCircle()
	{
		return &m_circle;
	}
};
