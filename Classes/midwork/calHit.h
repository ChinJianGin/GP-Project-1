#pragma once

#include "midwork/CRunner.h"
#include "midwork/enemySpawn.h"
#include "midwork/CScoring.h"

class calhit
{
private:
	enemySpawn* _enemy;
	CRunner* _runner;
	Point _runnerLoc;
	CScoring* _score;

	bool _hitNor, _hitTall, _hitSpeed, _noHitNor, _noHitTall, _noHitSpeed;
public:
	/*calhit();
	~calhit();*/
	void init(enemySpawn& enemy, CRunner& player, Sprite& loctag, CScoring& score);
	void update(float dt, int& whichaction);
};