//
//  NSTimer+AutoRetain.h
//  BaiKeTheVoice
//
//  Created by NegHao on 2017/1/8.
//  Copyright © 2017年 facebac.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSTimer (AutoRetain)
+ (NSTimer *)nh_scheduledTimerWithTimeInterval:(NSTimeInterval)inerval
                                        repeats:(BOOL)repeats
                                          block:(void(^)(NSTimer *timer))block;
@end
