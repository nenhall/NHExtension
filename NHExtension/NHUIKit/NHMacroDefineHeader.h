//
//  NHMacroDefineHeader.h
//  Pods
//
//  Created by nenhall_work on 2018/7/12.
//

#ifndef NHMacroDefineHeader_h
#define NHMacroDefineHeader_h
#ifdef __OBJC__

/*********************************屏幕尺寸相关********************************/
/******************************Screen Property******************************/
#pragma mark - 屏幕尺寸相关
#define NHCurrentModeSize       [[UIScreen mainScreen] currentMode].size
#define NHScreenScale           [UIScreen mainScreen].scale
#define NHNativeScale           [[UIScreen mainScreen] nativeScale]
#define NHScreenBounds          [UIScreen mainScreen].bounds
#define NHScreenSize            NHScreenBounds.size
#define NHScreenWidth           NHScreenSize.width
#define NHScreenHeight          NHScreenSize.height
/** 通过转屏通知得到的屏幕方向，有延迟，不可靠，建议使用此属性 */
#define NHInterfaceOrientation  [[UIApplication sharedApplication] statusBarOrientation]
#define NHStatusBarHeight       [[UIApplication sharedApplication] statusBarFrame].size.height
#define NHDelegateWindow        [UIApplication sharedApplication].delegate.window
#define NHTabBarHeight          ((NHScreen5_85inch) ? 83.0 : 49.0)
#define NHNavBarHeight          44.0
#define NHNavgationHeight       (NHStatusBarHeight + NHNavBarHeight)

/*********************************屏幕类型判定********************************/
#pragma mark - 屏幕类型判定
#define NHRespondCurrentMode [UIScreen instancesRespondToSelector:@selector(currentMode)]
/** 3.5inch屏幕 */
#define NHScreen3_5inch  (NHRespondCurrentMode && CGSizeEqualToSize(CGSizeMake(640, 960), NHCurrentModeSize))
/** 4.0inch屏幕 */
#define NHScreen4_0inch  (NHRespondCurrentMode && CGSizeEqualToSize(CGSizeMake(640, 1136), NHCurrentModeSize))
/** 5.5inch屏幕 在放大模式下*/
#define NHScreen4_7inch_BM (NHRespondCurrentMode && CGSizeEqualToSize(CGSizeMake(1125, 2001), NHCurrentModeSize))
/** 4.7inch屏幕 */
#define NHScreen4_7inch  (NHRespondCurrentMode && CGSizeEqualToSize(CGSizeMake(750, 1334), NHCurrentModeSize))
#define NHScreen5_5inch  (NHRespondCurrentMode && (CGSizeEqualToSize(CGSizeMake(1242, 2208), NHCurrentModeSize)||CGSizeEqualToSize(CGSizeMake(1125, 2001), NHCurrentModeSize)))
/** 5.85inch屏幕 -> iPhone_X */
#define NHScreen5_85inch (NHRespondCurrentMode && CGSizeEqualToSize(CGSizeMake(1125, 2436), NHCurrentModeSize))
/** 放大显示模式 */
#define NHIsDisplayZoomed (((NHScreenScale == 2)&&(NHNativeScale == 2.343750)) || ((NHScreenScale == 3)&&(NHNativeScale == 2.880000)))
/** 以4.7inch屏幕计算尺寸比例 */
#define NHScaleBased4_7inch_W  ((NHCurrentModeSize.width/NHScreenScale)/375.0)
#define NHScaleBased4_7inch_H  ((NHCurrentModeSize.height/NHScreenScale)/667.0)

//适配参数
//#define NHSuitParam (NHIsDisplayZoomed ? (NHScreen4_7inch ? 1.0 : (NHScreen5_5inch ? 1.01 : 0.85)) : (NHScreen5_5inch ? 1.12 : (NHScreen4_7inch ? 1.0 : (NHScreen5_85inch ? 1.0 : 0.85))))

/*************************iPhoneX设备上的相关间隙补偿**************************/
#pragma mark - iPhoneX设备上的相关间隙补偿
//iPhoneX相关属性
#define NHTabBarBottomPad          (NHScreen5_85inch ? 34.0 : 0.0)
#define NHNavBarTopPad             (NHScreen5_85inch ? 44.0 : 0.0)
#define NHStatusTopPad             (NHScreen5_85inch ? 24.0 : 0.0)
#define NHLandscapeBottomPad       (NHScreen5_85inch ? 21.0 : 0.0)
/** iphoneX横屏时左或右的边缘间隙 */
#define NHIPhoneXLandscape_L_R_Pad (NHScreen5_85inch ? 44.0 : 0.0)//72.5?16:9

/*******************************设备类型判定******************************/
#pragma mark - 设备类型判定
//判断是否为iPhone
#define NHIPhoneDevice (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
//判断是否为iPad
#define NHIPadDevice   (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
//判断是否为ipod
#define NHIPodDeveice  ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

/*******************************版本判定******************************/
#pragma mark - 版本判定
/** 大于等于某个版本 */
#define iOS_X_OR_LATER(version)  ([[[UIDevice currentDevice] systemVersion] compare:@#version options:NSNumericSearch] != NSOrderedAscending)

/*******************************自定义的 NSLog******************************/
#pragma mark - 自定义的 NSLog
#ifdef DEBUG
#define NHLog(fmt, ...) NSLog((@"%s " fmt), __PRETTY_FUNCTION__, ##__VA_ARGS__);
#else
#define NHLog(...)
#endif

/*********************不需要打印时间戳等信息，使用如下宏定义***********************/
#ifdef DEBUG
#define NHCLog(FORMAT, ...) fprintf(stderr,"%s\n",[[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NHCLog(...)
#endif


/**********************打印日志,当前行 并弹出一个警告**************************/
#ifdef DEBUG
#   define NHALERTLog(fmt, ...)  { UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"%s\n [Line %d] ", __PRETTY_FUNCTION__, __LINE__] message:[NSString stringWithFormat:fmt, ##__VA_ARGS__]  delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil]; [alert show]; }
#else
#   define NHALERTLog(...)
#endif

//#ifndef __OPTIMIZE__
//#define OPEN_MEMORY_WARNING_TEST YES //打开内存警告测试开关
//#endif
//#define SimulateMemoryWarning  [[UIApplication sharedApplication] performSelector:@selector(_performMemoryWarning)];

/***********************由角度转换弧度 由弧度转换角度**************************/
#pragma mark - 由角度转换弧度 由弧度转换角度
#define NHDegreesToRadian(x) (M_PI * (x) / 180.0)
#define NHRadianToDegrees(radian) (radian * 180.0)/(M_PI)


/****************************关联方法宏定义********************************/
#pragma mark - 关联方法宏定义
/** 为对象类型属性快速生成get/set方法 */
#define NH_SYNTHESIZE_CATEGORY_OBJ_PROPERTY(propertyGetter, propertySetter)\
- (id)propertyGetter {\
return objc_getAssociatedObject(self, @selector(propertyGetter));\
}\
- (void)propertySetter(id)obj {\
objc_setAssociatedObject(self, @selector(propertyGetter), obj, OBJC_ASSOCIATION_RETAIN_NONATOMIC);\
}

/** 为基本数据类型属性快速生成get/set方法 */
#define NH_SYNTHESIZE_CATEGORY_VALUE_PROPERTY(valueType, propertyGetter, propertySetter)\
-(valueType)propertyGetter{\
valueType ret = {0};\
[objc_getAssociatedObject(self, @selector(propertyGetter)) getValue:&ret];\
return ret;\
}\
-(void)propertySetter(valueType)value{\
NSValue *valueObj = [NSValue valueWithBytes:&value objCType:@encode(valueType)];\
objc_setAssociatedObject(self, @selector(propertyGetter), valueObj, OBJC_ASSOCIATION_RETAIN_NONATOMIC);\
}

/*****************************设置RGB颜色/设置RGBA颜色******************************/
#define NHRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]
#define NHRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.f green:(g)/255.f blue:(b)/255.f alpha:a]

/*****************************其它常用宏定义******************************/
#pragma mark - 其它常用宏定义
/** 弱引用/强引用 */
#define NHWeakSelf(type)   __weak typeof(type) weak##type = type;
#define NHStrongSelf(type) __strong typeof(type) strong_##type = type;
#define NHGetImageWithName(imageName)     [UIImage imageNamed:@#imageName]


#endif
#endif /* NHMacroDefineHeader_h */
