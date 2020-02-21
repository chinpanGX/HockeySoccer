/*=========================================================

	[Player.h]
	プレイヤーを管理する
	Author : 出合翔太

==========================================================*/

#pragma once
#include "Actor.h"
#include "BoxComponent.h"

enum ColliderType
{
	center,
	up,
	down,
	circle,
};

class Player : public Actor
{
private:
	Component2D m_Component;
	float m_Speed; // 補正スピード値

	// Update()のヘルパー関数
	void Action();		//	入力の処理
	void Move();		//	移動の更新処理
	void Collision();	//	衝突判定
public:
	void Init()override;
	void Init(float Speed);	// 補正スピードの変更
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
	Component2D* GetCollision();
	D3DXVECTOR2 GetPosition();
	D3DXVECTOR2 GetVector();
};

