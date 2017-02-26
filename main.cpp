
//
//  main.cpp
//  glutCpp
//
//  Created by Ruben Cuadra on 2/10/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved. Basado en trabajo de Ryan Pridgeon 

#include <cmath>
#include <cstdlib>
#include <iostream>
#include "Humanoid.h"

#ifdef __APPLE__
    #include <GLUT/glut.h>
#elif _WIN32 || __linux__
    #include <GL/glut.h>
#endif


float screenWidth=1000,screenHeight=1000;

//Material
GLfloat matSpecular[] = { 0.3, 0.3, 0.3, 1.0 }; //Color Charolazo(Blanco)
GLfloat matAmbience[] = { 0.3, 0.3, 0.3, 1.0 }; //Color del planeta
GLfloat matShininess[] = { 70.0 };              //Charolazo
//Luces
GLfloat lightAmbient[] = { 1.0, 1.0, 1.0, 0.5 }; //Ambiente
GLfloat lightDiffuse[] = { 1.0, 1.0, 1.0, 1.0 }; //Difusa
GLfloat lightSpecular[] = { 1.0, 1.0, 1.0, 1.0 }; //Specular blanca
GLfloat lightPosition[] = { 0.0, 0.0, -1.0, 1.0 }; //Position

Human *human;
float *angles;
float angle_modifier = 5; //Cuando movamos algo se mueve de 5 en 5

//Funcion que recibe como parametro una funcion de la clase Human la cual sirve para rotar alguna parte del cuerpo
//Ademas recibe como parametro un angulo, lo que hace es que llama la funcion con ese angulo + un modificador, si es capaz de rotarla
//nos devuelve el nuevo angulo en el que se encuentra, de otra forma nos devolvera el mismo en el que ya estaba
float incrementAngle(bool (Human::*function)(float), float angle)
{
    return (human->*function)(angle+angle_modifier)
            ?angle+angle_modifier
            :angle;
}
//Mismo que incrementAngle solo que ahora lo decrese
float decreaseAngle(bool (Human::*function)(float), float angle)
{
    return (human->*function)(angle-angle_modifier)?angle-angle_modifier:angle;
}


void timer(int)
{
    glutPostRedisplay(); //invocamos func display
    glutTimerFunc(10, timer, 0); //100fps
}

void setAngles() //Inicializa todos en 0
{
    angles = new float[26]; //26 grados de libertad
    for (int i = 0;i<26;++i)
    {
        angles[i] = 0;
    }
}

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0); //Negro
    
    //Inits
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glShadeModel (GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    //Materiales
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbience);
    //Luz
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    glEnable (GL_LIGHT0);
    
    human = new Human();
    setAngles();
    timer(0);
}

void setUpPerspective() //Inicializar perspectiva
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //70 veces en x por cada y (Lo que se ve)
    //aspecto -> tamaño de pantalla ; zNear y far son los planos
    gluPerspective(40.0f, (float)screenWidth / (float)screenHeight, 1,20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Buffers

    glPushMatrix();
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    
        //setUpPerspective();
        //gluLookAt(0 , 1 , 1 ,0 ,0 ,0 ,0 ,1 ,0);
    
    glPopMatrix();
    
    human->render();
    
    glutSwapBuffers();        //End
}
void keyDown(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
            angles[0] = incrementAngle(&Human::rotateHead,angles[0]);
            break;
        case 'Q':
            angles[0] = decreaseAngle(&Human::rotateHead,angles[0]);
            break;
        case 'w':
            angles[1] = incrementAngle(&Human::verticalRotateHead,angles[1]);
            break;
        case 'W':
            angles[1] = decreaseAngle(&Human::verticalRotateHead,angles[1]);
            break;
        case 'e':
            angles[2] = incrementAngle(&Human::rotateTorso_Chest,angles[2]);
            break;
        case 'E':
            angles[2] = decreaseAngle(&Human::rotateTorso_Chest,angles[2]);
            break;
        case 'r':
            angles[3] = incrementAngle(&Human::rotateTorso_Stomach,angles[3]);
            break;
        case 'R':
            angles[3] = decreaseAngle(&Human::rotateTorso_Stomach,angles[3]);
            break;
            
    }
}

void reshape(int w, int h)
{
    screenWidth = w;
    screenHeight = h;
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(screenWidth,screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glutSetWindowTitle("A01019102");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyDown);
    glutMainLoop();
    return 0;
}
