#include "midwork/calHit.h"

void calhit::init(enemySpawn& enemy, CRunner& player, Sprite& loctag, CScoring& score)
{
	_enemy = &enemy;
	_runner = &player;
	_runnerLoc = loctag.getContentSize();
	_score = &score;
	_hitNor = _hitTall = _hitSpeed = _noHitNor = _noHitTall = _noHitSpeed = false;

}

void calhit::update(float dt, int& whichaction)
{
	if (_enemy->getEnemies(0)->getRoot()->getPosition().x >= 1040.0f 
		&& _enemy->getEnemies(0)->getRoot()->getPosition().x <= 1050.0f)
	{
		if (_runner->getRoot()->getPosition().y <= 204.0f && !_hitNor && whichaction != 3)
		{//hit by normal
			_hitNor = true;
			log("hit normal");			
		}
		else if((whichaction == 3 || !_hitNor) && !_noHitNor)
		{
			_noHitNor = true;
			_score->setScore(*_enemy->getEnemies(0));
		}
		
	}
	else
	{
		_hitNor = _noHitNor = false;
	}

	if (_enemy->getEnemies(1)->getRoot()->getPosition().x >= 1000.0f
		&& _enemy->getEnemies(1)->getRoot()->getPosition().x <= 1020.0f)
	{
		if (_runner->getRoot()->getPosition().y <= 220.0f && !_hitTall && whichaction != 3)
		{
			_hitTall = true;
			log("hit taller");			
		}
		else if ((whichaction == 3 || !_hitTall) && !_noHitTall)
		{
			_noHitTall = true;
			_score->setScore(*_enemy->getEnemies(1));
		}
	}
	else
	{
		_hitTall = _noHitTall = false;
	}

	if (_enemy->getEnemies(2)->getRoot()->getPosition().x >= 1010.0f
		&& _enemy->getEnemies(2)->getRoot()->getPosition().x <= 1030.0f)
	{
		if (_runner->getRoot()->getPosition().y <= 204.0f && !_hitSpeed && whichaction != 3)
		{
			_hitSpeed = true;
			log("hit speed");			
		}
		else if ((whichaction == 3 || !_hitSpeed) && !_noHitSpeed)
		{
			_noHitSpeed = true;
			_score->setScore(*_enemy->getEnemies(2));
		}
	}
	else
	{
		_hitSpeed = _noHitSpeed = false;
	}
}