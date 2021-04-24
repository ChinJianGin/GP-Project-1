#pragma once

#include "midwork/CEnemy.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

class normalEnemy : public CEnemy
{
private:
	
public:	
	void characterInit(Sprite& loctag, Scene& theScene) {
		CCharacter::_characterRoot = CSLoader::createNode("normalenemy.csb");
		CCharacter::_characterRoot->setPosition(loctag.getPosition());
		loctag.setVisible(false);
		theScene.addChild(CCharacter::_characterRoot, 5);

		CCharacter::_characterJumpAct = CSLoader::createTimeline("normalenemy.csb");
		CCharacter::_characterJumpAct->gotoFrameAndPlay(60, 108, false);
		CCharacter::_characterJumpAct->setTimeSpeed(1.0f);
		CCharacter::_characterRoot->runAction(CCharacter::_characterJumpAct);

		CCharacter::_characterRunAct = CSLoader::createTimeline("normalenemy.csb");
		CCharacter::_characterRunAct->gotoFrameAndPlay(0, 48, true);
		CCharacter::_characterRunAct->setTimeSpeed(1.0f);
		CCharacter::_characterRoot->runAction(CCharacter::_characterRunAct);
		
		_myDifficulty = CEnemy::LV::NORMAL;
	}
};