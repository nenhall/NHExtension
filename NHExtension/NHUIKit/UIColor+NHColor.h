//
//  UIColor+NHColor.h
//  DZNEmptyDataSet
//
//  Created by XiuDan on 2019/5/30.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (NHColor)

@property(class, nonatomic, readonly) UIColor *blackColor;      // 0.0 white
@property(class, nonatomic, readonly) UIColor *darkGrayColor;   // 0.333 white
@property(class, nonatomic, readonly) UIColor *lightGrayColor;  // 0.667 white
@property(class, nonatomic, readonly) UIColor *whiteColor;      // 1.0 white
@property(class, nonatomic, readonly) UIColor *grayColor;       // 0.5 white
@property(class, nonatomic, readonly) UIColor *redColor;        // 1.0, 0.0, 0.0 RGB
@property(class, nonatomic, readonly) UIColor *greenColor;      // 0.0, 1.0, 0.0 RGB
@property(class, nonatomic, readonly) UIColor *blueColor;       // 0.0, 0.0, 1.0 RGB
@property(class, nonatomic, readonly) UIColor *cyanColor;       // 0.0, 1.0, 1.0 RGB
@property(class, nonatomic, readonly) UIColor *yellowColor;     // 1.0, 1.0, 0.0 RGB
@property(class, nonatomic, readonly) UIColor *magentaColor;    // 1.0, 0.0, 1.0 RGB
@property(class, nonatomic, readonly) UIColor *orangeColor;     // 1.0, 0.5, 0.0 RGB
@property(class, nonatomic, readonly) UIColor *purpleColor;     // 0.5, 0.0, 0.5 RGB
@property(class, nonatomic, readonly) UIColor *brownColor;      // 0.6, 0.4, 0.2 RGB
@property(class, nonatomic, readonly) UIColor *clearColor; 

@end

NS_ASSUME_NONNULL_END
