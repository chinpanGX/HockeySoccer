/*=========================================================

	[Enemy.h]
	Author : 出合翔太

==========================================================*/

#pragma once
#include "Player.h"
#include "BoxComponent.h"

class Enemy : public Player
{
private:
	Component2D m_Component;

	// Update()のヘルパー関数
	void Move();
	void Collision();

public:
	void Init()override;
	void Init(float Speed,D3DXVECTOR2 Position = D3DXVECTOR2((480.0f * 3) - 32.0f, 540.0f)); //	Y軸の移動スピード,初期位置の変更
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
	Component2D * GetCollision();
	D3DXVECTOR2 GetVector();
};

