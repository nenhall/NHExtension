//
//  NSDictionary+BKJSON.h
//  BaiKeMiJiaLive
//
//  Created by chendb on 2017/4/17.
//  Copyright © 2017年 facebac.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (BKJSON)

//将nsstring类型的json数据结构   转化为NSDictionary类型结构
+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;

@end
