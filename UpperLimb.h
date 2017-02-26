//
//  UpperLimb.h
//  glutCpp
//
//  Created by Ruben Cuadra on 2/26/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved.
//

#pragma once

class Arm : public Part
{
public:
    Arm(float minRotation, float maxRotation,float minRevolution,float maxRevolution):Part(minRotation,maxRotation,0,0,minRevolution,maxRevolution){}
    
    void render(void)
    {
        glPushMatrix();
            glRotatef(rotation,1,0,0);
            glRotatef(revolution,0,0,1);
        
            glScalef(0.18,0.3,0.3);
            glutSolidSphere(1,20,20);
        
        glPopMatrix();
    }
};

class Forearm
{
private:
public:
};

class Hand
{
private:
public:
};

class UpperLimb //Seria como el Humanoid, este manda a rotar cada parte
{
private:
    Arm* arm;
    Hand *hand;
    Forearm *forearm;

public:
    UpperLimb(float minRotArm,float maxRotArm,float minRevArm,float maxRevArm)
    {
        arm = new Arm(minRotArm,maxRotArm,minRevArm,maxRevArm);
        //forearm = new Forearm();
        //hand = new Hand()
    }
    
    void render()
    {
        arm->render();
    }
};
