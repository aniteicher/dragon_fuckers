#include "Mask.h"


// //@param
// //val_mat - matrix value as a 2d array 
// // row - row number number to fill
// // col - starting colom 
// // len - amount leds to fill
// // r,g,b - Red Green Blue values
// // action - ADD to add values (sum the old RGB values with new), REPLACE to overwrite old values
// //retval: None
void Mask :: fill_row (u8 row ,u8 col, u8 len, u8 r , u8 g, u8 b,u8 action)
{
  u32 tmp;
  if (row >=0 && row <NUMOFROWS)
    for (int i=col ; i<col+len ; i++)
    {
      if( i >=0 && i <NUMOFCOLS )
    {
      if(action==ADD)
      {
        tmp=val_mat[row][i]+rgb2word(r,g,b);
        /*if(tmp>2^24-1)
        tmp=2^24-1;*/
        val_mat[row][i]=tmp;
        //val_mat[row+2][i]= val_mat[row][i];
      }
        else if(action==REPLACE)
        val_mat[row][i]=rgb2word(r,g,b);
      }
    }

}  

void Mask :: fill_row2 (u8 row ,u8 col, u8 len, u8 h , u8 s, u8 v,u8 action)
{
  u8 r,g,b;
  CRGB tmp;
  CHSV tmp2 = CHSV(h,s,v);
  if (row >=0 && row <NUMOFROWS)
    for (int i=col ; i<col+len ; i++)
    {
      if( i >=0 && i <NUMOFCOLS )
    {
      if(action==ADD)
      {
        
        hsv2rgb_rainbow(tmp2,tmp);
        r=tmp.r;
        b=tmp.b;
        g=tmp.g;
        f_led[mappingMatrix[row][i]] += CRGB(r,g,b);
        
     
      }
        else if(action==REPLACE)
         f_led[mappingMatrix[row][i]] = CHSV(h,s,v);
      }
    }

}



void Mask :: fill_row2_swipe(u32 row_start,u32 row_end,u32 col, u8 len ,u32 swipe_delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade)
  {
    if(row_end>=row_start )
    {
    for(u32 i= row_start; i<row_end;i++)
      {
      
      fill_row2(i,col,len,h,s,v,action);
      fast2octo(1);  
      delay(swipe_delay);
      if(style>0)
        {
          if(style<2)
          fill_row2(i,col,len,h,s,0,REPLACE);
          else
          {
            fadeToBlackBy(f_led,NUMOFLEDS,fade);
          }
          
        }
       } 
    }
    else
    {
            for(u32 i= row_start; i>row_end;i--)
            {
            
                fill_row2(i,col,len,h,s,v,action);
                fast2octo(1);
      delay(swipe_delay);
      if(style>0)
        {
          if(style<2)
          fill_row2(i,col,len,h,s,0,REPLACE);
          else
          {
            fadeToBlackBy(f_led,NUMOFLEDS,fade);
          }
          
        }
       } 
          }
      }   
  
// //TODO : add doco
void Mask::LED_update ()
{
  for (int i=0; i<NUMOFROWS;i++)
  {
    for (int j=0;j<NUMOFCOLS;j++)
      if (mappingMatrix[i][j]!=-1)
      set_color(mappingMatrix[i][j],val_mat[i][j]);
}
}




void Mask :: fill_col (u8 col ,u8 row, u8 len, u8 r , u8 g, u8 b,bool action)
{
   u32 tmp;
  if (col >=0 && col <NUMOFCOLS)
    for (int i=row ; i<row+len ; i++)
    {
      if( i >=0 && i <NUMOFROWS )
      {
      if(action==ADD)
      {
		    tmp=rgb2word(r,g,b);
        val_mat[i][col]=val_mat[i][col]+tmp;

      }
      else if(action==REPLACE)
        val_mat[i][col]=rgb2word(r,g,b);
      }
    }

}  
void Mask :: fill_col2 (u8 col ,u8 row, u8 len, u8 h , u8 s, u8 v,bool action)
{
    u8 r,g,b;

  CRGB tmp;
  CHSV tmp2 = CHSV(h,s,v);

  if (col >=0 && col <NUMOFCOLS)
    for (int i=row ; i<row+len ; i++)
    {
      if( i >=0 && i <NUMOFROWS )
      {
      if(action==ADD)
      {
        hsv2rgb_raw(tmp2,tmp);
                r=tmp.r;
        b=tmp.b;
        g=tmp.g;
                
                f_led[mappingMatrix[i][col]]+= CRGB(r,g,b);

      }
      else if(action==REPLACE)
         f_led[mappingMatrix[i][col]] = CHSV(h,s,v);
      }
    }

}  
void Mask :: fill_col2_swipe(u32 col_start,u32 col_end,u32 row, u8 len,u32 ,u32 swipe_delay , u8 h,u8 s,u8 v,bool action,int style,u8 fade)
  {
    if(col_end>=col_start )
    {
    for(u32 i= col_start; i<col_end;i++)
      {
      
      fill_col2(i,row,len,h,s,v,action);
      fast2octo(1);  
      delay(swipe_delay);
      if(style>0)
        {
          if(style<2)
          fill_col2(i,row,len,h,s,0,REPLACE);
          else
          {
            fadeToBlackBy(f_led,NUMOFLEDS,fade);
          }
          
        }
       } 
    }
    else
    {
            for(u32 i= col_start; i>col_end;i--)
            {
            
                fill_col2(i,row,len,h,s,v,action);
                fast2octo(1);
                delay(swipe_delay);
      if(style>0)
        {
          if(style<2)
          fill_col2(i,row,len,h,s,0,REPLACE);
          else
          {
            fadeToBlackBy(f_led,NUMOFLEDS,fade);
          }
          
        }
       } 
          }
      }   
  

void Mask :: print_mat()
{	
  for (int i=0;i<NUMOFROWS;i++)
  {
    for (int j=0;j<NUMOFCOLS;j++)
    {
    Serial.write("%d ",val_mat[i][j]);
    // Serial.write(" ");
    }
   Serial.write("\n");
  }


}

void Mask :: slash(u32 diag, u8 r,u8 g,u8 b,bool action){
  for (u32 i=0;i<=diag;i++)
  {
    if(i<NUMOFROWS && i>=0 && diag-i>=0 && diag-i<NUMOFCOLS)
      {
        if(action==ADD)
        {
          val_mat[i][diag-i] +=rgb2word(r,g,b);
        }
        else
        {  
          val_mat[i][diag-i] =rgb2word(r,g,b);
        }
        
      }  
    }
  }


void Mask :: slash2(u32 diag, u8 h,u8 s,u8 v,bool action){
  u8 r,g,b;
  CRGB tmp;
  CHSV tmp2 = CHSV(h,s,v);
  for (u32 i=0;i<=diag;i++)
  {
    if(i<NUMOFROWS && i>=0 && diag-i>=0 && diag-i<NUMOFCOLS)
      {
        if(action==ADD)
        {
        hsv2rgb_raw(tmp2,tmp);
        r=tmp.r;
        b=tmp.b;
        g=tmp.g;
                
          f_led[mappingMatrix[i][diag-i]]+= CRGB(r,g,b);
          
        }
        else
        {  
          f_led[mappingMatrix[i][diag-i]]= CHSV(h,s,v);
        }
        
      }  
    }
  }

void Mask :: slash_swipe(u32 diag_start,u32 diag_end,u32 swipe_delay, u8 r,u8 g,u8 b,bool action,int style)
  {
    if(diag_end>=diag_start )
    {
    for(u32 i= diag_start; i<diag_end;i++)
    {
      
  slash(i,r,g,b,action);
  LED_update();
  show();  
  delay(swipe_delay);
  if(style>0)
      {
       slash(i,0,0,0,REPLACE);
      }
   } 
    }
    else
    {
       for(u32 i= diag_start; i>diag_end;i--)
    {
      
  slash(i,r,g,b,action);
  LED_update();
  show();
  delay(swipe_delay);
  if(style>0)
      {
       slash(i,0,0,0,REPLACE);
      }
     }
      }   
  }


void Mask :: slash_swipe2(u32 diag_start,u32 diag_end,u32 swipe_delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade)
  {
    if(diag_end>=diag_start )
    {
    for(u32 i= diag_start; i<diag_end;i++)
      {
      
      slash2(i,h,s,v,action);
      fast2octo(1);  
      delay(swipe_delay);
      if(style>0)
        {
          if(style<2)
          slash2(i,0,0,0,REPLACE);
          else
          {
            fadeToBlackBy(f_led,NUMOFLEDS,fade);
          }
          
        }
       } 
    }
    else
    {
            for(u32 i= diag_start; i>diag_end;i--)
            {
            
                slash2(i,h,s,v,action);
                fast2octo(1);
                delay(swipe_delay);
      if(style>0)
        {
          if(style<2)
          slash2(i,0,0,0,REPLACE);
          else
          {
            fadeToBlackBy(f_led,NUMOFLEDS,fade);
          }
          
        }
       } 
          }
      }   
  




void Mask :: backslash(u32 diag, u8 r,u8 g,u8 b,bool action)
{
  
  for (u32 i=0 ; i<=diag;i++)
  {
	  if(NUMOFROWS-i<NUMOFROWS&&NUMOFROWS-i>=0&&diag-i>=0&&diag-i<NUMOFCOLS)
		 
      {
        
        if(action==ADD)
        {
          val_mat[NUMOFROWS-i][diag-i] +=rgb2word(r,g,b);
        }
        else
        {  
          val_mat[NUMOFROWS-i][diag-i] =rgb2word(r,g,b);
        }
        }
  }
}	 


void Mask :: backslash2(u32 diag, u8 h,u8 s,u8 v,bool action)
{
    u8 r,g,b;

  CRGB tmp;
  CHSV tmp2 = CHSV(h,s,v);

  for (u32 i=0 ; i<=diag;i++)
  {
	  if(NUMOFROWS-i<NUMOFROWS&&NUMOFROWS-i>=0&&diag-i>=0&&diag-i<NUMOFCOLS)
		 
      {
        
        if(action==ADD)
        {
        hsv2rgb_raw(tmp2,tmp);
        r=tmp.r;
        b=tmp.b;
        g=tmp.g;
                
          f_led[mappingMatrix[NUMOFROWS-i][diag-i]]+= CRGB(r,g,b);

        }
        else
        {  
           f_led[mappingMatrix[NUMOFROWS-i][diag-i]]= CHSV(h,s,v);

        }
        }
  }
}	 
void Mask :: backslash_swipe2(u32 diag_start,u32 diag_end,u32 swipe_delay, u8 h,u8 s,u8 v,bool action,int style,u8 fade)
  {
    if(diag_end>=diag_start )
    {
    for(u32 i= diag_start; i<diag_end;i++)
      {
      
      backslash2(i,h,s,v,action);
      fast2octo(1);  
      delay(swipe_delay);
      if(style>0)
        {
          if(style<2)
          backslash2(i,0,0,0,REPLACE);
          else
          {
            fadeToBlackBy(f_led,NUMOFLEDS,fade);
          }
          
        }
       } 
    }
    else
    {
            for(u32 i= diag_start; i>diag_end;i--)
            {
            
                backslash2(i,h,s,v,action);
                fast2octo(1);
                delay(swipe_delay);
      if(style>0)
        {
          if(style<2)
          backslash2(i,0,0,0,REPLACE);
          else
          {
            fadeToBlackBy(f_led,NUMOFLEDS,fade);
          }
          
        }
       } 
          }
      }   
  
  
  //random path
  //a led with color RGB will run randomly until it reaches the edge of the mask
  // the function will not stop until reaching the edge!
  // param:
  // col - starting colom index 
  // row - starting row index
  // direction - possible directions - (R,L,U,D,RL,RU,RD,RLU,RLD,RUD,LUD,ALL)
  // retval : None
  void Mask :: randomPath(u8 col,u8 row,u32 RGB,std::string direction,u32 del)
  {
    u8 randNum;
    bool legal;
    u32  len = direction.length();
    char action;
    set_color(mappingMatrix[row][col],0);
    show();
    delay(del);

    if (col < NUMOFCOLS && row < NUMOFROWS && row>=0 && col>=0)
    {
    legal = true;
    Serial.println("LEGAL");
    }
    else
    {
      Serial.println("ILEGAL");
      return;
    }
    
    while (legal)
    {
      randNum = random(0,len);
      action = direction[randNum];
      set_color(mappingMatrix[row][col],0);

      if (action == 'R')
      {
        col ++;
      }
      if (action == 'L')
      {
        col--;
      }
      if (action == 'U')
     {
      row --;
     }
      if (action == 'D')
      {
        row ++;
      }
      if (col < NUMOFCOLS && row < NUMOFROWS && row>=0 && col>=0)
      {
        if (mappingMatrix[row][col] == -1)
        {
          Serial.println("setting color");
          set_color(mappingMatrix[row][col],RGB);
          show();
          delay(del);
        }
        else 
        {
          Serial.println("Continue");
          continue;
        }
      }
      else
      {
        Serial.println("ILEGAL");
      }
      

    }
  }

void Mask :: drawsquare(u32 center_x,u32 center_y,u32 length,u8 h,u8 s,u8 v,bool action)
{
  fill_row2(center_y-(length/2),center_x-(length/2),length,h,s,v,action);
  fill_row2(center_y+(length/2),center_x-(length/2),length,h,s,v,action);
  fill_col2(center_x-(length/2),center_y-(length/2),length,h,s,v,action);
  fill_col2(center_x+(length/2),center_y-(length/2),length,h,s,v,action);
}



