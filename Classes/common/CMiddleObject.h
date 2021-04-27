#pragma once // 一個非標準但是被廣泛支援的前置處理符號，讓該檔案載入到原始檔時，只會在該原始檔內被包含一次

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
	cocos2d::Point    genLoc[3]; // 生成在 road 上裝飾物的 x 座標 與 y 座標
	cocos2d::Sprite*  _road0, *_road1;  // 兩段道路, 圖片來源都是 road00.png
	cocos2d::Node*    _road0obj[3], *_road1obj[3]; // 兩段道路上的三個裝飾物件
	CEnemy* _road0ene[2], * _road1ene[2];

	int _iroad0on[3], _iroad1on[3]; // 紀錄目前每一個生成點,顯示的是哪一個物件

public:
	CMiddleObject();
	~CMiddleObject();
	void update(float dt);  // 根據時間自己移動

	void init(const std::string& roadname, const std::string& csbname, cocos2d::Node& parent, const cocos2d::Point locPt);
	void resetObj(int itype);
};
