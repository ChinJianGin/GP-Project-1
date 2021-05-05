#pragma once

#include "midwork/CEnemy.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"


USING_NS_CC;

class tallerEnemy : public CEnemy
{
private:

public:
	void characterInit(Sprite& loctag, Node& theScene);

	int doRun();

	int doJump();

	int doRoll();

	int doJumpHigh();

	CEnemy::LV getDifficulty();
};

