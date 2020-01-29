/*=========================================================

	[CollisonManager.h]
	Author : èoçá„ƒëæ

==========================================================*/

#pragma once
#include "main.h"

enum ReturnType
{
	TOP,
	UNDER,
	LEFT,
	RIGHT
};															

void UpdateCollision();
bool Collision_Player_vs_Line();
bool Collision_Ball_vs_Line();