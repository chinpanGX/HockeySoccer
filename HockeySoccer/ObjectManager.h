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
	static Topline * GetTopLine();
	static Underline * GetUnderLine();
	static Leftline * GetLeftLine();
	static Rightline * GetRightLine();
	static Player * GetPlayer();
	static Ball* GetBall();
};

