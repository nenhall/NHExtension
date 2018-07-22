//
//  ViewController.m
//  NHExtensionDemo
//
//  Created by neghao on 2017/9/23.
//  Copyright © 2017年 neghao. All rights reserved.
//

#import "ViewController.h"
#import "UIView+test.h"
#import "NextViewController.h"



@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    UIView *nhView = [[UIView alloc] initWithFrame:self.view.bounds];
    [self.view setNh_superView:nhView];
    UIView *get_nhView = self.view.nh_superView;
    if ([get_nhView isEqual:nhView]) {
        kNSLog(@"nhView是同一个");
    }
    
    UIButton *button = [[UIButton alloc] init];
    [button setTitle:@"跳转" forState:UIControlStateNormal];
    [button setTitleColor:kBrownColor forState:UIControlStateNormal];
    button.backgroundColor = kLightGrayColor;
    [button setImage:kGetImageWithName(11111) forState:UIControlStateNormal];
    [button addTarget:self action:@selector(goToNextVC) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    [button setImageTitleStyle:NHButtonLayoutImageCenterTitleTop padding:20];
    [button mas_makeConstraints:^(MASConstraintMaker *make) {
        make.bottom.equalTo(self.mas_bottomLayoutGuideTop);
        make.width.height.mas_equalTo(60);
        make.centerX.mas_offset(0);
    }];
    kNHViewBorderRadius(button, 30, 0, NULL);

    kNSLog(@"%d--%f--%f",kIsDisplayZoomed,kScaleBased4_7inch_W,kScaleBased4_7inch_H);
    
    self.view.constraints;
    
    if (kScreen4_0inch) {
        kNSLog(@"kScreen5_5inch");
    }
    
//    kNSLog(@"%f-%@-%@-%f",kSuitParam,NSStringFromCGSize(kScreenSize),NSStringFromCGSize(kCurrentModeSize),kScreenScale);
    
    if (iOS_X_OR_LATER(11.0)) {
        kNSLog(@"iOSX_OR_LATER");
    }
    
    NSDate *date = [NSDate dataFromTimeStamp:1532244375];

    
    kNSLog(@"%@--year%@--%@",
           date
           ,[[NSDate date] formatDateWithSeparator:@"/" format:NHDateFormatYYYYMMddHHmm]
           ,[NSDate timeDifferenceWithStarTime:1532246867 endTime:1532246988]
           );

}


- (void)goToNextVC {
    NextViewController *next = (NextViewController*)kLoadMainStroyboardWithNibName(@"12345678");
    [self presentViewController:next animated:YES completion:nil];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    kNSLog(@"%@",NSStringFromCGSize([[UIScreen mainScreen] currentMode].size));
    kNSLog(@"%@",NSStringFromCGSize(kScreenSize));
}



@end
