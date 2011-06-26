//
//  OpenShooterAppDelegate.h
//  OpenShooter
//
//  Created by Jacob Beaudoin on 6/25/11.
//  Copyright 2011 SMT. All rights reserved.
//

#import <UIKit/UIKit.h>

@class OpenShooterViewController;

@interface OpenShooterAppDelegate : NSObject <UIApplicationDelegate> {

}

@property (nonatomic, retain) IBOutlet UIWindow *window;

@property (nonatomic, retain) IBOutlet OpenShooterViewController *viewController;

@end
