#pragma once

#include "cocos2d.h"
#include "vector"
USING_NS_CC;

class CScoring
{
private:
	std::ostringstream ostr;	
	std::string _strNowScore;
	Label* labelBMF;
	Node* _player;
	int _nowScore;
	int _hisScore[11];
	std::vector<int> _score = { 0,0,0,0,0,0,0,0,0,0 };
public:
	void init(Node& player,Node& theScene);
	void ranking();
	void pointCal();
	void resetScore();
};