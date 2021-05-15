#pragma

#include "midwork/CScoring.h"

USING_NS_CC;

using namespace std;

static CScoring* _singleScore = nullptr;

vector<int> _score = {0,0,0,0,0,0,0,0,0,0};

bool CScoring::bigTosmall(int i, int j)
{
	return i > j;
}

void CScoring::StartInit(Node& theScene, Size& visibleSize, Vec2& origin) {
	for (int j = 0; j < 10; j++)
	{
		log("big bug");
		ostr.str(""); ostr.clear();
		ostr << _hisScore[j];
		_strNowScore = ostr.str();
		labelBMF = Label::createWithBMFont("fonts/couriernew32.fnt", _strNowScore);
		auto size = labelBMF->getContentSize();
		labelBMF->setPosition(Vec2(origin.x + visibleSize.width / 10 + (j * 50), origin.y + visibleSize.height / 8 - size.height));
		theScene.addChild(labelBMF, 11);
	}	
}

void CScoring::GameInit(Node& theScene, Size& visibleSize, Vec2& origin) 
{
	log("initscore");
	ostr.str(""); ostr.clear();
	_nowScore = 0;
	ostr << _nowScore;
	_strNowScore = ostr.str();
	labelBMF = Label::createWithBMFont("fonts/couriernew32.fnt", _strNowScore);
	auto size = labelBMF->getContentSize();
	labelBMF->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - size.height));
	theScene.addChild(labelBMF, 11);
}

void CScoring::ranking(int nowscore) {
	log("ranking");
	int i = 0;
	int localScore = 0;
	localScore = nowscore;
	_score.push_back(localScore);
	sort(_score.begin(), _score.end(), [](int i, int j) {return i > j; });
	_score.pop_back();
	vector<int>::iterator first1 = _score.begin();
	log("%d",  first1);

	for (vector<int>::iterator first = _score.begin(); first != _score.end(); ++first)
	{
		log("ranking");
		_hisScore[i] = *first;
		i++;
	}
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

CScoring* CScoring::getSingleScore()
{
	if (_singleScore == nullptr)
	{
		_singleScore = new CScoring();
	}
	return _singleScore;
}

int CScoring::gethisscore()
{
	return _hisScore[0];
}

void CScoring::singleDelete()
{
	delete _singleScore;
}