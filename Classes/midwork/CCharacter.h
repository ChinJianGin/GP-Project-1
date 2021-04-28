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
	Rect _characterRect;
	cocostudio::timeline::ActionTimeline* _characterRunAct;
	cocostudio::timeline::ActionTimeline* _characterJumpAct;
	cocostudio::timeline::ActionTimeline* _characterRollAct;
	cocostudio::timeline::ActionTimeline* _characterJumpHighAct;


public:
	void virtual characterInit(Sprite& loctag, Node& theScene) = 0;
	//virtual Rect* getRect();
	void virtual doRun() = 0;
	void virtual doJump() = 0;
	void virtual doRoll() = 0;
	void virtual doJumpHigh() =0;
	Node* getRoot();
};

