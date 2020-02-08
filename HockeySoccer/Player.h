/*=========================================================

	[Player.h]
	プレイヤーを管理する
	Author : 出合翔太

==========================================================*/

#pragma once
#include "Actor.h"
#include "Collision.h "

enum Collision
{
	Up,
	Center,
	Down
};

class Player : public Actor
{
private:
	AABB2d m_aabb[3]; // AABBコリジョン
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
	AABB2d* GetCollision(int i);
	D3DXVECTOR2 GetPosition();
};

