/*===================================================
	
	[SceneResult.h]
	Author : 出合翔太

===================================================*/

#pragma once
#include"SceneBase.h"

class SceneResult : public SceneBase
{
private:
	static int	m_Ranking[5];	//	ランキングの値を格納する配列
public:
	void Init()override;	//	ゲームの初期化処理	
	void Uninit()override;	//	ゲームの終了処理
	void Update()override;	//	ゲームの更新処理
	void Draw()override;	//	ゲームの描画処理
private:
	void Sort(int Score);	//	ソート関数
};

