//
//  CPTabBarController.h
//  candpiosapp
//
//  Created by Stephen Birarda on 4/2/12.
//  Copyright (c) 2012 Coffee and Power Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CPThinTabBar.h"
#import "CPPost.h"

@interface CPTabBarController : UITabBarController <UIAlertViewDelegate>

// TODO: get rid of the currentVenueID here, let's keep that in NSUserDefaults (my bad)
@property (strong, nonatomic) NSString *currentVenueID;
@property (nonatomic, readonly) CPThinTabBar *thinBar;

- (IBAction)tabBarButtonPressed:(id)sender;
- (IBAction)updateButtonPressed:(id)sender;
- (IBAction)checkinButtonPressed:(id)sender;
- (void)questionButtonPressed:(id)sender;

- (void)showFeedVCForVenue:(CPVenue *)venue;
- (void)showFeedVCForNewPostAtCurrentVenueWithPostType:(CPPostType)postType;

@end
