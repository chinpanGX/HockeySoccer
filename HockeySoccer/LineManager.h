/*========================================================

	[LineManager.h]
	Author : �o���đ�

=========================================================*/

#pragma once
#include "Line.h"

class LineManager
{
private:
	Line *m_Line[4];
public:
	void  Set();
	Line* GetLine(int Index);
};

