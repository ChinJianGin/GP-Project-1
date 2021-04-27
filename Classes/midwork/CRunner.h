#pragma once

#include "midwork/CCharacter.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

class CRunner : public CCharacter {
private:
	int _MAX_HP, _NOW_HP;
	enum class _playerState{DEAD,ALIVE};
	CRunner::_playerState _nowState;
public:
	void characterInit(Sprite& loctag, Node& theScene) {
		_loctag = &loctag;
		_characterRoot = CSLoader::createNode("watsonrun.csb");
		_characterRoot->setPosition(loctag.getPosition());
		loctag.setVisible(false);
		theScene.addChild(_characterRoot, 5);

		_characterRect = Rect(loctag.getPosition().x - loctag.getContentSize().width / 2, loctag.getPosition().y - loctag.getContentSize().height / 2, loctag.getContentSize().width, loctag.getContentSize().height);

		_characterRunAct = CSLoader::createTimeline("watsonrun.csb");
		_characterRoot->runAction(_characterRunAct);		
		_characterRunAct->setTimeSpeed(1.0f);

		_characterJumpAct = CSLoader::createTimeline("watsonrun.csb");
		_characterRoot->runAction(_characterJumpAct);
		_characterJumpAct->setTimeSpeed(1.0f);

		_characterRollAct = CSLoader::createTimeline("watsonrun.csb");
		_characterRoot->runAction(_characterRollAct);
		_characterRollAct->setTimeSpeed(1.0f);

		_characterJumpHighAct = CSLoader::createTimeline("watsonrun.csb");
		_characterRoot->runAction(_characterJumpHighAct);
		_characterJumpHighAct->setTimeSpeed(1.0f);

		_neutralFace = _characterRoot->getChildByName("neutral_face");
		_happyFace = _characterRoot->getChildByName("happy_face");
		_sadFace = _characterRoot->getChildByName("sad_face");

		_nowState = CRunner::_playerState::ALIVE;
		_MAX_HP = _NOW_HP = 10;
	}
	void update();
	CRunner::_playerState getNowState();
	Rect getRect() {
		return _characterRect;
	};
};