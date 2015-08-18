//
//  Clock.h
//  movingObjects
//
//  Created by 권다예 on 2015. 8. 3..
//
//

#ifndef __movingObjects__Clock__
#define __movingObjects__Clock__

#include <stdio.h>
#include "ofMain.h"

class Clock {
public:
    Clock();
    ~Clock();
    
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    int action;
    
    ofImage img;
    float imgX, imgY, imgW, imgH, ratio;
    
    ofPath clock;
    float clockX, clockY, clockR;
    
    int numOfHours;
    float hourDist, lengOfHour;
    
    float handX, handY, lengOfHand;
    float handAng, handAngAccel;
    float hammerR;
    float throwSpeed;
    
};


#endif /* defined(__movingObjects__Clock__) */
