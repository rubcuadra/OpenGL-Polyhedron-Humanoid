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
    
    bool rotateTorso_Stomach(float toAngle){ return torso->setStomachTorsion(toAngle); }
    bool rotateTorso_Chest  (float toAngle){ return torso->setChestTorsion  (toAngle); }
    
    bool verticalRotateHead(float toAngle) {return head->setRotation(toAngle);}
    bool rotateHead(float toAngle) {return head->setTorsion(toAngle);}
};

class Human : public Humanoid
{
public:
    Human()
    {
        torso = new Torso(-30,30,-20,20);
        head = new Head(-60,80,-90,90);
        right = new UpperLimb(-180,180,-180,180);
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
                glTranslatef(0.7,0.2,0);
                right->render();
            glPopMatrix();
        
        glPopMatrix();
    }
};
