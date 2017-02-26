//
//  Torso.h
//  glutCpp
//
//  Created by Ruben Cuadra on 2/24/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved.
//


#ifdef __APPLE__
    #include <GLUT/glut.h>
#elif _WIN32 || __linux__
    #include <GL/glut.h>
#endif
#pragma once

class Torso
{
private:
    float minTorsionChest,maxTorsionChest;
    float minTorsionStomach,maxTorsionStomach;
    float torsionC, torsionS;
    
public:
    Torso(float minChest,float maxChest,float minStomach, float maxStomach)
    : minTorsionChest(minChest),maxTorsionChest(maxChest),minTorsionStomach(minStomach),maxTorsionStomach(maxStomach),torsionC(0),torsionS(0){}
    
    bool setChestTorsion(float torsion)
    {
        torsion = ((int)torsion)%365;
        if (torsion<maxTorsionChest && torsion>minTorsionChest)
        {
            this->torsionC = torsion;
            return true;
        }
        return false;
    }
    bool setStomachTorsion(float torsion)
    {
        torsion = ((int)torsion)%365;
        if (torsion<maxTorsionStomach && torsion>minTorsionStomach)
        {
            this->torsionS = torsion;
            return true;
        }
        return false;
    }
    
    float getChestTorsion(){return torsionC;}
    float getStomachTorsion(){return torsionS;}
    
    void render(void)
    {
        glPushMatrix(); //Stomach
            glRotatef(torsionS,0,1,0);
            glTranslatef(0,-0.1,0);
            glScalef(0.75,0.6,0.5);
            glutSolidCube(1);
        glPopMatrix();
        
        glPushMatrix(); //Chest
            glTranslatef(0,0.35,0);
            glRotatef(torsionC,0,1,0);
            glScalef(1.2,0.65,0.7); //Escala para un Rectangulo
            glScalef(0.4,0.3,0.4);   //Dode es mas grande
            glutSolidDodecahedron();
        glPopMatrix();
    }
};
