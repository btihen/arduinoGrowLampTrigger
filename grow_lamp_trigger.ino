int lightSensor  = A0;  // select the input pin for the potentiometer
int lampControl  = 13;  // select the pin for the LED
int triggerValue = 0;   // variable to store the value coming from the sensor
int lightValue   = 0;   // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(lampControl, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  lightValue = analogRead(lightSensor);  
    
  // print sensor value to screen
  Serial.print("light sensor: ");  
  Serial.println(lightValue);  
  
  // turn on lapm trigger (if difference too high)
  if (lightValue < triggerValue) {
    digitalWrite(lampControl, HIGH);  // turn on if value is too high
    Serial.println("LAMP ON");
  } else {
    digitalWrite(lampControl, LOW);   // tiurn off when value is ok
    Serial.println("LAMP OFF");
  }

  delay(1000);     // read sensor every second (100 milliseconds)            
}
