#include "looper.h"


void Looper :: write_line(byte channel, byte note, byte velocity)
{

//change to hex
myFile.print("N");

// char tmp[30];
// sprintf(tmp, "N%x,%x,%x",channel, note, velocity);
// myFile.println(tmp);

myFile.print(channel);
// Serial.println(channel);

myFile.print(",");
myFile.print(note);
// Serial.println(note);

myFile.print(",");
myFile.print(velocity);
// Serial.println(velocity);
myFile.print(",");
if (isFirst)
{
    T0 = millis();
    myFile.println(0);
    isFirst = false;
}
else
{ 
myFile.println(millis()-T0);
Serial.print("record");
}
}



void Looper :: read_line()
{
  String temp="\n";
  u8 tav=myFile.read();
  A=0;
  B=0;
  C=0;
  goalT=0;

  while(tav!=',')
  {
    temp.append(tav-48);
    tav=myFile.read();
     

  }
  A=temp.toInt();
  temp="\n";

  tav=myFile.read();
     

    while(tav!=',')
  {
    temp.append(tav-48);
    tav=myFile.read();
     

  }
  B=temp.toInt();
  temp="\n";

  tav=myFile.read();
     

    while(tav!=',')
  {
    temp.append(tav-48);
    tav=myFile.read();
       

  }
  C=temp.toInt();
  temp="\n";

    tav=myFile.read();
       


    while(tav!='\n')
  {
    temp.append(tav-48);
    tav=myFile.read();
       

  }
  goalT=temp.toInt();
}


  void Looper::start(bool read = false, String filename = "test.txt")
  {
        if (!isRecording)
        {
            this->filename = filename;
            Serial.print("Initializing SD card...");
            if (!SD.begin(SD_CS)) 
            {
            Serial.println("initialization failed!");
            while (1);
            }
            Serial.println("initialization done.");
            // open the file. note that only one file can be open at a time,
            // so you have to close this one before opening another.
            if (read)
            {
            myFile = SD.open("test.txt", FILE_READ);
            Serial.println("opeing for read");
            }
            else
            {
                myFile = SD.open("test.txt", FILE_WRITE);
                Serial.println("opeing for write");
            }
            isRecording = !read;
            isFirst = true;
        }
  }

  void Looper::stop()
  {
      Serial.println("stoping");
      myFile.close();
      isRecording = false;
      isPlaying = false;
      isFirst = true;
  }

  void Looper::play()
  {
      if (isFirst && isPlaying)
      {
          start(true);
          startT = millis(); //??
          isFirst = false;

      }

      if (myFile.available() && isPlaying)
      {
        Serial.println("reading line.");
        read_line();
        
        // flag = false;
      }
      else if(!myFile.available())
      {
        stop();
      }

      if (!myFile.available()) //TODO : add options for loop
      {
          isPlaying = false;
          isFirst = true;
      }
   
  }
   bool Looper::is_time(u32 current_time = millis())
    {
     if(current_time-startT>=goalT)
     return true;
     else
     return false;
        
    }

void Looper:: delete_record()
{
  bool tmp = false;
  char file[15] = "TEST.txt";
  if (!isPlaying && !isRecording)
  {
  tmp = SD.remove(file);
  }
  if (tmp)
  Serial.println("deletedet");
  else
   Serial.println("failed to delete");
}


  

