#include "bean01.h"

cocos2d::Scene* bean01::getScene() {
	return scene_container;
}
void bean01::setBean01_container(const char* file_location) {
	bean01_container = cocos2d::Sprite::create(file_location);
}

void bean01::setBean01_rect() {
	bean01_rect = cocos2d::Rect(bean_pos.x - bean_size.width / 2, bean_pos.y - bean_size.height / 2, bean_size.width, bean_size.height);
}

void bean01::setPt_cur(cocos2d::Point cur) {
	pt_cur = cur;
}

void bean01::setPt_old(cocos2d::Point old) {
	pt_old = old;
}

void bean01::set_bBean01(bool flag) {
	_bBean01 = flag;
}

void bean01::setBean(bean01* bean) {
	bean_self = bean;
}
void bean01::setBean_size(bean01* bean) {
	bean_size = bean->getBean01()->getContentSize();
}
void bean01::setBean_pos(bean01* bean) {
	bean_pos = bean->getBean01()->getPosition();
}
float bean01::getPosition_x() {
	return position_x;
}
float bean01::getPosition_y() {
	return position_y;
}
cocos2d::Sprite* bean01::getBean01() {
	return bean01_container;
}

cocos2d::Rect bean01::getBean01_rect() {
	return bean01_rect;
}

cocos2d::Point bean01::getPt_cur() {
	return pt_cur;
}

cocos2d::Point bean01::getPt_old() {
	return pt_old;
}

cocos2d::Point bean01::drag_cal() {
	pt_cal = pt_cur - pt_old;
	return pt_cal;
}
cocos2d::Point bean01::getBean_pos() {
	return bean_pos;
}
cocos2d::Size bean01::getBean_size() {
	return bean_size;
}
bean01* bean01::getBean() {
	return bean_self;
}
bool bean01::get_bBean01() {
	return _bBean01;
}