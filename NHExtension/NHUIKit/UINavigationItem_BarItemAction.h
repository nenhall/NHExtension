//
//  UINavigationItem_BarItemAction.h
//  BaiKeMiJiaLive
//
//  Created by neghao on 2017/6/30.
//  Copyright © 2017年 facebac.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UINavigationItem ()

@property (nonatomic, copy) void (^navigationLeftBarItemDidClick)(UIButton *button);

@property (nonatomic, copy) void (^navigationRightBarItemDidClick)(UIButton *button);


@end
