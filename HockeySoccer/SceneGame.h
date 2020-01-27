/*==================================

	[SceneGame.h]
	Author : 出合翔太

===================================*/

#pragma once
#include "main.h"
#include "SceneBase.h"
#include "Background.h"
#include "Player.h"
#include "Ball.h"

//#	SceneGameクラス:抽象クラス,SceneBaseを継承した子クラス
class SceneGame : public SceneBase
{
private:
	Background	m_Bg;		//	ゲーム背景
	Player		m_Player;	//	プレイヤー
	Ball		m_Ball;		//	ボール

	bool EndCheck();

public:
	void Init()override;	//	ゲームの初期化処理	
	void Uninit()override;	//	ゲームの終了処理
	void Update()override;	//	ゲームの更新処理
	void Draw()override;	//	ゲームの描画処理
};
