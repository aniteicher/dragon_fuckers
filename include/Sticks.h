#include "Mask.h"
#include "BasicPattern.h"
#include "Defines.h"

#ifndef sticks_H
#define sticks_H


extern Mask led;

class sticks : public BasicPattern
{
    public:
    u16 shape1_index[4];




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
    u8 shape;
    u8 shape2;

    
    sticks(u8 shape,u8 shape2, u32 delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade);
    sticks(const sticks &copy);
    sticks();
    

    // void fill_shape(u16 shape_index[],u16 length,u8 fade, );

    void render();

    void hexagon(u8 shape ,u8 h , u8 s, u8 v);
    void upper_tri();
    void lower_tri();
    void big_tri();
    void parrallel();
};



#endif