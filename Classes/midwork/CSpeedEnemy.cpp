#pragma once

#include "midwork/CSpeedEnemy.h"

void speedEnemy::characterInit(Sprite& loctag, Node& theScene)
{
	_characterRoot = CSLoader::createNode("speedenemy-2.csb");
	theScene.addChild(_characterRoot, 5);

	_characterSpawn = CSLoader::createTimeline("speedenemy-2.csb");
	_characterSpawn->setTimeSpeed(1.0f);
	_characterRoot->runAction(_characterSpawn);

	_characterRunAct = CSLoader::createTimeline("speedenemy-2.csb");
	_characterRunAct->setTimeSpeed(1.0f);
	_characterRoot->runAction(_characterRunAct);

	_myDifficulty = CEnemy::LV::SPEED;
}

int speedEnemy::doRun()
{
	_characterRunAct->gotoFrameAndPlay(0, 12, true);
	return 1;
}

int speedEnemy::doRoll()
{
	return 3;
}

int speedEnemy::doJump()
{
	return 2;
}

int speedEnemy::doJumpHigh()
{
	return 4;
}

int speedEnemy::doSpawn()
{
	_characterRunAct->pause();
	_characterSpawn->gotoFrameAndPlay(20, 32, false);
	return 5;
}

CEnemy::LV speedEnemy::getDifficulty()
{
	return _myDifficulty;
}