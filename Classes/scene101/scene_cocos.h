/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __SCENE_COCOS_H__
#define __SCENE_COCOS_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"  // For Cocos Studio 控制項元件
#include "cocostudio/CocoStudio.h"
#include "patterns/CMoveableObject.h"

#define MOVEABLE_OBJECT 1

class SceneCocos : public cocos2d::Scene
{
private:
    cocos2d::Sprite* btn_cuber; // 場景中會放置的按鈕
    cocos2d::Sprite* btn_replay;
    cocos2d::Sprite* btn_return;
    cocos2d::Rect    cuber_rect;
    cocos2d::Rect    replay_rect;
    cocos2d::Rect    return_rect; //包含住按鈕的長方形
    cocos2d::ui::LoadingBar* _loadingBar;
    int  _sceneno;
    std::string _cSceneNo;
    cocos2d::Label* _labelBMF;

    // for Background Music
    int _ibgMusic;

    // for slider
    cocos2d::ui::Text* _sliderValue;	// 用於顯示目前滑動條上的數值

    // for animation control
    cocostudio::timeline::ActionTimeline* _triAction;

    cocos2d::Action *_jumpAction;
    cocos2d::Sprite *_runner;

public:
    SceneCocos();
    ~SceneCocos();

#ifdef MOVEABLE_OBJECT
    //std::unique_ptr<CMoveableObject> _mobj; //C++ 11 smart pointer, 無須釋放取得的資源, 會自動釋放
    CMoveableObject* _mobj;
#endif

    static cocos2d::Scene* createScene();
    virtual bool init();  
    void update(float dt);

    // 定義 Callback function
    void btn_CuberTouchEvent(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);

    void checkBoxTouchEvent(cocos2d::Ref* object, cocos2d::ui::CheckBox::EventType type);
    void sliderEvent(cocos2d::Ref* sender, cocos2d::ui::Slider::EventType type);

    bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //觸碰開始事件,回傳值必須是 bool
    void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //觸碰移動事件
    void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //觸碰結束事件 

    // implement the "static create()" method manually
    CREATE_FUNC(SceneCocos); //展開後定義了 create() 成員函式

};

#endif // __SCENE_102_H__
