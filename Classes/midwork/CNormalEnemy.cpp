#pragma once

#include "midwork/CNormalEnemy.h"

void normalEnemy::characterInit(Sprite& loctag, Node& theScene)
{
	_characterRoot = CSLoader::createNode("normalenemy-2.csb");
	theScene.addChild(_characterRoot, 5);

	_characterSpawn = CSLoader::createTimeline("normalenemy-2.csb");
	_characterSpawn->setTimeSpeed(1.0f);
	_characterRoot->runAction(_characterSpawn);

	_characterRunAct = CSLoader::createTimeline("normalenemy-2.csb");
	_characterRunAct->setTimeSpeed(1.0f);
	_characterRoot->runAction(_characterRunAct);

	_myDifficulty = CEnemy::LV::NORMAL;
}

int normalEnemy::doRun()
{
	_characterRunAct->gotoFrameAndPlay(0, 48, true);
	return 1;
}

int normalEnemy::doSpawn()
{
	_characterRunAct->pause();
	_characterSpawn->gotoFrameAndPlay(60, 108, false);
	return 5;
}

int normalEnemy::doJump()
{
	return 2;
}

int normalEnemy::doRoll()
{
	return 3;
}

int normalEnemy::doJumpHigh()
{
	return 4;
}

CEnemy::LV normalEnemy::getDifficulty()
{
	return _myDifficulty;
}