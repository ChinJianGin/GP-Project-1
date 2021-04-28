#include "midwork/enemySpawn.h"

#define MOVESPEED 200
#define SPEED_ENEMY

USING_NS_CC;
using namespace cocostudio::timeline;

enemySpawn::enemySpawn()
{
	genLoc[0] = Point(240, 124); genLoc[1] = Point(640, 124); genLoc[2] = Point(1040, 124);
	_enemies[0] = _enemies[1] = _enemies[2] = nullptr;
	_enemieson[0] = _enemieson[1] = _enemieson[2] = 1;
}

enemySpawn::~enemySpawn()
{

}

void enemySpawn::update(float dt)
{
	Point pt0 = _enemies[0]->getPosition();
	Point pt1 = _enemies[1]->getPosition();
	Point pt2 = _enemies[2]->getPosition();
	pt0.x += dt * MOVESPEED;
	if (pt0.x >= 1920)
	{
		pt0.x = pt0.x - 2 * 1280;
		resetEnemies(0);
	}
	_enemies[0]->setPosition(pt0);
	
	pt1.x += dt * MOVESPEED;
	if(pt1.x >= 1920)
	{
		pt1.x = pt1.x - 2 * 1280;
		resetEnemies(0);
	}
	_enemies[1]->setPosition(pt1);
	
	
	pt2.x += dt * (MOVESPEED * 1.5);
	if(pt2.x >= 1920)
	{
		pt2.x = pt2.x - 2 * 1280;
		resetEnemies(0);
	}
	_enemies[2]->setPosition(pt2);
	
}

void enemySpawn::init(Sprite& loctag, Node& parent)
{
	_enemies[0] = new normalEnemy();
	_enemies[1] = new tallerEnemy();
	_enemies[2] = new speedEnemy();

	_enemies[0]->characterInit(loctag, parent);
	_enemies[1]->characterInit(loctag, parent);
	_enemies[2]->characterInit(loctag, parent);
}