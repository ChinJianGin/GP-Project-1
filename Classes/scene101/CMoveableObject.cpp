#include "CMoveableObject.h"

USING_NS_CC;

// 目前先僅支援 Sprite
CMoveableObject::CMoveableObject()
{
	_pStage = nullptr;
	_bVisible = true;
	_sprSubject = nullptr;
	_bTouched = false;
}

// 設定可被移動物件的參數，sprite name, 所加入的scene 物件, 以及該 sprite 是否為隱藏
// Sprite is created with Sprite::create
void  CMoveableObject::setProperty(const std::string& filename, cocos2d::Scene& stage, bool bVisible)
{
	_sprSubject = Sprite::create(filename); // 必須確保圖片是存在，否則執行會有問題
	_pStage = &stage;
	_bVisible = bVisible;
	_pStage->addChild(_sprSubject);
}

// 僅產生 sprite 與設定是否出現，但不設定所在場景
void CMoveableObject::setProperty(const std::string& filename)
{
	_sprSubject = Sprite::create(filename); // 必須確保圖片是存在，否則執行會有問題
	// 這裡會有問題, 如果不立即將_sprSubject加入場景中，過一段時間就會被自動釋放
	// 解決的方式, 就是執行 retain 先設定該資源被使用，也就是 _referenceCount + 1
	// 之後就必須自己釋放，_sprSubject->release() 也就是 _referenceCount -1
	_sprSubject->retain();
}

// Sprite is created with Sprite::createWithSpriteFrameName
void CMoveableObject::setPropertySF(const std::string& filename, cocos2d::Scene& stage, bool bVisible)
{
	_sprSubject = Sprite::createWithSpriteFrameName(filename);
	_pStage = &stage;
	_bVisible = bVisible;
	_pStage->addChild(_sprSubject);
}

// Sprite is created with Sprite::createWithSpriteFrameName
void CMoveableObject::setPropertySF(const std::string& filename)
{
	_sprSubject = Sprite::createWithSpriteFrameName(filename); // 必須確保圖片是存在，否則執行會有問題
	// 這裡會有問題, 如果不立即將_sprSubject加入場景中，過一段時間就會被自動釋放
	// 解決的方式, 就是執行 retain 先設定該資源被使用，也就是 _referenceCount + 1
	// 之後就必須自己釋放，_sprSubject->release() 也就是 _referenceCount -1
	_sprSubject->retain();
}


CMoveableObject::~CMoveableObject()
{

}


void CMoveableObject::setVisible(bool bVisible)
{
	_bVisible = bVisible;
}

// 傳入的 scene object 必須是參照,否則.....
void CMoveableObject::attachToScene(cocos2d::Scene& stage, bool bVisible)
{
	_pStage = &stage;
	_pStage->addChild(_sprSubject);
	_bVisible = bVisible;
	// addChild 會讓 _referenceCount + 1，所以必須 check 是否之前有執行 retain()
	// 原則上每一個 sprite 加入場景, 應該 _referenceCount 為 1 ，超過就表示之前有執行 retain
	if (_pStage->getReferenceCount() > 1) _pStage->release();
}

void CMoveableObject::setPosition(const cocos2d::Point& pos)
{
	_pt = pos;
	_sprSubject->setPosition(_pt);
	// 建立觸控偵測所需要的基本資料
	_size = _sprSubject->getContentSize();
	_rect = Rect(_pt.x - _size.width / 2, _pt.y - _size.height / 2, _size.width, _size.height);
}

void CMoveableObject::onBegan(const cocos2d::Point& touchPt) //觸碰開始事件
{
	if (_rect.containsPoint(touchPt)) {
		_bTouched = true;
		_prept = touchPt;
	}
	else {
		if ( _bTouched ) _bTouched = false;
	}
}

void CMoveableObject::onMoved(const cocos2d::Point& touchPt) //觸碰移動事件
{
	if (_bTouched)
	{
		Point pt = touchPt - _prept;
		_pt += pt;
		_sprSubject->setPosition(_pt);
		// 更新左下角的位置即可
		_rect.origin.x = _pt.x - _size.width / 2;
		_rect.origin.y = _pt.y - _size.height / 2;
		_prept = touchPt;
	}

}
void CMoveableObject::onEnded(const cocos2d::Point& touchPt) //觸碰結束事件 
{
	if (_bTouched) _bTouched = false;
}
