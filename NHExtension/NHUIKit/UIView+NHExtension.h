//
//  UIView+NHExtension.h
//  NHExtension
//
//  Created by neghao on 2016/8/24.
//  Copyright © 2017年 neghao.studio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#if TARGET_INTERFACE_BUILDER
IB_DESIGNABLE
@interface UIView (NHIBAppearance)

/** 可视化设置边框宽度 */
@property (nonatomic, assign)IBInspectable CGFloat borderWidth;
/** 可视化设置边框颜色 */
@property (nonatomic, strong)IBInspectable UIColor *borderColor;
/** 可视化设置圆角 */
@property (nonatomic, assign)IBInspectable CGFloat cornerRadius;

@end
#endif


@interface UIView (NHConstantMethod)

/** Find first responder in subviews */
- (UIView *)findFirstResponder;

/** 获取当前View的控制器对象 */
- (UIViewController *)currentViewController;

/** 从nib上加载view 保持nib名称与类名一致，否则重新实现此方法*/
+ (instancetype)loadViewFromNib;

/** 加载cell，内部自动判空及创建 */
+ (instancetype)loadCellWithTableView:(UITableView *)tableView;

/** 自定义标识 */
@property (nonatomic, copy) NSString *identifier;

@end

/** UITableviewVell/UICollectionViewIten Animation Style */
typedef NS_ENUM(NSInteger, NHCellDisplayAnimationStyle) {
    NHCellDisplayAnimationFade,     /**< 透明度变化 */
    NHCellDisplayAnimationScale,    /**< 缩放 */
    NHCellDisplayAnimationPosition, /**< 位置变化 */
    NHCellDisplayAnimationRotateX,  /**< X 轴旋转 */
    NHCellDisplayAnimationRotateY   /**< Y 轴旋转 */
};

@interface UIView (NHCellDisplayAnimation)


/**
 给cell 或者 item 添加显示动画
 
 @param animationStyle 动画风格
 */
-(void)doCellAnimationWithAnimationStyle:(NHCellDisplayAnimationStyle)animationStyle;

/**
 给cell 或者 item 添加显示动画

 @param animationStyle 动画风格
 @param view 对应的cell
 */
+(void)doCellAnimationWithAnimationStyle:(NHCellDisplayAnimationStyle)animationStyle onTheView:(UIView *)view;

@end

