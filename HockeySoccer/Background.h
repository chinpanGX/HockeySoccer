/*=========================================================
	
	[Background.h]
	�Q�[���w�i��`��
	Author : �o�� �đ�

==========================================================*/

#pragma once
#include "Object.h"
class Background : public Object
{
private:
	Texture m_Texture;
	unsigned int m_Bgtexture;
public:
	void Init();
	void Uninit();
	void Draw();
};

