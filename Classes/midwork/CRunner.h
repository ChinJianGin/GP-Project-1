#pragma once

#include "cocos2d.h"

USING_NS_CC;

class CRunner : public Node 
{
private:
	Node* _watsonRoot;
	cocostudio::timeline::ActionTimeline* _watsonRunAct;
	cocostudio::timeline::ActionTimeline* _watsonJumpAct;
	cocostudio::timeline::ActionTimeline* _watsonRollAct;
public:
	void playerInit(Sprite& loctag, Scene& theScene);

	void doRun();
	void doJump();
	void doRoll();
};