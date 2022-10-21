#include "DxLib.h"
#include "game.h"
#include "enemy.h"
#include "SceneMain.h"


namespace
{
	// X•ûŒüAY•ûŒü‚ÌÅ‘å‘¬“x
	constexpr float kSpeedMax = 8.0f;
	constexpr float kAcc = 0.4f;
}

Enemy::Enemy() :
	m_pMain(nullptr),
	m_handle(-1),
	m_isExist(false),
	m_pos(),
	m_vec()
{
}

Enemy::~Enemy()
{
	
}

void Enemy::init()
{
	m_pos.x = Game::kScreenWidth-80.0f;
	m_pos.y = Game::kScreenHeight/2;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_isExist = true;
}

void Enemy::update()
{
	if (!m_isExist)return;
	m_pos += m_vec;

	m_shotInteval++;
	if ((m_pMain) && (m_shotInteval >= 60))
	{
		m_pMain->creatShot(m_pos,false);
		m_shotInteval = 0;
	}
}

void Enemy::draw()
{
	if (!m_isExist)return;
	DrawTurnGraphF(m_pos.x, m_pos.y, m_handle, true);
}

float Enemy::getColWidth()
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempX;
}

float Enemy:: getColHeight()
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempY;
}




