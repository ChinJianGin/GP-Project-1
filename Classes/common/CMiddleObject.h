#pragma once // �@�ӫD�зǦ��O�Q�s�x�䴩���e�m�B�z�Ÿ��A�����ɮ׸��J���l�ɮɡA�u�|�b�ӭ�l�ɤ��Q�]�t�@��

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "midwork/CEnemy.h"
#include "midwork/CNormalEnemy.h"
#include "midwork/CSpeedEnemy.h"
#include "midwork/CTallerEnemy.h"

class CMiddleObject
{
private:
	cocos2d::Point    genLoc[3]; // �ͦ��b road �W�˹����� x �y�� �P y �y��
	cocos2d::Sprite*  _road0, *_road1;  // ��q�D��, �Ϥ��ӷ����O road00.png
	cocos2d::Node*    _road0obj[3], *_road1obj[3]; // ��q�D���W���T�Ӹ˹�����
	CEnemy* _road0ene[2], * _road1ene[2];

	int _iroad0on[3], _iroad1on[3]; // �����ثe�C�@�ӥͦ��I,��ܪ��O���@�Ӫ���

public:
	CMiddleObject();
	~CMiddleObject();
	void update(float dt);  // �ھڮɶ��ۤv����

	void init(const std::string& roadname, const std::string& csbname, cocos2d::Node& parent, const cocos2d::Point locPt);
	void resetObj(int itype);
};
