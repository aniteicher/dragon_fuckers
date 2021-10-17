#include "BasicLed.h"



// puts a uint32 color into FastLED object
// @param: 
//	LED - The led object array
//	index - the index of the led
//	colour - a 4 byte word with the colour in RGB
void BasicLed :: set_color (u16 index ,u32 color)
{
	u8 r = (u8)(color >>16);
	u8 g = (u8)(color >>8);
	u8 b =(u8)(color >>0);
	octo.setPixel(index,r,g,b);
    
}


// rgb2word
// convert R G B channels (uint8_t) to a RGB WORD (uint32_t)
// @parm:
// r,g,b - uint8 red green blue channel value
// retval : uint32 containing RGB data in the first 24 bit blue as 0x00RRGGBB
u32 BasicLed :: rgb2word(u8 r, u8 g, u8 b)
{
	return ( (r<<16 ) | ( g << 8 ) | b );
}

// clear
// set all leds to zero for both the fastled object and the octoWS object
void BasicLed :: clear(bool update=0)
{
    for (u32 i=0; i<LEDSPERSTRIP; i++)
    {
        f_led[i]=CRGB(0,0,0);
    }
    fast2octo();
    if (update)
    {
    octo.show();
    }
}

// show
// displays the leds
void BasicLed :: show()
{
    octo.show();
    #ifdef DEBUG  //define DEBUG in defines.h for serial debugging
    Serial.println("led show");
    #endif

}

void BasicLed:: begin()
{
    octo.begin();
    Serial.println("BasicLed::Begin()");
    #ifdef DEBUG  //define DEBUG in defines.h for serial debugging
    Serial.println("led begin");
    #endif

}

void BasicLed :: fast2octo(bool update =false)
{
      for(int i = 0; i < LEDSPERSTRIP; i++) {
        CRGB fastLedRGB =  f_led[i];
        int octowsColor = octo.color(fastLedRGB.r, fastLedRGB.g, fastLedRGB.b);
        octo.setPixel( i, octowsColor);
      }
      if(update)
      octo.show();
}