//
//#include <new>
//#include "CGlobalVariables.h"
//
//using namespace std;
//
//CGlobalVariables::CGlobalVariables()
//{
//	_instance = nullptr;
//	_volume = 50; // 假設音量大小是 0 到 100
//	_bSound = _bVoice = true;
//}
//
//CGlobalVariables* CGlobalVariables::getInstance()
//{
//	if (_instance == nullptr) { // CGlobalVariables 的物件不存在
//		// 宣告 CGlobalVariables 的物件，並儲存在成員變數 _instance 中
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