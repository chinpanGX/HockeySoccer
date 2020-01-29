/*=========================================================

	[Player.h]
	プレイヤーを管理する
	Author : 出合翔太

==========================================================*/

#pragma once
#include "Actor.h"
#include "Collision.h "

class Player : public Actor
{
private:
	Texture m_Texture;
	unsigned int m_Playertexture;
	AABB2d m_aabb;			 // AABBコリジョン
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override;
	AABB2d* GetCollision();
private:
	// Update()のヘルパー関数
	void Action();		//	入力の処理
	void Move();		//	移動の更新処理
	void Collision();	//	衝突判定

	//	コリジョンのヘルパー関数
	bool HitLine(const AABB2d* p_Object);
};

