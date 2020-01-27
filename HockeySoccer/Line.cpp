/*=========================================================

	[Line.h]
	Author : èoçá„ƒëæ

==========================================================*/

#include "Line.h"

void Line::SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y)
{
	m_aabb2d.cx = Position.x;
	m_aabb2d.cy = Position.y;
	m_aabb2d.sx = Size_x;
	m_aabb2d.sy = Size_y;
}

AABB2d * Line::GetCollision()
{
	return &m_aabb2d;
}
