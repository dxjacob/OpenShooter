//
//  OpenShooterViewController.h
//  OpenShooter
//
//  Created by Jacob Beaudoin on 6/25/11.
//  Copyright 2011 SMT. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import <vector>
#import "GameState.h"
#import "Texture.h"
#import "Mesh.h"

@interface OpenShooterViewController : UIViewController <UIAccelerometerDelegate> {
@private
    EAGLContext *context;
    GLuint program;
    
    BOOL animating;
    NSInteger animationFrameInterval;
    CADisplayLink *displayLink;
    
    Mesh *mesh;
    Texture *texture;
    GameState *state;

}

@property (readonly, nonatomic, getter=isAnimating) BOOL animating;
@property (nonatomic) NSInteger animationFrameInterval;

- (void)startAnimation;
- (void)stopAnimation;

@end
