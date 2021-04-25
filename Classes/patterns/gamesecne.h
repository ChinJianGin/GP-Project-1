#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "Common/CButton.h"
#include "Common/CMiddleObject.h"
#include "midwork/CCharacter.h"
#include "midwork/CRunner.h"
#include "midwork/CEnemy.h"
#include "midwork/CNormalEnemy.h"
#include "midwork/CTallerEnemy.h"
#include "midwork/CSpeedEnemy.h"
#include "midwork/CScoring.h"
class GameScene : public cocos2d::Scene
{
public:
    GameScene();
    ~GameScene();

    static cocos2d::Scene* createScene();
    virtual bool init();
    void update(float dt);

    void resetMiddle(int n); // ���s���ͫe�� n �����󪺦�m�P���A

    // �h�IĲ���B�z
    void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    void onTouchesCancelled(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene); //�i�}��w�q�F create() �����禡

private:
    CButton* _returnbtn, *_runbtn, *_jumpbtn;
    bool _bToStartScene, _bBoyRun, _bBoyJump;
    int _irunid, _ijumpid;

    // ���⪺����
    cocos2d::Node* _boyRoot;
    cocostudio::timeline::ActionTimeline* _boyAction;

    CMiddleObject * _midobj;

    CCharacter* _watsonRunner;

    CEnemy* _normalEnemy;

    CScoring* _score;
};
