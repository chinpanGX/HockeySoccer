/*========================================================

	[ClearBG.h]
	Author : �o���đ�

=========================================================*/

#pragma once
#include "Object.h"

class ClearBG : public Object
{
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
};

