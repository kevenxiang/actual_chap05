//
//  MenuTest.hpp
//  actual_chap05
//
//  Created by xiang on 2017/6/27.
//
//

#ifndef MenuTest_hpp
#define MenuTest_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class MenuTest : public Layer {
public:
    static Scene *createScene();
    
    virtual bool init();
    
    // 菜单回调函数
    void menuPrintCallback();
    void menuItemToggle(Ref* pSender);
    
    // 选择器回调函数
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(MenuTest);
};


#endif /* MenuTest_hpp */
