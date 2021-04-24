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

#include "scene_patterns.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d::ui;
//using namespace CocosDenshion;

extern cocos2d::Size fSize;


ScenePatterns::ScenePatterns()
{
    btn_cuber = btn_cubersad = btn_return = nullptr;

#ifdef Character_Example
    // for runner
    _runnerRoot = nullptr;
    _body = nullptr;
    _neutalFace = nullptr;
    _happyFace = nullptr;
    _sadnessFace = nullptr;
    _iState = ScenePatterns::CuberStatus::NEUTAL;
    _bChanging = false;
    _fTimer = 0;
#endif
}

ScenePatterns::~ScenePatterns()
{
    SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("scene101.plist");
    SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("scene101bg.plist");
    Director::getInstance()->getTextureCache()->removeUnusedTextures(); // 釋放用不到的TEXTURE
}


Scene* ScenePatterns::createScene()
{
    return ScenePatterns::create();
}



// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool ScenePatterns::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

// 載入 cocos Studio 輸出的 csb 檔
    auto rootNode = CSLoader::createNode("scene_patterns.csb");
    this->addChild(rootNode); // 加入目前的 scene 中
    
    // 將放置在場景中的物件，建立一對應物的物件指標指向該物件
    // 為該物件(圖片)建立對應的 rect 資訊，以利後續的觸控測試
    btn_cuber = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("cuberbtn"));
    cocos2d::Size size = btn_cuber->getContentSize();
    cocos2d::Point pt = btn_cuber->getPosition();
    cuber_rect = Rect(pt.x - size.width / 2, pt.y - size.height / 2, size.width, size.height);

    btn_cubersad = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("cuberbtn_sad"));
    size = btn_cubersad->getContentSize();
    pt = btn_cubersad->getPosition();
    cubersad_rect = Rect(pt.x - size.width / 2, pt.y - size.height / 2, size.width, size.height);

    btn_return = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("returnbtn"));
    size = btn_return->getContentSize();
    pt = btn_return->getPosition();
    return_rect = Rect(pt.x - size.width / 2, pt.y - size.height / 2, size.width, size.height);

#ifdef Character_Example
    _runnerRoot = CSLoader::createNode("runner_demo.csb"); //讀入節點(node)資料
    _runnerRoot->setPosition(1040, 320);
    this->addChild(_runnerRoot); // 加入 scence 中

    // 讀取並設定動畫撥放
    _body = dynamic_cast<cocos2d::Sprite*>(_runnerRoot->getChildByName("body_cuber1"));
    _body->setColor(Color3B(135, 250, 50));
    _runnerAct = CSLoader::createTimeline("runner_demo.csb"); // 讀取動畫並建立【動作】
    _runnerAct->gotoFrameAndPlay(0, 24, true); // 撥放指定範圍內的動畫, true 代表重複撥放
    _runnerAct->setTimeSpeed(1.0f); // 一倍速
    _body->runAction(_runnerAct); // 讓 sprite 執行該【動作】

    _neutalFace = _runnerRoot->getChildByName("neutal_face");
    _happyFace = _runnerRoot->getChildByName("happy_face");
    _sadnessFace = _runnerRoot->getChildByName("sadness_face");
#endif



    //創建一個一對一的事件聆聽器
    auto listener = EventListenerTouchOneByOne::create();	
    listener->onTouchBegan = CC_CALLBACK_2(ScenePatterns::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(ScenePatterns::onTouchMoved, this);//加入觸碰移動事件
    listener->onTouchEnded = CC_CALLBACK_2(ScenePatterns::onTouchEnded, this);//加入觸碰離開事件

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);	//加入剛創建的事件聆聽器
    this->schedule(CC_SCHEDULE_SELECTOR(ScenePatterns::update));

    return true;
}

#ifdef Character_Example
void ScenePatterns::setExpression()
{


}
#endif

void ScenePatterns::update(float dt)
{
#ifdef Character_Example


#endif

#if Command_Pattern == 1
    player.inputHandle();
#else
    CCommand* cmd = inputHandle.handleInput();
    if (cmd != nullptr) cmd->execute(player);
#endif

}


bool ScenePatterns::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)//觸碰開始事件
{
    Point touchLoc = pTouch->getLocation();
#ifdef Character_Example


#endif

#if Command_Pattern == 1
    if (cuber_rect.containsPoint(touchLoc)) { player.setPressed(1); }
    if (cubersad_rect.containsPoint(touchLoc)) { player.setPressed(2); }
#else 
    if (cuber_rect.containsPoint(touchLoc)) { inputHandle.setPressed(1); }
    if (cubersad_rect.containsPoint(touchLoc)) { inputHandle.setPressed(2); }
#endif

    if (return_rect.containsPoint(touchLoc)) {
        unscheduleAllCallbacks();
        Director::getInstance()->end();
    }
  return true;
}



void ScenePatterns::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) //觸碰移動事件
{

}

void  ScenePatterns::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) //觸碰結束事件 
{


}