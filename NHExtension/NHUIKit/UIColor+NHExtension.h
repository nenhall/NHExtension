//
//  UIColor+NHExtension.h
//  NHExtension
//
//  Created by simope on 16/7/19.
//  Copyright © 2016年 facebac. All rights reserved.
//

#import <UIKit/UIKit.h>

//颜色字符串返回一个颜色组
#define  kHexColor(hex)        [UIColor colorWithHEX:hex]
#define  kcallColor(hex)        [UIColor callColorFromHexRGB:hex]

//通过图片获取图片颜色
#define  kColorWithPatternImage(image)    \
[UIColor colorWithPatternImage:image]

//通过图片名获取图片颜色
#define  kColorWithPatternImageName(imageName) \
[UIColor colorWithPatternImageName:imageName]

/*****************************设置随机颜色******************************/
#define kRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]

/*****************************设置RGB颜色/设置RGBA颜色******************************/
#define kRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.f green:(g)/255.f blue:(b)/255.f alpha:a]
#define kBlackColor      [UIColor blackColor]
#define kDarkGrayColor   [UIColor darkGrayColor]
#define kLightGrayColor  [UIColor lightGrayColor]
#define kWhiteColor      [UIColor whiteColor]
#define kGrayColor       [UIColor grayColor]
#define kRedColor        [UIColor redColor]
#define kGreenColor      [UIColor greenColor]
#define kBlueColor       [UIColor blueColor]
#define kCyanColor       [UIColor cyanColor]
#define kYellowColor     [UIColor yellowColor]
#define kMagentaColor    [UIColor magentaColor]
#define kOrangeColor     [UIColor orangeColor]
#define kPurpleColor     [UIColor purpleColor]
#define kBrownColor      [UIColor brownColor]
#define kClearColor      [UIColor clearColor]

@interface UIColor (NHExtension)

+ (UIColor *)colorWithHEX:(uint)color;
+ (NSArray*)colorForHex:(NSString *)hexColor;
+ (UIColor *)colorWithHexString:(NSString *)color;  //
+ (UIColor *)randomColor;
+ (UIColor *)flashColorWithRed:(uint)red green:(uint)green blue:(uint)blue alpha:(float)alpha;
+ (UIColor *)colorWithPatternImageName:(NSString *)imageName;

/*颜色:得到16#转rgb   增加*/
+ (UIColor *) callColorFromHexRGB:(NSString *) inColorString;

+ (UIColor *)colorWithHexString:(NSString *)color Alpha:(CGFloat)alpha;

@end
