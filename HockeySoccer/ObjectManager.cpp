/*=======================================================

	[ObjectManager.h]
	オブジェクトのゲッターを管理するクラス
	Author : 出合翔太

=======================================================*/

#include "ObjectManager.h"

//	上のライン
Topline* ObjectManager::GetTopLine()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetLineMgr()->Gettopline();
}

//	下のライン
Underline * ObjectManager::GetUnderLine()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetLineMgr()->Getunderline();
}

//	左のライン
Leftline * ObjectManager::GetLeftLine()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetLineMgr()->Getleftline();
}

//	右のライン　
Rightline * ObjectManager::GetRightLine()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetLineMgr()->Getrightline();
}

//	プレイヤー
Player * ObjectManager::GetPlayer()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetStageEditor()->GetPlayer();
}

//	エネミー
Enemy * ObjectManager::GetEnemy()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetStageEditor()->GetEnemy();
}

//	ボール
Ball * ObjectManager::GetBall()
{
	return ((SceneGame*)SceneManager::SetSceneGame())->GetStageEditor()->GetBall();
}


