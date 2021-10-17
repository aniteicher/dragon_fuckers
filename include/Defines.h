#include <string>


#ifndef DEFINES_H
#define DEFINES_H

// #define DEBUG

// octoWS defines
#define BRIGHTNESS         20
#define FRAMES_PER_SECOND  30

#define MAX_PATTERNS        100
#define SUB_PAT_SIZE        20


// RGB MASKING DEFINES
#define RMASK 0x0000FF
#define BMASK 0x00FF00
#define GMASK 0xFF0000

// FUNCTION AUXILARIES DEFINES
// fill and swipe
#define ADD     0
#define REPLACE 1

// path

// LED SIZE DEFINES

// mask


// #define NUMOFROWS 28
// #define NUMOFCOLS 20 
// #define LEDSPERSTRIP (uint32_t)295
// #define NUMOFLEDS 295



//geo_sticks

// #define NUMOFROWS 30
// #define NUMOFCOLS 14
// #define LEDSPERSTRIP (uint32_t)420
// #define NUMOFLEDS 420


//led sign

#define NUMOFROWS 6
#define NUMOFCOLS 104
#define LEDSPERSTRIP (uint32_t)624
#define NUMOFLEDS 624
// // drums
// #define NUMOFROWS 100
// #define NUMOFCOLS 7
// #define LEDSPERSTRIP (uint32_t)700
// #define NUMOFLEDS 700



// //mandala 
// #define NUMOFROWS 39
// #define NUMOFCOLS 39
// #define LEDSPERSTRIP (uint32_t)148
// #define NUMOFLEDS 700



#define NUMOFPIX NUMOFROWS*NUMOFCOLS

//veriables
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define i8 int8_t
#define i16 int16_t
#define i32 int32_t


// geo stick shapes
#define hex 0 
#define tritop 1 
#define tribott 2
#define tribig 3
#define pararight 4
#define paraleft 5 

  // Directions for stepping routines
  // R - RIGHT
  // L - LEFT
  // U - UP
  // D - DOWN
// #define      ALL    (std::string)"RLUD" 
// #define      RUD    (std::string)"RUD"
// #define      RLU    (std::string)"RLU"
// #define      RLD    (std::string)"RLD"
// #define      LUD    (std::string)"LUD"
// #define      RL     (std::string)"RL"
// #define      RU     (std::string)"RU"
// #define      RD     (std::string)"RD"
// #define      LU     (std::string)"LU"
// #define      LD     (std::string)"LD"
// #define      UD     (std::string)"UD"
// #define      R      (std::string)"R"
// #define      L      (std::string)"L"
// #define      U      (std::string)"U"
// #define      D      (std::string)"D"


#endif
