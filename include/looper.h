#include "Defines.h"
#include "Arduino.h"
#include "SD.h"
#include <string.h>

#ifndef LOOPER_H
#define LOOPER_H

#define WRITE false
#define READ  true
#define SD_CS 10



class Looper
{
    public:
    File myFile;
    uint8_t &A,&B,&C;
    String filename;
    bool isRecording = false;
    bool isPlaying = false;
    u32 goalT, startT, tmpT;
    u32 T0;
    bool isFirst = true;
    Looper() {};
    Looper(u8 &AA, u8 &BB, u8 &CC) : A(AA), B(BB), C(CC)
    {
        tmpT = 0;
    }
    void write_line(byte channel, byte note, byte velocity);
    void read_line();
    void play();
    void stop();
    void start(bool read = false, String filename = "test.txt");
    bool is_time(u32 current_time);
    void delete_record();
};


//   1A   1B   1C  1D




#endif