#pragma once

#include "cocos2d.h"
#include "vector"
#include "algorithm"
USING_NS_CC;

class CScoring
{
private:
	std::ostringstream ostr;	
	std::string _strNowScore;
	Label* labelBMF;
	Node* _player;
	int _nowScore;
	int _hisScore[10];
	std::vector<int> _score;
public:
	void init(Node& player,Node& theScene);
	void ranking();
	void pointCal();
	void resetScore();

	int getNowScore();
	bool bigTosmall(int i, int j);
};