#pragma once

#include "cocos2d.h"
#include "midwork/CCharacter.h"


USING_NS_CC;

//void CCharacter::doRun() {
//	_characterRoot->runAction(_characterRunAct);
//}
//
//void CCharacter::doJump() {
//	_characterRoot->runAction(_characterJumpAct);
//}
//
//void CCharacter::doRoll() {
//	_characterRoot->runAction(_characterRollAct);
//}
//
//void CCharacter::doJumpHigh() {
//	_characterRoot->runAction(_characterJumpHighAct);	
//}

Node* CCharacter::getRoot()
{
	return _characterRoot;
}