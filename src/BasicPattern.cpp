#include "BasicPattern.h"

    BasicPattern :: BasicPattern()
    {
      done =true;
      is_active=false;
      startTime=millis();

    }

bool BasicPattern :: endStory()
    {
      return millis() - startTime > run_time || done;
    }


