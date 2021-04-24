#include "CSimpleCharacter.h"

USING_NS_CC;

CSimpleCharacter::CSimpleCharacter() { _iKey = BTN_NONE; }

CSimpleCharacter::~CSimpleCharacter(){ }

void CSimpleCharacter::inputHandle()
{
	if (_iKey == BTN_X) J();
	else if (_iKey == BTN_Y) F();
	else if (_iKey == BTN_A) S();
	_iKey = BTN_NONE; // 處理完畢，清楚目前的按鈕設定
}

void CSimpleCharacter::setPressed(int itype) { _iKey = itype; }

void CSimpleCharacter::J()
{
	CCLOG("Jump");
}
void CSimpleCharacter::F()
{
	CCLOG("Fire");
}
void CSimpleCharacter::S()
{
	CCLOG("Switch Weapon");
}
