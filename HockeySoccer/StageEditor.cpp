/*=========================================================

	[StageEditor.cpp]
	Author : èoçá„ƒëæ

==========================================================*/

#include "StageEditor.h"

void StageEditor::Init()
{
	LoadTexture();
	m_EnemyGoal.Init();
	m_Goal.Init();
	m_Player.Init();
	m_Enemy.Init();
	m_Ball.Init();
}

void StageEditor::Uninit()
{
	m_Ball.Uninit();
	m_Enemy.Uninit();
	m_Player.Uninit();
	m_Goal.Uninit();
	m_EnemyGoal.Uninit();
	m_Texture.UnLoadTexture(texture[1]);
	m_Texture.UnLoadTexture(texture[0]);
}

void StageEditor::Update()
{
	m_Goal.Update();
	m_EnemyGoal.Update();
	m_Ball.Update();
	m_Player.Update();
	m_Enemy.Update();
}

void StageEditor::Draw()
{
	DrawPlayer();
	DrawEnemy();
	DrawBall();
	DrawGoal();
	DrawEnemyGoal();
}

bool StageEditor::GameEnd()
{
	if (m_Goal.GameEnd() == true)
	{
		return true;
	}
	return false;
}

void StageEditor::LoadTexture()
{
	texture[0] = m_Texture.LoadTexture("Rom/TExture/Ball.png"); // É{Å[Éã
	texture[1] = m_Texture.LoadTexture("Rom/Texture/Bar.png");	// Player&Goal
}

void StageEditor::DrawPlayer()
{
	m_Player.Draw(m_Texture.SetTexture(texture[1]));
}

void StageEditor::DrawEnemy()
{
	m_Enemy.Draw(m_Texture.SetTexture(texture[1]));
}

void StageEditor::DrawBall()
{
	m_Ball.Draw(m_Texture.SetTexture(texture[0]));
}

void StageEditor::DrawGoal()
{
	m_Goal.Draw(m_Texture.SetTexture(texture[1]));
}

void StageEditor::DrawEnemyGoal()
{
	m_EnemyGoal.Draw(m_Texture.SetTexture(texture[1]));
}

Player * StageEditor::GetPlayer()
{
	return &m_Player;
}

Enemy * StageEditor::GetEnemy()
{
	return &m_Enemy;
}

Ball * StageEditor::GetBall()
{
	return &m_Ball;
}
