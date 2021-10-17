#include "Square.h"


square :: square(const square &copy)
    {
     
        center_x=copy.center_x;
        center_y=copy.center_y;
        length_start = copy.length_start;
        delay_counter=copy.delay_counter;
        steps=copy.steps;
        h=copy.h;
        s=copy.s;
        v=copy.v;
        action=copy.action;
        style=copy.style;
        fade=copy.fade;
        x=copy.x;
        y=copy.y;
        done=false;
        is_active=true;
        i=0;
        time=millis();


    }


square ::square(u16 center_x,u16 center_y,u16 length_start,u16 steps, u32 delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade)
    {
       this->center_x=center_x;
       this->center_y=center_y;
        swipe_delay=delay;
        this->length_start = length_start;
        delay_counter=0;
        this->steps=steps;
        this->h=h;
        this->s=s;
        this->v=v;
        this->action=action;
        this->style=style;
        this->fade=fade;
        x=center_x-(length/2);
        y=center_y-(length/2);
        done=false;
        is_active=true;
        i=0;
        this->startTime=startTime;
    }

    square :: square()
    {
      center_x=0;
      center_y=0;
      length_start=0;
      length_end =0;
      length = 0;
      swipe_delay=0;
      h=0;
      s=0;
      v=0;
      action=0;
      style=0;
      fade=0;
      x=0;
      y=0;
      delay_counter=0;
      done=true;
      is_active=false;
      i=0;
    }
 



void square :: render()
{
 if (style<3)
 {
   if(steps>0 )
    {
        length = length_start+(i*2);
      
      led.drawsquare(center_x,center_y,length,h,s,v,action);
          if(style==1 && length >0)
          {
            led.drawsquare(center_x,center_y,length-1,h,s,0,action);
          }
          else if (style == 2)
          {
            fadeToBlackBy(led.f_led,NUMOFLEDS,fade);
          }
 
    i++;
    steps--;
    if(steps==0)
    {
      i=0;
      is_active=0;
      done=1;
    }
    }

     }
     else if(style<4)
     {

       if(millis()-startTime>200)
       {
       
               for ( i=0;i<12;i++)
          {
             led.fill_row2(center_y+i,0,7,h,s,0,REPLACE);
          } 
          is_active=0;
          done=1;
       }
       else
       {
       for ( i=0;i<12;i++)
       {
         led.fill_row2(center_y+i,0,7,h,s,v,REPLACE);
       }
       }
     }
     else
     {
       for (i=0;i<NUMOFLEDS;i++)
       {led.f_led[i]=CHSV(h,s,v);}

       if(millis()-startTime>25)
       {
       
               for ( i=0;i<NUMOFLEDS;i++)
          {
                    {led.f_led[i]=CHSV(h,s,0);}
          } 
         is_active=0;
          done=1;


     }
     }
     
    }
