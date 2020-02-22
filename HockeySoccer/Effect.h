/*====================================================

	[Effect.h]
	Author : èoçá„ƒëæ

=====================================================*/

#pragma once
#include "Object.h"
#include "Texture.h"

enum EffectNumber
{
	EXPLOSION,
	HITPLAYER,
	GOAL
};

class Effect : public Object
{
protected:
	D3DXVECTOR2 m_Position;
	bool m_Use;
	int m_Frame;
	float FrameSize;
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
	void Set(float x,float y);
};

