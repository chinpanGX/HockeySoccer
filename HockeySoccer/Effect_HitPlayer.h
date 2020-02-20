/*====================================================

	[Effect_HitPlayer.h]
	Author : èoçá„ƒëæ

=====================================================*/

#pragma once
#include "Effect.h"

class HitPlayer : public Effect
{
public:
	void Init();
	void Update();
	void Draw(LPDIRECT3DTEXTURE9 Texture);
};

