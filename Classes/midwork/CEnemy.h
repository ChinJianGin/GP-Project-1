#pragma once

#include "midwork/CCharacter.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

class CEnemy : public CCharacter
{
public:
	enum class LV { NORMAL = 1, TALLER, SPEED };
	CEnemy::LV _myDifficulty;
	void virtual characterInit(Sprite& loctag, Node& theScene) = 0;
	void virtual doRun() = 0;
	void virtual doJump() = 0;
	void virtual doRoll() = 0;
	void virtual doJumpHigh() = 0;
protected:
	
};