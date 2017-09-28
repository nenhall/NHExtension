//
//  ViewController.m
//  NHExtensionDemo
//
//  Created by neghao on 2017/9/23.
//  Copyright © 2017年 neghao. All rights reserved.
//

#import "ViewController.h"
#import "NSDate+switchDate.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [NSDate getCurrentDateBaseStyleWithData:nil];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
