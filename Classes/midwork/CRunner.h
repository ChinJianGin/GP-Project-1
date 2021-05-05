#pragma once

#include "midwork/CCharacter.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "common/CButton.h"

USING_NS_CC;

class CRunner : public CCharacter {
private:
	float _MAX_HP, _NOW_HP;
	float _fjtime;
	enum class _playerState{DEAD,ALIVE};
	CRunner::_playerState _nowState;
public:
	void characterInit(Sprite& loctag, Node& theScene);
	void update(float dt, cocos2d::Point& _nowPos, int& whichAction, CButton& theButton);

	int doRun();
	int doJump();
	int doRoll();
	int doJumpHigh();
	int doSpawn();
	
	CRunner::_playerState getNowState();

	Rect getRect();

	float getHPpercent();

	float getNowHP();

	void setNowHp(float damage);

	void setFace(int NO);

	void resetRunner();
};