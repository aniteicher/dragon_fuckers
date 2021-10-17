#include "Row_Swipe.h"

Row_Swipe :: Row_Swipe(const Row_Swipe &copy)
    {
      row_start=copy.row_start;
      row_end=copy.row_end;
      delay=copy.delay;
      length = copy.length;
      col_start =copy.col_start;
      delay_counter =copy.delay_counter;
      h=copy.h;
      s=copy.s;
      v=copy.v;
      action=copy.action;
      style=copy.style;
      fade=copy.fade;
      i=row_start;
      done=false;
      flag =false;
      is_active=true;
      time_stamp = millis();

    }
    
     Row_Swipe :: Row_Swipe(u32 start,u32 end,u32 col, u8 len ,u32 delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade)
    {
        row_start=start;
        row_end=end;
        this->delay=delay;
        col_start =col;
        length = len;
        delay_counter=0;
        this->h=h;
        this->s=s;
        this->v=v;
        this->action=action;
        this->style=style;
        this->fade=fade;
        i=row_start;
        done=false;
        is_active=true;
        flag =false;
        time_stamp = millis();

    }

    Row_Swipe :: Row_Swipe()
    {
      row_start=0;
      row_end=0;
      col_start =0;
      length = 0;
      delay=0;
      h=0;
      s=0;
      v=0;
      action=0;
      style=0;
      fade=0;
      i=0;
      delay_counter=0;
      done=true;
      is_active=false;
      flag =false;
    }

void Row_Swipe :: render()
{
     if((millis()-time_stamp)>=delay)
    {
      time_stamp=millis();
   if(row_end>=row_start )
    {

    led.fill_row2(i,col_start,length,h,s,v,action);
   if(i==row_end)
    {
      if(flag)
      {
        is_active=0;
        done=1;
          led.fill_row2(i,col_start,length,h,s,0,REPLACE);
      }
      flag=true;
    }
          if(style==1 && i<=NUMOFROWS)
          {
            led.fill_row2(i-1,col_start,length,h,s,0,REPLACE);
          }
          else if (style == 2)
          {
            fadeToBlackBy(led.f_led,NUMOFLEDS,fade);
          }
          if(!flag)
          i++;


    }
     else  
    {
      
      led.fill_row2(i,col_start,length,h,s,v,action);
   if(i==row_end)
    {
      if(flag)
      {
        is_active=0;
        done=1;
          led.fill_row2(i,col_start,length,h,s,0,REPLACE);
      }
      flag=true;
    }
          if(style==1 && i<NUMOFROWS)
          {
            led.fill_row2(i+1,col_start,length,h,s,0,REPLACE);
          }
          else if (style == 2)
          {
            fadeToBlackBy(led.f_led,NUMOFLEDS,fade);
          }
          if(!flag)
          i--;
      }
    }
}

