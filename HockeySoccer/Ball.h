/*========================================================

	[Ball.h]
	Author : èoçá „ƒëæ

========================================================*/

#pragma once
#include "Actor.h"

class Ball : public Actor
{
private:
	Texture m_Texture;
	unsigned int m_Balltexture;
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
};
