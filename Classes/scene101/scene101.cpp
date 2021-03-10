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

#include "scene101.h"
#include "SimpleAudioEngine.h"


#define HOME_BACKGROUND "scene101/s101bgimg.png"

USING_NS_CC;

Scene* Scene101::createScene()
{
    return Scene101::create();
}


// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Scene101::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. 增加場景中的物件
    // 2. add a menu item with "X" image, which is clicked to quit the program you may modify it.
    //以 Sprite 作為背景
    Sprite* bkimage = Sprite::create(HOME_BACKGROUND);  // 使用 create 函式,給予檔名即可
    bkimage->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y)); // 位置通常放置在螢幕正中間
    this->addChild(bkimage, 0);

    // 自行增加 sprite 將 bean01.png 到螢幕正中間

    /////////////////////////////
    // 3. add your codes below...

// 文字的加入
    // label 使用 TTF 與 BitMap Font
    auto labelTTF = Label::createWithTTF("Scene 101", "fonts/Marker Felt.ttf", 32);
    labelTTF->setAlignment(cocos2d::TextHAlignment::CENTER); // 預設靠左對齊
    labelTTF->setWidth(100);	// 設定每行文字的顯示寬度
    auto size = labelTTF->getContentSize();
    labelTTF->setPosition(Vec2(origin.x + visibleSize.width - size.width / 2 - 10, origin.y + visibleSize.height - size.height / 2 - 10));
    this->addChild(labelTTF, 1);

    //一般(非中文字)文字的顯示方式
    auto labelBMF = Label::createWithBMFont("fonts/couriernew32.fnt", "Scene 101");
    size = labelBMF->getContentSize();
    labelBMF->setColor(Color3B::WHITE);
    labelBMF->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - size.height));
    this->addChild(labelBMF, 1);

    // 中文字的顯示方式
    auto strings = FileUtils::getInstance()->getValueMapFromFile("scene101/strings.xml");
    std::string str1 = strings["text1"].asString();
    std::string str2 = strings["text2"].asString();
    auto labelchi1 = Label::createWithBMFont("fonts/msblack48.fnt", str1);
    auto labelchi2 = Label::createWithBMFont("fonts/msblack48.fnt", str2);
    size = labelchi1->getContentSize();
    labelchi1->setColor(Color3B(255, 238, 217));
    labelchi1->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 80 - size.height));
    this->addChild(labelchi1, 1);

    labelchi2->setColor(Color3B(238, 255, 227));
    size = labelchi2->getContentSize();
    labelchi2->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 140 - size.height));
    this->addChild(labelchi2, 1);
  
// Touch 與 Button 的處理
    // add Return Button
    this->returnbtn = Sprite::create("scene101/returnbtn.png");
    size = returnbtn->getContentSize();
    this->returnbtn->setPosition(Vec2(origin.x + size.width / 2 + 5, origin.y + visibleSize.height - size.height / 2 - 5));
    Point pos = returnbtn->getPosition();
    this->rectReturn = Rect(pos.x - size.width / 2, pos.y - size.height / 2, size.width, size.height);
    this->addChild(returnbtn, 1);

    // add Replay Button
    this->replaybtn = Sprite::create("scene101/replaybtn.png"); 
    size = replaybtn->getContentSize();
    this->replaybtn->setPosition(Vec2(origin.x + size.width / 2 + 90, origin.y + visibleSize.height - size.height / 2 - 5));
    pos = replaybtn->getPosition();
    this->rectReplay = Rect(pos.x - size.width / 2, pos.y - size.height / 2, size.width, size.height);
    this->addChild(replaybtn, 1);

    // add Cuber Button
    this->cuberbtn = Sprite::create("scene101/cuberbtn1.png");  
    size = cuberbtn->getContentSize();
    this->cuberbtn->setPosition(Vec2(origin.x + visibleSize.width - size.width / 2, origin.y + visibleSize.height - size.height / 2 - 60));
    pos = cuberbtn->getPosition();
    this->rectCuber = Rect(pos.x - size.width / 2, pos.y - size.height / 2, size.width, size.height);
    this->addChild(cuberbtn, 1);

    //this->_sceneno = 101;
    //strcpy(this->_cSceneNo, "Scene 101");

    //創建一個一對一的事件聆聽器
    auto listener = EventListenerTouchOneByOne::create();	
    listener->onTouchBegan = CC_CALLBACK_2(Scene101::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(Scene101::onTouchMoved, this);//加入觸碰移動事件
    listener->onTouchEnded = CC_CALLBACK_2(Scene101::onTouchEnded, this);//加入觸碰離開事件


    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);	//加入剛創建的事件聆聽器
    this->schedule(CC_SCHEDULE_SELECTOR(Scene101::update));

 //   schedule(CC_SCHEDULE_SELECTOR(Scene101::update));

    return true;
}

void Scene101::update(float dt)
{

}
//
//void Scene101::menuCloseCallback(Ref* pSender)
//{
//    //Close the cocos2d-x game scene and quit the application
//    Director::getInstance()->end();
//
//    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/
//
//    //EventCustom customEndEvent("game_scene_close_event");
//    //_eventDispatcher->dispatchEvent(&customEndEvent);
// }

bool Scene101::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)//觸碰開始事件
{
    Point touchLoc = pTouch->getLocation();
    if (rectCuber.containsPoint(touchLoc)) {

    }
    if (rectReplay.containsPoint(touchLoc)) {

    }
    if (rectReturn.containsPoint(touchLoc)) {
        unscheduleAllCallbacks();
        Director::getInstance()->end();
    }

  return true;
}


void Scene101::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) //觸碰移動事件
{


}

void  Scene101::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) //觸碰結束事件 
{



}