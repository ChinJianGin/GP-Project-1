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

#include "scene_cocos.h"
#include "cocostudio/CocoStudio.h"

//#include "SimpleAudioEngine.h"

//#define EXERCISE 1
//#define Audio_Example  1
//#define Sprite_Example 1
//#define Button_Example 1
//#define Button_Example 1
//#define TTFBMF_Example 1
//#define CheckBox_Example 1
//#define LoadingBar_Example 1
//#define Slider_Example 1


#ifdef Audio_Example 1
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#endif

USING_NS_CC;
using namespace cocostudio::timeline;
using namespace ui;
//using namespace CocosDenshion;

extern cocos2d::Size fSize;


SceneCocos::SceneCocos()
{
    btn_cuber = btn_replay = btn_return = nullptr;
    _sceneno = 0;
    _labelBMF = nullptr;
    _ibgMusic = -1; // 背景音樂的編號為 -1
}

SceneCocos::~SceneCocos()
{
#ifdef Audio_Example 1
    AudioEngine::end();
#endif

#if EXERCISE == 1
    _jumpAction->release();
#endif

}


Scene* SceneCocos::createScene()
{
    return SceneCocos::create();
}



// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SceneCocos::init()
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
    auto rootNode = CSLoader::createNode("mainscene.csb");
    this->addChild(rootNode); // 加入目前的 scene 中
    
    // 將放置在場景中的物件，建立一對應物的物件指標指向該物件
    // 為該物件(圖片)建立對應的 rect 資訊，以利後續的觸控測試
    btn_cuber = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("cuberbtn"));
    cocos2d::Size size = btn_cuber->getContentSize();
    cocos2d::Point pt = btn_cuber->getPosition();
    cuber_rect = Rect(pt.x - size.width / 2, pt.y - size.height / 2, size.width, size.height);

// 音樂與音效的加入
#ifdef Audio_Example
    _ibgMusic = AudioEngine::play2d("./scene101/music/sr_bg.mp3",true);
    auto effectid = AudioEngine::play2d("./scene101/music/gain_point.mp3", false);
    AudioEngine::setVolume(_ibgMusic, 0.4f);
    // AudioEngine::preload("./scene101/music/sr_bg.mp3"); // 事先載入背景音樂
#endif

// Sprite 的加入
 #ifdef Sprite_Example
    auto runner = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("cuber01"));
    runner->setColor(Color3B(75, 155, 77));
    pt = runner->getPosition();
    auto jumpAction = cocos2d::JumpTo::create(1.25f, Point(pt.x - 600, pt.y), 100, 3);
    auto tintTo = cocos2d::TintTo::create(1.25f, Color3B(50, 125, 250));
    runner->runAction(tintTo);
    runner->runAction(jumpAction);
#endif

#ifdef Button_Example
    Button* btn_cuber = dynamic_cast<Button*>(rootNode->getChildByName("btn_cuber"));
    btn_cuber->addTouchEventListener(CC_CALLBACK_2(SceneCocos::btn_CuberTouchEvent, this));
#endif
    
#ifdef TTFBMF_Example 
    auto textTTF = dynamic_cast<cocos2d::ui::Text*>(rootNode->getChildByName("textTTF"));
    textTTF->setColor(Color3B(200, 255, 50));
    auto textBMF = dynamic_cast<cocos2d::ui::TextBMFont*>(rootNode->getChildByName("textBMF"));
    textBMF->setColor(Color3B(200, 255, 50));
#endif

#ifdef CheckBox_Example 
    CheckBox* checkBox = dynamic_cast<CheckBox*>(rootNode->getChildByName("checkbox_1"));
    checkBox->addEventListener(CC_CALLBACK_2(SceneCocos::checkBoxTouchEvent, this));
#endif

#ifdef LoadingBar_Example
    auto loadingBar = dynamic_cast<cocos2d::ui::LoadingBar*>(rootNode->getChildByName("loadingbar_1"));
    loadingBar->setDirection(LoadingBar::Direction::LEFT);
    loadingBar->setPercent(50);
#endif

#ifdef Slider_Example
    _sliderValue = dynamic_cast<cocos2d::ui::Text*>(rootNode->getChildByName("sildetText")); // 使用文本的物件
    auto* slider = dynamic_cast<cocos2d::ui::Slider*>((rootNode->getChildByName("slider_1")));
    slider->addEventListener(CC_CALLBACK_2(SceneCocos::sliderEvent, this));
    slider->setPercent(50);
    slider->setMaxPercent(100);// 可以設定超過 100，但超過100會讓捲動鈕的顯示會有問題
#endif
  
// Touch 與 Button 的處理



    //創建一個一對一的事件聆聽器
    auto listener = EventListenerTouchOneByOne::create();	
    listener->onTouchBegan = CC_CALLBACK_2(SceneCocos::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(SceneCocos::onTouchMoved, this);//加入觸碰移動事件
    listener->onTouchEnded = CC_CALLBACK_2(SceneCocos::onTouchEnded, this);//加入觸碰離開事件

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);	//加入剛創建的事件聆聽器
    this->schedule(CC_SCHEDULE_SELECTOR(SceneCocos::update));

    return true;
}


void SceneCocos::btn_CuberTouchEvent(Ref* pSender, Widget::TouchEventType type)
{
    switch (type)
    {
    case Widget::TouchEventType::BEGAN:
        log("Touch Down"); break;
    case Widget::TouchEventType::MOVED:
        log("Touch Move"); break;
    case Widget::TouchEventType::ENDED:
#if EXERCISE == 1
        _runner->runAction(_jumpAction);
#endif
        log("Touch Up"); break;
    case Widget::TouchEventType::CANCELED:
        log("Touch Cancelled"); break;
    default: break;
    }
}

void SceneCocos::checkBoxTouchEvent(Ref* object, CheckBox::EventType type) {
    switch (type)
    {
    case CheckBox::EventType::UNSELECTED:  // 取消核取
        log("Unselected");
        break;
    case CheckBox::EventType::SELECTED:	 // 核取
        log("Selected");
        break;
    }
}

void  SceneCocos::sliderEvent(cocos2d::Ref* sender, cocos2d::ui::Slider::EventType type)
{
    if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
    {
        const Slider* slider = dynamic_cast<Slider*>(sender);
        int percent = slider->getPercent();	// 目前滑動條上的數值
        int maxPercent = slider->getMaxPercent(); // 滑動條的最大數值數值
        _sliderValue->setString(StringUtils::format("Percent %5.2f", 100.0 * percent / maxPercent));
    }
}


void SceneCocos::update(float dt)
{
#if EXERCISE == 2 //課堂練習二
    float t = _loadingBar->getPercent();
    if (t >= dt * 5)  t = t - dt * 5;
    else t = 0;
    _loadingBar->setPercent(t);
#endif
}



bool SceneCocos::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)//觸碰開始事件
{
    Point touchLoc = pTouch->getLocation();
    if (cuber_rect.containsPoint(touchLoc)) {
#ifdef Audio_Example
        if (AudioEngine::getState(_ibgMusic) == AudioEngine::AudioState::PLAYING) 	AudioEngine::pause(_ibgMusic);
        else AudioEngine::resume(_ibgMusic);
#endif
    }
    if (replay_rect.containsPoint(touchLoc)) {

    }
    if (return_rect.containsPoint(touchLoc)) {
        unscheduleAllCallbacks();
        Director::getInstance()->end();
    }

  return true;
}



void SceneCocos::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) //觸碰移動事件
{


}

void  SceneCocos::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) //觸碰結束事件 
{



}