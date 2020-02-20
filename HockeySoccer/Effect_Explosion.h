/*=====================================================

	[Effect_Explosion.h]
	Author : èoçá„ƒëæ

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

