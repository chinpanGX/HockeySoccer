/*=======================================================

	[ObjectManager.h]
	�I�u�W�F�N�g�̃Q�b�^�[���Ǘ�����N���X
	Author : �o���đ�

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
