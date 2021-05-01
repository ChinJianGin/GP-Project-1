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
	ui::LoadingBar* _healthBar;

	bool _hitNor, _hitTall, _hitSpeed, _noHitNor, _noHitTall, _noHitSpeed;
	float _fdt;
public:
	/*calhit();
	~calhit();*/
	void init(enemySpawn& enemy, CRunner& player, Sprite& loctag, CScoring& score, ui::LoadingBar& healthBar);
	void update(float dt, int& whichaction);
};