#include "Col_Swipe.h"

Col_Swipe :: Col_Swipe(const Col_Swipe &copy)
    {
      col_start=copy.col_start;
      col_end=copy.col_end;
      delay=copy.delay;
      delay_counter=copy.delay_counter;
      length = copy.length;
      row_start =copy.row_start;
      h=copy.h;
      s=copy.s;
      v=copy.v;
      action=copy.action;
      style=copy.style;
      fade=copy.fade;
      i=row_start;
      done=false;
      is_active=true;
      flag =false;
      time_stamp = millis();

    }
    
     Col_Swipe :: Col_Swipe(u32 start,u32 end,u32 row, u8 len ,u32 delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade)
    {
        col_start=start;
        col_end=end;
        this->delay=delay;
        row_start =row;
        length = len;
        delay_counter=0;
        this->h=h;
        this->s=s;
        this->v=v;
        this->action=action;
        this->style=style;
        this->fade=fade;
        i=col_start;
        done=false;
        is_active=true;
        flag =false;
    }

    Col_Swipe :: Col_Swipe()
    {
      col_start=0;
      col_end=0;
      row_start =0;
      length = 0;
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
      is_active=false;
      flag =false;
    }

void Col_Swipe :: render()
{
  if((millis()-time_stamp)>=delay)
    {
    time_stamp=millis();

  if(col_end>=col_start )
    {



       if(!flag)
      led.fill_col2(i,row_start,length,h,s,v,action);
      if (i==col_end)
      {
        
          if(flag)
          {
            led.fill_col2(i,row_start,length,h,s,0,REPLACE);
            is_active=0;
            done=1;
          }
          flag =true;
      }
      if(style>0)
        {
          if(style==1 && i<=NUMOFCOLS)
          {
          if(i>0)
          led.fill_col2(i-1,row_start,length,h,s,0,REPLACE);
          }
          else if (style == 2)
            {
              fadeToBlackBy(led.f_led,NUMOFLEDS,fade);
            }     
        }
    if(!flag)
     i++;


    }
  else
    { 
            if(!flag)
      led.fill_col2(i,row_start,length,h,s,v,action);
      if (i==col_end)
      {
        
          if(flag)
          {
            led.fill_col2(i,row_start,length,h,s,0,REPLACE);
            is_active=0;
            done=1;
          }
          flag =true;
      }
      if(style>0)
        {
          if(style==1 && i<NUMOFCOLS)
          {
          if(i>=0)
          led.fill_col2(i+1,row_start,length,h,s,0,REPLACE);
          }
          else if (style == 2)
            {
              fadeToBlackBy(led.f_led,NUMOFLEDS,fade);
            }     
        }
if(!flag)
  i--;

  }
    }
}


