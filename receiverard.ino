#include <IRremote.h>

// Define the pin where your IR receiver is connected
const int RECV_PIN = 3;

// Create an instance of the IRrecv class
IRrecv irrecv(RECV_PIN);

// Create a structure to store the decoded IR data
decode_results results;

void setup() {
  Serial.begin(9600);
  // Enable the IR receiver
  irrecv.enableIRIn();
}

void loop() {
  // Check if the IR receiver has captured any data
  if (irrecv.decode(&results)) {
    // Print the raw timing data with commas
    Serial.print("Received IR timing data: ");
    for (int i = 1; i < results.rawlen; i += 2) {
      // Print the duration of the mark (positive pulse)
      Serial.print(results.rawbuf[i] * USECPERTICK, DEC);
      if (i < results.rawlen - 2) {
        // Add a comma after each value except the last one
        Serial.print(", ");
      }
    }
    Serial.println();
    // Resume receiving the next value
    irrecv.resume();
  }
}
