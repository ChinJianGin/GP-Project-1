#include "scene101/CCommandPattern.h"

CInputHandler::CInputHandler()
{
	_btn_X = new (std::nothrow) CJumpCommand();
	_btn_Y = new (std::nothrow) CFireCommand();
	_iKey = BTN_NONE;
}

CInputHandler::~CInputHandler()
{
	CC_SAFE_DELETE(_btn_X);
	CC_SAFE_DELETE(_btn_Y);
}

CCommand* CInputHandler::handleInput()
{
	if (_iKey == BTN_X) {
		_iKey = BTN_NONE; // 處理完畢，清楚目前的按鈕設定
		return _btn_X;
	}
	else if (_iKey == BTN_Y) {
		_iKey = BTN_NONE; // 處理完畢，清楚目前的按鈕設定
		return _btn_Y;
	}
	else return nullptr;
}
void CInputHandler::setPressed(int itype) { _iKey = itype; }
