//
//  NHMacroDefineHeader.h
//  Pods
//
//  Created by nenhall_work on 2018/7/12.
//

#ifndef NHMacroDefineHeader_h
#define NHMacroDefineHeader_h
#ifdef __OBJC__

/*****************************Screen Property******************************/
#define kScale                 [UIScreen mainScreen].scale
#define kScreenBounds          [UIScreen mainScreen].bounds
#define kScreenSize            [[UIScreen mainScreen] bounds].size
#define kScreenWidth           [UIScreen mainScreen].bounds.size.width
#define kScreenHeight          [UIScreen mainScreen].bounds.size.height
#define kInterfaceOrientation  [[UIApplication sharedApplication] statusBarOrientation]
#define kStatusBarHeight       [[UIApplication sharedApplication] statusBarFrame].size.height
#define kWindow                [UIApplication sharedApplication].delegate.window
#define kTabbarHeight          (([UIScreen mainScreen].bounds.size.height == 812) ? 83 : 49)
#define kBarItemYOffect        35
#define kNabBarHeight          44
#define kNavgationHeight       (kStatusBarHeight +  kNabBarHeight)
#define kScreenScale           ([UIScreen mainScreen].bounds.size.width/375)

//判断是否为iPhone
#define kPhoneDevice (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
//判断是否为iPad
#define kPadDevice   (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
//判断是否为ipod
#define kPodDeveice  ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

/** 3.5inch屏幕 */
#define kScreen3_5inch  ((kScreenHeight == 480.f) || (kScreenWidth == 480.f))
/** 4.0inch屏幕 */
#define kScreen4_0inch  ((kScreenHeight == 568.f) || (kScreenWidth == 568.f))
/** 4.7inch屏幕 */
#define kScreen4_7inch  ((kScreenHeight == 667.f) || (kScreenWidth == 667.f))
/** 5.5inch屏幕 */
#define kScreen5_5inch  ((kScreenHeight == 736.f) || (kScreenWidth == 736.f))
/** 5.85inch屏幕 */
#define kScreen5_85inch ((kScreenHeight == 812.f) || (kScreenWidth == 812.f))
#define kiPhone_X       ((kScreenHeight == 812.f) || (kScreenWidth == 812.f))


//iPhoneX相关属性
#define kTabBarBottomOffset    (kiPhone_X == YES ? 34.0 : 0.0)
#define kNavBarTopOffset       (kiPhone_X == YES ? 44.0 : 0.0)
#define kStatusTopOffset       (kiPhone_X == YES ? 24.0 : 0.0)
#define kLandscapeBottomOffset (kiPhone_X == YES ? 21.0 : 0.0)
#define kIPhoneXFullScreenLeftOffset (kiPhone_X == YES ? 72.5 : 0.0)


/*****************************获取通知中心******************************/
#define BKAppendingPathComponent(path,subPath) [NSString stringWithFormat:@"%@/%@",(path),(subPath)];

#define kNotificationCenter   [NSNotificationCenter defaultCenter]
#define kBundleDictionary     [[NSBundle mainBundle] infoDictionary]
//通过xib名称加载cell
#define kLoadNibWithNamed(name) [[NSBundle mainBundle] loadNibNamed:(name) owner:self options:nil].firstObject
//获取main stroyboard
#define kLoadMainStroyboard     [UIStoryboard storyboardWithName:@"Main" bundle:nil]
//通过xib名称加载controller
#define kLoadMainStroyboardWithNibName(name) [kLoadMainStroyboard instantiateViewControllerWithIdentifier:(name)]



// app版本
#define kAppVersion         [kBundleDictionary objectForKey:@"CFBundleShortVersionString"]
// app build版本
#define kAppBuildVersion    [kBundleDictionary objectForKey:@"CFBundleVersion"]


///*****************************自定义的 NSLog******************************/
#ifdef DEBUG
#define kNSLog(fmt, ...) NSLog((@"%s " fmt), __PRETTY_FUNCTION__, ##__VA_ARGS__);
#else
#define kNSLog(...)
//#define kNSLog(fmt, ...) NSLog((@"%s -- " fmt), __PRETTY_FUNCTION__, ##__VA_ARGS__);
#endif

/*****************************不需要打印时间戳等信息，使用如下宏定义******************************/
#ifdef DEBUG
#define kCNSLog(FORMAT, ...) fprintf(stderr,"%s\n",[[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define kCNSLog(...)
//#define kCNSLog(FORMAT, ...) fprintf(stderr,"%s\n",[[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#endif


/*****************************打印日志,当前行 并弹出一个警告******************************/
#ifdef DEBUG
#   define kALERTLog(fmt, ...)  { UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"%s\n [Line %d] ", __PRETTY_FUNCTION__, __LINE__] message:[NSString stringWithFormat:fmt, ##__VA_ARGS__]  delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil]; [alert show]; }
#else
#   define kALERTLog(...)
#endif

//#ifndef __OPTIMIZE__
//#define OPEN_MEMORY_WARNING_TEST YES //打开内存警告测试开关
//#endif
//#define SimulateMemoryWarning  [[UIApplication sharedApplication] performSelector:@selector(_performMemoryWarning)];

/*****************************弱引用/强引用******************************/
#define kWeakSelf(type)   __weak typeof(type) weak##type = type;
#define kStrongSelf(type) __strong typeof(type) strong_##type = type;



#define ObjIsNSNullClass(obj)            [(obj) isKindOfClass:[NSNull null]]
#define kGetImageWithName(imageName)     [UIImage imageNamed:@#imageName]
#define kGetIntegerWithString(integer)   [NSString stringWithFormat:@"%ld",integer]
#define kGetIntValueWithString(intValue) [NSString stringWithFormat:@"%d",intValue]
#define kGetString(string)               [NSString stringWithFormat:@"%@",string]

#define kStrignToUTF8String(obj)             [(obj) stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]


/*****************************由角度转换弧度 由弧度转换角度******************************/
#define kDegreesToRadian(x) (M_PI * (x) / 180.0)
#define kRadianToDegrees(radian) (radian * 180.0)/(M_PI)


/*****************************关联方法宏定义******************************/
#pragma mark -- 关联方法宏定义

//对象类型
#define NH_SYNTHESIZE_CATEGORY_OBJ_PROPERTY(propertyGetter, propertySetter)\
- (id) propertyGetter {\
return objc_getAssociatedObject(self, @selector( propertyGetter ));\
}\
- (void) propertySetter (id)obj{\
objc_setAssociatedObject(self, @selector( propertyGetter ), obj, OBJC_ASSOCIATION_RETAIN_NONATOMIC);\
}

//基本类型
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


/*****************************沙盒目录文件******************************/
//获取temp
#define kPathTemp NSTemporaryDirectory()
//获取沙盒 Document
#define kPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
//获取沙盒 Library
#define kPathLibrary  [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject]
//获取沙盒 Cache
#define kPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]


/*****************************系统加载动效******************************/
#define kNetworkActivityIndicatorVisible(visible)  [UIApplication sharedApplication].networkActivityIndicatorVisible = (Visible)





#endif
#endif /* NHMacroDefineHeader_h */
