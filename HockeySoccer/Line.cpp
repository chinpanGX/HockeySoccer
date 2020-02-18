/*=========================================================

	[Line.h]
	Author : èoçá„ƒëæ

==========================================================*/

#include "Line.h"

void Topline::SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y)
{
	m_Component.m_aabb.cx = Position.x;
	m_Component.m_aabb.cy = Position.y;
	m_Component.m_aabb.sx = Size_x;
	m_Component.m_aabb.sy = Size_y;
}

Component2D * Topline::GetCollision()
{
	return &m_Component;
}

void Underline::SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y)
{
	m_Component.m_aabb.cx = Position.x;
	m_Component.m_aabb.cy = Position.y;
	m_Component.m_aabb.sx = Size_x;
	m_Component.m_aabb.sy = Size_y;
}

Component2D * Underline::GetCollision()
{
	return &m_Component;
}

void Leftline::SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y)
{
	m_Component.m_aabb.cx = Position.x;
	m_Component.m_aabb.cy = Position.y;
	m_Component.m_aabb.sx = Size_x;
	m_Component.m_aabb.sy = Size_y;
}

Component2D * Leftline::GetCollision()
{
	return &m_Component;
}

void Rightline::SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y)
{
	m_Component.m_aabb.cx = Position.x;
	m_Component.m_aabb.cy = Position.y;
	m_Component.m_aabb.sx = Size_x;
	m_Component.m_aabb.sy = Size_y;
}

Component2D * Rightline::GetCollision()
{
	return &m_Component;
}
