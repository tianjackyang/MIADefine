//
//  FIUserDef.h
//  e-friends
//
//

#ifndef FIUserDef_h
#define FIUserDef_h

#define SCREEN_WIDTH                            ([UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT                           ([UIScreen mainScreen].bounds.size.height)
#define NAVIGATION_HEIGHT                       (64)
#define colorWithHex(hexValue)                  [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16))/255.0 \
                                                green:((float)((hexValue & 0xFF00) >> 8))/255.0 \
                                                blue:((float)(hexValue & 0xFF))/255.0 alpha:1.0]

#define CURRENT_SYS_VERSION                     [[[UIDevice currentDevice] systemVersion] floatValue]
//带有RGBA的颜色设置
#define COLOR(R, G, B, A)                       [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]

#ifdef __OBJC__
//代码只被oc使用
#endif

//获取当前语言
#define CurrentLanguage         (［NSLocale preferredLanguages] objectAtIndex:0])

#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//判断是真机还是模拟器
#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif

//使用ARC和不使用ARC
#if __has_feature(objc_arc)
//compiling with ARC
#else
// compiling without ARC
#endif

//释放一个对象
#define RELEASE_SAFELY(__POINTER) { [__POINTER release]; __POINTER = nil; }

//读取本地图片
#define LOADIMAGE(file,ext) [UIImage imageWithContentsOfFile:［NSBundle mainBundle]pathForResource:file ofType:ext］

//定义UIImage对象
#define IMAGE(A) [UIImage imageWithContentsOfFile:［NSBundle mainBundle] pathForResource:A ofType:nil］

//定义UIImage对象
#define ImageNamed(_pointer) [UIImage imageNamed:_pointer]

// rgb颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

//带有RGBA的颜色设置
#define COLOR(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]

//背景色
#define BACKGROUND_COLOR [UIColor colorWithRed:242.0/255.0 green:236.0/255.0 blue:231.0/255.0 alpha:1.0]

//清除背景色
#define CLEARCOLOR [UIColor clearColor]

//方正黑体简体字体定义
#define FONT(F)         [UIFont fontWithName:@"FZHTJW--GB1-0" size:F]
#define SYSTEM_FONT(S)  [UIFont systemFontOfSize:S]

//根据tag返回控件指针
#define VIEWWITHTAG(_OBJECT, _TAG)    [_OBJECT viewWithTag : _TAG]

//程序的本地化,引用国际化的文件
#define MyLocal(x, ...) NSLocalizedString(x, nil)

//G－C－D
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)

//NSUserDefaults 实例化
#define USER_DEFAULT [NSUserDefaults standardUserDefaults]

//由角度获取弧度 有弧度获取角度
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)

#define KOriginX        [[UIScreen mainScreen] bounds].origin.x
#define KOriginY        [[UIScreen mainScreen] bounds].origin.y
#define KNavigationHeight 44
#define KStatusHeight     20

/**
 *  弱引用
 *
 *  @param weakSelf 传入的对象
 *
 *  @return 返回弱引用对象
 */
#define WS(weakSelf) __weak __typeof(&*self)weakSelf = self;

#define autoSizeScaleX  KScreenWidth / 320.0
#define autoSizeScaleY  KScreenHeight / 480.0

#define autoFontSizeScale(font)  (font * KScreenWidth / 320.0)

#define WEAKSELF typeof(self) __weak weakSelf = self;
#define STRONGSELF typeof(weakSelf) __strong strongSelf = weakSelf;

//单例化一个类方法一(ARC)
//定义
#define DEFINE_SINGLETON_FOR_HEADER(className) \
\
+ (className *)shared##className;
//实现
#define SYNTHESIZE_SINGLETON_FOR_CLASS(classname) \
\
static classname *shared##classname = nil; \
\
+ (classname *)shared##classname \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = ［self alloc] init]; \
} \
} \
\
return shared##classname; \
} \
\
+ (id)allocWithZone:(NSZone *)zone \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [super allocWithZone:zone]; \
return shared##classname; \
} \
} \
\
return nil; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
return self; \
}

//单例化一个类方法二
//定义
#define DEFINE_SINGLETON_FOR_HEADEREX(className) \
\
+ (className *)shared##className##Manager;
//实现
#define SYNTHESIZE_SINGLETON_FOR_CLASSEX(classname) \
\
+ (classname *)shared##classname##Manager { \
static classname *shared##classname##ManagerInstance = nil;  \
static dispatch_once_t onceToken;   \
dispatch_once(&onceToken, ^{    \
shared##classname##ManagerInstance = [[self alloc] init]; \
}); \
return shared##classname##ManagerInstance;    \
}

//类型转换
#define DYNAMIC_CAST(x, cls)                        \
({                                                 \
cls *inst_ = (cls *)(x);                        \
[inst_ isKindOfClass:[cls class]]? inst_ : nil; \
})

//文件目录
#define kPathTemp                   NSTemporaryDirectory()
#define kPathDocument               [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define kPathCache                  [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define kPathLibrary                [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) objectAtIndex:0]

//是否为空
#define IsNilOrNull(_ref)   (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) || ([[_ref stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] length]==0))

#endif /* FIUserDef_h */
