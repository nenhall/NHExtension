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
        NHLog(@"nhView是同一个");
    }
  
    UIButton *button = [[UIButton alloc] init];
    [button setTitle:@"跳转" forState:UIControlStateNormal];
    [button setTitleColor:UIColor.brownColor forState:UIControlStateNormal];
    button.backgroundColor = UIColor.lightGrayColor;
    [button setImage:NHGetImageWithName(11111) forState:UIControlStateNormal];
    [button addTarget:self action:@selector(goToNextVC) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
    [button nh_setImageTitleStyle:NHButtonLayoutImageCenterTitleTop padding:20];
    [button mas_makeConstraints:^(MASConstraintMaker *make) {
        make.bottom.equalTo(self.mas_bottomLayoutGuideTop);
        make.width.height.mas_equalTo(60);
        make.centerX.mas_offset(0);
    }];
    NHViewBorderRadius(button, 30, 0, NULL);

    NHLog(@"%d--%f--%f",NHIsDisplayZoomed,NHScaleBased4_7inch_W,NHScaleBased4_7inch_H);
        
    if (NHScreen4_0inch) {
        NHLog(@"kScreen5_5inch");
    }
    
//    NHLog(@"%f-%@-%@-%f",kSuitParam,NSStringFromCGSize(kScreenSize),NSStringFromCGSize(kCurrentModeSize),kScreenScale);
    
    if (iOS_X_OR_LATER(11.0)) {
        NHLog(@"iOSX_OR_LATER");
    }
    
    NSDate *date = [NSDate dataFromTimeStamp:1532244375];

    
    NHLog(@"%@--year%@--%@",
           date
           ,[[NSDate date] formatDateWithSeparator:@"/" format:NHDateFormatYYYYMMddHHmm]
           ,[NSDate timeDifferenceWithStarTime:1532246867 endTime:1532246988]
           );

}


- (void)goToNextVC {
    NextViewController *next = (NextViewController*)NHLoadMainStroyboardWithNibName(@"12345678");
    [self presentViewController:next animated:YES completion:nil];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    NHLog(@"%@",NSStringFromCGSize([[UIScreen mainScreen] currentMode].size));
    NHLog(@"%@",NSStringFromCGSize(NHScreenSize));
}



@end
