/*=======================================================

	[ObjectManager.h]
	�I�u�W�F�N�g�̃Q�b�^�[���Ǘ�����N���X
	Author : �o���đ�

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

