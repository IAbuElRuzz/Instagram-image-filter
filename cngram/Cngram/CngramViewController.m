//
//  CngramViewController.m
//  Cngram
//
//  Created by Chen Changneng on 12-4-21.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//
#import "UIImage+Cngram.h"
#import "UIImage+Filter.h"
#import "CngramViewController.h"
#import "Filters.h"
#import "define.h"



@interface CngramViewController () {
    Filters * _filter;
    UIActivityIndicatorView * _indicator;
}

@end

@implementation CngramViewController

@synthesize imageView = _imageView;
@synthesize filterListView = _filterListView;
@synthesize effectImage = _effectImage;
@synthesize orgineImage = _orgineImage;


- (void) setEffectImage:(UIImage *)effectImage {
    _effectImage = effectImage;
    self.imageView.image = _effectImage;
}

- (void) setOrgineImage:(UIImage *)orgineImage {
    _orgineImage = orgineImage;
    self.imageView.image = _orgineImage;
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    // add filter
    _filter = [[Filters alloc] init];
    
    // add indecator
    _indicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle: UIActivityIndicatorViewStyleWhite];
    _indicator.frame = CGRectMake((self.view.bounds.size.width - 20) / 2, (self.view.bounds.size.height - 150) / 2, 20, 20);

    // add save button
    UIBarButtonItem *save = [[UIBarButtonItem alloc]initWithBarButtonSystemItem:UIBarButtonSystemItemSave target:self action:@selector(save)];
    self.navigationItem.rightBarButtonItem = save;

    // add filterList
    CGRect frameRect = CGRectMake(0, LANDSCAPE_HEIGHT - BUTTOM_HEIGHT, LANDSCAPE_WIDTH, BUTTOM_HEIGHT);
    EasyTableView * view = [[EasyTableView alloc] initWithFrame:frameRect numberOfColumns:[_filter count] ofWidth:BUTTOM_WIDTH];
    view.delegate = self;
    view.tableView.allowsSelection = YES;
    view.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    view.tableView.backgroundColor = [UIColor clearColor];
    self.filterListView = view;
    [self.view addSubview:_filterListView];
    self.orgineImage = self.orgineImage;
}

- (void)viewDidUnload
{
    [self setImageView:nil];
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return NO;
}

#pragma mark easyTableView delegate
- (UIView *) easyTableView:(EasyTableView *)easyTableView viewForRect:(CGRect)rect  {
    // view
	CGRect viewRect		= CGRectMake(0, 0, rect.size.width, rect.size.height);
    UIView * view = [[UIView alloc] initWithFrame:viewRect];
    
    // icon
	CGRect imageRect = CGRectMake((rect.size.width - ICON_SIZE) / 2, ICON_PADDING, ICON_SIZE, ICON_SIZE);
    UIImageView * imageView = [[UIImageView alloc] initWithFrame:imageRect];
    imageView.tag = ICON_VIEW_TAG;
    [view addSubview:imageView];
    
    // label
    CGRect labelRect = CGRectMake(0, ICON_SIZE, viewRect.size.width, 10);
    UILabel * labelView = [[UILabel alloc] initWithFrame:labelRect];
    labelView.textAlignment = UITextAlignmentCenter;
    labelView.textColor = [UIColor whiteColor];
    labelView.font = [UIFont boldSystemFontOfSize:10];
    labelView.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0];
    labelView.tag = LABEL_VIEW_TAG;
    [view addSubview:labelView];

    // border
    UIImageView *borderView		= [[UIImageView alloc] initWithFrame:imageRect];
	borderView.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
	borderView.tag				= BORDER_VIEW_TAG;
    [view addSubview:borderView];
    
    return view;
}

- (void)borderIsSelected:(BOOL)selected forView:(UIView *)view {
	UIImageView * borderView	= (UIImageView *)[view viewWithTag:BORDER_VIEW_TAG];
	NSString * borderImageName	= (selected) ? @"filterChooserItemSelected.png" : @"filterChooserItemUnselected.png";
	borderView.image			= [UIImage imageNamed:borderImageName];
}

- (void)easyTableView:(EasyTableView *)easyTableView setDataForView:(UIView *)view forIndexPath:(NSIndexPath *)indexPath {
    // label
    UILabel * label = (UILabel *)[view viewWithTag:LABEL_VIEW_TAG];
    label.text = [_filter nameForIndex:indexPath.row];
    
    // icon
    UIImageView * imageView = (UIImageView *)[view viewWithTag:ICON_VIEW_TAG];
    imageView.image = [UIImage imageNamed:[_filter iconForIndex:indexPath.row]];
    
    // selectedIndexPath can be nil so we need to test for that condition
	BOOL isSelected = (easyTableView.selectedIndexPath) ? ([easyTableView.selectedIndexPath compare:indexPath] == NSOrderedSame) : NO;
	[self borderIsSelected:isSelected forView:view];
}

- (void) easyTableView:(EasyTableView *)easyTableView selectedView:(UIView *)selectedView atIndexPath:(NSIndexPath *)indexPath deselectedView:(UIView *)deselectedView  {
    // set border
    [self borderIsSelected:YES forView:selectedView];
    if (deselectedView) {
        [self borderIsSelected:NO forView:deselectedView];
    }

    // apply filter
    SEL selector = NSSelectorFromString([_filter methodForIndex:indexPath.row]);
    if ([self.orgineImage respondsToSelector:selector]) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
        self.effectImage = [self.orgineImage performSelector: selector];
#pragma clang diagnostic pop
    }
}

#pragma mark save action
-(void) save {
    UIImageWriteToSavedPhotosAlbum(self.imageView.image, self, @selector(image:didFinishSavingWithError:contextInfo:), nil);
}

- (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo {
    UIAlertView *alert =[[UIAlertView alloc] initWithTitle:@"Save successful" 
                                                   message:@"保存成功"
                                                  delegate:self 
                                         cancelButtonTitle:@"ok" 
                                         otherButtonTitles:nil];
    [alert show];
}


@end



