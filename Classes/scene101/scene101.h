/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __SCENE_101_H__
#define __SCENE_101_H__

#include "cocos2d.h"
class Scene101 : public cocos2d::Scene
{
private:
    cocos2d::Sprite* btn_cuber; // �������|��m�����s
    cocos2d::Sprite* btn_replay;
    cocos2d::Sprite* btn_return;
    cocos2d::Rect    cuber_rect;
    cocos2d::Rect    replay_rect;
    cocos2d::Rect    return_rect; //�]�t����s�������

    cocos2d::Sprite* bean01 = nullptr;
    cocos2d::Rect    bean01_rect;

    //int _sceneno;
    //std::string _strSceneNo;

public:
    Scene101();
    ~Scene101();
    static cocos2d::Scene* createScene();  // �^�ǭȫ��O�O Scene ���R�A����
    virtual bool init(); // �o�Ө禡�N�|�b create() �禡���Q�I�s
    void update(float dt);

    bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //Ĳ�I�}�l�ƥ�,�^�ǭȥ����O bool
    void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //Ĳ�I���ʨƥ�
    void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent); //Ĳ�I�����ƥ� 

    // implement the "static create()" method manually
    CREATE_FUNC(Scene101); //�i�}��w�q�F create() �����禡

};

#endif // __SCENE_101_H__
