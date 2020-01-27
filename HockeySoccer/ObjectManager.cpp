/*=======================================================

	[ObjectManager.h]
	�I�u�W�F�N�g�̃Q�b�^�[���Ǘ�����N���X
	Author : �o���đ�

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
