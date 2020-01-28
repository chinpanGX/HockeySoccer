/*=======================================================

	[ObjectManager.h]
	オブジェクトのゲッターを管理するクラス
	Author : 出合翔太

=======================================================*/

#include "ObjectManager.h"

Topline* ObjectManager::GetTopLine()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetLineMgr()->Gettopline();
}

Underline * ObjectManager::GetUnderLine()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetLineMgr()->Getunderline();
}

Leftline * ObjectManager::GetLeftLine()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetLineMgr()->Getleftline();
}

Rightline * ObjectManager::GetRightLine()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetLineMgr()->Getrightline();
}

Player * ObjectManager::GetPlayer()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetPlayer();
}

Ball * ObjectManager::GetBall()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetBall();
}	
