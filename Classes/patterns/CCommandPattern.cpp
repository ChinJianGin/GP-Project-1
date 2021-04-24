#include "patterns/CCommandPattern.h"

CInputHandler::CInputHandler()
{
	_iKey = BTN_NONE;
	_btn_X = _btn_Y = nullptr;
}
void CInputHandler::bindingCommand()
{
	_btn_X = new (std::nothrow) CJumpCommand();  // 鏈結到 Command 的對應子物件
	_btn_Y = new (std::nothrow) CFireCommand();  // 鏈結到 Command 的對應子物件
}
CInputHandler::~CInputHandler()
{
	CC_SAFE_DELETE(_btn_X);	// 釋放取得的資源
	CC_SAFE_DELETE(_btn_Y);	// 釋放取得的資源
}
CCommand* CInputHandler::handleInput()
{
	if (_iKey == BTN_X) { 
		_iKey = BTN_NONE;	// 處理完畢，清除目前的按鈕設定
		return _btn_X;		// 此處傳回在 bindingCommand 所指向的 CJumpCommand 物件
	}
	else if (_iKey == BTN_Y) {
		_iKey = BTN_NONE;	// 處理完畢，清除目前的按鈕設定
		return _btn_Y;		// 此處傳回 bindingCommand 所指向的 CFireCommand 物件
	}
	else return nullptr;
}
void CInputHandler::setPressed(int itype) { _iKey = itype; }
