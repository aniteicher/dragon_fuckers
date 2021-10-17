#include "BackSlash_Swipe.h"

BackSlash_Swipe :: BackSlash_Swipe(const BackSlash_Swipe &copy)
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
      done=false;
      flag=false;
      is_active=true;
      time_stamp = millis();

    }
    
     BackSlash_Swipe :: BackSlash_Swipe(u32 start,u32 end, u32 delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade)
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
        flag=false;
        is_active=true;
        time_stamp = millis();

    }

    BackSlash_Swipe :: BackSlash_Swipe()
    {
      delay_counter=0;
      diag_start=0;
      diag_end=0;
      delay=0;
      h=0;
      s=0;
      v=0;
      action=0;
      style=0;
      fade=0;
      i=0;
      flag=false;
      done=true;
      is_active=false;
    }

void BackSlash_Swipe :: render()
{
  if((millis()-time_stamp)>=delay)
    {
      time_stamp=millis();

   if(diag_end>=diag_start )
    {

    
          led.backslash2(i,h,s,v,action);
       if (i==diag_end)
      {
         if(flag)
          {
              is_active=0;
              done=1;
              led.backslash2(i,0,0,0,REPLACE);
          }
            flag=true;

      }

     
          if(style==1)
          {
            if(i!=0)
            led.backslash2(i-1,0,0,0,REPLACE);
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
               led.backslash2(i,h,s,v,action);
       if (i==diag_end)
      {
         if(flag)
          {
              is_active=0;
              done=1;
              led.backslash2(i,0,0,0,REPLACE);
          }
            flag=true;

      }

     
          if(style==1)
          {
            led.backslash2(i+1,0,0,0,REPLACE);
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