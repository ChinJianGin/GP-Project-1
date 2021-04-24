#pragma once

#include "cocos2d.h"
#include "midwork/CCharacter.h"


USING_NS_CC;



//void CCharacter::playerInit(Sprite& loctag, Scene& theScene) {
//	_characterRoot = CSLoader::createNode("characterrun.csb");
//	_characterRoot->setPosition(loctag.getPosition());
//	loctag.setVisible(false);
//	theScene.addChild(_characterRoot, 5);
//
//	_characterRunAct = CSLoader::createTimeline("characterrun.csb");
//	_characterRunAct->gotoFrameAndPlay(0, 32, true);
//	_characterRunAct->setTimeSpeed(1.0f);
//
//	_characterJumpAct = CSLoader::createTimeline("characterrun.csb");
//	_characterJumpAct->gotoFrameAndPlay(40, 78, false);
//	_characterJumpAct->setTimeSpeed(1.0f);
//
//	_characterRollAct = CSLoader::createTimeline("characterrun.csb");
//	_characterRollAct->gotoFrameAndPlay(85, 143, false);
//	_characterRollAct->setTimeSpeed(1.0f);
//
//	_neutralFace = _characterRoot->getChildByName("neutral_face");
//	_happyFace = _characterRoot->getChildByName("happy_face");
//	_sadFace = _characterRoot->getChildByName("sad_face");
//}

void CCharacter::doRun() {
	_characterJumpAct->stop();
	_characterRollAct->stop();
	_characterRoot->runAction(_characterRunAct);
}

void CCharacter::doJump() {
	_characterRunAct->stop();
	_characterRoot->runAction(_characterJumpAct);
}

void CCharacter::doRoll() {
	_characterRunAct->stop();
	_characterRoot->runAction(_characterRollAct);
}

void CCharacter::doJumpHigh() {
	_characterRunAct->stop();
	_characterRoot->runAction(_characterJumpHighAct);
}