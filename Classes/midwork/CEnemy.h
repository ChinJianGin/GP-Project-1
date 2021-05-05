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
	virtual int  doRun() = 0;
	virtual int  doJump() = 0;
	virtual int  doRoll() = 0;
	virtual int  doJumpHigh() = 0;
	virtual int doSpawn() = 0;
	virtual CEnemy::LV getDifficulty() = 0;
protected:
	
};