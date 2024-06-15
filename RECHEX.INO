#include <Arduino.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>

// Define the GPIO pin where the IR receiver is connected
const uint16_t kRecvPin = 14; 

// Create an instance of the IRrecv class
IRrecv irrecv(kRecvPin);

// Create a buffer to store the raw data
decode_results results;

void setup() {
  Serial.begin(115200); // Start the serial communication
  irrecv.enableIRIn();  // Start the IR receiver
  Serial.println("IR Receiver initialized");
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print the raw data in hexadecimal format
    Serial.println(resultToHexidecimal(&results));
    
    // Optionally, you can also print the raw timing data
    serialPrintUint64(results.value, HEX);
    
    // Resume receiving the next value
    irrecv.resume();
  }
}
