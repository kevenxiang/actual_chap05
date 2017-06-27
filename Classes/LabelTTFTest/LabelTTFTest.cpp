//
//  LabelTTFTest.cpp
//  actual_chap05
//
//  Created by xiang on 2017/6/27.
//
//

#include "LabelTTFTest.hpp"

Scene *LabelTTFTest::createScene() {
    auto scene = Scene::create();
    auto layer = LabelTTFTest::create();
    scene->addChild(layer);
    return scene;
}

bool LabelTTFTest::init() {
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label1 = Label::createWithTTF("center", "fonts/Marker Felt.ttf", 64);
    label1->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(label1);
    

    return true;
}













