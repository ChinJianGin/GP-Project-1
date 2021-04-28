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
		_characterRoot = CSLoader::createNode("speedenemy.csb");
#ifndef SPAWN
		_characterRoot->setPosition(loctag.getPosition());
		loctag.setVisible(false);		
#else
		theScene.addChild(_characterRoot, 5);
		//_characterRoot->setVisible(false);
#endif // !SPAWN
		//_characterRoot->setScale(0.25);
		
		

		_characterJumpAct = CSLoader::createTimeline("speedenemy.csb");
		_characterJumpAct->setTimeSpeed(1.0f);
		_characterRoot->runAction(_characterJumpAct);

		_characterRunAct = CSLoader::createTimeline("speedenemy.csb");		
		_characterRunAct->setTimeSpeed(1.0f);
		_characterRoot->runAction(_characterRunAct);

		_myDifficulty = CEnemy::LV::SPEED;
	}
	void doRun()
	{
		
		_characterJumpAct->gotoFrameAndPlay(0, 12, true);
	}

	void doJump()
	{
		_characterRunAct->pause();
		_characterRunAct->gotoFrameAndPlay(20, 32, false);
	}

	void doRoll()
	{

	}

	void doJumpHigh()
	{

	}
};