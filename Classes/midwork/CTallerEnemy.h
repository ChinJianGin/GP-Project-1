#pragma once

#include "midwork/CEnemy.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

//#define SPAWN

USING_NS_CC;

class tallerEnemy : public CEnemy
{
private:

public:
	void characterInit(Sprite& loctag, Node& theScene) {
		_characterRoot = CSLoader::createNode("tallerenemy.csb");
#ifndef SPAWN
		_characterRoot->setPosition(loctag.getPosition());
		loctag.setVisible(false);
#else
		//_characterRoot->setVisible(false);
		theScene.addChild(_characterRoot, 5);		
#endif // !SPAWN
		
		

		_characterJumpAct = CSLoader::createTimeline("tallerenemy-2.csb");
		_characterJumpAct->setTimeSpeed(1.0f);
		_characterRoot->runAction(_characterJumpAct);

		_characterRunAct = CSLoader::createTimeline("tallerenemy-2.csb");
		_characterRunAct->setTimeSpeed(1.0f);
		_characterRoot->runAction(CCharacter::_characterRunAct);

		_myDifficulty = CEnemy::LV::TALLER;
	}
	void doRun()
	{
		_characterRunAct->gotoFrameAndPlay(0, 24, true);
	}

	void doJump()
	{
		_characterRunAct->pause();
		_characterJumpAct->gotoFrameAndPlay(30, 58, false);
	}

	void doRoll()
	{

	}

	void doJumpHigh()
	{

	}
};