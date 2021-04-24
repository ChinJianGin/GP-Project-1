#pragma once

#include "cocos2d.h"

class CSimpleCharacter : public cocos2d::Node
{
public:
	enum KeyPress{ BTN_NONE = -1, BTN_X = 1, BTN_Y, BTN_A };

	CSimpleCharacter();
	~CSimpleCharacter();
	
	void inputHandle(); // update 函式呼叫
	void setPressed(int itype); // 按鈕呼叫
	void J();
	void F();
	void S();

private:
	int _iKey; // 紀錄目前被按下的 key 編號
};

