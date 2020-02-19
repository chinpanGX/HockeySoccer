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
};

class Effect : public Object
{
private:
	Texture m_Texture;
	unsigned int m_Effecttexture;
	D3DXVECTOR2 m_Position;
	bool m_Use;
	int m_Frame;
	float FrameSize;
	int AnimeMax;
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
	void Draw();
	void Set(float x,float y);
};

