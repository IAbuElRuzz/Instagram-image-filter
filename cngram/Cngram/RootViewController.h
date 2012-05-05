//
//  RootViewController.h
//  Cngram
//
//  Created by Chen Changneng on 12-5-5.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "define.h"

@interface RootViewController : UIViewController <UIImagePickerControllerDelegate, UINavigationControllerDelegate> {
    UIImagePickerController * imagePicker;
}
@property (weak, nonatomic) IBOutlet UIButton *pickPhotoBtn;
@property (weak, nonatomic) IBOutlet UIButton *tackPhotoBtn;

- (IBAction)showCam:(UIButton *)sender;

@end
