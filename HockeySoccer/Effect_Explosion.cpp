/*=====================================================

	[Effect_Explosion.h]
	Author : �o���đ�

======================================================*/

#include "Effect_Explosion.h"

void Explosion::Init()
{
	Effect::Init();
}

void Explosion::Update()
{
	Effect::Update();
}

void Explosion::Draw(LPDIRECT3DTEXTURE9 Texture)
{
	if (m_Use == true)
	{
		// ���ݕ\������ׂ��p�^�[���ԍ�����؂�����W���Z�o����
		float tx = FrameSize * (m_Frame % 5);
		float ty = FrameSize * (m_Frame / 5);
		m_Sprite.Draw(Texture, m_Position.x - (FrameSize * 0.5f), m_Position.y - (FrameSize * 0.5f), 960.0f, 768.0f, tx, ty, FrameSize, FrameSize);
	}
}