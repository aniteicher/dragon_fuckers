#include "Mask.h"
#include "BasicPattern.h"
#include "Defines.h"

#ifndef ROWSWIPE_H
#define ROWSWIPE_H


extern Mask led;

class Row_Swipe : public BasicPattern
{
    public:
    u32 row_start;
    u32 row_end;
    u32   col_start =0;
    u8  length = 0;
    u32 delay;
    u32 delay_counter;
    u8 h;
    u8 s;
    u8 v;
    bool action;
    bool flag =false;
    int style;
    u8 fade;
    u16 i ; //index 
    int time_stamp;
    
    // Row_Swipe(u32 row_start,u32 row_end,u32 col, u8 len,u32 ,u32 swipe_delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade);
    Row_Swipe(const Row_Swipe &copy);
    Row_Swipe();
    Row_Swipe(u32 start,u32 end,u32 col, u8 len,u32 delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade);
    
    void render();
    
};



#endif