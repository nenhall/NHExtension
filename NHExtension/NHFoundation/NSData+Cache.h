//
//  NSData+Cache.h
//  BaiKeMiJiaLive
//
//  Created by NegHao.W on 16/12/24.
//  Copyright © 2016年 facebac.com. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <UIKit/UIKit.h>

@interface NSData (Cache)

/**
 *  get image Data from DB
 *
 *  @param url url: URL unique identification
 *
 *  @return data of images
 */
+ (NSData *)getDataFromLocationApplicationCacheWithURL:(NSString *)url;

/**
 *  save image data to DB through MD5
 *
 *  @param url url: URL unique identification
 *
 *  @param image data to save
 */
+ (void)saveDataIntoLocationApplicationCacheWithURL:(NSString *)url image:(UIImage *)image;


/**
 *  when receiveMemeryWarning or need to clear memery, remove the image'data
 */
//+ (void)removeDataWhenReceiveMemeryWarning;

@end
