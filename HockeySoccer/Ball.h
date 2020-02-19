/*========================================================

	[Ball.h]
	Author : 出合 翔太

========================================================*/

#pragma once
#include "Actor.h"
#include "BoxComponent.h"

class Ball : public Actor
{
private:
	Component2D m_Component;
	D3DXCOLOR m_Color;
	bool m_GameEnd;	  // 自陣ゴールしたかどうか
	bool m_GoalFlag;  // ゴールしたかどうか判定
	int m_EffectFlag;

	// Update()のヘルパー関数
	void PlayerCollision();
	void EnemyCollision();
	void LineCollsion();
	void GoalCollsion();
	void EnemyGoalCollision();
public:
	void Init()override;
	void Init(D3DXVECTOR2 Velocity); // 移動方向べクトルの変更
	void Uninit()override;
	void Update()override;
	void Draw(LPDIRECT3DTEXTURE9 Texture)override;
	Component2D* GetCollision();
	bool GetGameEnd();
	bool GetGoalFlag();
	D3DXVECTOR2 GetPosition();
	int GetEffect();
};
