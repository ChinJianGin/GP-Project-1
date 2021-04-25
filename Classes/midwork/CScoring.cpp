#pragma

#include "midwork/CScoring.h"

USING_NS_CC;

bool CScoring::bigTosmall(int i, int j)
{
	return i > j;
}

void CScoring::init(Node& player, Node& theScene) {
	_hisScore[0] = _hisScore[1] = _hisScore[2] = _hisScore[3] = _hisScore[4] = _hisScore[5] = _hisScore[6] = _hisScore[7] = _hisScore[8] = _hisScore[9] = _hisScore[10] = 0;
	_score = { _hisScore, _hisScore+10 };
	ostr.str("");
	_nowScore = 0;
	ostr << _nowScore;
	_strNowScore = ostr.str();
	labelBMF = Label::createWithBMFont("fonts/couriernew32.fnt", _strNowScore);
	_player = &player;
}

void CScoring::ranking() {
	int i = 0;
	int localScore = 0;
	localScore = _nowScore;
	_score.push_back(localScore);
	std::sort(_score.begin(), _score.end(), bigTosmall);
	_score.pop_back();
	for (std::vector<int>::iterator first = _score.begin(), int i = 0; first != _score.end(); ++first, i++)
	{
		_hisScore[i] = *first;
		i++;
	}
	resetScore();
}

void CScoring::resetScore() {
	_nowScore = 0;
}

int CScoring::getNowScore() {
	return _nowScore;
}