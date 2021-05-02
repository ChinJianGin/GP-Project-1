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
	int _nowScore;
	int _hisScore[10];	
public:
	void StartInit(Node& theScene, Size& visibleSize, Vec2& origin);
	void GameInit(Node& theScene, Size& visibleSize, Vec2& origin);
	void ranking(int nowscore);
	void resetScore();
	void setScore(CEnemy& theEnemy);

	int getNowScore();
	bool bigTosmall(int i, int j);

	static CScoring* getSingleScore();

	int gethisscore();
};