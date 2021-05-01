#pragma

#include "midwork/CScoring.h"

USING_NS_CC;

bool CScoring::bigTosmall(int i, int j)
{
	return i > j;
}

void CScoring::init(Node& player, Node& theScene, Size& visibleSize, Vec2& origin) {
	_hisScore[0] = _hisScore[1] = _hisScore[2] = _hisScore[3] = _hisScore[4] = _hisScore[5] = _hisScore[6] = _hisScore[7] = _hisScore[8] = _hisScore[9] = _hisScore[10] = 0;
	_score = { _hisScore, _hisScore+10 }; 
	ostr.str("");
	_nowScore = 0;
	ostr << _nowScore;
	_strNowScore = ostr.str();
	labelBMF = Label::createWithBMFont("fonts/couriernew32.fnt", _strNowScore);
	auto size = labelBMF->getContentSize();
	labelBMF->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - size.height));
	theScene.addChild(labelBMF, 11);
	_player = &player;
}

void CScoring::ranking() {
	int i = 0;
	int localScore = 0;
	localScore = _nowScore;
	_score.push_back(localScore);
	std::sort(_score.begin(), _score.end(), [](int i, int j) {return i > j; });
	_score.pop_back();
	for (std::vector<int>::iterator first = _score.begin(); first != _score.end(); ++first)
	{
		_hisScore[i] = *first;
		i++;
	}
	resetScore();
}

void CScoring::setScore(CEnemy& theEnemy)
{
	ostr.str(""); ostr.clear();
	if (theEnemy.getDifficulty() == CEnemy::LV::NORMAL)
	{
		_nowScore = _nowScore + 1;
		ostr << _nowScore;
		_strNowScore = ostr.str();
		labelBMF->setString(_strNowScore);
	}
	else if (theEnemy.getDifficulty() == CEnemy::LV::TALLER)
	{
		_nowScore = _nowScore + 2;
		ostr << _nowScore;
		_strNowScore = ostr.str();
		labelBMF->setString(_strNowScore);
	}
	else
	{
		_nowScore = _nowScore + 3;
		ostr << _nowScore;
		_strNowScore = ostr.str();
		labelBMF->setString(_strNowScore);
	}
}

void CScoring::resetScore() {
	ostr.str(""); ostr.clear();
	_nowScore = 0;
	ostr << _nowScore;
	_strNowScore = ostr.str();
	labelBMF->setString(_strNowScore);
}

int CScoring::getNowScore() {
	return _nowScore;
}