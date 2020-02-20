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
	HITPLAYER
};

class Effect : public Object
{
protected:
	D3DXVECTOR2 m_Position;
	bool m_Use;
	int m_Frame;
	float FrameSize;
	int AnimeMax;

	// Draw()ÇÃÉwÉãÉpÅ[ä÷êî
	void EffectDraw(unsigned int texture);

public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
	void Draw();
	void Set(float x,float y);
	bool GetUse();
	int GetFrame();
};

