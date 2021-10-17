// // python-build-start
// // action, verify
// // board, arduino:avr:uno
// // port, /dev/ttyACM0
// // ide, 1.6.3
// // python-build-end


// // testSDnRF24.ino
// // Combination of SimpleTxAckPayload - the master or the transmitter
// //   abd ListFiles.ino

// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>

// #include <SD.h>


// #define CE_PIN  6 // for nRF24
// #define CSN_PIN 7 // for nRF24

// #define csPin 10 // for SDCard

// const byte slaveAddress[5] = {'R','x','A','A','A'};

// RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

// char dataToSend[10] = "Message 0";
// char txNum = '0';
// int ackData[2] = {-1, -1}; // to hold the two values coming from the slave
// bool newData = false;


// //===============

// void setup() {

//     Serial.begin(9600);
//     Serial.println(F("Source File /mnt/sdb1/SGT-Prog/Arduino/SDandNRF/testSDnRF24.ino"));
//     Serial.println("testSDnRF24 Starting");

// }

// //=============

// void loop() {

//     setupNRF();
//     send();
//     showData();
//     delay(1000);

//     setupSD();
//     listFiles();
//     delay(1000);
// }

// //================
// //   These are the nRF24 functions
// //================

// void setupNRF() {
//         radio.begin();
//     radio.setDataRate( RF24_250KBPS );

//     radio.enableAckPayload();

//     radio.setRetries(3,5); // delay, count
// }

// void send() {

//     bool rslt;
//     radio.openWritingPipe(slaveAddress);
//     rslt = radio.write( &dataToSend, sizeof(dataToSend) );
//         // Always use sizeof() as it gives the size as the number of bytes.
//         // For example if dataToSend was an int sizeof() would correctly return 2

//     Serial.print("Data Sent ");
//     Serial.print(dataToSend);
//     if (rslt) {
//         if ( radio.isAckPayloadAvailable() ) {
//             radio.read(&ackData, sizeof(ackData));
//             newData = true;
//         }
//         else {
//             Serial.println("  Acknowledge but no data ");
//         }
//         updateMessage();
//     }
//     else {
//         Serial.println("  Tx failed");
//     }
//  }


// //=================

// void showData() {
//     if (newData == true) {
//         Serial.print("  Acknowledge data ");
//         Serial.print(ackData[0]);
//         Serial.print(", ");
//         Serial.println(ackData[1]);
//         Serial.println();
//         newData = false;
//     }
// }

// //================

// void updateMessage() {
//         // so you can see that new data is being sent
//     txNum += 1;
//     if (txNum > '9') {
//         txNum = '0';
//     }
//     dataToSend[8] = txNum;
// }

// //============
// //  And these are the SD Card functions
// //============

// void setupSD() {
//     if (!SD.begin(csPin)) {
//     Serial.println("initialization failed!");
//     }
//     else {
//         Serial.println("initialization done.");
//     }
// }

// //===================

// void listFiles() {

//     File root = SD.open("/");
//     printDirectory(root, 0);
//     Serial.println("done! ----------");
//     Serial.println();
// }

// //=================

// void printDirectory(File dir, int numTabs) {
//   while (true) {

//     File entry =  dir.openNextFile();
//     if (! entry) {
//       // no more files
//       break;
//     }
//     for (uint8_t i = 0; i < numTabs; i++) {
//       Serial.print('\t');
//     }
//     Serial.print(entry.name());
//     if (entry.isDirectory()) {
//       Serial.println("/");
//       printDirectory(entry, numTabs + 1);
//     } else {
//       // files have sizes, directories do not
//       Serial.print("\t\t");
//       Serial.println(entry.size(), DEC);
//     }
//     entry.close();
//   }
// }