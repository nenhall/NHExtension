//
//  UIView+test.m
//  NHExtensionDemo
//
//  Created by neghao on 2018/7/14.
//  Copyright © 2018年 neghao. All rights reserved.
//

#import "UIView+test.h"
#import <objc/runtime.h>


@implementation UIView (test)

/** 同步sett gett 方法 */
NH_SYNTHESIZE_CATEGORY_OBJ_PROPERTY(nh_superView, setNh_superView:)


@end
