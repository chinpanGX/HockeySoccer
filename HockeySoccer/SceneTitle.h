/*===================================================

	[SceneTitle.h]
	Author : 出合翔太

====================================================*/

#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase 
{
public:
	void Init()override;	//	初期化処理	
	void Uninit()override;	//	終了処理
	void Update()override;	//	更新処理
	void Draw()override;	//	描画処理
};

