//
//  NSObject+getCurrentVC.h
//  BaiKeMiJiaLive
//
//  Created by neghao on 2017/6/22.
//  Copyright © 2017年 facebac.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (getCurrentVC)

///获取当前window最上层的控件器
- (UIViewController *)getCurrentTopViewController;

@end
