/*==========================================================

	[Collision.h]
	Author : 出合翔太

===========================================================*/
#pragma once
#include "main.h"
#include "math.h"

// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//		コリジョン構造体と当たり判定処理のテンプレート
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■

// 2D点
struct Point
{
	float px, py;
};

//	2Dサークル
struct Circle2d
{
	float cx, cy; // 中心座標
	float radian; // 半径
};

//	2DAABB
struct AABB2d
{
	float cx, cy; // 中心座標
	float sx, sy; // 短径サイズ
};

// 円と線分の当たり判定
inline bool Intercept(const Circle2d Collision,const Point* start, const Point* end)
{
	// ベクトルをつくる
	D3DXVECTOR2 startcenter = D3DXVECTOR2(Collision.cx - start->px, Collision.cy - start->py);
	D3DXVECTOR2 endcenter = D3DXVECTOR2(Collision.cx - end->px, Collision.cy - end->py);
	D3DXVECTOR2 startend = D3DXVECTOR2(end->px - start->px, end->py - start->py);
	D3DXVECTOR2 normal;
	// 単位ベクトル化
	D3DXVec2Normalize(&normal, &startend);
	// 始点と円の中心で外積を行う
	float distance = startcenter.x * normal.y - normal.x * startcenter.y;
	// 射影の長さが半径よりも小さい
	if (fabs(distance) < Collision.radian)
	{
		// 始点=>終点と始点=>円の中心の内積を計算
		float dot1 = startcenter.x * startend.x + startcenter.y * startend.y;
		// 始点=>終点と始点=>円の中心の内積を計算
		float dot2 = endcenter.x * startend.x + endcenter.y * startend.y;
		// 内積の積の結果が結果が0以下なら
		if (dot1 * dot2 <= 0.0f)
		{
			return true;
		}
		//	線分上にないとき、始点=>円の中心の長さor終点=>円の中心の長さが円の半径より短い
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
	//引数からベクトル型の変数を作る
	D3DXVECTOR2 dst1(Collision.cx, Collision.cy);
	D3DXVECTOR2 dst2(p_Collision->cx, p_Collision->cy);
	//二点間のベクトルを作る
	D3DXVECTOR2 distance = dst2 - dst1;
	//作ったベクトルの長さを求める
	float length = D3DXVec2Length(&distance);
	//お互いの半径を足した値を求める
	float size = Collision.radian + p_Collision->radian;

	//ベクトルの長さとお互いの半径を足した値を比較する → ベクトルの長さの方が小さければヒット
	if (length < size)
	{
		return true;
	}
	//ヒットしていなかった
	return false;
}

// AABB2d
inline bool Intercept(const AABB2d Collision, const AABB2d * p_Collision)
{
	D3DXVECTOR2 minA, minB;	//	最小点
	D3DXVECTOR2 maxA, maxB;	//	最大点

	//	Aのbox最小点
	minA.x = Collision.cx - Collision.sx;
	minA.y = Collision.cy - Collision.sy;

	//	Aのbox最大点
	maxA.x = Collision.cx + Collision.sx;
	maxA.y = Collision.cy + Collision.sy;

	//	Bのbox最小点
	minB.x = p_Collision->cx - p_Collision->sx;
	minB.y = p_Collision->cy - p_Collision->sy;

	//	Bのbox最大点 
	maxB.x = p_Collision->cx + p_Collision->sx;
	maxB.y = p_Collision->cy + p_Collision->sy;
	//	X軸の比較
	if (maxA.x > minB.x && minA.x < maxB.x)
	{
		//	Y軸の比較
		if (maxA.y > minB.y && minA.y < maxB.y)
		{
			return true;
		}
	}
	return false;
}

// 球スイープの交差判定
inline bool SweptSphere(const Circle2d Collision, const D3DXVECTOR2 Vector, D3DXVECTOR2 Position,const Circle2d* p_Collision, const D3DXVECTOR2 &p_Vector, D3DXVECTOR2 p_Posiiton)
{
	// 前位置及び到達位置におけるベクトルを算出。ベクトルは2乗して計算する
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
	// 衝突判定に解の公式を使う
	if (P == 0)
	{
		// t = 0で衝突しているか
		// C0のドット積と比較
		if (C0.x * C0.x + C0.y * C0.y > rABSq)
		{
			return false; // 解の公式は使えない
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
	// 衝突判定式
	float judge = Q * Q - P * (R - rAB * rAB);
	if (judge < 0) 
	{
		// 衝突していない
		return false;
	}

	// 衝突時間の算出
	float judge_rt = sqrtf(judge);
	float time_puls = (-Q + judge_rt) / P;
	float time_minus = (-Q - judge_rt) / P;
	if (time_minus > time_puls)
	{
		// time_minusを小さい方に
		float tmp = time_minus;
		time_minus = time_puls;
		time_puls = tmp;
	}

	// 時間外衝突か？
	if (time_minus < 0.0f || time_minus > 1.0f) 
	{
		return false;
	}

	// 衝突位置の決定
	D3DXVECTOR2 Atc, Btc;
	Atc.x = Collision.cx + Vector.x * time_minus;
	Atc.y = Collision.cy + Vector.y * time_minus;
	Btc.x = p_Collision->cx + p_Vector.x * time_minus;
	Btc.y = p_Collision->cy + p_Vector.y * time_minus;

	if (Position != 0)
		Position = Atc;
	if (p_Posiiton != 0)
		p_Posiiton = Btc;

	// 0 < t < 1 なら衝突
	return true; 
}

#if 0
// 精密チェック
inline bool Intercept(const AABB2d Collision, const D3DXVECTOR2 Vec, const AABB2d* p_Collision, const D3DXVECTOR2& p_Vec)
{
	D3DXVECTOR2 Point;	// ObjectA
	D3DXVECTOR2 minB, maxB;	// ObjectB
	
	// ObejectAを点に変形
	Point = D3DXVECTOR2(Collision.cx - Collision.sx, Collision.cy + Collision.sy);
	
	// ObjectBの設定
	// ObjectBを拡張
	// Bのbox最小点
	minB.x = (p_Collision->cx - p_Collision->sx) - ((p_Collision->cx + p_Collision->sx) - (p_Collision->cx - p_Collision->sx));
	minB.y = p_Collision->cy - p_Collision->sy;
	// Bのbox最大点 
	maxB.x = p_Collision->cx + p_Collision->sx;
	maxB.y = (p_Collision->cy + p_Collision->sy) - ((p_Collision->cy - p_Collision->sy) - (p_Collision->cy + p_Collision->sy));

	// 相対速度を計算
	D3DXVECTOR2 rvecec = Vec - p_Vec;

	if (rvecec.x != 0)
	{
		float lx = (rvecec.x > 0) ? maxB.x : minB.x;
		float t = lx - (Point.x + rvecec.x) / rvecec.x;
		if ((t >= 0) && (t <= 1.0f))
		{
			// 衝突点YとAABBの線分が当たればtrue
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
			// 衝突点XとAABBの線分が当たればtrue
			float hitx = Point.x + t * rvecec.x;
			if ((hitx >= maxB.x) && (hitx <= minB.x))
			{
				return true;
			}
		}
	}

	D3DXVECTOR2 Point;	// ObjectA
	D3DXVECTOR2 minB, maxB;	// ObjectB

	// ObejectAを点に変形
	Point = D3DXVECTOR2(Collision.cx - Collision.sx, Collision.cy + Collision.sy);

	// ObjectBの設定
	// ObjectBを拡張
	// Bのbox最小点
	minB.x = (p_Collision->cx - p_Collision->sx) - ((p_Collision->cx + p_Collision->sx) - (p_Collision->cx - p_Collision->sx));
	minB.y = p_Collision->cy - p_Collision->sy;
	// Bのbox最大点 
	maxB.x = p_Collision->cx + p_Collision->sx;
	maxB.y = (p_Collision->cy + p_Collision->sy) - ((p_Collision->cy - p_Collision->sy) - (p_Collision->cy + p_Collision->sy));

	// 相対速度を計算
	D3DXVECTOR2 rvec = Vec - p_Vec;
	if (rvec.x != 0)
	{
		float fLineX = (rvec.x > 0) ? minB.x : maxB.x;
		float t = fLineX - (Point.x + rvec.x) / rvec.x;

		if ((t >= 0) && (t <= 1.0f))
		{
			// 衝突点(ｙ方向)がAABBの線分に収まっていれば衝突
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
			// 衝突点(x方向)がAABBの線分に収まっていれば衝突
			float hitX = Point.x + t * rvec.x;
			if ((hitX >= minB.x) && (hitX <= maxB.x))
			{
				return true;
			}
		}
	}
	return false;

}

// 精密チェック
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