#include "midwork/enemySpawn.h"

#define MOVESPEED 400
#define X_OFFSET  100
#define SHIFTX(X) ((rand()%(2*(X)))- (X))
#define SPEED_ENEMY

USING_NS_CC;
using namespace cocostudio::timeline;

enemySpawn::enemySpawn()
{
	genLoc[0] = Point(-240, 124); genLoc[1] = Point(-640, 124); genLoc[2] = Point(-1040, 124);
	_enemies[0] = _enemies[1] = _enemies[2] = nullptr;
	_enemieson[0] = _enemieson[1] = _enemieson[2] = 1;
}

enemySpawn::~enemySpawn()
{

}

void enemySpawn::update(float dt)
{
	Point pt0 = _enemies[0]->getRoot()->getPosition();
	Point pt1 = _enemies[1]->getRoot()->getPosition();
	Point pt2 = _enemies[2]->getRoot()->getPosition();
	pt0.x += dt * MOVESPEED;
	if (pt0.x >= 0 && _enemieson[0] == 1)
	{
		log("burn");
		_enemies[0]->doJump();
		_enemieson[0]++;
	}
	if (pt0.x >= 160 && _enemieson[0] == 2)
	{
		_enemies[0]->doRun();
		_enemieson[0]++;
	}
	if (pt0.x >= 1920)
	{
		pt0.x = pt0.x - 2 * 1280;
		resetEnemies(0);
	}
	_enemies[0]->getRoot()->setPosition(pt0);
	
	pt1.x += dt * MOVESPEED;
	if (pt1.x >= 0 && _enemieson[1] == 1)
	{
		log("burn");
		_enemies[1]->doJump();
		_enemieson[1]++;
	}
	if (pt1.x >= 150 && _enemieson[1] == 2)
	{
		_enemies[1]->doRun();
		_enemieson[1]++;
	}
	if(pt1.x >= 1920)
	{
		pt1.x = pt1.x - 2 * 1280;
		resetEnemies(1);
	}
	_enemies[1]->getRoot()->setPosition(pt1);
	
	
	pt2.x += dt * MOVESPEED * 1.5;
	if (pt2.x >= 0 && _enemieson[2] == 1)
	{
		log("speed");
		_enemies[2]->doJump();
		_enemieson[2]++;
	}
	if (pt2.x >= 20 && _enemieson[2] == 2)
	{
		_enemies[2]->doRun();
		_enemieson[2]++;
	}
	if(pt2.x >= 1920)
	{
		pt2.x = pt2.x - 2 * 1280;
		resetEnemies(2);
	}
	_enemies[2]->getRoot()->setPosition(pt2);
	
}

void enemySpawn::init(Sprite& loctag, Node& parent)
{
	_enemies[0] = new normalEnemy();
	_enemies[1] = new tallerEnemy();
	_enemies[2] = new speedEnemy();

	_enemies[0]->characterInit(loctag, parent);
	_enemies[1]->characterInit(loctag, parent);
	_enemies[2]->characterInit(loctag, parent);

	_enemies[0]->getRoot()->setPosition(genLoc[0] + Point(SHIFTX(X_OFFSET), 80));
	_enemies[0]->doRun();

	_enemies[1]->getRoot()->setPosition(genLoc[2] + Point(SHIFTX(X_OFFSET), 80));
	_enemies[1]->doRun();

	_enemies[2]->getRoot()->setPosition(genLoc[1] + Point(SHIFTX(X_OFFSET), 80));
	_enemies[2]->doRun();
}

void enemySpawn::resetEnemies(int itype)
{
	if (itype == 0)
	{
		_enemieson[0] = 1;
		_enemies[0]->getRoot()->setVisible(false);
		_enemies[0]->getRoot()->setPosition(genLoc[rand() % 3] + Point(SHIFTX(X_OFFSET), 80));
		_enemies[0]->getRoot()->setVisible(true);
	}
	else if (itype == 1)
	{
		_enemieson[1] = 1;
		_enemies[1]->getRoot()->setVisible(false);
		_enemies[1]->getRoot()->setPosition(genLoc[rand() % 3] + Point(SHIFTX(X_OFFSET), 80));
		_enemies[1]->getRoot()->setVisible(true);
	}
	else
	{
		_enemieson[2] = 1;
		_enemies[2]->getRoot()->setVisible(false);
		_enemies[2]->getRoot()->setPosition(genLoc[rand() % 3] + Point(SHIFTX(X_OFFSET), 80));
		_enemies[2]->getRoot()->setVisible(true);
	}
}

CEnemy* enemySpawn::getEnemies(int i)
{
	return _enemies[i];
}