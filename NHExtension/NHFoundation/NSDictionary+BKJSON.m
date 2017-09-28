//
//  NSDictionary+BKJSON.m
//  BaiKeMiJiaLive
//
//  Created by chendb on 2017/4/17.
//  Copyright © 2017年 facebac.com. All rights reserved.
//

#import "NSDictionary+BKJSON.h"

@implementation NSDictionary (BKJSON)

+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString
{
    if (jsonString == nil) {
        return nil;
    }
//    NSString *newString = [jsonString stringByReplacingOccurrencesOfString:@"\"" withString:@""];
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    NSError *err;
    NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:jsonData
                                                        options:NSJSONReadingMutableLeaves
                                                          error:&err];
    if(err)
    {
        NSLog(@"json解析失败：%@",err);
        return nil;
    }
    return dic;
}

@end
