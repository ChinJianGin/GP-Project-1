#pragma once

#include "midwork/CCharacter.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

class CEnemy : public CCharacter
{
private:

public:
	void virtual characterInit(Sprite& loctag, Scene& theScene) = 0;
};