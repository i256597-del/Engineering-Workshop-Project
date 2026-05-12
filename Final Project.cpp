#include <SoftwareSerial.h>

// --- CONFIGURATION ---
const int bulbPin = 3; 
// RX is 10 (Connect to HC-05 TX), TX is 11 (Connect to HC-05 RX)
SoftwareSerial bluetooth(10, 11); 

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  pinMode(bulbPin, OUTPUT);
  digitalWrite(bulbPin, HIGH); // Default OFF
  
  Serial.println("System Started. Send commands via Bluetooth App.");
}

void loop() {
  if (bluetooth.available() > 0) {
    String command = bluetooth.readStringUntil('\n');
    command.trim();
    command.toLowerCase(); // This makes the text lowercase automatically

    Serial.print("Bluetooth received: [");
    Serial.print(command);
    Serial.println("]");

    // FIXED: Removed the extra ')' and simplified logic
    if (command == "let there be light" || command == "bulb on") {
      digitalWrite(bulbPin, LOW); // Relay ON
      bluetooth.println("Bulb is now ON");
    } 
    // FIXED: Simplified the "Bijali" command
    else if (command == "bijali ka bil tera baap bharega" || command == "bijali ka bil tera baap bhadega" || command == "bulb off") {
      digitalWrite(bulbPin, HIGH); // Relay OFF
      bluetooth.println("Bulb is now OFF");
    }
  }
}