const int sensorPin = A0;  // Pin connected to the voltage sensor
float voltage = 0.0;       // Variable to store the voltage value
float R1 = 10000.0;        // Resistor R1 value (in ohms) in voltage divider
float R2 = 10000.0;        // Resistor R2 value (in ohms) in voltage divider

void setup() {
  Serial.begin(9600);      // Start the serial communication at 9600 baud rate
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // Read the analog value from sensor
  float sensorVoltage = sensorValue * (5.0 / 1023.0); // Convert ADC value to voltage

  // If using a voltage divider, calculate the actual voltage
  voltage = sensorVoltage * ((R1 + R2) / R2);

  // Display the voltage on the serial monitor
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  delay(1000); // Wait for a second before the next reading
}
