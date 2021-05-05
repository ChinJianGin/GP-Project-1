#pragma once

#include "midwork/CTallerEnemy.h"

void tallerEnemy::characterInit(Sprite& loctag, Node& theScene)
{
	_characterRoot = CSLoader::createNode("tallerenemy.csb");
	theScene.addChild(_characterRoot, 5);

	_characterJumpAct = CSLoader::createTimeline("tallerenemy-2.csb");
	_characterJumpAct->setTimeSpeed(1.0f);
	_characterRoot->runAction(_characterJumpAct);

	_characterRunAct = CSLoader::createTimeline("tallerenemy-2.csb");
	_characterRunAct->setTimeSpeed(1.0f);
	_characterRoot->runAction(CCharacter::_characterRunAct);

	_myDifficulty = CEnemy::LV::TALLER;
}

int tallerEnemy::doRun()
{
	_characterRunAct->gotoFrameAndPlay(0, 24, true);
	return 1;
}

int tallerEnemy::doJump()
{
	_characterRunAct->pause();
	_characterJumpAct->gotoFrameAndPlay(30, 58, false);
	return 2;
}

int tallerEnemy::doRoll()
{
	return 3;
}

int tallerEnemy::doJumpHigh()
{
	return 4;
}

CEnemy::LV tallerEnemy::getDifficulty()
{
	return _myDifficulty;
}