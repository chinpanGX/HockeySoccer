/*=======================================================

	[ Line.h]
	Author : �o���đ�

========================================================*/

#pragma once
#include "BoxComponent.h"

class Line
{
public:
	virtual void SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y) = 0;
};

//	��̃��C��
class Topline : public Line
{
private:
	Component2D m_Component;
public:
	void SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y);
	Component2D* GetCollision();
};

//	���̃��C��
class Underline : public Line
{
private:
	Component2D m_Component;
public:
	void SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y);
	Component2D* GetCollision();
};

//	���̃��C��
class Leftline : public Line
{
private:
	Component2D m_Component;
public:
	void SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y);
	Component2D* GetCollision();
};

//	�E�̃��C��
class Rightline : public Line
{
private:
	Component2D m_Component;
public:
	void SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y);
	Component2D* GetCollision();
};