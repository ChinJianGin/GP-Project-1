#include ".\patterns\midworkgamesecne.h"
#include ".\patterns\startscene.h"
#include ".\patterns\startscene.h"

#include <unordered_map>

USING_NS_CC;

#define MOVESPEED 125
#define MOVESPEED 125

GameScene::GameScene()
{
	_returnbtn = _runbtn = _jumpbtn = _rollbtn = _whichbtn = _resetbtn = nullptr;
	_bBoyJump = _bBoyRun = _bToStartScene = _watsonRoll = _resetJump = _resetRoll = false;
	_boyAction = nullptr;
	_midobj = nullptr;
	_boyRoot = nullptr;
	_irunid = _ijumpid = _irollid =-1;
	_watsonRunner = nullptr;
	_healthbar_1 = nullptr;
	_audio = nullptr;
	_enemycontroller = nullptr;
	_isHit = nullptr;
	_doOnce = false;
	_actionID = 0;
	_chargeTime = _timer1 = _timer2 = 0.0f;
	_addSpeed = 1.0f;
}

GameScene::~GameScene()
{
	CC_SAFE_DELETE(_returnbtn);
	CC_SAFE_DELETE(_runbtn);
	CC_SAFE_DELETE(_jumpbtn);
	CC_SAFE_DELETE(_midobj);
	CC_SAFE_DELETE(_rollbtn);
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

	std::vector<std::string> searchPath;
	searchPath.push_back("patterns/");
	CCFileUtils::getInstance()->setSearchPaths(searchPath);

	// ???J cocos Studio ???X?? csb ??
	auto rootNode = CSLoader::createNode("./patterns/gamescene.csb");
	this->addChild(rootNode); // ?[?J?ثe?? scene ??

	// ?̧?Ū???T?ӫ??s?????m,?ó]?w???????????s
	// ?^???e?@???????s?A?]?w Z ORDER ?? 11?A?b?̫e??
	auto loctag= dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("returnbtn"));
	loctag->setVisible(false);
	_returnbtn = new (std::nothrow) CButton();
	_returnbtn->setProperty("returnnormal.png", "returnon.png", *this, loctag->getPosition());
	_bToStartScene = false;


	// jump ???s
	loctag = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("jumpbtn"));
	loctag->setVisible(false);
	_jumpbtn = new (std::nothrow) CButton();
	_jumpbtn->setProperty("jumpnormal.png", "jumpon.png", *this, loctag->getPosition());

	//roll ???s
	loctag = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("rollbtn"));
	loctag->setVisible(false);
	_rollbtn = new (std::nothrow) CButton();
	_rollbtn->setProperty("runnormal.png", "runon.png", *this, loctag->getPosition());

	loctag = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("resetbtn"));
	loctag->setVisible(false);
	_resetbtn = new (std::nothrow) CButton();
	_resetbtn->setProperty("replaybtn.png", "runon.png", *this, loctag->getPosition());
	

	//?Ȧs
	_whichbtn = new (std::nothrow) CButton();

	
	_boyRoot = CSLoader::createNode("boyrunning.csb"); //Ū?J?`?I(node)????
	loctag = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("boyrun"));
	

	_audio = new audioController();

	_watsonRunner = new CRunner();
	_watsonRunner->characterInit(*loctag, *this);
	_watsonRunner->doRun();

	_enemycontroller = new enemySpawn();
	_enemycontroller->init(*loctag, *this);

	_score = CScoring::getSingleScore();
	_score->GameInit(*this, visibleSize, origin);	

	_healthbar_1 = dynamic_cast<cocos2d::ui::LoadingBar*>(rootNode->getChildByName("healthbar"));
	_healthbar_1->setDirection(cocos2d::ui::LoadingBar::Direction::LEFT);
	_healthbar_1->setPercent(100);
	_healthbar_1->setGlobalZOrder(11);

	_isHit = new calhit();
	_isHit->init(*_enemycontroller, *_watsonRunner, *loctag, *_score, *_healthbar_1);

		//?[?J?i?ʪ?????
	loctag = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("road00"));
	loctag->setVisible(false);
	_midobj = new (std::nothrow) CMiddleObject();
	_midobj->init("road00.png", "midobj.csb", *this, loctag->getPosition());

    //?Ыؤ䴩?h?IĲ?????ƥ???ť??
    auto listener = EventListenerTouchAllAtOnce::create();;
	listener->onTouchesBegan = CC_CALLBACK_2(GameScene::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(GameScene::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(GameScene::onTouchesEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(GameScene::onTouchesCancelled, this);

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);	//?[?J???Ыت??ƥ???ť??
    this->schedule(CC_SCHEDULE_SELECTOR(GameScene::update));

    return true;
}


void GameScene::update(float dt)
{
	// ?C???e?????????? MOVESPEED ??PIXEL	
	
	if ( _addSpeed == 1)
	{
		_midobj->update(dt);
		_enemycontroller->update(dt);
	}
	else
	{
		_midobj->update(dt + (_addSpeed / 1000));
		_enemycontroller->update(dt + (_addSpeed / 700));
		
	}
	if (_score->getNowScore() / 10 == _addSpeed)_addSpeed++;
	
	
	
	_watsonRunner->update(dt, _boypt, _actionID, *_whichbtn);
	_isHit->update(dt, _actionID);
	//log("%f",_watsonRunner->getRoot()->getPosition().y);   //////Debug
	//log("%f", _chargeTime);								//////Debug
	//log("%d", _score->gethisscore());						//////Debug
	if (_watsonRunner->getNowHP() <= 0)
	{//player dead
		_score->ranking(_score->getNowScore());
		_reset();
	}
	if (_bBoyJump)
	{
		_chargeTime += dt;
	}

	if (_resetRoll)
	{
		_timer1 += dt;
		//log("_timer = %f", _timer1);
		if (_timer1 >= 2)
		{
			_watsonRoll = false;
		}
		if (_timer1 >= 6.0f)
		{
			_timer1 = 0.0f;
			_resetRoll = false;
			_rollbtn->setEnabled(true);
		}
	}

	if (_resetJump)
	{
		_timer2 += dt;
		if (_timer2 >= 1.0f)
		{
			_timer2 = 0;
			_resetJump = false;
		}
	}

	if (_bToStartScene) {
		// ???N?o?? SCENE ?? update?q schedule update ?????X
		this->unschedule(schedule_selector(GameScene::update)); 
		SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("gamescene.plist");
		TransitionFade* pageTurn = TransitionFade::create(1.0F, StartScene::createScene());
		Director::getInstance()->replaceScene(pageTurn);
		_audio->setAudioState();
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
		// ?x?sĲ???I?y?лP?????? ID
		 if (!_watsonRoll && _jumpbtn->touchesBegin(touchLoc)) {
			_bBoyJump = true;
			_ijumpid = touchId;
			_boypt = _watsonRunner->getRoot()->getPosition();
		}
		else if (!_resetJump && !_bBoyJump && _rollbtn->touchesBegin(touchLoc)) {
			_resetRoll = true;
			_watsonRoll = true;
			_irollid = touchId;
			_whichbtn = _rollbtn;
			_actionID = _watsonRunner->doRoll();
			_boypt = _watsonRunner->getRoot()->getPosition();
		}
		else {
			_resetbtn->touchesBegin(touchLoc);
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
		auto PreLoc = touchMap.at(touchId);	// ?d?߳o??ID ?e?@??Ĳ???I???y??
		touchMap.erase(touchId);			// ?R???o?? ID ?b MAP ???????e
		touchMap.insert(std::unordered_map<int, Vec2>::value_type(touchId, touchLoc));  // ?N?ثe?o?ӷs???[?J
		if ((_ijumpid == touchId) && _bBoyJump) {
			_jumpbtn->touchesMoved(touchLoc); // ?u?O?? jump ???s????????, ?????????????s?ϰ???
		}
		else if ((_irollid == touchId) && _watsonRoll) {
			_rollbtn->touchesMoved(touchLoc); // ?u?O?? jump ???s????????, ?????????????s?ϰ???
		}
		else {
			_resetbtn->touchesMoved(touchLoc);
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
		auto PreLoc = touchMap.at(touchId);	// ?d?߳o?? ID ?e?@??Ĳ???I???y??
		touchMap.erase(touchId);			// ?R???o?? ID ?b MAP ???????e
		if ((_ijumpid == touchId) && _bBoyJump) { // ?o?? touch ?I???e?O?I?b runbtn ?W
			_jumpbtn->touchesEnded(touchLoc);
			_bBoyJump = false;
			_irunid = -1;
			if (_chargeTime > 0.5f) 
			{
				_resetJump = true;
				_whichbtn = _jumpbtn;
				_actionID = _watsonRunner->doJumpHigh();
				_chargeTime = 0;
			}
			else 
			{
				_resetJump = true;
				_whichbtn = _jumpbtn;
				_actionID = _watsonRunner->doJump();
				_chargeTime = 0;
			}
			
		}
		else if ((_irollid == touchId) && _watsonRoll) {
			_rollbtn->touchesEnded(touchLoc);
			_irollid = -1;
		}
		else {
			if (_resetbtn->touchesEnded(touchLoc))_reset();
			if ( _returnbtn->touchesEnded(touchLoc) ) _bToStartScene = true;
			CCLOG("%d",_bToStartScene);
		}
	}
}

void GameScene::onTouchesCancelled(const std::vector<Touch*>& touches, Event* event)
{
	onTouchesEnded(touches, event);
}

void GameScene::_reset()
{
	_bBoyJump = _bBoyRun = _bToStartScene = _watsonRoll = _resetJump = _resetRoll = false;
	_irunid = _ijumpid = _irollid = -1;
	_actionID = 0;
	_addSpeed = 0.0f;
	_boypt = Point(0, 0);
	_chargeTime = _timer1 = _timer2 = 0.0f;
	_midobj->resetObj(0); _midobj->resetObj(1);
	_watsonRunner->resetRunner();
	_healthbar_1->setPercent(_watsonRunner->getHPpercent());
	_score->resetScore();
	_enemycontroller->resetEnemies(0); _enemycontroller->resetEnemies(1); _enemycontroller->resetEnemies(2);
}