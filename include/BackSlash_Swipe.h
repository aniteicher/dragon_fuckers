#include "Mask.h"
#include "BasicPattern.h"
#include "Defines.h"

#ifndef BACKSLASHSWIPE_H
#define BACKSLASHSWIPE_H


extern Mask led;

class BackSlash_Swipe : public BasicPattern
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
    bool flag=false;
    int style;
    int time_stamp;
    u8 fade;
    u16 i ; //index 
    BackSlash_Swipe(u32 start,u32 end, u32 delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade);
    BackSlash_Swipe(const BackSlash_Swipe &copy);
    BackSlash_Swipe();
    void render();
    
};



#endif