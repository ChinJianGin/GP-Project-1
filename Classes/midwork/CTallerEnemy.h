#pragma once

#include "midwork/CEnemy.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

class tallerEnemy : public CEnemy
{
private:

public:
	void characterInit(Sprite& loctag, Scene& theScene) {
		CCharacter::_characterRoot = CSLoader::createNode("tallerenemy.csb");
		CCharacter::_characterRoot->setPosition(loctag.getPosition());
		loctag.setVisible(false);
		theScene.addChild(CCharacter::_characterRoot, 5);

		CCharacter::_characterRunAct = CSLoader::createTimeline("tallerenemy.csb");
		CCharacter::_characterRunAct->gotoFrameAndPlay(0, 24, true);
		CCharacter::_characterRunAct->setTimeSpeed(1.0f);
		CCharacter::_characterRoot->runAction(CCharacter::_characterRunAct);

		_myDifficulty = CEnemy::LV::TALLER;
	}
};