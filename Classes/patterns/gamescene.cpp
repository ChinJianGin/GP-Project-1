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

	// ���J cocos Studio ��X�� csb ��
	auto rootNode = CSLoader::createNode("./patterns/gamescene.csb");
	this->addChild(rootNode); // �[�J�ثe�� scene ��

	// �̧�Ū���T�ӫ��s����m,�ó]�w�����������s
	// �^��e�@�������s�A�]�w Z ORDER �� 11�A�b�̫e��
	auto loctag= dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("returnbtn"));
	loctag->setVisible(false);
	_returnbtn = new (std::nothrow) CButton();
	_returnbtn->setProperty("returnnormal.png", "returnon.png", *this, loctag->getPosition());
	_bToStartScene = false;

	// running ���s
	loctag = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("runbtn"));
	loctag->setVisible(false);
	_runbtn = new (std::nothrow) CButton();
	_runbtn->setProperty("runnormal.png", "runon.png", *this, loctag->getPosition());

	// jump ���s
	loctag = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("jumpbtn"));
	loctag->setVisible(false);
	_jumpbtn = new (std::nothrow) CButton();
	_jumpbtn->setProperty("jumpnormal.png", "jumpon.png", *this, loctag->getPosition());

	// �[�J�]�B�p�k��
	_boyRoot = CSLoader::createNode("boyrunning.csb"); //Ū�J�`�I(node)���
	loctag = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("boyrun"));
	//_boyRoot->setPosition(loctag->getPosition());
	//loctag->setVisible(false);
	//this->addChild(_boyRoot, 5); // �[�J scence ��, ��b�������e��
	//_boyAction = CSLoader::createTimeline("boyrunning.csb"); // Ū���ʵe�ëإߡi�ʧ@�j
	//_boyAction->gotoFrameAndPlay(0, 55, true); // ������w�d�򤺪��ʵe, true �N���Ƽ���
	//_boyAction->setTimeSpeed(1.0f); // �@���t
	//_boyRoot->runAction(_boyAction); // �� sprite ����ӡi�ʧ@�j

	_watsonRunner = new CRunner();
	_watsonRunner->characterInit(*loctag, *this);
	_watsonRunner->doRun();

	_normalEnemy = new tallerEnemy();
	_normalEnemy->characterInit(*loctag, *this);
	

	//�[�J�i�ʪ�����
	loctag = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("road00"));
	loctag->setVisible(false);
	_midobj = new (std::nothrow) CMiddleObject();
	_midobj->init("road00.png","midobj.csb", *this, loctag->getPosition());

    //�Ыؤ䴩�h�IĲ�����ƥ��ť��
    auto listener = EventListenerTouchAllAtOnce::create();;
	listener->onTouchesBegan = CC_CALLBACK_2(GameScene::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(GameScene::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(GameScene::onTouchesEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(GameScene::onTouchesCancelled, this);

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);	//�[�J��Ыت��ƥ��ť��
    this->schedule(CC_SCHEDULE_SELECTOR(GameScene::update));

    return true;
}

void GameScene::resetMiddle(int n) // ���s���ͫe��1 �����󪺦�m�P���A
{


}


void GameScene::update(float dt)
{
	// �C��e���������� MOVESPEED ��PIXEL
	if (_bBoyRun) {
		_midobj->update(dt);
	}
	if (_bToStartScene) {
		// ���N�o�� SCENE �� update�q schedule update �����X
		this->unschedule(schedule_selector(GameScene::update)); 
		//_boyAction->stop(); // ����]�B�p�k�ͪ��ʵe����
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
		// �x�sĲ���I�y�лP������ ID
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

		auto PreLoc = touchMap.at(touchId);	// �d�߳o��ID �e�@��Ĳ���I���y��
		touchMap.erase(touchId);			// �R���o�� ID �b MAP �������e
		touchMap.insert(std::unordered_map<int, Vec2>::value_type(touchId, touchLoc));  // �N�ثe�o�ӷs���[�J

		if ( (_irunid == touchId) && _bBoyRun ) { // �o�� touch �I���e�O�I�b runbtn �W
			if (!_runbtn->touchesMoved(touchLoc)) {	// �P�_�O�_�w�g���}�]�B����
				_bBoyRun = false;
				_irunid = -1;
			}
		}
		else if ((_ijumpid == touchId) && _bBoyJump) {
			_jumpbtn->touchesMoved(touchLoc); // �u�O�� jump ���s�������, �����������s�ϰ��
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
		auto PreLoc = touchMap.at(touchId);	// �d�߳o�� ID �e�@��Ĳ���I���y��
		touchMap.erase(touchId);			// �R���o�� ID �b MAP �������e

		if ( (_irunid == touchId) && _bBoyRun) { // ID �۲ŦӥB���b�]��
			_runbtn->touchesEnded(touchLoc); // �I�s���s�A�����A��_
			_bBoyRun = false;
			_irunid = -1;
		}
		else if ((_ijumpid == touchId) && _bBoyJump) { // �o�� touch �I���e�O�I�b runbtn �W
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