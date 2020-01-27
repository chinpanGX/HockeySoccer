/*=======================================================

	[ObjectManager.h]
	オブジェクトのゲッターを管理するクラス
	Author : 出合翔太

=======================================================*/

#pragma once
#include "SceneGame.h"
#include "SceneManager.h"

class ObjectManager
{
public:
	static Line *GetLine(int Index);
	static Player * GetPlayer();
	static Ball* GetBall();
};

