#include "Mask.h"
#include "BasicPattern.h"
#include "Defines.h"

#ifndef SLASHSWIPE_H
#define SLASHSWIPE_H


extern Mask led;

class Slash_Swipe : public BasicPattern
{
    public:
    u32 diag_start;
    u32 diag_end;
    u32 delay;
    u32 delay_counter;
    u8 h;
    u8 s;
    u8 v;
    bool action;
    bool flag = false;
    int time_stamp;
    int style;
    u8 fade;
    u16 i ; //index 
    Slash_Swipe(u32 start,u32 end, u32 delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade);
    Slash_Swipe(const Slash_Swipe &copy);
    Slash_Swipe();
    void render();
    
};



#endif