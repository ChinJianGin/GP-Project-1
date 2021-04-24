#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "common/CButton.h"

class StartScene : public cocos2d::Scene
{
public:

    StartScene();
    ~StartScene();

    static cocos2d::Scene* createScene();
    virtual bool init();
    void update(float dt);

    bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //Ĳ�I�}�l�ƥ�,�^�ǭȥ����O bool
    void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //Ĳ�I���ʨƥ�
    void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //Ĳ�I�����ƥ� 

    // implement the "static create()" method manually
    CREATE_FUNC(StartScene); //�i�}��w�q�F create() �����禡

private:
    CButton* _startBtn;
    bool _bToGameScene;

};