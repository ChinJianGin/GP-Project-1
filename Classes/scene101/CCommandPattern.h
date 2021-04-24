#pragma once

#include "scene101/CSimpleCharacter.h"

class CCommand
{
public:
	virtual ~CCommand() {}
	virtual void execute(CSimpleCharacter& actor) = 0; // �µ����禡
};

class CJumpCommand : public CCommand
{
public:
	virtual void execute(CSimpleCharacter& actor) { actor.J(); } 
};

class CFireCommand : public CCommand
{
public:
	virtual void execute(CSimpleCharacter& actor) { actor.F(); }
};

class CInputHandler
{
public:
	CInputHandler();
	~CInputHandler();
	enum KeyPress { BTN_NONE = -1, BTN_X = 1, BTN_Y, BTN_A };
	CCommand* handleInput();
	void setPressed(int itype); // ���s�I�s

private:
	CCommand* _btn_X;
	CCommand* _btn_Y;

	int _iKey; // �����ثe�Q���U�� key �s��
};