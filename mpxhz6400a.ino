#include <analogFuncs.h>
#define ANALOG_PIN 6

int raw_value;
float pressure;

void setup() {
  Serial.begin(57600);
}

void loop() {
  // Get value form AD
  raw_value = analogRead_16bits(ANALOG_PIN);

  // Convert raw value to pressure
  pressure = (float)raw_value / 65535.0f;
  pressure += 0.00842f;
  pressure /= 0.002421f;

  // Write pressure to serial port
  Serial.write((byte*)&pressure, sizeof(float));

  // Wait half a second
  delay(500);
}
