#pragma once

#include "midwork/CEnemy.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

#define SPAWN

USING_NS_CC;

class normalEnemy : public CEnemy
{
private:
	
public:	
	void characterInit(Sprite& loctag, Node& theScene) {
		_characterRoot = CSLoader::createNode("normalenemy-2.csb");
#ifndef SPAWN
		_characterRoot->setPosition(loctag.getPosition());
		loctag.setVisible(false);
		theScene.addChild(_characterRoot, 5);
#else
		//_characterRoot->setVisible(false);
		theScene.addChild(_characterRoot, 4);
#endif // SPAWN		
		
		

		_characterJumpAct = CSLoader::createTimeline("normalenemy-2.csb");
		_characterJumpAct->setTimeSpeed(1.0f);
		_characterRoot->runAction(_characterJumpAct);

		_characterRunAct = CSLoader::createTimeline("normalenemy-2.csb");		
		_characterRunAct->setTimeSpeed(1.0f);
		_characterRoot->runAction(_characterRunAct);
		
		_myDifficulty = CEnemy::LV::NORMAL;
	}
	int doRun() 
	{
		_characterRunAct->gotoFrameAndPlay(0, 48, true);
		return 1;
	}

	int doJump() 
	{
		_characterRunAct->pause();
		_characterJumpAct->gotoFrameAndPlay(60, 108, false);
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