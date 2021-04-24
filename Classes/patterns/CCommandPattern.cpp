#include "patterns/CCommandPattern.h"

CInputHandler::CInputHandler()
{
	_iKey = BTN_NONE;
	_btn_X = _btn_Y = nullptr;
}
void CInputHandler::bindingCommand()
{
	_btn_X = new (std::nothrow) CJumpCommand();  // �쵲�� Command �������l����
	_btn_Y = new (std::nothrow) CFireCommand();  // �쵲�� Command �������l����
}
CInputHandler::~CInputHandler()
{
	CC_SAFE_DELETE(_btn_X);	// ������o���귽
	CC_SAFE_DELETE(_btn_Y);	// ������o���귽
}
CCommand* CInputHandler::handleInput()
{
	if (_iKey == BTN_X) { 
		_iKey = BTN_NONE;	// �B�z�����A�M���ثe�����s�]�w
		return _btn_X;		// ���B�Ǧ^�b bindingCommand �ҫ��V�� CJumpCommand ����
	}
	else if (_iKey == BTN_Y) {
		_iKey = BTN_NONE;	// �B�z�����A�M���ثe�����s�]�w
		return _btn_Y;		// ���B�Ǧ^ bindingCommand �ҫ��V�� CFireCommand ����
	}
	else return nullptr;
}
void CInputHandler::setPressed(int itype) { _iKey = itype; }
