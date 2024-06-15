const int analogPin = A0;  // Analog pin A0 to read the voltage
const int ledPin = 13;     // Digital pin 13 for LED
const float R1 = 10000.0;  // Value of R1 in ohms
const float R2 = 2200.0;   // Value of R2 in ohms
const float referenceVoltage = 5.0; // Reference voltage of Arduino (5V)
const float lowBatteryThreshold = 10.5; // Low battery voltage threshold

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(analogPin);
  float voltage = sensorValue * (referenceVoltage / 1023.0);
  float batteryVoltage = voltage / (R2 / (R1 + R2));
  
  Serial.print("Battery Voltage: ");
  Serial.println(batteryVoltage);
  
  if (batteryVoltage < lowBatteryThreshold) {
    digitalWrite(ledPin, HIGH); // Turn on LED
   
  } else {
    digitalWrite(ledPin, LOW); // Turn off LED
    
  }
  
  delay(1000); // Check every second
}
