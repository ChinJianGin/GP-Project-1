#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "midwork/CRunner.h"

USING_NS_CC;

void CRunner::playerInit(Sprite& loctag, Scene& theScene) {
	_watsonRoot = CSLoader::createNode("watsonrun.csb");
	_watsonRoot->setPosition(loctag.getPosition());
	loctag.setVisible(false);
	theScene.addChild(_watsonRoot, 5);

	_watsonRunAct = CSLoader::createTimeline("watsonrun.csb");
	_watsonRunAct->gotoFrameAndPlay(0, 32, true);
	_watsonRunAct->setTimeSpeed(1.0f);

	_watsonJumpAct = CSLoader::createTimeline("watsonrun.csb");
	_watsonJumpAct->gotoFrameAndPlay(40, 78, false);
	_watsonJumpAct->setTimeSpeed(1.0f);

	_watsonRollAct = CSLoader::createTimeline("watsonrun.csb");
	_watsonRollAct->gotoFrameAndPlay(85, 143, false);
	_watsonRollAct->setTimeSpeed(1.0f);
}

void CRunner::doRun() {
	_watsonRoot->runAction(_watsonRunAct);
}

void CRunner::doJump() {
	_watsonRoot->runAction(_watsonJumpAct);
}

void CRunner::doRoll() {
	_watsonRoot->runAction(_watsonRollAct);
}