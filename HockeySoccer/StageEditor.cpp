/*=========================================================

	[StageEditor.cpp]
	Author : 出合翔太

==========================================================*/

#include "StageEditor.h"
#include "Controller.h"
#include "Fade.h"
#include "ObjectManager.h"

//	初期化処理
void StageEditor::Init()
{
	LoadTexture();
	m_Stage = STAGE_1;
	InitObject(STAGE_1);
	m_StageCount = m_Stage;
}

//	終了処理
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

//	更新処理
void StageEditor::Update()
{
	switch (m_Stage)
	{
	case STAGE_CLEAR:
		InitObject(STAGE_CLEAR);
		UninitObject();
		if (KeyBoard::IsTrigger(DIK_RIGHTARROW))
		{
			m_StageCount++;		   // ステージカウントを加算する 
			InitObject(m_StageCount);
			m_Stage = (Stage)m_StageCount; //	キャストしてカウントを代入
			Fade::Start(false, 60);
		}
		else if (KeyBoard::IsTrigger(DIK_LEFTARROW))
		{
			m_Stage = STAGE_END;
		}
		break;
	case STAGE_1:
		UpdateObject();
		EnemyGoalEnd();
		break;
	case STAGE_2:
		UpdateObject();
		EnemyGoalEnd();
		break;
	case STAGE_3:
		UpdateObject();
		EnemyGoalEnd();
		break;
	case STAGE_END:
		GameEnd();
		break;
	}
}

//	描画処理
void StageEditor::Draw()
{
	switch (m_Stage)
	{
	case STAGE_CLEAR:
		m_Bg.Draw(m_Texture.SetTexture(texture[2]));
		break;
	case STAGE_1:
		DrawObject();
		break;
	case STAGE_2:
		DrawObject();
		break;
	case STAGE_3:
		DrawObject();
		break;
	case STAGE_END:
		break;
	}
}

//	ゲーム終了
bool StageEditor::GameEnd()
{
	if (m_Ball.GetGameEnd() == true) // 自陣ゴールに入る
	{
		return true;
	}
	if (m_Stage == STAGE_END) // ステージが終了。
	{
		return true;
	}
	return false;
}

/// <summary>
///	Init()のヘルパー関数
/// </summary>
//	テクスチャのロード
void StageEditor::LoadTexture()
{
	texture[0] = m_Texture.LoadTexture("Rom/Texture/Ball.png");  // ボール
	texture[1] = m_Texture.LoadTexture("Rom/Texture/Bar.png");	 // Player&Goal
	texture[2] = m_Texture.LoadTexture("Rom/Texture/BG.png"); // クリア画面
}
//	オブジェクトの初期化
void StageEditor::InitObject(int Stage)
{
	switch (Stage)
	{
	case STAGE_CLEAR:
		break;
	case STAGE_1:
		m_EnemyGoal.Init();
		m_Goal.Init();
		m_Player.Init();
		m_Enemy.Init();
		m_Ball.Init();
		break;
	case STAGE_2:
		m_EnemyGoal.Init();
		m_Goal.Init();
		m_Player.Init();
		m_Enemy.Init(6.0f);
		m_Ball.Init();
		break;
	case STAGE_3:
		m_EnemyGoal.Init();
		m_Goal.Init();
		m_Player.Init();
		m_Enemy.Init(6.0f, D3DXVECTOR2(960.0f + 320.0f, 360.0f));
		m_Ball.Init(D3DXVECTOR2(-7.0f, 10.5f));
		break;
	case STAGE_END:
		m_Stage = STAGE_END;
		break;
	}
}

/// <summry>
///	Uninit()のヘルパー関数
/// </summary>
//	オブジェクトの終了処理
void StageEditor::UninitObject()
{
	m_Ball.Uninit();
	m_Enemy.Uninit();
	m_Player.Uninit();
	m_Goal.Uninit();
	m_EnemyGoal.Uninit();
}

/// <summary>
/// Update()のヘルパー関数
/// </summary>
//	オブジェクトの更新
void StageEditor::UpdateObject()
{
	m_Goal.Update();
	m_EnemyGoal.Update();
	m_Player.Update();
	m_Enemy.Update();
	m_Ball.Update();
}

//	ゴールに入れたときの処理
void StageEditor::EnemyGoalEnd()
{
	if (m_Ball.GetGoalFlag() == true)
	{
		Fade::Start(false, 30);
		m_Stage = STAGE_CLEAR; // ステートを更新
	}
}


/// <summary>
/// Draw()のヘルパー関数
/// </summary>
//	オブジェクトの描画
void StageEditor::DrawObject()
{
	m_Player.Draw(m_Texture.SetTexture(texture[1]));
	m_Enemy.Draw(m_Texture.SetTexture(texture[1]));
	m_Ball.Draw(m_Texture.SetTexture(texture[0]));
	m_Goal.Draw(m_Texture.SetTexture(texture[1]));
	m_EnemyGoal.Draw(m_Texture.SetTexture(texture[1]));
}

/// <summary>
///  Getter
///	</summary>
Player * StageEditor::GetPlayer()
{
	return &m_Player;
}

Enemy * StageEditor::GetEnemy()
{
	return &m_Enemy;
}

Goal * StageEditor::GetGoal()
{
	return &m_Goal;
}

EnemyGoal * StageEditor::GetEnemyGoal()
{
	return &m_EnemyGoal;
}

Ball * StageEditor::GetBall()
{
	return &m_Ball;
}

