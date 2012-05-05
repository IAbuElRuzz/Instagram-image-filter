//
//  RootViewController.m
//  Cngram
//
//  Created by Chen Changneng on 12-5-5.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "RootViewController.h"
#import "CngramViewController.h"
#import "UIImage+Cngram.h"


@interface RootViewController () {
    UIImage * _pickedImage;
}
@end

@implementation RootViewController
@synthesize pickPhotoBtn;
@synthesize tackPhotoBtn;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
}

- (void)viewDidUnload
{
    [self setPickPhotoBtn:nil];
    [self setTackPhotoBtn:nil];
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

#pragma mark image picker
- (IBAction)showCam:(UIButton *)sender {
    imagePicker = [[UIImagePickerController alloc] init];
    imagePicker.delegate = self;
    if (sender == pickPhotoBtn) {
        imagePicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    } else {
        imagePicker.sourceType = UIImagePickerControllerSourceTypeCamera;
    }
    [imagePicker setAllowsEditing: YES];
    [self presentModalViewController:imagePicker animated:YES];
}

- (void) imagePickerController:(UIImagePickerController *)picker didFinishPickingImage:(UIImage *) image editingInfo:(NSDictionary *)editingInfo {
    _pickedImage = [image scaleToSize:CGSizeMake(IMAGE_WIDTH, IMAGE_HEIGHT)];
    [picker dismissModalViewControllerAnimated:YES];
    [self performSegueWithIdentifier:@"filter" sender:self ];
}

- (void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    if ([segue.identifier isEqualToString:@"filter"]) {
        CngramViewController * vc = (CngramViewController *) segue.destinationViewController;
        vc.orgineImage = _pickedImage;
    }
}

@end
