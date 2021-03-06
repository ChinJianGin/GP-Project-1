#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
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
#include "midwork/audioController.h"
#include "midwork/enemySpawn.h"
#include "midwork/calHit.h"

class GameScene : public cocos2d::Scene
{
public:
    GameScene();
    ~GameScene();

    static cocos2d::Scene* createScene();
    virtual bool init();
    void update(float dt);

    // 多點觸控處理
    void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    void onTouchesCancelled(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene); //展開後定義了 create() 成員函式

    void _reset();

private:
    CButton* _returnbtn, *_runbtn, *_jumpbtn, *_rollbtn, *_resetbtn, *_whichbtn;
    bool _bToStartScene, _bBoyRun, _bBoyJump, _watsonRoll, _resetJump, _resetRoll;
    int _irunid, _ijumpid, _irollid;
    int _actionID;
    bool _doOnce;
    float _addSpeed;
    float _chargeTime;
    float _timer1,_timer2;

    // 角色的控制
    cocos2d::Node* _boyRoot;

    cocostudio::timeline::ActionTimeline* _boyAction;

    CMiddleObject * _midobj;

    CRunner* _watsonRunner;

    CScoring* _score;

    audioController* _audio;

    enemySpawn* _enemycontroller;

    calhit* _isHit;

    cocos2d::ui::LoadingBar* _healthbar_1;

    cocos2d::Point _boypt;
};
