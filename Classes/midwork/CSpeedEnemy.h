#pragma once

#include "midwork/CEnemy.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

#define SPAWN

USING_NS_CC;

class speedEnemy : public CEnemy
{
private:

public:
	void characterInit(Sprite& loctag, Node& theScene) {
		_characterRoot = CSLoader::createNode("speedenemy-2.csb");
#ifndef SPAWN
		_characterRoot->setPosition(loctag.getPosition());
		loctag.setVisible(false);		
#else
		theScene.addChild(_characterRoot, 5);
		//_characterRoot->setVisible(false);
#endif // !SPAWN
		//_characterRoot->setScale(0.25);
		
		

		_characterJumpAct = CSLoader::createTimeline("speedenemy-2.csb");
		_characterJumpAct->setTimeSpeed(1.0f);
		_characterRoot->runAction(_characterJumpAct);

		_characterRunAct = CSLoader::createTimeline("speedenemy-2.csb");		
		_characterRunAct->setTimeSpeed(1.0f);
		_characterRoot->runAction(_characterRunAct);

		_myDifficulty = CEnemy::LV::SPEED;
	}
	int doRun()
	{
		_characterJumpAct->gotoFrameAndPlay(0, 12, true);
		return 1;
	}

	int doJump()
	{
		_characterRunAct->pause();
		_characterRunAct->gotoFrameAndPlay(20, 32, false);
		return 2;
	}

	int doRoll()
	{
		return 3;
	}

	int doJumpHigh()
	{
		return 4;
	}
};