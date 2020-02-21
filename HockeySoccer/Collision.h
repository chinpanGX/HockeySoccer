/*==========================================================

	[Collision.h]
	Author : �o���đ�

===========================================================*/
#pragma once
#include "main.h"
#include "math.h"

// ������������������������������������������������������������
//		�R���W�����\���̂Ɠ����蔻�菈���̃e���v���[�g
// ������������������������������������������������������������

// 2D�_
struct Point
{
	float px, py;
};

//	2D�T�[�N��
struct Circle2d
{
	float cx, cy; // ���S���W
	float radian; // ���a
};

//	2DAABB
struct AABB2d
{
	float cx, cy; // ���S���W
	float sx, sy; // �Z�a�T�C�Y
};

// �~�Ɛ����̓����蔻��
inline bool Intercept(const Circle2d Collision,const Point* start, const Point* end)
{
	// �x�N�g��������
	D3DXVECTOR2 startcenter = D3DXVECTOR2(Collision.cx - start->px, Collision.cy - start->py);
	D3DXVECTOR2 endcenter = D3DXVECTOR2(Collision.cx - end->px, Collision.cy - end->py);
	D3DXVECTOR2 startend = D3DXVECTOR2(end->px - start->px, end->py - start->py);
	D3DXVECTOR2 normal;
	// �P�ʃx�N�g����
	D3DXVec2Normalize(&normal, &startend);
	// �n�_�Ɖ~�̒��S�ŊO�ς��s��
	float distance = startcenter.x * normal.y - normal.x * startcenter.y;
	// �ˉe�̒��������a����������
	if (fabs(distance) < Collision.radian)
	{
		// �n�_=>�I�_�Ǝn�_=>�~�̒��S�̓��ς��v�Z
		float dot1 = startcenter.x * startend.x + startcenter.y * startend.y;
		// �n�_=>�I�_�Ǝn�_=>�~�̒��S�̓��ς��v�Z
		float dot2 = endcenter.x * startend.x + endcenter.y * startend.y;
		// ���ς̐ς̌��ʂ����ʂ�0�ȉ��Ȃ�
		if (dot1 * dot2 <= 0.0f)
		{
			return true;
		}
		//	������ɂȂ��Ƃ��A�n�_=>�~�̒��S�̒���or�I�_=>�~�̒��S�̒������~�̔��a���Z��
		else if (D3DXVec2Length(&startcenter) < Collision.radian || D3DXVec2Length(&endcenter) < Collision.radian)
		{
			return true;
		}
	}
	return false;
}

// Circle2d
inline bool Intersept(const Circle2d Collision, const Circle2d *p_Collision)
{
	//��������x�N�g���^�̕ϐ������
	D3DXVECTOR2 dst1(Collision.cx, Collision.cy);
	D3DXVECTOR2 dst2(p_Collision->cx, p_Collision->cy);
	//��_�Ԃ̃x�N�g�������
	D3DXVECTOR2 distance = dst2 - dst1;
	//������x�N�g���̒��������߂�
	float length = D3DXVec2Length(&distance);
	//���݂��̔��a�𑫂����l�����߂�
	float size = Collision.radian + p_Collision->radian;

	//�x�N�g���̒����Ƃ��݂��̔��a�𑫂����l���r���� �� �x�N�g���̒����̕�����������΃q�b�g
	if (length < size)
	{
		return true;
	}
	//�q�b�g���Ă��Ȃ�����
	return false;
}

// AABB2d
inline bool Intercept(const AABB2d Collision, const AABB2d * p_Collision)
{
	D3DXVECTOR2 minA, minB;	//	�ŏ��_
	D3DXVECTOR2 maxA, maxB;	//	�ő�_

	//	A��box�ŏ��_
	minA.x = Collision.cx - Collision.sx;
	minA.y = Collision.cy - Collision.sy;

	//	A��box�ő�_
	maxA.x = Collision.cx + Collision.sx;
	maxA.y = Collision.cy + Collision.sy;

	//	B��box�ŏ��_
	minB.x = p_Collision->cx - p_Collision->sx;
	minB.y = p_Collision->cy - p_Collision->sy;

	//	B��box�ő�_ 
	maxB.x = p_Collision->cx + p_Collision->sx;
	maxB.y = p_Collision->cy + p_Collision->sy;
	//	X���̔�r
	if (maxA.x > minB.x && minA.x < maxB.x)
	{
		//	Y���̔�r
		if (maxA.y > minB.y && minA.y < maxB.y)
		{
			return true;
		}
	}
	return false;
}

// ���X�C�[�v�̌�������
inline bool SweptSphere(const Circle2d Collision, const D3DXVECTOR2 Vector, D3DXVECTOR2 Position,const Circle2d* p_Collision, const D3DXVECTOR2 &p_Vector, D3DXVECTOR2 p_Posiiton)
{
	// �O�ʒu�y�ѓ��B�ʒu�ɂ�����x�N�g�����Z�o�B�x�N�g����2�悵�Čv�Z����
	D3DXVECTOR2 C0 = D3DXVECTOR2(p_Collision->cx - Collision.cx, p_Collision->cy - Collision.cy);
	D3DXVECTOR2 A1 = D3DXVECTOR2(Collision.cx + Vector.x, Collision.cy + Vector.y);
	D3DXVECTOR2 B1 = D3DXVECTOR2(p_Collision->cx + p_Vector.x, p_Collision->cy + p_Vector.y);
	D3DXVECTOR2 C1 = B1 - A1;
	D3DXVECTOR2 D = C1 - C0;
	float rAB = Collision.radian + p_Collision->radian;
	float rABSq = rAB * rAB;
	float P = D.x * D.x + D.y * D.y;
	float Q = C0.x * D.x + C0.y * D.y;
	float R = C0.x * C0.x + C0.y * C0.y;
	/*
	// �Փ˔���ɉ��̌������g��
	if (P == 0)
	{
		// t = 0�ŏՓ˂��Ă��邩
		// C0�̃h�b�g�ςƔ�r
		if (C0.x * C0.x + C0.y * C0.y > rABSq)
		{
			return false; // ���̌����͎g���Ȃ�
		}

		if (Position != 0)
		{
			Position = D3DXVECTOR2(Collision.cx, Collision.cy);
		}
		if (p_Posiiton != 0)
		{
			p_Posiiton = D3DXVECTOR2(p_Collision->cx, p_Collision->cy);
		}

		if (p_Collision->cx == Collision.cx && p_Collision->cy == Collision.cy)
		{
			return true;
		}

		return true;
	}
	*/
	// �Փ˔��莮
	float judge = Q * Q - P * (R - rAB * rAB);
	if (judge < 0) 
	{
		// �Փ˂��Ă��Ȃ�
		return false;
	}

	// �Փˎ��Ԃ̎Z�o
	float judge_rt = sqrtf(judge);
	float time_puls = (-Q + judge_rt) / P;
	float time_minus = (-Q - judge_rt) / P;
	if (time_minus > time_puls)
	{
		// time_minus������������
		float tmp = time_minus;
		time_minus = time_puls;
		time_puls = tmp;
	}

	// ���ԊO�Փ˂��H
	if (time_minus < 0.0f || time_minus > 1.0f) 
	{
		return false;
	}

	// �Փˈʒu�̌���
	D3DXVECTOR2 Atc, Btc;
	Atc.x = Collision.cx + Vector.x * time_minus;
	Atc.y = Collision.cy + Vector.y * time_minus;
	Btc.x = p_Collision->cx + p_Vector.x * time_minus;
	Btc.y = p_Collision->cy + p_Vector.y * time_minus;

	if (Position != 0)
		Position = Atc;
	if (p_Posiiton != 0)
		p_Posiiton = Btc;

	// 0 < t < 1 �Ȃ�Փ�
	return true; 
}

#if 0
// �����`�F�b�N
inline bool Intercept(const AABB2d Collision, const D3DXVECTOR2 Vec, const AABB2d* p_Collision, const D3DXVECTOR2& p_Vec)
{
	D3DXVECTOR2 Point;	// ObjectA
	D3DXVECTOR2 minB, maxB;	// ObjectB
	
	// ObejectA��_�ɕό`
	Point = D3DXVECTOR2(Collision.cx - Collision.sx, Collision.cy + Collision.sy);
	
	// ObjectB�̐ݒ�
	// ObjectB���g��
	// B��box�ŏ��_
	minB.x = (p_Collision->cx - p_Collision->sx) - ((p_Collision->cx + p_Collision->sx) - (p_Collision->cx - p_Collision->sx));
	minB.y = p_Collision->cy - p_Collision->sy;
	// B��box�ő�_ 
	maxB.x = p_Collision->cx + p_Collision->sx;
	maxB.y = (p_Collision->cy + p_Collision->sy) - ((p_Collision->cy - p_Collision->sy) - (p_Collision->cy + p_Collision->sy));

	// ���Α��x���v�Z
	D3DXVECTOR2 rvecec = Vec - p_Vec;

	if (rvecec.x != 0)
	{
		float lx = (rvecec.x > 0) ? maxB.x : minB.x;
		float t = lx - (Point.x + rvecec.x) / rvecec.x;
		if ((t >= 0) && (t <= 1.0f))
		{
			// �Փ˓_Y��AABB�̐������������true
			float hity = Point.y + t * rvecec.y;
			if ((hity >= maxB.y) && (hity <= minB.y))
			{
				return true;
			}
		}
	}
	if (rvecec.y != 0)
	{
		float lx = (rvecec.y > 0) ? maxB.y : minB.y;
		float t = lx - (Point.y + rvecec.y) / rvecec.y;
		if ((t >= 0) && (t <= 1.0f))
		{
			// �Փ˓_X��AABB�̐������������true
			float hitx = Point.x + t * rvecec.x;
			if ((hitx >= maxB.x) && (hitx <= minB.x))
			{
				return true;
			}
		}
	}

	D3DXVECTOR2 Point;	// ObjectA
	D3DXVECTOR2 minB, maxB;	// ObjectB

	// ObejectA��_�ɕό`
	Point = D3DXVECTOR2(Collision.cx - Collision.sx, Collision.cy + Collision.sy);

	// ObjectB�̐ݒ�
	// ObjectB���g��
	// B��box�ŏ��_
	minB.x = (p_Collision->cx - p_Collision->sx) - ((p_Collision->cx + p_Collision->sx) - (p_Collision->cx - p_Collision->sx));
	minB.y = p_Collision->cy - p_Collision->sy;
	// B��box�ő�_ 
	maxB.x = p_Collision->cx + p_Collision->sx;
	maxB.y = (p_Collision->cy + p_Collision->sy) - ((p_Collision->cy - p_Collision->sy) - (p_Collision->cy + p_Collision->sy));

	// ���Α��x���v�Z
	D3DXVECTOR2 rvec = Vec - p_Vec;
	if (rvec.x != 0)
	{
		float fLineX = (rvec.x > 0) ? minB.x : maxB.x;
		float t = fLineX - (Point.x + rvec.x) / rvec.x;

		if ((t >= 0) && (t <= 1.0f))
		{
			// �Փ˓_(������)��AABB�̐����Ɏ��܂��Ă���ΏՓ�
			float hitY = Point.y + t * rvec.y;
			if ((hitY >= maxB.y) && (hitY <= minB.y))
			{
				return true;
			}
		}
	}

	if (rvec.y != 0)
	{
		float fLineY = (rvec.y > 0) ? maxB.y : minB.y;
		float t = fLineY - (Point.y + rvec.y) / rvec.y;

		if ((t >= 0) && (t <= 1.0f))
		{
			// �Փ˓_(x����)��AABB�̐����Ɏ��܂��Ă���ΏՓ�
			float hitX = Point.x + t * rvec.x;
			if ((hitX >= minB.x) && (hitX <= maxB.x))
			{
				return true;
			}
		}
	}
	return false;

}

// �����`�F�b�N
template <class Type>
bool SweptSphere(const Type P0, const Type P1, const Type Q0, const Type Q1)
{
	D3DXVECTOR2 A = D3DXVECTOR2(P0.cx, P0.cy);
	D3DXVECTOR2 B = D3DXVECTOR2(P1.cx - P0.cx - (Q1.cx - Q0.cx), P1.cy - P0.cy - (Q1.cy - Q0.cy));
	float a = (B.x * B.x + B.y * B.y);
	float b = 2.0f * (A.x * B.x + A.y * B.y);
	float sumRadii = P0.radian + Q0.radian;
	float c = (A.x * A.x + A.y * A.y) - sumRadii * sumRadii;
	float outT = 100.0f;
	// Solve discriminant
	float disc = b * b - 4.0f * a * c;
	if (disc < 0.0f)
	{
		return false;
	}
	else
	{
		disc = sqrt(disc);
		// We only care about the smaller solution
		outT = (-b - disc) / (2.0f * a);
		if (outT >= 0.0f && outT <= 0.0f)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
#endif 