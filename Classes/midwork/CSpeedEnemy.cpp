#pragma once

#include "midwork/CSpeedEnemy.h"

void speedEnemy::characterInit(Sprite& loctag, Node& theScene)
{
	_characterRoot = CSLoader::createNode("speedenemy-2.csb");
	theScene.addChild(_characterRoot, 5);

	_characterJumpAct = CSLoader::createTimeline("speedenemy-2.csb");
	_characterJumpAct->setTimeSpeed(1.0f);
	_characterRoot->runAction(_characterJumpAct);

	_characterRunAct = CSLoader::createTimeline("speedenemy-2.csb");
	_characterRunAct->setTimeSpeed(1.0f);
	_characterRoot->runAction(_characterRunAct);

	_myDifficulty = CEnemy::LV::SPEED;
}

int speedEnemy::doRun()
{
	_characterJumpAct->gotoFrameAndPlay(0, 12, true);
	return 1;
}

int speedEnemy::doRoll()
{
	return 3;
}

int speedEnemy::doJump()
{
	_characterRunAct->pause();
	_characterRunAct->gotoFrameAndPlay(20, 32, false);
	return 2;
}

int speedEnemy::doJumpHigh()
{
	return 4;
}

CEnemy::LV speedEnemy::getDifficulty()
{
	return _myDifficulty;
}