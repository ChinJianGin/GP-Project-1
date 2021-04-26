#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "audio/include/AudioEngine.h"

using namespace cocos2d::experimental;

class audioController
{
private:
	int _jump;
	int _spawn;
	int _hit;
	int _ibgMusic;
public:
	audioController()
	{
		_ibgMusic = AudioEngine::play2d("./scene101/music/groundpound.mp3", true);
		_jump = AudioEngine::play2d("./scene101/music/thinking cloud.mp3", false);
		AudioEngine::setVolume(_ibgMusic, 1.0f);
	}
	~audioController();


};