//
//#include <new>
//#include "CGlobalVariables.h"
//
//using namespace std;
//
//CGlobalVariables::CGlobalVariables()
//{
//	_instance = nullptr;
//	_volume = 50; // ���]���q�j�p�O 0 �� 100
//	_bSound = _bVoice = true;
//}
//
//CGlobalVariables* CGlobalVariables::getInstance()
//{
//	if (_instance == nullptr) { // CGlobalVariables �����󤣦s�b
//		// �ŧi CGlobalVariables ������A���x�s�b�����ܼ� _instance ��
//		_instance = new (std::nothrow) CGlobalVariables();
//	}
//	return _instance;
//}
//
//int CGlobalVariables::setVolumn(int value) { _volume = value; }
//int CGlobalVariables::getVolumn() { return(_volume); }
//
//void CGlobalVariables::setSoundON(bool bv) { _bSound = bv; }
//bool CGlobalVariables::getSoundStatus() { return(_bSound); }
//
//void CGlobalVariables::setVoiceON(bool bv) { _bVoice = bv; }
//bool CGlobalVariables::getVoiceStatus() { return(_bVoice); }