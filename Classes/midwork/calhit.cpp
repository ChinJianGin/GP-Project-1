#include "midwork/calHit.h"

void calhit::init(enemySpawn& enemy, CRunner& player, Sprite& loctag, CScoring& score, ui::LoadingBar& healthBar)
{
	_enemy = &enemy;
	_runner = &player;
	_runnerLoc = loctag.getContentSize();
	_score = &score;
	_hitNor = _hitTall = _hitSpeed = _noHitNor = _noHitTall = _noHitSpeed = false;
	_fdt = 0;
	_healthBar = &healthBar;
}

void calhit::update(float dt, int& whichaction)
{
	_fdt += dt;
	if (_enemy->getEnemies(0)->getRoot()->getPosition().x >= 1040.0f 
		&& _enemy->getEnemies(0)->getRoot()->getPosition().x <= 1050.0f)
	{
		_fdt = 0;
		if (_runner->getRoot()->getPosition().y <= 204.0f && !_hitNor && whichaction != 3)
		{//hit by normal
			_hitNor = true;
			_runner->setNowHp(1.0f);
			_healthBar->setPercent(_runner->getHPpercent());
			log("hit normal");
		}
		else if((whichaction == 3 || !_hitNor) && !_noHitNor)
		{//miss
			_noHitNor = true;
			_score->setScore(*_enemy->getEnemies(0));
		}
		
	}
	else
	{//reset conditions
		if (_fdt >= 0.7f && _noHitNor)
		{
			_runner->setFace(3);
			_noHitNor = false;
			_fdt = 0;
		}
		if (_fdt >= 0.7f && _hitNor)
		{
			_runner->setFace(2);
			_hitNor = false;
			_fdt = 0;
		}		
		if (_fdt >= 1.3f)
		{
			_runner->setFace(1);
			_fdt = 0;
		}
	}

	if (_enemy->getEnemies(1)->getRoot()->getPosition().x >= 1000.0f
		&& _enemy->getEnemies(1)->getRoot()->getPosition().x <= 1020.0f)
	{
		_fdt = 0;
		if (_runner->getRoot()->getPosition().y <= 220.0f && !_hitTall && whichaction != 3)
		{//hit tall
			_hitTall = true;
			_runner->setNowHp(2.0f);
			_healthBar->setPercent(_runner->getHPpercent());
			log("hit taller");			
		}
		else if ((whichaction == 3 || !_hitTall) && !_noHitTall)
		{//miss
			_noHitTall = true;
			_score->setScore(*_enemy->getEnemies(1));
		}
	}
	else
	{//reset conditions
		if (_fdt >= 0.7f && _noHitTall)
		{
			_runner->setFace(3);
			_noHitTall = false;
			_fdt = 0;
		}
		if (_fdt >= 0.7f && _hitTall)
		{
			_runner->setFace(2);
			_hitTall = false;
			_fdt = 0;
		}
		if (_fdt >= 1.3f)
		{
			_runner->setFace(1);
			_fdt = 0;
		}
	}

	if (_enemy->getEnemies(2)->getRoot()->getPosition().x >= 1010.0f
		&& _enemy->getEnemies(2)->getRoot()->getPosition().x <= 1030.0f)
	{
		_fdt = 0;
		if (_runner->getRoot()->getPosition().y <= 204.0f && !_hitSpeed && whichaction != 3)
		{//hit speed
			_hitSpeed = true;
			_runner->setNowHp(3.0f);
			_healthBar->setPercent(_runner->getHPpercent());
			log("hit speed");			
		}
		else if ((whichaction == 3 || !_hitSpeed) && !_noHitSpeed)
		{//miss
			_noHitSpeed = true;
			_score->setScore(*_enemy->getEnemies(2));
		}
	}
	else
	{//reset conditions
		if (_fdt >= 0.7f && _noHitSpeed)
		{
			_runner->setFace(3);
			_noHitSpeed = false;
			_fdt = 0;
		}
		if (_fdt >= 0.7f && _hitSpeed)
		{
			_runner->setFace(2);
			_hitSpeed = false;
			_fdt = 0;
		}
		if (_fdt >= 1.3f)
		{
			_runner->setFace(1);
			_fdt = 0;
		}
	}
}