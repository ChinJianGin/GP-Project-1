#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"


USING_NS_CC;

class CCharacter : public Node 
{
protected:
	Node* _characterRoot;
	Node* _neutralFace;
	Node* _happyFace;
	Node* _sadFace;
	Sprite* _loctag;
	cocostudio::timeline::ActionTimeline* _characterRunAct;
	cocostudio::timeline::ActionTimeline* _characterJumpAct;
	cocostudio::timeline::ActionTimeline* _characterRollAct;
	cocostudio::timeline::ActionTimeline* _characterJumpHighAct;

	int _HP;
public:
	void virtual characterInit(Sprite& loctag, Node& theScene) = 0;

	void doRun();
	void doJump();
	void doRoll();
	void doJumpHigh();
};

