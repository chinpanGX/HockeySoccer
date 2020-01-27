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
#include "LineManager.h"

//#	SceneGameクラス:抽象クラス,SceneBaseを継承した子クラス
class SceneGame : public SceneBase
{
private:
	Background	m_Bg;		// ゲーム背景
	LineManager m_LineMgr;	// ラインのコリジョン
	Player		m_Player;	// プレイヤー
	Ball		m_Ball;		// ボール
	
	bool EndCheck(); // ゲーム終了チェック

public:
	void Init()override;	
	void Uninit()override;
	void Update()override;
	void Draw()override;
	// Getter
	LineManager* GetLineMgr();
	Player* GetPlayer();
	Ball* GetBall();
};
