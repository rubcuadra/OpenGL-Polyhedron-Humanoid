//
//  LowerLimb.h
//  glutCpp
//
//  Created by Ruben Cuadra on 2/26/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved.
//

#pragma once

class Thigh : public Part //Entre cadera y rodilla
{
public:
    Thigh(float minRotation, float maxRotation,float minRevolution,float maxRevolution):Part(minRotation,maxRotation,0,0,minRevolution,maxRevolution){}
    void render()
    {
        
        glTranslatef(0,0.45,0);     //Movemos para generar la articulacion
            glRotatef(rotation,1,0,0);
            glRotatef(revolution,0,0,1);
        glTranslatef(0,-0.45,0);    //Regresamos para generar el muslo
        
        glPushMatrix();             //Pintamos el musculo
            glScalef(0.1,0.3,0.1);
            glutSolidDodecahedron();
        glPopMatrix();
        
        glTranslatef(0,-0.5,0);
        glutWireSphere(0.2,20, 20); //Nos deja en la rodilla
    }
};

class Calf //Entre rodilla y tobillo
{

};
class Foot //Pie
{
    
};

class LowerLimb
{
private:
    Thigh * thigh;
    Calf * calf;
    Foot * foot;
    
public:
    LowerLimb(float minRotThigh,float maxRotThigh,float minRevThigh,float maxRevThigh,
              float minForeRotation,float maxForeRotation, float minForeTor,float maxForeTor,
              float minHandRotation, float maxHandRotation, float minHandTor, float maxHandTor)
    {
        thigh = new Thigh(minRotThigh,maxRotThigh,minRevThigh,maxRevThigh);
    }
    
    bool rotateThigh(float toAngle) {return thigh->setRotation(toAngle);}
    bool revThigh(float toAngle) { return thigh->setRevolution(toAngle); }
    
    void render()
    {
        thigh->render();
    }
};
