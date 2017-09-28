//
//  NSTimer+AutoRetain.m
//  BaiKeTheVoice
//
//  Created by NegHao on 2017/1/8.
//  Copyright © 2017年 facebac.com. All rights reserved.
//

#import "NSTimer+AutoRetain.h"

@implementation NSTimer (AutoRetain)
+ (NSTimer *)nh_scheduledTimerWithTimeInterval:(NSTimeInterval)inerval repeats:(BOOL)repeats block:(void (^)(NSTimer *timer))block{
    
    return [NSTimer scheduledTimerWithTimeInterval:inerval target:self selector:@selector(nh_blcokInvoke:) userInfo:[block copy] repeats:repeats];
}

+ (void)nh_blcokInvoke:(NSTimer *)timer {
    
    void (^block)(NSTimer *timer) = timer.userInfo;
    
    if (block) {
        block(timer);
    }
}

@end
