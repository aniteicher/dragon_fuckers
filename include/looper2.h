// #include "Defines.h"
// #include "Arduino.h"
// #include "SD.h"
// #include <string.h>

// #ifndef LOOPER_H
// #define LOOPER_H

// #define WRITE false
// #define READ  true




// class Looper
// {
//     public:
//     File write_file[2];
//     File read_file[2];
//     uint8_t &A,&B,&C;
//     String filename;
//     u8 r_file=0;
//     bool overlay_flag=false;
//     u8 w_file=0;
//     bool isRecording = false;
//     bool isPlaying = false;
//     u32 goalT, startT, tmpT;
//     u32 T0;
//     bool isFirst = true;
//     Looper() {};
//     Looper(u8 &AA, u8 &BB, u8 &CC) : A(AA), B(BB), C(CC)
//     {
//         tmpT = 0;
//     }
//     void write_line(byte channel, byte note, byte velocity);
//     void read_line();
//     void play();
//     void stop();
//     void start(bool read = false, String filename = "test.txt");
//     bool is_time(u32 current_time);
//     void overlay_record(byte channel, byte note, byte velocity);
//     void delete_record();
// };


// //   1A   1B   1C  1D




// #endif