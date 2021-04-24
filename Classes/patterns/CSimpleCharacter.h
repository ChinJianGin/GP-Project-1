#pragma once

#include "cocos2d.h"

class CSimpleCharacter : public cocos2d::Node
{
public:
	enum KeyPress{ BTN_NONE = -1, BTN_X = 1, BTN_Y, BTN_A };

	CSimpleCharacter();
	~CSimpleCharacter();
	
	void inputHandle(); // update �禡�I�s
	void setPressed(int itype); // ���s�I�s
	void J();
	void F();
	void S();

private:
	int _iKey; // �����ثe�Q���U�� key �s��
};

