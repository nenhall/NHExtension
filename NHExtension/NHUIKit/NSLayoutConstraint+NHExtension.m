//
//  NSLayoutConstraint+NHExtension.m
//  DZNEmptyDataSet
//
//  Created by neghao on 2018/7/15.
//

#import "NSLayoutConstraint+NHExtension.h"
#import "NHMacroDefineHeader.h"

@implementation NSLayoutConstraint (NHExtension)

- (void)setFitSafeAereLayout:(BOOL)fitSafeAereLayout {
    if (fitSafeAereLayout) {
        if (NHScreen5_85inch) {
            CGFloat constant = self.constant + NHIPhoneXLandscape_L_R_Pad;
            self.constant = constant;
        }
    }
}

- (BOOL)fitSafeAereLayout {
    return YES;
}

- (void)setScaleBased47inchH:(CGFloat)scaleBased47inchH {
    CGFloat constant = scaleBased47inchH - (scaleBased47inchH * NHScaleBased4_7inch_W);
    self.constant = constant;
}

- (CGFloat)scaleBased47inchH {
    return 0;
}

- (void)setScaleBased47inchW:(CGFloat)scaleBased47inchW {
    
    CGFloat constant = scaleBased47inchW - (scaleBased47inchW * NHScaleBased4_7inch_W);
    self.constant = constant;
}

- (CGFloat)scaleBased47inchW {
    return 0;
}

@end
