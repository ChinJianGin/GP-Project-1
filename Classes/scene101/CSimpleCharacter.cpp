#include "CSimpleCharacter.h"

USING_NS_CC;

CSimpleCharacter::CSimpleCharacter() { _iKey = BTN_NONE; }

CSimpleCharacter::~CSimpleCharacter(){ }

void CSimpleCharacter::inputHandle()
{
	if (_iKey == BTN_X) J();
	else if (_iKey == BTN_Y) F();
	else if (_iKey == BTN_A) S();
	_iKey = BTN_NONE; // �B�z�����A�M���ثe�����s�]�w
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
