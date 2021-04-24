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

    // �]�w�j�M���|
    std::vector<std::string> searchPath;
    searchPath.push_back("patterns/");
    CCFileUtils::getInstance()->setSearchPaths(searchPath);

    // ���J cocos Studio ��X�� csb ��
    auto rootNode = CSLoader::createNode("/patterns/startscene.csb");
    this->addChild(rootNode); // �[�J�ثe�� scene ��
    auto btnloc = dynamic_cast<cocos2d::Sprite*>(rootNode->getChildByName("startbtn"));
    btnloc->setVisible(false);

    _startBtn = new (std::nothrow) CButton();
    _startBtn->setProperty("startnormal.png", "starton.png", *this, btnloc->getPosition());
    _bToGameScene = false;

    //�Ыؤ@�Ӥ@��@���ƥ��ť��
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(StartScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(StartScene::onTouchMoved, this);//�[�JĲ�I���ʨƥ�
    listener->onTouchEnded = CC_CALLBACK_2(StartScene::onTouchEnded, this);//�[�JĲ�I���}�ƥ�

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);	//�[�J��Ыت��ƥ��ť��
    this->schedule(CC_SCHEDULE_SELECTOR(StartScene::update));

    return true;
}



void StartScene::update(float dt)
{
    if (_bToGameScene) { // ������ SecondScene
        // ���N�o�� SCENE �� update  �q schedule update �����X
        this->unschedule(schedule_selector(StartScene::update));
        SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("startscene.plist");
        //  �]�w�����������S��
        //TransitionFade *pageTurn = TransitionFade::create(1.0F, GameScene::createScene());
        //Director::getInstance()->replaceScene(pageTurn);
        Director::getInstance()->replaceScene(GameScene::createScene());
        // �����n���g�b�o��
    }
}

bool StartScene::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)//Ĳ�I�}�l�ƥ�
{
    Point touchLoc = pTouch->getLocation();
    _startBtn->touchesBegin(touchLoc);
    return true;
}


void StartScene::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) //Ĳ�I���ʨƥ�
{
    Point touchLoc = pTouch->getLocation();
    _startBtn->touchesMoved(touchLoc);
}

void  StartScene::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) //Ĳ�I�����ƥ� 
{
    Point touchLoc = pTouch->getLocation();
    if (_startBtn->touchesEnded(touchLoc)) { // �i�����������
        _bToGameScene = true;
    }
}