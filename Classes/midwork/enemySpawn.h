#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "midwork/CEnemy.h"
#include "midwork/CNormalEnemy.h"
#include "midwork/CSpeedEnemy.h"
#include "midwork/CTallerEnemy.h"

class enemySpawn
{
private:
	CEnemy* _enemies[3];
	Point genLoc[3];
	int _enemieson[3];
public:
	enemySpawn();
	~enemySpawn();
	void update(float dt);

	void init(cocos2d::Sprite& loctag,cocos2d::Node& parent);
	void resetEnemies(int itype) {}

};