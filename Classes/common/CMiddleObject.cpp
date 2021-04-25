#include "CMiddleObject.h"

#define X_OFFSET  100
#define SHIFTX(X) ((rand()%(2*(X)))- (X))
#define MOVESPEED 125

USING_NS_CC;
using namespace cocostudio::timeline;

CMiddleObject::CMiddleObject()
{
	genLoc[0] = Point(240, 124); genLoc[1] = Point(640, 124); genLoc[2] = Point(1040, 124);
	_road1 = nullptr; _road0 = nullptr;
	_road0obj[0] = _road0obj[1] = _road0obj[2] = nullptr;
	_road1obj[0] = _road1obj[1] = _road1obj[2] = nullptr;
	_iroad0on[0] = _iroad0on[1] = _iroad0on[2] = 1;
	_iroad1on[0] = _iroad1on[1] = _iroad1on[2] = 1;
}

CMiddleObject::~CMiddleObject()
{
	
}

void CMiddleObject::update(float dt)  // 根據時間自己移動
{
	//目前的移動設定移動的距離
	Point pt1 = _road0->getPosition();
	pt1.x += dt * MOVESPEED;
	if ( pt1.x >= 1920) {
		// 將道路移動到 +1280+640 ，但必須扣除本身超過 -640 多的部分，所以是 2 * 1280 + pt1.x
		pt1.x = pt1.x -2 * 1280;
		// 更新物件的顯示內容
		resetObj(0);
	}
	_road0->setPosition(pt1);

	pt1 = _road1->getPosition();
	pt1.x += dt * MOVESPEED;
	if (pt1.x >= 1920) {
		// 將道路移動到 +1280+640 ，但必須扣除本身超過 -640 多的部分，所以是 2 * 1280 + pt1.x
		pt1.x = pt1.x - 2 * 1280;
		// 更新物件的顯示內容
		resetObj(1);
	}
	_road1->setPosition(pt1);
}

void  CMiddleObject::init(const std::string& roadname, const std::string& csbname, cocos2d::Node& parent, const cocos2d::Point locPt)
{
	std::string objname;
	// 建立兩段背景的所有基礎
	_road0 = Sprite::createWithSpriteFrameName(roadname);
	_road1 = Sprite::createWithSpriteFrameName(roadname);
	_road0->setPosition(locPt);
	_road1->setPosition(locPt+Point(-1280,0));
	parent.addChild(_road0, 3); // 高於背景層
	parent.addChild(_road1, 3); // 高於背景層

	_road0obj[0] = CSLoader::createNode("./patterns/midobj.csb");
	_road0obj[1] = CSLoader::createNode("./patterns/midobj.csb");
	_road0obj[2] = CSLoader::createNode("./patterns/midobj.csb");
	_road1obj[0] = CSLoader::createNode("./patterns/midobj.csb");
	_road1obj[1] = CSLoader::createNode("./patterns/midobj.csb");
	_road1obj[2] = CSLoader::createNode("./patterns/midobj.csb");
	for (int i = 1; i <= 6; i++) // 將三個生成點中的物件都設定 false
	{
		std::ostringstream ostr;
		ostr << "mid0" << i;
		objname = ostr.str();
		(_road0obj[0]->getChildByName(objname))->setVisible(false);
		(_road0obj[1]->getChildByName(objname))->setVisible(false);
		(_road0obj[2]->getChildByName(objname))->setVisible(false);
		(_road1obj[0]->getChildByName(objname))->setVisible(false);
		(_road1obj[1]->getChildByName(objname))->setVisible(false);
		(_road1obj[2]->getChildByName(objname))->setVisible(false);
	}
	// 將 _road0obj 加入 _road0，並設定生成的位置
	_road0->addChild(_road0obj[0], -1); _road0obj[0]->setPosition(genLoc[0] + Point(SHIFTX(X_OFFSET),0));
	_road0->addChild(_road0obj[1], -1); _road0obj[1]->setPosition(genLoc[1] + Point(SHIFTX(X_OFFSET), 0));
	_road0->addChild(_road0obj[2], -1); _road0obj[2]->setPosition(genLoc[2] + Point(SHIFTX(X_OFFSET), 0));
	resetObj(0);
	// 將 _road1obj 加入 _road1，並設定生成的位置
	_road1->addChild(_road1obj[0], -1); _road1obj[0]->setPosition(genLoc[0] + Point(SHIFTX(X_OFFSET), 0));
	_road1->addChild(_road1obj[1], -1); _road1obj[1]->setPosition(genLoc[1] + Point(SHIFTX(X_OFFSET), 0));
	_road1->addChild(_road1obj[2], -1); _road1obj[2]->setPosition(genLoc[2] + Point(SHIFTX(X_OFFSET), 0));
	resetObj(1);
}

// 0 for road0, 1 for road1
void CMiddleObject::resetObj(int itype)
{
	std::ostringstream ostr;
	std::string objname;
	// 根據 genLoc[3] 放置物件到 _road0 上
	//隨機產生 0 到 5 的數字
	// 將原來的 visible 設定成 false, 新生成的設定成 true
	if (itype == 0) {
		// for road0
		ostr << "mid0" << _iroad0on[0]; objname = ostr.str();
		(_road0obj[0]->getChildByName(objname))->setVisible(false);

		ostr.str(""); ostr.clear();
		ostr << "mid0" << _iroad0on[1]; objname = ostr.str();
		(_road0obj[1]->getChildByName(objname))->setVisible(false);

		ostr.str(""); ostr.clear();
		ostr << "mid0" << _iroad0on[2]; objname = ostr.str();
		(_road0obj[2]->getChildByName(objname))->setVisible(false);

		ostr.str(""); ostr.clear();
		_iroad0on[0] = rand() % 6 + 1; ostr << "mid0" << _iroad0on[0]; objname = ostr.str();
		(_road0obj[0]->getChildByName(objname))->setVisible(true); ostr.str(""); ostr.clear();

		_iroad0on[1] = rand() % 6 + 1; ostr << "mid0" << _iroad0on[1]; objname = ostr.str();
		(_road0obj[1]->getChildByName(objname))->setVisible(true); ostr.str(""); ostr.clear();

		_iroad0on[2] = rand() % 6 + 1; ostr << "mid0" << _iroad0on[2]; objname = ostr.str();
		(_road0obj[2]->getChildByName(objname))->setVisible(true); ostr.str(""); ostr.clear();
		_road0obj[0]->setPosition(genLoc[0] + Point(SHIFTX(X_OFFSET), 0));
		_road0obj[1]->setPosition(genLoc[1] + Point(SHIFTX(X_OFFSET), 0));
		_road0obj[2]->setPosition(genLoc[2] + Point(SHIFTX(X_OFFSET), 0));
	}
	else  {
		// for road1
		ostr << "mid0" << _iroad1on[0]; objname = ostr.str();
		(_road1obj[0]->getChildByName(objname))->setVisible(false);

		ostr.str(""); ostr.clear(); ostr << "mid0" << _iroad1on[1]; objname = ostr.str();
		(_road1obj[1]->getChildByName(objname))->setVisible(false);

		ostr.str(""); ostr.clear(); ostr << "mid0" << _iroad1on[2]; objname = ostr.str();
		(_road1obj[2]->getChildByName(objname))->setVisible(false);

		ostr.str(""); ostr.clear();
		_iroad1on[0] = rand() % 6 + 1; ostr << "mid0" << _iroad1on[0]; objname = ostr.str();
		(_road1obj[0]->getChildByName(objname))->setVisible(true); ostr.str(""); ostr.clear();

		_iroad1on[1] = rand() % 6 + 1; ostr << "mid0" << _iroad1on[1]; objname = ostr.str();
		(_road1obj[1]->getChildByName(objname))->setVisible(true); ostr.str(""); ostr.clear();

		_iroad1on[2] = rand() % 6 + 1; ostr << "mid0" << _iroad1on[2]; objname = ostr.str();
		(_road1obj[2]->getChildByName(objname))->setVisible(true); ostr.str(""); ostr.clear();

		_road1obj[0]->setPosition(genLoc[0] + Point(SHIFTX(X_OFFSET), 0));
		_road1obj[1]->setPosition(genLoc[1] + Point(SHIFTX(X_OFFSET), 0));
		_road1obj[2]->setPosition(genLoc[2] + Point(SHIFTX(X_OFFSET), 0));
	}
}