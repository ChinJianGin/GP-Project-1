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
		_characterRoot = CSLoader::createNode("normalenemy.csb");
#ifndef SPAWN
		_characterRoot->setPosition(loctag.getPosition());
		loctag.setVisible(false);
		theScene.addChild(_characterRoot, 5);
#else
		//_characterRoot->setVisible(false);
		theScene.addChild(_characterRoot, 4);
#endif // SPAWN		
		
		

		_characterJumpAct = CSLoader::createTimeline("normalenemy.csb");
		_characterJumpAct->setTimeSpeed(1.0f);
		_characterRoot->runAction(_characterJumpAct);

		_characterRunAct = CSLoader::createTimeline("normalenemy.csb");		
		_characterRunAct->setTimeSpeed(1.0f);
		_characterRoot->runAction(_characterRunAct);
		
		_myDifficulty = CEnemy::LV::NORMAL;
	}
	void doRun() 
	{
		_characterRunAct->gotoFrameAndPlay(0, 48, true);
	}

	void doJump() 
	{
		_characterRunAct->pause();
		_characterJumpAct->gotoFrameAndPlay(60, 108, false);
	}

	void doRoll() 
	{
		
	}

	void doJumpHigh() 
	{
		
	}
};