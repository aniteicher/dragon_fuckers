#include "Slash_Swipe.h"

Slash_Swipe :: Slash_Swipe(const Slash_Swipe &copy)
    {
      diag_start=copy.diag_start;
      diag_end=copy.diag_end;
      delay=copy.delay;
      delay_counter=copy.delay_counter;
      h=copy.h;
      s=copy.s;
      v=copy.v;
      action=copy.action;
      style=copy.style;
      fade=copy.fade;
      i=0;
      flag =false;
      done=false;
      is_active=true;
      time_stamp = millis();

    }
    
     Slash_Swipe :: Slash_Swipe(u32 start,u32 end, u32 delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade)
    {
        diag_start=start;
        diag_end=end;
        this->delay=delay;
        delay_counter=0;
        this->h=h;
        this->s=s;
        this->v=v;
        this->action=action;
        this->style=style;
        this->fade=fade;
        i=diag_start;
        done=false;
        flag =false;
        is_active=true;
        time_stamp = millis();

    }

    Slash_Swipe :: Slash_Swipe()
    {
      diag_start=0;
      diag_end=0;
      delay=0;
      delay_counter=0;
      h=0;
      s=0;
      v=0;
      action=0;
      style=0;
      fade=0;
      i=0;
      done=true;
      flag =false;
      is_active=false;
      time_stamp;
    }
  
void Slash_Swipe :: render()
{
  if(millis()-time_stamp>=delay)
    {
    time_stamp=millis();

    if(diag_end>=diag_start)
    {

    
    led.slash2(i,h,s,v,action);

       if (i==diag_end)
          {
            if(flag)
            {
            is_active=0;
            done=1;
            led.slash2(i,0,0,0,REPLACE);

            }
            flag=true;
          }
        
      
          if(style==1)
          {
            if(i!=0)
            led.slash2(i-1,0,0,0,REPLACE);
          }
          else if(style==2)
          {
            fadeToBlackBy(led.f_led,NUMOFLEDS,fade);
          }
          if(!flag)
          i++;  

    }
    else
    {
      
      led.slash2(i,h,s,v,action);

       if (i==diag_end)
          {
            if(flag)
            {
            is_active=0;
            done=1;
            led.slash2(i,0,0,0,REPLACE);

            }
            flag=true;
          }
        
      
          if(style==1)
          {
            led.slash2(i+1,0,0,0,REPLACE);
          }
          else if(style==2)
          {
            fadeToBlackBy(led.f_led,NUMOFLEDS,fade);
          }
          if(!flag)
          i--;  

    }
 
  }
}