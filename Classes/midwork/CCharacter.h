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
	virtual int  doRun() = 0;
	virtual int  doJump() = 0;
	virtual int  doRoll() = 0;
	virtual int  doJumpHigh() =0;
	Node* getRoot();
};

