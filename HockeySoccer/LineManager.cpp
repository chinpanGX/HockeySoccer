/*========================================================

	[LineManager.cpp]
	Author : o‡ãÄ‘¾

=========================================================*/

#include "LineManager.h"

void LineManager::Set()
{
	m_Line[0]->SetLine(D3DXVECTOR2(SCREEN_WIDTH * 0.5f,10.0f),1920.0f,20.0f);
	m_Line[1]->SetLine(D3DXVECTOR2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT - 10.0f), 1920.0f, 20.0f);
	m_Line[2]->SetLine(D3DXVECTOR2(90.0f,SCREEN_WIDTH * 0.5f),20.0f,1080.0f);
	m_Line[3]->SetLine(D3DXVECTOR2(SCREEN_WIDTH - 90.0f, SCREEN_HEIGHT* 0.5), 20.0f, 1080.0f);
}

Line* LineManager::GetLine(int Index)
{
	return m_Line[Index];
}
