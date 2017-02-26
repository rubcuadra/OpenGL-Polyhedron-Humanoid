//
//  LowerLimb.h
//  glutCpp
//
//  Created by Ruben Cuadra on 2/26/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved.
//

#pragma once

class Thigh : Part //Entre cadera y rodilla
{
public:
    Thigh(float minRotation, float maxRotation,float minRevolution,float maxRevolution):Part(minRotation,maxRotation,0,0,minRevolution,maxRevolution){}
    void render()
    {
        
        glTranslatef(0,0.15,0);     //Movemos para generar el hombro
            glRotatef(rotation,1,0,0);
            glRotatef(revolution,0,0,1);
        glTranslatef(0,-0.15,0);    //Regresamos para generar el brazo
        
        glPushMatrix();
            glScalef(0.18,0.3,0.22);     //Escalamos
            glutSolidSphere(1,20,20);   //Dibujamos
            glPopMatrix();
        glTranslatef(0,-0.2,0);     //Aqui estamos en el codo
        
        glPushMatrix();                 //Aqui va lo del muslo
            glScalef(0.1,0.3,0.1);
            glutWireDodecahedron();
        glPopMatrix();
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
    
    void render()
    {
        thigh->render();
    }
};
