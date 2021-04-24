#pragma once

#include "midwork/CCharacter.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

class CRunner : public CCharacter {
private:

public:
	void characterInit(Sprite& loctag, Scene& theScene) {
		CCharacter::_characterRoot = CSLoader::createNode("watsonrun.csb");
		CCharacter::_characterRoot->setPosition(loctag.getPosition());
		loctag.setVisible(false);
		theScene.addChild(CCharacter::_characterRoot, 5);

		CCharacter::_characterRunAct = CSLoader::createTimeline("watsonrun.csb");
		CCharacter::_characterRunAct->gotoFrameAndPlay(0, 32, true);
		CCharacter::_characterRunAct->setTimeSpeed(1.0f);

		CCharacter::_characterJumpAct = CSLoader::createTimeline("watsonrun.csb");
		CCharacter::_characterJumpAct->gotoFrameAndPlay(85, 143, true);
		CCharacter::_characterJumpAct->setTimeSpeed(1.0f);

		CCharacter::_characterRollAct = CSLoader::createTimeline("watsonrun.csb");
		CCharacter::_characterRollAct->gotoFrameAndPlay(40, 78, false);
		CCharacter::_characterRollAct->setTimeSpeed(1.0f);

		CCharacter::_characterJumpHighAct = CSLoader::createTimeline("watsonrun.csb");
		CCharacter::_characterJumpHighAct->gotoFrameAndPlay(155, 221, true);
		CCharacter::_characterJumpHighAct->setTimeSpeed(1.0f);

		CCharacter::_neutralFace = CCharacter::_characterRoot->getChildByName("neutral_face");
		CCharacter::_happyFace = CCharacter::_characterRoot->getChildByName("happy_face");
		CCharacter::_sadFace = CCharacter::_characterRoot->getChildByName("sad_face");
	}
};