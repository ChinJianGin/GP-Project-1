#pragma once

#include "midwork/CRunner.h"

void CRunner::update(float dt, cocos2d::Point& _nowPos,int& whichAction, CButton& theButton)
{
	if (whichAction == 2)
	{
		_fjtime += dt;
		if (_characterJumpAct->getCurrentFrame() == 72) 
		{
			theButton.setEnabled(false);
			float dh = sinf(_fjtime * (M_PI / 2.0f));
			cocos2d::Point pt = _characterRoot->getPosition();
			pt.y = dh * 300 + _nowPos.y;
			_characterRoot->setPosition(pt);
		}
		else if (_characterJumpAct->getCurrentFrame() == 91)
		{
			float dh = cosf(_fjtime * (M_PI / 2.5f));
			cocos2d::Point pt = _characterRoot->getPosition();
			pt.y = _nowPos.y - dh;
			_characterRoot->setPosition(pt);
		}
		if (_characterJumpAct->getCurrentFrame() == 132)
		{ // 停止跳耀
			//_neutralFace->setVisible(true);
			_fjtime = 0;
			// 重設 boy Y軸高度, 避免多跳幾次後產生誤差
			_characterRoot->setPosition(_characterRoot->getPosition().x, _nowPos.y);
			//_boyAction->setTimeSpeed(1.0f); // 一倍速
			whichAction = 0;
			theButton.setEnabled(true);
		}
	}
	else if (whichAction == 4)
	{
		_fjtime += dt;
		if (_characterJumpHighAct->getCurrentFrame() == 135)
		{
			theButton.setEnabled(false);
			float dh = sinf(_fjtime * (M_PI / 1.0f));
			cocos2d::Point pt = _characterRoot->getPosition();
			pt.y = dh * 150 + _nowPos.y;
			_characterRoot->setPosition(pt);
		}
		else if (_fjtime > 0.4f && _characterJumpHighAct->getCurrentFrame() == 155)
		{
			float dh = sinf(_fjtime * (M_PI / 2.0f));
			cocos2d::Point pt = _characterRoot->getPosition();
			pt.y = dh * 150 + _nowPos.y;
			_characterRoot->setPosition(pt);
			
		}
		if (_fjtime > 1.15f && _characterJumpHighAct->getCurrentFrame() == 201)
		{ // 停止跳耀
			//_neutralFace->setVisible(true);
			_fjtime = 0;
			// 重設 boy Y軸高度, 避免多跳幾次後產生誤差
			_characterRoot->setPosition(_characterRoot->getPosition().x, _nowPos.y);
			//_boyAction->setTimeSpeed(1.0f); // 一倍速
			whichAction = 0;
			theButton.setEnabled(true);
		}
	}
	else if (whichAction == 3)
	{
		_fjtime += dt;
		if (_characterRollAct->getCurrentFrame() == 33)
		{
			theButton.setEnabled(false);
		}
		if (_fjtime >= 2.0f)
		{
			_characterRollAct->pause();
			doRun();
			log("do Run");
			//_neutralFace->setVisible(true);
			_fjtime = 0;
			_characterRoot->setPosition(_characterRoot->getPosition().x, _nowPos.y);
			whichAction = 0;
			//theButton.setEnabled(true);
		}
	}

}

void CRunner::setFace(int NO)
{
	bool neutral, sad, happy;
	neutral = sad = happy = false;
	if (NO == 1)
	{
		_neutralFace->setVisible(true);
		_sadFace->setVisible(false);
		_happyFace->setVisible(false);
		_characterRoot->setColor(Color3B(255, 255, 255));
	}
	else if (NO == 2)
	{
		sad = true;
		auto tintTo = cocos2d::TintTo::create(1.25f, Color3B(250, 50, 125));
		_characterRoot->runAction(tintTo);
		_neutralFace->setVisible(false);
		_sadFace->setVisible(true);
		_happyFace->setVisible(false);
	}
	else
	{
		happy = true;
		auto tintTo = cocos2d::TintTo::create(1.25f, Color3B(255, 255, 0));
		_characterRoot->runAction(tintTo);
		_neutralFace->setVisible(false);
		_sadFace->setVisible(false);
		_happyFace->setVisible(true);
	}
}