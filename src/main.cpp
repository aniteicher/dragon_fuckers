#include "Mask.h"
#include "Slash_Swipe.h"
#include "BackSlash_Swipe.h"
#include "BasicPattern.h"
#include "BasicLed.h"
#include "Defines.h"
#include "Row_Swipe.h"
#include "Col_Swipe.h"
#include "square.h"
#include <MIDI.h>
#include "SPI.h"
#include "SD.h"
#include <string.h>
#include "looper.h"

                    
#define MASTER




#if defined(USBCON)
#include <midi_UsbTransport.h>

static const unsigned sUsbTransportBufferSize = 16;
typedef midi::UsbTransport<sUsbTransportBufferSize> UsbTransport;

UsbTransport sUsbTransport;

MIDI_CREATE_INSTANCE(UsbTransport, sUsbTransport, MIDI);

#else // No USB available, fallback to Serial
MIDI_CREATE_DEFAULT_INSTANCE();
#endif

// --


void runtheloop();
void shiftleft(int index);
void add_pattern(int pattern_id, uint8_t gHue);
u8 aux(u8 id);
void processMIDI();
void myNoteOn(byte channel, byte note, byte velocity);
void myRealTimeSystem(byte realtimebyte);
void handleControlChange(byte channel, byte number, byte value);
void myNoteOff(byte channel, byte note , byte velocity);
void set_delay();
void set_On_Off();


Mask led;

BasicPattern *pattern_list[MAX_PATTERNS];

Slash_Swipe slash[SUB_PAT_SIZE]; // he right

BackSlash_Swipe backslash[SUB_PAT_SIZE]; // he right

Row_Swipe rowswipe[SUB_PAT_SIZE];

Col_Swipe colswipe[SUB_PAT_SIZE];

square Square[SUB_PAT_SIZE];

uint8_t A;
uint8_t B;
uint8_t C;
uint8_t tav;
String temp;

bool flag=true;
u8 delay1=50;
u8 delay2=50;
u8 delay3=50;
u8 delay4=50;


u8 OnOff[112]={0};
bool OnOff_flag=false;

u8 Pulse_rate=0;
u32 T[2]={0,0};
u32 Tsum=0;
u8 flag_bpm=0;
u8 counter_bpm=0;
u8 bpm;
u16 duration=0;
u8 old_bpm=0;


u8 hue = 200;
u8 diag = 0;
int pot1 = 0;
int pot2 = 0;
u32 start;
u32 col;
u32 row;
u8 len=60;
u8 h;
u8 s;
u8 v=255;
u8 fade=10;
bool sd_in;
Looper looper{A, B, C};

// clouds veriables
uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t glit = 0; // rotating "base color" used by many of the patterns
uint8_t ro = 0; 
uint8_t pole = 0;
uint8_t p_hue=130;
u8 style=1;  
bool light =false;
bool active = true;
uint8_t state = 0;
File myFile;
uint8_t offset=21;
uint8_t hue_arr[4]={0,63,126,189};
void setup()
{ 

  Serial.begin(115200);
  
  usbMIDI.begin();
  usbMIDI.setHandleNoteOn(myNoteOn);
  usbMIDI.setHandleNoteOff(myNoteOff);
  usbMIDI.setHandleControlChange(handleControlChange);
  usbMIDI.setHandleRealTimeSystem(myRealTimeSystem);

  T[0]=0;
  T[1]=0;
  Serial.println("Arduino ready.");
  led.begin();
  led.clear(1);
  
  for (int i = 0; i < MAX_PATTERNS; i++)
  {
    pattern_list[i] = NULL;
  }
led.drawsquare(14,9,6,222,222,100,1);
led.drawsquare(3,9,6,122,222,100,1);

  //  led.fill_row2(3, 0, NUMOFCOLS, 100, 200, 200, REPLACE);
  led.fast2octo();
  led.show();
  if (!SD.begin(SD_CS)) 
      {
        Serial.println("initialization failed!");
        sd_in=false;
      }
  else
      {
        Serial.println("initialization done.");
        sd_in=true;
      }
      
  
Serial.print("lets start...");
}


void loop()
{
    usbMIDI.read();
    if(sd_in)
    {
if(looper.isPlaying==false)
{
  looper.isPlaying=true;
      looper.play();  
}
    }
  
  if(looper.isPlaying && looper.is_time(millis()) ) 
  {

    myNoteOn(1,looper.B,20);
    if(looper.myFile.available())
      looper.read_line();
      else
      {
        looper.stop();
      }
      
  }
if(OnOff_flag)
{
  set_On_Off();
  OnOff_flag=false;
}
  runtheloop();
  led.fast2octo();
  led.show();
}

void runtheloop()
{
  for (int i = 0; i < MAX_PATTERNS; i++)
  {
    if (pattern_list[i] != NULL) {
      if (pattern_list[i]->is_active) {
        
        pattern_list[i]->render();
        
      } else {
        shiftleft(i);
      }
    }
  }
}

void shiftleft(int index)
{
  for (int i = index; i < MAX_PATTERNS - 1; i++)
  {
    pattern_list[i] = pattern_list[i + 1];
  }
  pattern_list[MAX_PATTERNS - 1] = NULL;
}

void add_pattern(int pattern_id, uint8_t gHue)
{
  
  u8 j = 0;
  for (int i = 0; i < MAX_PATTERNS; i++)
  {
    if (pattern_list[i] == NULL || pattern_list[i]->is_active == 0)
    {
      j = aux(pattern_id/6 );
     switch (pattern_id)
      { 
  
  //offset = 15

// slash
    case 0:
      slash[j] = Slash_Swipe(0, NUMOFROWS+offset, delay1, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &slash[j];
    break;
    
    case 1:
      slash[j] = Slash_Swipe(NUMOFROWS+offset, 0, delay1, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &slash[j];
    break;
     
    case 2:
      slash[j] = Slash_Swipe(0, (NUMOFROWS+offset)/2-1, delay1, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &slash[j];
    break;

    case 3:
      slash[j] = Slash_Swipe((NUMOFROWS+offset)/2, NUMOFROWS+offset, delay1, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &slash[j];
    break;
         
    case 4:
      slash[j] = Slash_Swipe((NUMOFROWS+offset)/2-1, 0, delay1, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &slash[j];
    break;

    case 5:
      slash[j] = Slash_Swipe(NUMOFROWS+offset, (NUMOFROWS+offset)/2, delay1, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &slash[j];
    break;
         


// Backslash


    case 6:
      // Square[j] = square(NUMOFCOLS/2,NUMOFROWS/2,1,20,50,222,222,222,0,style,fade);
      // pattern_list[i] = &Square[j];
      backslash[j] = BackSlash_Swipe(0, NUMOFROWS+offset, delay2, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &backslash[j];
    break;

    case 7:
      backslash[j] = BackSlash_Swipe(NUMOFROWS+offset, 0, delay2, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &backslash[j];
    break;

    case 8:
      backslash[j] = BackSlash_Swipe(0, (NUMOFROWS+offset)/2-1, delay2, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &backslash[j];
    break;

    case 9:
      backslash[j] = BackSlash_Swipe((NUMOFROWS+offset)/2, NUMOFROWS+offset, delay2, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &backslash[j];
    break;

    case 10:
      backslash[j] = BackSlash_Swipe(NUMOFROWS+offset, (NUMOFROWS+offset)/2, delay2, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &backslash[j];
    break;

    case 11:
      backslash[j] = BackSlash_Swipe((NUMOFROWS+offset)/2-1, 0, delay2, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &backslash[j];
    break;

    //ROW SWIPE

    case 12:
      rowswipe[j] = Row_Swipe(0, NUMOFROWS+1, 0, NUMOFCOLS, delay3, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &rowswipe[j];
    break;

    case 13:
      rowswipe[j] = Row_Swipe(NUMOFROWS, 0, 0, NUMOFCOLS, delay3, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &rowswipe[j];
    break;

    case 14:
      rowswipe[j] = Row_Swipe(0, NUMOFROWS/2-1, 0, NUMOFCOLS, delay3, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &rowswipe[j];
    break;

    case 15:
      rowswipe[j] = Row_Swipe(NUMOFROWS/2, NUMOFROWS+1, 0, NUMOFCOLS, delay3, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &rowswipe[j];
    break;

    case 16:
      rowswipe[j] = Row_Swipe(NUMOFROWS, NUMOFROWS/2-1, 0, NUMOFCOLS, delay3, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &rowswipe[j];
    break;

    case 17:
      rowswipe[j] = Row_Swipe(NUMOFROWS/2-1, 0, 0, NUMOFCOLS, delay3, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &rowswipe[j];
            

    break;

// COL SWIPE

    case 18:
      colswipe[j] = Col_Swipe(0, NUMOFCOLS, 0,NUMOFROWS, delay4, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &colswipe[j];
    break;
  
    case 19:
      colswipe[j] = Col_Swipe(NUMOFCOLS, 0, 0,NUMOFROWS, delay4, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &colswipe[j];
    break;

    case 20:
      colswipe[j] = Col_Swipe(0, NUMOFCOLS/2-1, 0,NUMOFROWS, delay4, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &colswipe[j];
    break;

    case 21:
      colswipe[j] = Col_Swipe(NUMOFCOLS/2, NUMOFCOLS, 0,NUMOFROWS, delay4, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &colswipe[j];
    break;

    case 22:
      colswipe[j] = Col_Swipe(NUMOFCOLS, NUMOFCOLS/2, 0,NUMOFROWS, delay4, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &colswipe[j];
    break;

    case 23:
      colswipe[j] = Col_Swipe(NUMOFCOLS/2-1, 0, 0,NUMOFROWS, delay4, pot2+gHue, 255, v, 0, style, fade);
      pattern_list[i] = &colswipe[j];
    break;

    case 24:
      Square[j] = square(10,10,0,0,0,gHue,255,v,REPLACE,3,0);
       pattern_list[i] = &Square[j];
    break;
    
    case 25:
      Square[j] = square(42,45,0,0,0,gHue,255,v,REPLACE,3,0);
       pattern_list[i] = &Square[j];
    break;
    
    case 26:
      Square[j] = square(78,78,0,0,0,gHue,255,v,REPLACE,3,0);
       pattern_list[i] = &Square[j];
    break;
  case 27:
      Square[j] = square(78,0,0,0,0,gHue,255,v,REPLACE,4,0);
       pattern_list[i] = &Square[j];
    break;

         
     
      }
      i = MAX_PATTERNS;
    }
  }
}


u8 aux(u8 id)
{
  switch (id)
  {
  case 0:
    for (u8 i = 0; i < SUB_PAT_SIZE; i++)
    {
      if (slash[i].is_active == 0)
      {
        return i;
      }
    }
    return 0;

    break;

  case 1:
    for (u8 i = 0; i < SUB_PAT_SIZE; i++)
    {
      if (backslash[i].is_active == 0)
      {
        return i;
      }
    }
    return 0;
    break;

  case 2:
    for (u8 i = 0; i < SUB_PAT_SIZE; i++)
    {
      if (rowswipe[i].is_active == 0)
      {
        return i;
      }
    }
    return 0;
    break;

  case 3:
    for (u8 i = 0; i < SUB_PAT_SIZE; i++)
    {
      if (colswipe[i].is_active == 0)
      {
        return i;
      }
    }
    return 0;
    break;

    case 4:
    for (u8 i = 0; i < SUB_PAT_SIZE; i++)
    {
      if (Square[i].is_active == 0)
      {
        return i;
      }
    }
    return 0;
    break;

  default:
    break;
  }
  return 0;
}
  void myNoteOff(byte channel, byte note , byte velocity)
  {
  OnOff[note]=0;  
  }

void myNoteOn(byte channel, byte note, byte velocity)
{
  OnOff[note]=1;
 // v=velocity*2;
int count=0;
for(int i=1;i<=note;i++)
{
  if(i%4==0)
  count++;
}
add_pattern(count,hue_arr[note%4]);
// Serial.println(count);

  //   switch (note)
  //   {
    
  //   case 0x2B:
  //   {
  //     add_pattern(1);
  //     add_pattern(0);
  //     break; 
  //   }

  //   default:
  //   {
  //   pot2 = note * 3;
  //   add_pattern(note % 24);
  //   if(looper.isRecording)
  //   {
  //   looper.write_line(channel,note,velocity);
    
  //   }
  //   break;
  //   }
  // }
}

void handleControlChange(byte channel, byte number, byte value)
{
if (value!=0) // recates only for push
{
  switch (number) { // control channel choose the control
    
        case 0x07:
      v=value*2;
     break; 
    case 0x17:
      pot2=value;
     break;
    case 0x47:
     Pulse_rate++;
  if(Pulse_rate==4)
  Pulse_rate=0;
     break; 
    case 0x37:
       if(style==1)
        style=2;
      else
        {
        style=1; 
        }  
     break;


     case 0x1A:
      Serial.print("start recording");
      looper.start(WRITE);
     break;
    

    case 0x1B:
      looper.stop();
    break;
    
    case 0x1C:
      looper.isPlaying=true;
      looper.play();
     break;
    
  

    case 0x12: 
      len += value-0x40;
    break;
      
    case 0x16: 
      if(style==1)
        style=2;
      else
        {
        style=1; 
        }   
    break;
   
  
  
    case 0x1D:
      looper.delete_record();
    break;


      // case 0x18:
      // add_pattern(12);
      // add_pattern(13);
      // add_pattern(18);
      // add_pattern(19);
      // break;

      //  case 0x19:
      // add_pattern(14);
      // add_pattern(16);
      // add_pattern(20);
      // add_pattern(22);
      // break;
    
    

      

      default:
      break;
      
      }
  }
}

void myRealTimeSystem(byte realtimebyte)
{
  counter_bpm++;
switch(Pulse_rate)
{
  case 0:
  if(counter_bpm%24==0)
  OnOff_flag=true;
  break;

  case 1:
  if(counter_bpm%12==0)
  OnOff_flag=true;
  break;

  case 2:
  if(counter_bpm%6==0)
  OnOff_flag=true;
  break;

  case 3:
    if(counter_bpm%3==0)
  OnOff_flag=true;
  break;
}

  if (counter_bpm == 24)
  {
    
    counter_bpm =0; 
    T[flag_bpm]=millis();
    flag_bpm = flag_bpm^1;
    if(T[0]>T[1])
    Tsum=T[0]-T[1];
    else
    Tsum=T[1]-T[0];


    bpm=60000/Tsum;
//    Serial.println(bpm);
    duration=(60000*4)/(bpm);


 // if(abs(bpm-old_bpm)>3)
  //set_delay();
 
  old_bpm=bpm;
  }

}

 

void set_delay()
{
  delay1=duration/(NUMOFROWS+offset);
  delay2 = delay1;
  delay3=duration/NUMOFROWS;
  delay4=duration/NUMOFCOLS;
}

void set_On_Off()
{
  for(int i=0;i<112;i++)
  {
      if(OnOff[i]==1)
        {
          int count=0;
          for(int j=1;j<=i;j++)
          {
            if(j%4==0)
            count++;
          }
          add_pattern(count,hue_arr[i%4]);
          Serial.println(count);
        }
  }
}

