/*=====================================================

	[Effect_Explosion.h]
	Author : �o���đ�

======================================================*/

#pragma once
#include "Effect.h"

class Explosion : public Effect
{
public:
	void Init();
	void Update();
	void Draw(LPDIRECT3DTEXTURE9 Texture);
};

