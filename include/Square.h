#include "Mask.h"
#include "BasicPattern.h"
#include "Defines.h"

#ifndef square_H
#define square_H


extern Mask led;

class square : public BasicPattern
{
    public:
    u16 center_x;
    u16 center_y;
    u16 length_start;
    u16 length_end;
    u16 swipe_delay;
    u16 delay_counter;
    u16 length;
    u16 steps;
    u8 h;
    u8 s;
    u8 v;
    int style;
    bool action;
    u8 fade;
    u16 x ; //index
    u16 y ; //index 
    int i;
    long time;
    square(u16 center_x,u16 center_y,u16 length_start,u16 steps, u32 delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade);
    square(const square &copy);
    square();
    
    void render();

};



#endif