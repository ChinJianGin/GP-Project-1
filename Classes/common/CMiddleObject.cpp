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

void CMiddleObject::update(float dt)  // �ھڮɶ��ۤv����
{
	//�ثe�����ʳ]�w���ʪ��Z��
	Point pt1 = _road0->getPosition();
	pt1.x += dt * MOVESPEED;
	if ( pt1.x >= 1920) {
		// �N�D�����ʨ� +1280+640 �A���������������W�L -640 �h�������A�ҥH�O 2 * 1280 + pt1.x
		pt1.x = pt1.x -2 * 1280;
		// ��s������ܤ��e
		resetObj(0);
	}
	_road0->setPosition(pt1);

	pt1 = _road1->getPosition();
	pt1.x += dt * MOVESPEED;
	if (pt1.x >= 1920) {
		// �N�D�����ʨ� +1280+640 �A���������������W�L -640 �h�������A�ҥH�O 2 * 1280 + pt1.x
		pt1.x = pt1.x - 2 * 1280;
		// ��s������ܤ��e
		resetObj(1);
	}
	_road1->setPosition(pt1);
}

void  CMiddleObject::init(const std::string& roadname, const std::string& csbname, cocos2d::Node& parent, const cocos2d::Point locPt)
{
	std::string objname;
	// �إߨ�q�I�����Ҧ���¦
	_road0 = Sprite::createWithSpriteFrameName(roadname);
	_road1 = Sprite::createWithSpriteFrameName(roadname);
	_road0->setPosition(locPt);
	_road1->setPosition(locPt+Point(-1280,0));
	parent.addChild(_road0, 3); // ����I���h
	parent.addChild(_road1, 3); // ����I���h

	_road0obj[0] = CSLoader::createNode("./patterns/midobj.csb");
	_road0obj[1] = CSLoader::createNode("./patterns/midobj.csb");
	_road0obj[2] = CSLoader::createNode("./patterns/midobj.csb");
	_road1obj[0] = CSLoader::createNode("./patterns/midobj.csb");
	_road1obj[1] = CSLoader::createNode("./patterns/midobj.csb");
	_road1obj[2] = CSLoader::createNode("./patterns/midobj.csb");
	for (int i = 1; i <= 6; i++) // �N�T�ӥͦ��I�������󳣳]�w false
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
	// �N _road0obj �[�J _road0�A�ó]�w�ͦ�����m
	_road0->addChild(_road0obj[0], -1); _road0obj[0]->setPosition(genLoc[0] + Point(SHIFTX(X_OFFSET),0));
	_road0->addChild(_road0obj[1], -1); _road0obj[1]->setPosition(genLoc[1] + Point(SHIFTX(X_OFFSET), 0));
	_road0->addChild(_road0obj[2], -1); _road0obj[2]->setPosition(genLoc[2] + Point(SHIFTX(X_OFFSET), 0));
	resetObj(0);
	// �N _road1obj �[�J _road1�A�ó]�w�ͦ�����m
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
	// �ھ� genLoc[3] ��m����� _road0 �W
	//�H������ 0 �� 5 ���Ʀr
	// �N��Ӫ� visible �]�w�� false, �s�ͦ����]�w�� true
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