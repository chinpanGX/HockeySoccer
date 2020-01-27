/*=========================================================

	[Player.h]
	プレイヤーを管理する
	Author : 出合翔太

==========================================================*/

#pragma once
#include "Actor.h"

class Player : public Actor
{
private:
	Texture m_Texture;
	unsigned int m_Playertexture;
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
};

