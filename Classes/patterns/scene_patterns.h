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

#ifndef __SCENE_PATTERNS_H__
#define __SCENE_PATTERNS_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"  // For Cocos Studio 控制項元件
#include "cocostudio/CocoStudio.h"
#include "patterns/CSimpleCharacter.h"
#include "patterns/CCommandPattern.h"

#define Character_Example 1
//#define Command_Pattern 2  // 1 未使用 Command Pattern,  2 使用 Command Pattern

class ScenePatterns : public cocos2d::Scene
{
public:

    ScenePatterns();
    ~ScenePatterns();

    enum class CuberStatus { NEUTAL, HAPPY, SADNESS };

    static cocos2d::Scene* createScene();
    virtual bool init();
    void update(float dt);

    bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //觸碰開始事件,回傳值必須是 bool
    void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //觸碰移動事件
    void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //觸碰結束事件 

    // implement the "static create()" method manually
    CREATE_FUNC(ScenePatterns); //展開後定義了 create() 成員函式

private:
    cocos2d::Sprite* btn_cuber; // 場景中會放置的按鈕
    cocos2d::Sprite* btn_cubersad; // 場景中會放置的按鈕
    cocos2d::Sprite* btn_return;
    cocos2d::Rect    cuber_rect;
    cocos2d::Rect    cubersad_rect;
    cocos2d::Rect    return_rect; //包含住按鈕的長方形

#ifdef Character_Example
    // For Runner
    cocos2d::Node* _runnerRoot;
    cocos2d::Sprite* _body;
    cocos2d::Node* _neutalFace;
    cocos2d::Node* _happyFace;
    cocos2d::Node* _sadnessFace;
    cocostudio::timeline::ActionTimeline* _runnerAct;
    ScenePatterns::CuberStatus _iState; 
    bool _bChanging;
    float _fTimer; // 控制表情顯示的時間
    void setExpression();  // 改變表情的顯示
#endif

#if Command_Pattern == 1
    CSimpleCharacter player;
#else
    CSimpleCharacter player;
    CInputHandler inputHandle;
#endif

};

#endif // __SCENE_PATTERNS_H__
