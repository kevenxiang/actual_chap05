//
//  LabelTTFTest.hpp
//  actual_chap05
//
//  Created by xiang on 2017/6/27.
//
//

#ifndef LabelTTFTest_hpp
#define LabelTTFTest_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class LabelTTFTest : public cocos2d::Layer {
public:
    static Scene *createScene();
    
    virtual bool init();
    
    CREATE_FUNC(LabelTTFTest);
};

#endif /* LabelTTFTest_hpp */
