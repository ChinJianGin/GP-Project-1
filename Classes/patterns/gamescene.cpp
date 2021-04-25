#include ".\patterns\gamesecne.h"
#include ".\patterns\startscene.h"
#include ".\patterns\startscene.h"

#include <unordered_map>

USING_NS_CC;

#define MOVESPEED 125
#define MOVESPEED 125

GameScene::GameScene()
{
	_returnbtn = _runbtn = _jumpbtn = nullptr;
	_bBoyJump = _bBoyRun = _bToStartScene = false;
	_boyAction = nullptr;
	_midobj = nullptr;
	_boyRoot = nullptr;
	_irunid = _ijumpid = -1;
	_watsonRunner = nullptr;
	_normalEnemy = nullptr;
}

GameScene::~GameScene()
{
	CC_SAFE_DELETE(_returnbtn);
	CC_SAFE_DELETE(_runbtn);
	CC_SAFE_DELETE(_jumpbtn);
	CC_SAFE_DELETE(_midobj);
	this->removeAllChildren();
	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("gamescene.plist");
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
}


Scene* GameScene::createScene()
{
    return GameScene::create();
}



// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// 載入 cocos Studio 輸出的 csb 檔
	auto rootNode = CSLoader::createNode("./patterns/gamescene.csb");
	this->addChild(rootNode); // 加入目前的 scene 中

	// 依序讀取三個按鈕的位置,並設定成對應的按鈕
	// 回到前一頁的按鈕，設定 Z ORDER 為 11，在最前面
	auto loctag= dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("returnbtn"));
	loctag->setVisible(false);
	_returnbtn = new (std::nothrow) CButton();
	_returnbtn->setProperty("returnnormal.png", "returnon.png", *this, loctag->getPosition());
	_bToStartScene = false;

	// running 按鈕
	loctag = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("runbtn"));
	loctag->setVisible(false);
	_runbtn = new (std::nothrow) CButton();
	_runbtn->setProperty("runnormal.png", "runon.png", *this, loctag->getPosition());

	// jump 按鈕
	loctag = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("jumpbtn"));
	loctag->setVisible(false);
	_jumpbtn = new (std::nothrow) CButton();
	_jumpbtn->setProperty("jumpnormal.png", "jumpon.png", *this, loctag->getPosition());

	// 加入跑步小男生
	_boyRoot = CSLoader::createNode("boyrunning.csb"); //讀入節點(node)資料
	loctag = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("boyrun"));
	//_boyRoot->setPosition(loctag->getPosition());
	//loctag->setVisible(false);
	//this->addChild(_boyRoot, 5); // 加入 scence 中, 放在中景的前面
	//_boyAction = CSLoader::createTimeline("boyrunning.csb"); // 讀取動畫並建立【動作】
	//_boyAction->gotoFrameAndPlay(0, 55, true); // 撥放指定範圍內的動畫, true 代表重複撥放
	//_boyAction->setTimeSpeed(1.0f); // 一倍速
	//_boyRoot->runAction(_boyAction); // 讓 sprite 執行該【動作】

	_watsonRunner = new CRunner();
	_watsonRunner->characterInit(*loctag, *this);
	_watsonRunner->doRun();

	_normalEnemy = new tallerEnemy();
	_normalEnemy->characterInit(*loctag, *this);
	

	//加入可動的中景
	loctag = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("road00"));
	loctag->setVisible(false);
	_midobj = new (std::nothrow) CMiddleObject();
	_midobj->init("road00.png","midobj.csb", *this, loctag->getPosition());

    //創建支援多點觸控的事件聆聽器
    auto listener = EventListenerTouchAllAtOnce::create();;
	listener->onTouchesBegan = CC_CALLBACK_2(GameScene::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(GameScene::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(GameScene::onTouchesEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(GameScene::onTouchesCancelled, this);

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);	//加入剛創建的事件聆聽器
    this->schedule(CC_SCHEDULE_SELECTOR(GameScene::update));

    return true;
}

void GameScene::resetMiddle(int n) // 重新產生前景1 中物件的位置與狀態
{


}


void GameScene::update(float dt)
{
	// 每秒前景往左移動 MOVESPEED 個PIXEL
	if (_bBoyRun) {
		_midobj->update(dt);
	}
	if (_bToStartScene) {
		// 先將這個 SCENE 的 update從 schedule update 中移出
		this->unschedule(schedule_selector(GameScene::update)); 
		//_boyAction->stop(); // 停止跑步小男生的動畫撥放
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("gamescene.plist");
		TransitionFade* pageTurn = TransitionFade::create(1.0F, StartScene::createScene());
		Director::getInstance()->replaceScene(pageTurn);
	}
}
std::unordered_map<int, Vec2>touchMap;

void GameScene::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{
	for (auto& item : touches) {
		auto touch = item;
		auto touchLoc = touch->getLocation();
		int  touchId = touch->getID();
		touchMap.insert(std::unordered_map<int, Vec2>::value_type(touchId, touchLoc));
		// 儲存觸控點座標與對應的 ID
		if(_runbtn->touchesBegin(touchLoc)){
			_bBoyRun = true;
			_irunid = touchId;
			_watsonRunner->doRun();
		}
		else if (_jumpbtn->touchesBegin(touchLoc)) {
			_bBoyJump = true;
			_ijumpid = touchId;
		}
		else {
			_returnbtn->touchesBegin(touchLoc);
		}

	}
}


void GameScene::onTouchesMoved(const std::vector<Touch*>& touches, Event* event)
{
	for (auto& item : touches)
	{
		auto touch = item;
		auto touchLoc = touch->getLocation();
		int  touchId = touch->getID();

		auto PreLoc = touchMap.at(touchId);	// 查詢這個ID 前一個觸控點的座標
		touchMap.erase(touchId);			// 刪除這個 ID 在 MAP 中的內容
		touchMap.insert(std::unordered_map<int, Vec2>::value_type(touchId, touchLoc));  // 將目前這個新的加入

		if ( (_irunid == touchId) && _bBoyRun ) { // 這個 touch 點之前是點在 runbtn 上
			if (!_runbtn->touchesMoved(touchLoc)) {	// 判斷是否已經移開跑步按扭
				_bBoyRun = false;
				_irunid = -1;
			}
		}
		else if ((_ijumpid == touchId) && _bBoyJump) {
			_jumpbtn->touchesMoved(touchLoc); // 只是讓 jump 按鈕改變顯示, 當手指移除按鈕區域時
		}
		else {
			_returnbtn->touchesMoved(touchLoc);
		}
	}
}

void GameScene::onTouchesEnded(const std::vector<Touch*>& touches, Event* event)
{
	for (auto& item : touches)
	{
		auto touch = item;
		auto touchLoc = touch->getLocation();
		int  touchId = touch->getID();
		auto PreLoc = touchMap.at(touchId);	// 查詢這個 ID 前一個觸控點的座標
		touchMap.erase(touchId);			// 刪除這個 ID 在 MAP 中的內容

		if ( (_irunid == touchId) && _bBoyRun) { // ID 相符而且正在跑中
			_runbtn->touchesEnded(touchLoc); // 呼叫按鈕，讓狀態恢復
			_bBoyRun = false;
			_irunid = -1;
		}
		else if ((_ijumpid == touchId) && _bBoyJump) { // 這個 touch 點之前是點在 runbtn 上
			_jumpbtn->touchesEnded(touchLoc);
			_bBoyJump = false;
			_irunid = -1;
			_watsonRunner->doJumpHigh();
		}
		else {
			if ( _returnbtn->touchesEnded(touchLoc) ) _bToStartScene = true;
			CCLOG("%d",_bToStartScene);
		}
	}
}

void GameScene::onTouchesCancelled(const std::vector<Touch*>& touches, Event* event)
{
	onTouchesEnded(touches, event);
}