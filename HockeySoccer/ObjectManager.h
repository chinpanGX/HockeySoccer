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
	static Topline * GetTopLine();
	static Underline * GetUnderLine();
	static Leftline * GetLeftLine();
	static Rightline * GetRightLine();
	static Player * GetPlayer();
	static Ball* GetBall();
};

