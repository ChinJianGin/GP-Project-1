//#pragma once
//
//// 以 Singleton Pattern 示範全域變數與常數的使用
//
//class CGlobalVariables {
//private:
//	int  _volume;	// 代表音量的大小
//	bool _bSound; // 代表音效是否開啟
//	bool _bVoice; // 代表語音是否開啟
//	static CGlobalVariables* _instance;
//
//public:
//	CGlobalVariables();
//	int setVolumn(int value);
//	void setSoundON(bool bv);
//	void setVoiceON(bool bv);
//	int getVolumn();
//	bool getSoundStatus();
//	bool getVoiceStatus();
//	static CGlobalVariables* getInstance();
//};
