#pragma once

#include "cocos2d.h"
#include "vector"
#include "algorithm"
#include "midwork/CEnemy.h"

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
	void init(Node& player,Node& theScene, Size& visibleSize, Vec2& origin);
	void ranking();
	void resetScore();
	void setScore(CEnemy& theEnemy);

	int getNowScore();
	bool bigTosmall(int i, int j);
};