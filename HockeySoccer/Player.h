/*=========================================================

	[Player.h]
	�v���C���[���Ǘ�����
	Author : �o���đ�

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

