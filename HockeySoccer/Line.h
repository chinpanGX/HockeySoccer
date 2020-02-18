/*=======================================================

	[ Line.h]
	Author : 出合翔太

========================================================*/

#pragma once
#include "BoxComponent.h"

class Line
{
public:
	virtual void SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y) = 0;
};

//	上のライン
class Topline : public Line
{
private:
	Component2D m_Component;
public:
	void SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y);
	Component2D* GetCollision();
};

//	下のライン
class Underline : public Line
{
private:
	Component2D m_Component;
public:
	void SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y);
	Component2D* GetCollision();
};

//	左のライン
class Leftline : public Line
{
private:
	Component2D m_Component;
public:
	void SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y);
	Component2D* GetCollision();
};

//	右のライン
class Rightline : public Line
{
private:
	Component2D m_Component;
public:
	void SetLine(D3DXVECTOR2 Position, float Size_x, float Size_y);
	Component2D* GetCollision();
};