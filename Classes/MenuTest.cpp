//
//  MenuTest.cpp
//  actual_chap05
//
//  Created by xiang on 2017/6/27.
//
//

#include "MenuTest.hpp"

Scene *MenuTest::createScene() {
    auto scene = Scene::create();
    auto layer = MenuTest::create();
    scene->addChild(layer);
    return scene;
}

bool MenuTest::init() {
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // ①标签菜单项（MenuItemLabel）的使用
    auto label = Label::createWithSystemFont("MenuItemLabel", "fonts/Marker Felt.ttf", 20);
    // 创建MenuItemLabel菜单项，第一个参数是菜单项中显示的标签对象，第二个参数是玩家点击时调用的回调函数。
    auto labelItem = MenuItemLabel::create(label, CC_CALLBACK_0(MenuTest::menuPrintCallback, this));
    labelItem->setPosition(Vec2(visibleSize.width/2, visibleSize.height * 0.9));
    
    // ②标签菜单项（MenuItemFont）的使用
    MenuItemFont::setFontName("Courier New");  //设置字体
    MenuItemFont::setFontSize(20);  //设置大小
    // 创建MenuItemFont菜单项，第一个参数是菜单项中显示的文字内容，第二个参数是玩家点击时调用的回调函数。
    auto fontItem = MenuItemFont::create("MenuItemFont", CC_CALLBACK_0(MenuTest::menuPrintCallback, this));
    fontItem->setPosition(Vec2(visibleSize.width/2, visibleSize.height * 0.7));
    
    // ③精灵菜单项（MenuItemSprite）的使用
    auto closeNormal = Sprite::create("CloseNormal.png");  // 创建正常状态精灵对象
    auto closeSelected = Sprite::create("CloseSelected.png"); // 创建选择状态精灵对象
    // 创建MenuItemSprite菜单项，
    // 第一个参数是正常状态的精灵对象，第二个参数是选择状态下的精灵对象，第三个参数是回调函数。
    auto closeSpriteItem = MenuItemSprite::create(closeNormal, closeSelected, CC_CALLBACK_1(MenuTest::menuCloseCallback, this));
    closeSpriteItem->setPosition(visibleSize.width/2, visibleSize.height * 0.5);
    
    // ④图片菜单项（MenuItemImage）的使用
    // 创建MenuItemImage菜单项，
    // 第一个参数是正常状态的纹理图片，第二个参数是选择状态下的纹理图片，第三个参数是回调函数。
    // 关闭菜单
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(MenuTest::menuCloseCallback, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2, origin.y + closeItem->getContentSize().height/2));
    
    // ⑤触发器菜单项（MenuItemToggle）的使用
    // 创建MenuItemToggle菜单项，
    // 第一个参数是回调函数，第二个参数和第三个参数都是MenuItem对象
    auto toggleItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(MenuTest::menuItemToggle, this), MenuItemFont::create("On"), MenuItemFont::create("Off"), NULL);
    toggleItem->setPosition(Vec2(visibleSize.width/2, visibleSize.height * 0.3));
    
    // ⑥创建一个菜单（Menu），用来装载各种菜单项
    auto menu = Menu::create(labelItem,fontItem,closeSpriteItem,closeItem,toggleItem, NULL);
    // 设置菜单项在屏幕的位置
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);
    
    return true;
}

// 点击MenuItemLabel和MenuItemFont菜单项的回调函数
void MenuTest::menuPrintCallback() {
    log("callback menuPrintCallback-->");
}

// 点击MenuItemToggle菜单项的回调函数
void MenuTest::menuItemToggle(cocos2d::Ref *pSender) {
    // 获得点击的菜单项的索引，默认情况下，On=1，Off=0
    log("selected index:%d",dynamic_cast<MenuItemToggle *>(pSender)->getSelectedIndex());
}

void MenuTest::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


























