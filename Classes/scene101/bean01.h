#pragma once
#include "cocos2d.h"

class bean01 {
private:
	cocos2d::Sprite* bean01_container = nullptr;
	cocos2d::Rect    bean01_rect;
	cocos2d::Point pt_cur, pt_old, pt_cal;
	cocos2d::Scene* scene_container = nullptr;
	cocos2d::Point bean_pos;
	cocos2d::Size bean_size;
	bean01* bean_self;
	float position_x, position_y;
	bool _bBean01;
	

public:
	bean01(const char *file_location,float bean01_x, float bean01_y, cocos2d::Scene* cur_Scene) {
		bean01_container = cocos2d::Sprite::create(file_location); 
		bean01_container->setPosition(bean01_x, bean01_y);
		position_x = bean01_x; position_y = bean01_y;
		scene_container = cur_Scene;
		getScene()->addChild(bean01_container, 0);
		bean_size = bean01_container->getContentSize();
		bean_pos = bean01_container->getPosition();
		bean01_rect = cocos2d::Rect(bean_pos.x - bean_size.width / 2, bean_pos.y - bean_size.height / 2, bean_size.width, bean_size.height);		
		_bBean01 = false;
	}
	~bean01();
	void setBean01_container(const char* file_location);
	void setBean01_rect();
	void setPt_cur(cocos2d::Point cur);
	void setPt_old(cocos2d::Point old);
	void set_bBean01(bool flag);
	void setBean(bean01* bean);
	void setBean_size(bean01* bean);
	void setBean_pos(bean01* bean);
	void beanOnTouchBegan(cocos2d::Point touchLoc);
	void beanOnTouchMove(cocos2d::Point touchLoc);
	void beanOnTouchEnd();
	float getPosition_x();
	float getPosition_y();
	cocos2d::Sprite* getBean01();
	cocos2d::Rect getBean01_rect();
	cocos2d::Point getPt_cur();
	cocos2d::Point getPt_old();
	cocos2d::Scene* getScene();
	cocos2d::Point drag_cal();
	cocos2d::Point getBean_pos();
	cocos2d::Size getBean_size();
	bean01* getBean();
	bool get_bBean01();
};