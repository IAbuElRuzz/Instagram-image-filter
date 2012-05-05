//
//  CngramViewController.h
//  Cngram
//
//  Created by Chen Changneng on 12-4-21.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EasyTableView.h"
#import "define.h"

@interface CngramViewController : UIViewController <EasyTableViewDelegate> {
    UIImagePickerController * imagePicker;
}

@property (nonatomic, retain) UIImage * orgineImage;
@property (nonatomic, retain) UIImage * effectImage;
@property (nonatomic, retain) IBOutlet UIImageView *imageView;
@property (nonatomic, retain) EasyTableView * filterListView;

- (IBAction)showCam:(id)sender;

@end
