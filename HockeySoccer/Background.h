/*=========================================================
	
	[Background.h]
	ƒQ[ƒ€”wŒi‚ğ•`‰æ
	Author : o‡ ãÄ‘¾

==========================================================*/

#pragma once
#include "Object.h"
class Background : public Object
{
private:
	Texture m_Texture;
	unsigned int m_Bgtexture;
public:
	void Init();
	void Uninit();
	void Draw();
};

