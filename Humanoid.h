//
//  Humanoid.h
//  glutCpp
//
//  Created by Ruben Cuadra on 2/25/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved.
//

#pragma once
#include "Torso.h"
#include "Head.h"
#include "UpperLimb.h"

class Humanoid //Padre para personajes humanoides
{
protected:
    Torso *torso;
    Head *head;
    UpperLimb *right;
    UpperLimb *left;
    
public:
    virtual void render() = 0; //Puede cambiar acomodo de objetos
    
    //Torso
    bool rotateTorso_Stomach(float toAngle){ return torso->setStomachTorsion(toAngle); }
    bool rotateTorso_Chest  (float toAngle){ return torso->setChestTorsion  (toAngle); }
    //Head
    bool verticalRotateHead(float toAngle) {return head->setRotation(toAngle);}
    bool rotateHead(float toAngle) {return head->setTorsion(toAngle);}
    //Arms
        //Right
    bool rotateRightArm(float toAngle) {return right->rotateArm(toAngle); }
    bool revolRightArm(float toAngle)  {return right->revArm(toAngle); }
    bool rotRightForearm(float toAngle){return right->rotForearm(toAngle); }
    bool torRightForearm(float toAngle){return right->torForearm(toAngle); }
    bool rotRightHand(float toAngle){return right->rotHand(toAngle); }
    bool torRightHand(float toAngle){return right->torHand(toAngle); }
        //Left
    bool rotateLeftArm(float toAngle) {return left->rotateArm(toAngle); }
    bool revolLeftArm(float toAngle)  {return left->revArm(toAngle); }
    bool rotLeftForearm(float toAngle){return left->rotForearm(toAngle); }
    bool torLeftForearm(float toAngle){return left->torForearm(toAngle); }
    bool rotLeftHand(float toAngle){return left->rotHand(toAngle); }
    bool torLeftHand(float toAngle){return left->torHand(toAngle); }
};

class Human : public Humanoid
{
public:
    Human()
    {
        torso = new Torso(-30,30,-20,20);
        head = new Head(-60,80,-90,90);
        right = new UpperLimb(-90,180,-100,10,0,90,-20,20,-10,40,-20,20);
        left = new UpperLimb(-90,180,-10,100,0,90,-20,20,-10,40,-20,20);
    }
    void render()
    {
        glPushMatrix(); //Lo de arriba se afecta por la rotacion de hombros
        
            torso->render();
            glRotatef( torso->getChestTorsion() , 0,1,0);
        
            glPushMatrix();
                glTranslatef(0,0.95,0);
                head->render();
            glPopMatrix();
        
            glPushMatrix();
                glTranslatef(-0.7,0.2,0);
                right->render();
            glPopMatrix();
        
            glPushMatrix();
                glTranslatef(0.7,0.2,0);
                left->render();
            glPopMatrix();
        
        glPopMatrix();
    }
};
