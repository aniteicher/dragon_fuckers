
// #include <Arduino.h>
#include "Mask.h"

#ifndef BASICPATTERN_H
#define BASICPATTERN_H

class BasicPattern 
{

  public:
    BasicPattern();
    unsigned long startTime;
    unsigned long run_time;
    u32 repitions; // TO BE CONTINUED
    bool is_active;
    bool done;

    virtual void render()=0;
    bool endStory();

  

};

#endif