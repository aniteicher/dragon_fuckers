// #include "looper.h"


// void Looper :: write_line(byte channel, byte note, byte velocity)
// {

// //change to hex
//     write_file[w_file].print("N");
// // char tmp[30];
// // sprintf(tmp, "N%x,%x,%x",channel, note, velocity);
// // myFile.println(tmp);

//     write_file[w_file].print(channel);
// Serial.println(channel);

//     write_file[w_file].print(",");
//     write_file[w_file].print(note);
// Serial.println(note);

//     write_file[w_file].print(",");
//     write_file[w_file].print(velocity);
// Serial.println(velocity);
//     write_file[w_file].print(",");
// if (isFirst)
// {
//     T0 = millis();
//         write_file[w_file].println(0);
//     isFirst = false;
// }
// else
// { 
//     write_file[w_file].println(millis()-T0);
// Serial.print("record");
// }
// }



// void Looper :: read_line()
// {
//   String temp="\n";
//   u8 tav=read_file[r_file].read();
//   A=0;
//   B=0;
//   C=0;
//   goalT=0;

//   while(tav!=',')
//   {
//     temp.append(tav-48);
//     tav=read_file[r_file].read();
     

//   }
//   A=temp.toInt();
//   temp="\n";

//   tav=read_file[r_file].read();
     

//     while(tav!=',')
//   {
//     temp.append(tav-48);
//     tav=read_file[r_file].read();
     

//   }
//   B=temp.toInt();
//   temp="\n";

//   tav=read_file[r_file].read();
     

//     while(tav!=',')
//   {
//     temp.append(tav-48);
//     tav=read_file[r_file].read();
       

//   }
//   C=temp.toInt();
//   temp="\n";

//     tav=read_file[r_file].read();
       


//     while(tav!='\n')
//   {
//     temp.append(tav-48);
//     tav=read_file[r_file].read();
       

//   }
//   goalT=temp.toInt();
// }


//   void Looper::start(bool read = false, String filename = "test.txt")
//   {
//         if (!isRecording)
//         {
//             this->filename = filename;
//             Serial.print("Initializing SD card...");
//             if (!SD.begin(10)) 
//             {
//             Serial.println("initialization failed!");
//             while (1);
//             }
//             Serial.println("initialization done.");
//             // open the file. note that only one file can be open at a time,
//             // so you have to close this one before opening another.
//             if (read)
//             {
//             read_file[r_file] = SD.open("test.txt", FILE_READ);
//             Serial.println("opeing for read");
//             }
//             else
//             {
//                     write_file[w_file] = SD.open("test.txt", FILE_WRITE);
//             }
//             isRecording = !read;
//             isFirst = true;
//         }
//   }

//   void Looper::stop()
//   {
//       Serial.println("stoping");
//           write_file[0].close();
//           write_file[1].close();
//           read_file[0].close();
//           read_file[1].close();
//           if(overlay_flag)
//           (
//               if(w_file==1)

//           )

//       isRecording = false;
//       isPlaying = false;
//       isFirst = true;
//   }

//   void Looper::play()
//   {
//       if (isFirst && isPlaying)
//       {
//           start(true);
//           startT = millis(); //??
//           isFirst = false;

//       }

//       if (read_file[r_file].available() && isPlaying)
//       {
//         Serial.println("reading line.");
//         read_line();
        
//         // flag = false;
//       }
//       else if(!read_file[r_file].available())
//       {
//         stop();
//       }

//       if (!read_file[r_file].available()) //TODO : add options for loop
//       {
//           isPlaying = false;
//           isFirst = true;
//       }
   
//   }
//    bool Looper::is_time(u32 current_time = millis())
//     {
//      if(current_time-startT>=goalT)
//      return true;
//      else
//      return false;
        
//     }

// void Looper:: delete_record(u8 index)
// {
//   bool tmp = false;
//   char file[15] = "TEST.txt";
//   char file2[15] = "TEST1.txt";
//   if (!isPlaying && !isRecording)
//   {
//   tmp = SD.remove(file);
//   }
//   if (tmp)
//   Serial.println("deletedet");
//   else
//    Serial.println("failed to delete");
// }
//  //return A,B,C,T1





// //054-4530118 israel