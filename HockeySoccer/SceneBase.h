/*=====================================================

	[SceneBase.h]
	�T�v �F �V�[���N���X�̊��N���X
	Author : �o���đ�

======================================================*/

#pragma once
#include "main.h"
#include "Sprite.h"

class SceneBase
{
protected:
	bool m_bEnd;
	Sprite m_Sprite;
public:
	virtual ~SceneBase() {};
	virtual void Init() = 0;	//	����������
	virtual void Uninit() = 0;	//	�I������
	virtual void Update() = 0;	//	�X�V����
	virtual void Draw() = 0;	//	�`�揈��
};
