#include "Sticks.h"


sticks :: sticks(const sticks &copy)
    {
     
        center_x=copy.center_x;
        center_y=copy.center_y;
        length_start = copy.length_start;
        delay_counter=copy.delay_counter;
        steps=copy.steps;
        h=copy.h;
        s=copy.s;
        v=copy.v;
        shape=copy.shape;
        shape2=copy.shape2;
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


    sticks ::sticks(u8 shape, u32 delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade)
    {
      
        swipe_delay=delay;
        delay_counter=0;
        this->h=h;
        this->s=s;
        this->v=v;
        this->shape=shape;
        this->shape2=shape2;
        this->action=action;
        this->style=style;
        this->fade=fade;
        done=false;
        is_active=true;
        i=0;
        this->startTime=startTime;
    }

    sticks :: sticks()
    {
      
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
 



void sticks :: render()
{
    switch(shape)
    {
        default:
        {break;}
    }
    }

void sticks :: hexagon(u8 shape2 ,u8 h , u8 s, u8 v)
    {
        u8 shape_out[6] = {16,18,19,20,22,24};
        // u8 shape_in[6] = {24,25,26,27,28,29};
switch(shape2)
        {
            case 0:
            for(int j =0 ; j <sizeof(shape_out)/sizeof(shape_out[0]);i++)
            {
                led.fill_row2(shape_out[i],0,NUMOFCOLS,h,s,v,action);
            }
            break;
default:
break;
        }

    }

void sticks :: upper_tri(u8 shape2 ,u8 h , u8 s, u8 v)
    {
        u8 shape_out[6] = {22,23,15,16,26,29};
        switch(shape2)
        {
            case 0:
            break;
default:
break;
        }
    }
    
void sticks :: lower_tri(u8 shape2 ,u8 h , u8 s, u8 v)
    {
        u8 shape_out[6] = {28,27,6,7,8,9};

    }
    
void sticks :: big_tri(u8 shape2 ,u8 h , u8 s, u8 v)
    {
        u8 shape[10] = {1,2,3,17,26,29,21,12,13,14};

    }
    
void sticks :: parrallel(u8 shape2 ,u8 h , u8 s, u8 v)
    {
        u8 shape_right[4] = {17,18,4,5};
        u8 shape_left[4] = {11,21,20,10};

    }
    


