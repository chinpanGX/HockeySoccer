/*===================================================
	
	[SceneResult.h]
	Author : �o���đ�

===================================================*/

#pragma once
#include"SceneBase.h"

class SceneResult : public SceneBase
{
private:
	static int	m_Ranking[5];	//	�����L���O�̒l���i�[����z��
public:
	void Init()override;	//	�Q�[���̏���������	
	void Uninit()override;	//	�Q�[���̏I������
	void Update()override;	//	�Q�[���̍X�V����
	void Draw()override;	//	�Q�[���̕`�揈��
private:
	void Sort(int Score);	//	�\�[�g�֐�
};

