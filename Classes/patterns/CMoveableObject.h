#pragma once

#include "cocos2d.h"


class CMoveableObject : public cocos2d::Node
{
private:
    // 指向傳入的物件所加入的場景物件
    cocos2d::Scene* _pStage;

    // for Sprite
    bool _bVisible; // 該物件是否顯示
    bool _bTouched; // 該物件是否顯示
    cocos2d::Sprite* _sprSubject; // 場景中會放置的按鈕
    cocos2d::Rect    _rect;
    cocos2d::Size    _size;
    cocos2d::Point   _pt, _prept;

public:
    void setProperty(const std::string& filename, cocos2d::Scene& stage, bool bVisible=true);
    void setProperty(const std::string& filename);
    void setPropertySF(const std::string& filename, cocos2d::Scene& stage, bool bVisible = true);
    void setPropertySF(const std::string& filename);
    void attachToScene(cocos2d::Scene& stage, bool bVisible=true);
    void setVisible(bool bVisible);
    void setPosition(const cocos2d::Point& pos);


    void onBegan(const cocos2d::Point& touchPt); //觸碰開始事件
    void onMoved(const cocos2d::Point& touchPt); //觸碰移動事件
    void onEnded(const cocos2d::Point& touchPt); //觸碰結束事件 

	CMoveableObject();
	~CMoveableObject();

};