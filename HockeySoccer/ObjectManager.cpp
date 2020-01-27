/*=======================================================

	[ObjectManager.h]
	オブジェクトのゲッターを管理するクラス
	Author : 出合翔太

=======================================================*/

#include "ObjectManager.h"

Line* ObjectManager::GetLine(int Index)
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetLineMgr()->GetLine(Index);
}

Player * ObjectManager::GetPlayer()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetPlayer();
}

Ball * ObjectManager::GetBall()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetBall();
}
