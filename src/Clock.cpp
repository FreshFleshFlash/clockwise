//
//  Clock.cpp
//  movingObjects
//
//  Created by 권다예 on 2015. 8. 3..
//
//

#include "Clock.h"

Clock::Clock() {}
Clock::~Clock() {}

void Clock::setup() {
    
    ofBackground(255);
    
    action = 0;
    
    img.loadImage("clockHuman.png");
    ratio = 0.5;

    imgX;
    imgY;
    imgW = img.width * ratio;
    imgH = img.height * ratio;
    
    clockX = ofGetScreenWidth() / 2;
    clockY = ofGetScreenHeight() / 2;
    clockR = 500;
    
    clock.setStrokeColor(ofColor(0));
    clock.setStrokeWidth(5);
    clock.setFilled(false);
    clock.ellipse(0, 0, clockR, clockR);
    
    numOfHours = 12;
    lengOfHour = 50;
    hourDist = 200;
    
    lengOfHand = 150;
    handX;
    handY;
    
    handAng;
    handAngAccel = 1;
    
    hammerR = 10;
    
    throwSpeed = 5;
}

void Clock::update() {
    
    if(action == 1) {
        handAng += handAngAccel;
        handAngAccel *= 1.005;
        throwSpeed *= 1.005;
    }
    
    if(action == 2) {
        handY -= throwSpeed;
    }
}

void Clock::draw() {

    ofTranslate(clockX, clockY);
    clock.draw();
    
    for(int i = 1; i <= numOfHours; i++) {
        ofPushMatrix();
        ofRotate((360 / numOfHours) * i);
        
        ofPushStyle();
        ofSetColor(0);
        ofDrawBitmapString(ofToString(i), -5, -hourDist);
        ofPopStyle();
        ofPopMatrix();
    }
    
    ofPushMatrix();
    ofRotate(handAng);
    
    ofPushStyle();
    ofSetColor(0);
    ofLine(handX, handY, handX, handY - lengOfHand);
    ofCircle(handX, handY - lengOfHand, hammerR, hammerR);
    ofPopStyle();
    
    img.draw(-imgW/2, -imgH/2, imgW, imgH);
    ofPopMatrix();
}

void Clock::keyPressed(int key) {
    
    if(key == 13) {
        action = 1;
    }
    
    if(key == 32) {
        action = 2;
    }
}
