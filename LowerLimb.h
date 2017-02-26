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
    
    void render()
    {
        
    }
};
