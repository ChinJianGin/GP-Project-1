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
	void virtual characterInit(Sprite& loctag, Scene& theScene) = 0;
protected:
	
};