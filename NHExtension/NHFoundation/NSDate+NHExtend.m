//
//  NSDate+NHExtend.m
//  DZNEmptyDataSet
//
//  Created by neghao on 2018/7/21.
//

#import "NSDate+NHExtend.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#define CURRENT_CALENDAR [NSCalendar currentCalendar]


@implementation NSDate (NHExtend)

#pragma mark - Properties
#define DATE_COMPONENT(_type_, _conponent_) [[[NSCalendar currentCalendar] components:_type_ fromDate:self] _conponent_]
- (NSInteger)year { return DATE_COMPONENT(NSCalendarUnitYear, year); }
- (NSInteger)month { return DATE_COMPONENT(NSCalendarUnitMonth, month); }
- (NSInteger)hour{ return DATE_COMPONENT(NSCalendarUnitHour, hour); }
- (NSInteger)day{ return DATE_COMPONENT(NSCalendarUnitDay, day); }
- (NSInteger)minute{ return DATE_COMPONENT(NSCalendarUnitMinute, minute); }
- (NSInteger)second{ return DATE_COMPONENT(NSCalendarUnitSecond, second); }
- (NSInteger)nanosecond{ return DATE_COMPONENT(NSCalendarUnitNanosecond, nanosecond); }
- (NSInteger)weekday{ return DATE_COMPONENT((NSWeekCalendarUnit | NSWeekdayCalendarUnit |NSWeekdayOrdinalCalendarUnit), weekday);}
- (NSInteger)weekdayOrdinal{ return DATE_COMPONENT((NSWeekCalendarUnit | NSWeekdayCalendarUnit |NSWeekdayOrdinalCalendarUnit), weekdayOrdinal); }
- (NSInteger)weekOfYear{ return DATE_COMPONENT(((NSWeekCalendarUnit | NSWeekdayCalendarUnit |NSWeekdayOrdinalCalendarUnit)), week); }
- (NSInteger)weekOfMonth{ return DATE_COMPONENT((NSWeekCalendarUnit | NSWeekdayCalendarUnit |NSWeekdayOrdinalCalendarUnit), weekdayOrdinal); }
- (NSInteger)yearForWeekOfYear{ return DATE_COMPONENT(NSCalendarUnitYearForWeekOfYear, yearForWeekOfYear);}
- (NSInteger)quarter{ return DATE_COMPONENT(NSCalendarUnitQuarter, quarter); }
- (BOOL)isLeapMonth{ return DATE_COMPONENT(NSCalendarUnitMonth, isLeapMonth); }
- (BOOL)isLeapYear
{
    NSUInteger year = self.year;
    return ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)));
}

- (NSUInteger)timeStamp
{
    return (NSUInteger)self.timeIntervalSince1970;
}

NSString *nh_convertFormat(NHDateFormat format, NSString *separator) {
    NSString *formatStr;
    
    switch (format) {
        case NHDateFormatYYYYMMdd:
            formatStr = [NSString stringWithFormat:@"yyyy%@MM%@dd",separator,separator];
            break;
        case NHDateFormatYYYYMMddHH:
            formatStr = [NSString stringWithFormat:@"yyyy%@MM%@dd HH",separator,separator];
            break;
        case NHDateFormatYYYYMMddHHmm:
            formatStr = [NSString stringWithFormat:@"yyyy%@MM%@dd HH:mm",separator,separator];
            break;
        case NHDateFormatYYYYMMddHHmmss:
            formatStr = [NSString stringWithFormat:@"yyyy%@MM%@dd HH:mm:ss",separator,separator];
            break;
        default:
            break;
    }
    
    return formatStr;
}

#pragma mark Range
- (BOOL)isInToday
{
    return [CURRENT_CALENDAR isDateInToday:self];
}

- (BOOL)isInTomorrow
{
    return [CURRENT_CALENDAR isDateInTomorrow:self];
}

- (BOOL)isInYesterday
{
    return [CURRENT_CALENDAR isDateInYesterday:self];
}

- (BOOL)isInThisMonth
{
    NSDateComponents *nowComponents = [CURRENT_CALENDAR components:NSCalendarUnitMonth fromDate:[NSDate date]];
    NSDateComponents *selfComponents = [CURRENT_CALENDAR components:NSCalendarUnitMonth fromDate:self];
    return nowComponents.month == selfComponents.month;
}

- (BOOL)isInThisWeek
{
    NSDateComponents *nowComponents = [CURRENT_CALENDAR components:NSCalendarUnitWeekOfYear fromDate:[NSDate date]];
    NSDateComponents *selfComponents = [CURRENT_CALENDAR components:NSCalendarUnitWeekOfYear fromDate:self];
    return nowComponents.weekOfYear == selfComponents.weekOfYear;
}

- (BOOL)isInThisYear
{
    NSDateComponents *nowComponents = [CURRENT_CALENDAR components:NSCalendarUnitYear fromDate:[NSDate date]];
    NSDateComponents *selfComponents = [CURRENT_CALENDAR components:NSCalendarUnitYear fromDate:self];
    
    return nowComponents.year == selfComponents.year;
}

#pragma mark Convert
+ (NSDate *)dateWithString:(NSString *)dateString format:(NSString *)format
{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:format];
    return [formatter dateFromString:dateString];
}

- (NSString *)formatDateWithSeparator:(NSString *)separator format:(NHDateFormat)format
{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:nh_convertFormat(format,separator)];
    return [formatter stringFromDate:self];
}

- (NSString *)formatDateWithSeparator:(NSString *)separator
{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:[NSString stringWithFormat:@"yyyy%@MM%@dd",separator,separator]];
    return [formatter stringFromDate:self];
}

- (NSString *)formatTimeWithSeparator:(NSString *)separator
{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:[NSString stringWithFormat:@"HH%@mm",separator]];
    return [formatter stringFromDate:self];
}

+ (NSUInteger)timeStamp
{
    return [[[NSDate alloc] init] timeStamp];
}

//将NSDate转换成带毫秒的时间戳,从1970/1/1开始
+ (NSUInteger)timeStampAppendMilliscond:(NSDate *)date
{
    NSTimeInterval interval;
    if (date) {
        interval = [date timeIntervalSince1970];
    } else {
        interval = [[[NSDate alloc] init] timeIntervalSince1970];
    }
    NSUInteger totalMilliseconds = interval * 1000;
    return totalMilliseconds;
}

//把带毫秒的时间戳转换成时间
+ (NSDate *)dataFromTimeStamp:(NSUInteger)timeStamp
{
    NSTimeInterval tempMilli = timeStamp;
    if (timeStamp == 0) {
        tempMilli = [self timeStampAppendMilliscond:nil];
    }
    NSTimeInterval seconds = tempMilli;
    if (timeStamp > 9999999999) {
        seconds = tempMilli/1000.0;
    }
    return [NSDate dateWithTimeIntervalSince1970:seconds];
}

/**
 *  计算两时间戳的时间间隔
 */
+ (NSString *)timeDifferenceWithStarTime:(NSUInteger)starTime
                                 endTime:(NSUInteger)endTime {
    
    NSString *startTime_s = [[NSDate dataFromTimeStamp:starTime] formatDateWithSeparator:@"-" format:NHDateFormatYYYYMMddHHmmss];
    NSString *endTime_s = [[NSDate dataFromTimeStamp:endTime] formatDateWithSeparator:@"-" format:NHDateFormatYYYYMMddHHmmss];
    NSTimeInterval value = [self timeFormatterWithStartTime:startTime_s endTime:endTime_s];
    
    return [self intervalTimeWithValue:value];
}

/**
 *  时间格式转换成数值 Format:@"yyyy-MM-dd HH:mm:ss"  > To:  123
 */
+ (NSTimeInterval)timeFormatterWithStartTime:(NSString *)startTime
                                     endTime:(NSString *)endTime {
    
    NSDateFormatter *date = [[NSDateFormatter alloc]init];
    [date setDateFormat:nh_convertFormat(NHDateFormatYYYYMMddHHmmss, @"-")];
    NSDate *startD = [date dateFromString:startTime];
    NSDate *endD = [date dateFromString:endTime];
//    NSTimeInterval start = [startD timeIntervalSince1970]*1;
//    NSTimeInterval end = [endD timeIntervalSince1970]*1;
//    NSTimeInterval value = end - start;
    NSTimeInterval value = [endD timeIntervalSinceDate:startD];

    return value;
}


/**
 *  将时间差值转换成 00:00:00:00 天:小时:分钟:秒钟
 */
+ (NSString *)intervalTimeWithValue:(int)value{
    
    int second = (int)value %60;//秒
    int minute = (int)value /60%60;
    int house = (int)value / (24 * 3600)%3600;
    int day = (int)value / (24 * 3600);
    NSString *str;
    if (day != 0) {
        str = [NSString stringWithFormat:@"%02d:%02d:%02d:%02d",day,house,minute,second];
    }else if (day==0 && house != 0) {
        str = [NSString stringWithFormat:@"%02d:%02d:%02d",house,minute,second];
    }else if (day== 0 && house== 0 && minute!=0) {
        str = [NSString stringWithFormat:@"00:%02d:%02d",minute,second];
    }else{
        str = [NSString stringWithFormat:@"00:00:%02d",second];
    }
    return str;
}

- (NSString *)getMonthBeginAndEnd {
    double interval = 0;
    NSDate *beginDate = nil;
    NSDate *endDate = nil;
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    [calendar setFirstWeekday:2];//设定周一为周首日
    BOOL ok = [calendar rangeOfUnit:NSMonthCalendarUnit startDate:&beginDate interval:&interval forDate:self];
    // 分别修改为 NSCalendarUnitDay NSCalendarUnitWeekOfYear NSCalendarUnitYear
    if (ok) {
        endDate = [beginDate dateByAddingTimeInterval:interval-1];
    }else {
        return nil;
    }
    NSDateFormatter *myDateFormatter = [[NSDateFormatter alloc] init];
    [myDateFormatter setDateFormat:@"yyyy.MM.dd"];
    NSString *beginString = [myDateFormatter stringFromDate:beginDate];
    NSString *endString = [myDateFormatter stringFromDate:endDate];
    
    NSString *s = [NSString stringWithFormat:@"%@-%@",beginString,endString];
    return s;
}

+ (NSArray *)backToPassedTimeWithWeeksNumber:(NSInteger)number
{
    NSDate *date = [[NSDate date] dateByAddingTimeInterval:- 7 * 24 * 3600 * number];
    //滚动后，算出当前日期所在的周（周一－周日）
    NSCalendar *gregorian = [NSCalendar currentCalendar];
    NSDateComponents *comp = [gregorian components:NSCalendarUnitWeekday | NSCalendarUnitDay fromDate:date];
    NSInteger daycount = [comp weekday] - 2;
    
    NSDate *weekdaybegin=[date dateByAddingTimeInterval:-daycount*60*60*24];
    NSDate *weekdayend = [date dateByAddingTimeInterval:(6-daycount)*60*60*24];
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:NSCalendarUnitYear|NSCalendarUnitMonth|NSCalendarUnitDay fromDate:weekdaybegin];
    NSDateComponents *components1 = [calendar components:NSCalendarUnitYear|NSCalendarUnitMonth|NSCalendarUnitDay fromDate:weekdayend];
    
    NSDate *startDate = [calendar dateFromComponents:components];//这个不能改
    
    NSDate *startDate1 = [calendar dateFromComponents:components1];
    NSDate *endDate1 = [calendar dateByAddingUnit:NSCalendarUnitDay value:1 toDate:startDate1 options:0];
    
    //获取今天0点到明天0点的时间
    NSDateFormatter *formatter1 = [[NSDateFormatter alloc]init];
    [formatter1 setDateFormat:@"yyyy-MM-dd"];
    NSString *str1 = [formatter1 stringFromDate:startDate];
    
    NSDateFormatter *formatter2 = [[NSDateFormatter alloc]init];
    [formatter2 setDateFormat:@"yyyy-MM-dd"];
    NSString *str2 = [formatter2 stringFromDate:endDate1];
    
    NSArray *arr = @[str1,str2];
    return arr;
}

@end
#pragma clang diagnostic pop
