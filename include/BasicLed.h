#include <Arduino.h>
#include "OctoWS2811.h"
#include "FastLED.h"
#include "Defines.h"
// 
#ifndef BASICLED_H
#define BASICLED_H

static DMAMEM int displayMemory[LEDSPERSTRIP*6];
static int drawingMemory[LEDSPERSTRIP*6];
static const int config = WS2811_GRB | WS2811_800kHz;


class BasicLed
{
public:

CRGB f_led[LEDSPERSTRIP];
// octo veriables
OctoWS2811 octo = OctoWS2811(LEDSPERSTRIP,displayMemory,drawingMemory,config);

void begin();
void set_color (u16 index ,u32 color);
void fast2octo(bool update=false);
void show();
static u32 rgb2word(u8 r, u8 g, u8 b);
void clear(bool update);
virtual void slash(u32 diag, u8 r,u8 g,u8 b,bool action)=0;
virtual void LED_update()=0;
virtual void slash2(u32 diag, u8 h,u8 s,u8 v,bool action)=0;
};

#endif