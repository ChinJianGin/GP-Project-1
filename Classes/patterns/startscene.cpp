#include ".\patterns\startscene.h"
#include ".\patterns\gamesecne.h"


USING_NS_CC;


StartScene::StartScene()
{
    _startBtn = nullptr;
}

StartScene::~StartScene()
{
    CC_SAFE_DELETE(_startBtn);
    this->removeAllChildren();
    SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("startscene.plist");
    Director::getInstance()->getTextureCache()->removeUnusedTextures();
}


Scene* StartScene::createScene()
{
    return StartScene::create();
}



// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())  { return false; }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // 設定搜尋路徑
    std::vector<std::string> searchPath;
    searchPath.push_back("patterns/");
    CCFileUtils::getInstance()->setSearchPaths(searchPath);

    // 載入 cocos Studio 輸出的 csb 檔
    auto rootNode = CSLoader::createNode("/patterns/startscene.csb");
    this->addChild(rootNode); // 加入目前的 scene 中
    auto btnloc = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("startbtn"));
    btnloc->setVisible(false);

    _startBtn = new (std::nothrow) CButton();
    _startBtn->setProperty("startnormal.png", "starton.png", *this, btnloc->getPosition());
    _bToGameScene = false;

    //創建一個一對一的事件聆聽器
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(StartScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(StartScene::onTouchMoved, this);//加入觸碰移動事件
    listener->onTouchEnded = CC_CALLBACK_2(StartScene::onTouchEnded, this);//加入觸碰離開事件

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);	//加入剛創建的事件聆聽器
    this->schedule(CC_SCHEDULE_SELECTOR(StartScene::update));

    return true;
}



void StartScene::update(float dt)
{
    if (_bToGameScene) { // 切換到 SecondScene
        // 先將這個 SCENE 的 update  從 schedule update 中移出
        this->unschedule(schedule_selector(StartScene::update));
        SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("startscene.plist");
        //  設定場景切換的特效
        //TransitionFade *pageTurn = TransitionFade::create(1.0F, GameScene::createScene());
        //Director::getInstance()->replaceScene(pageTurn);
        Director::getInstance()->replaceScene(GameScene::createScene());
        // 關閉聲音寫在這裡
    }
}

bool StartScene::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)//觸碰開始事件
{
    Point touchLoc = pTouch->getLocation();
    _startBtn->touchesBegin(touchLoc);
    return true;
}


void StartScene::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) //觸碰移動事件
{
    Point touchLoc = pTouch->getLocation();
    _startBtn->touchesMoved(touchLoc);
}

void  StartScene::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) //觸碰結束事件 
{
    Point touchLoc = pTouch->getLocation();
    if (_startBtn->touchesEnded(touchLoc)) { // 進行場景的切換
        _bToGameScene = true;
    }
}