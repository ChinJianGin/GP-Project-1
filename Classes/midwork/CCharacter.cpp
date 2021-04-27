#pragma once

#include "cocos2d.h"
#include "midwork/CCharacter.h"


USING_NS_CC;





void CCharacter::doRun() {
	//_characterJumpAct->stop();
	//_characterRollAct->stop();
	_characterRunAct->gotoFrameAndPlay(0, 32, true);
	
}

void CCharacter::doJump() {
	//_characterRunAct->stop();
	_characterJumpAct->gotoFrameAndPlay(72, 132, false);
}

void CCharacter::doRoll() {
	//_characterRunAct->stop();
	_characterRollAct->gotoFrameAndPlay(33, 71, false);
}

void CCharacter::doJumpHigh() {
	//_characterRunAct->stop();
	_characterJumpHighAct->gotoFrameAndPlay(133, 201, false);
	
}

Node* CCharacter::getRoot()
{
	return _characterRoot;
}