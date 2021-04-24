#pragma once

#include "midwork/CEnemy.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

class speedEnemy : public CEnemy
{
private:

public:
	void characterInit(Sprite& loctag, Scene& theScene) {
		CCharacter::_characterRoot = CSLoader::createNode("speedenemy.csb");
		CCharacter::_characterRoot->setPosition(loctag.getPosition());
		loctag.setVisible(false);
		theScene.addChild(CCharacter::_characterRoot, 5);

		CCharacter::_characterRunAct = CSLoader::createTimeline("speedenemy.csb");
		CCharacter::_characterRunAct->gotoFrameAndPlay(0, 12, true);
		CCharacter::_characterRunAct->setTimeSpeed(1.0f);
		CCharacter::_characterRoot->runAction(CCharacter::_characterRunAct);
	}
};