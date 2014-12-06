int lampTriggerPin   = 13;    // use pin 13 as the control trigger
int lampIndicator    = 12;
int lightSensorPin   = A0;    // read light sensor on pin A0
int lightSensorValue = 0;     // define the input value as an integer
int waitTime         = 1000;   // wait 500ms and sample again

float nightValue        = 10.0;  // calibration -- more than darkroom with just the growlamp
float cloudyValue       = 80.0;  // calibration -- more than darkroom with just room lights on
float percentBrightness = 0.0;


void setup() {
  pinMode(lampTriggerPin, OUTPUT);
  pinMode(lampIndicator, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightSensorValue = analogRead(lightSensorPin);  // read light sensor 0-1023
  percentBrightness = lightSensorValue / 1023.0 * 100.0;  // calculate percent light
  Serial.print("Light Sensor percent of direct sunlight: ");
  Serial.print( percentBrightness );
  Serial.print(" % -- ");
  if ( percentBrightness < nightValue ) {
    digitalWrite(lampTriggerPin, HIGH);    
    digitalWrite(lampIndicator, LOW);       // turn off grow lamp if its night dark
    Serial.println("LAMP OFF - it night");
  } else if ( percentBrightness > cloudyValue ) {
    digitalWrite(lampTriggerPin, HIGH); 
    digitalWrite(lampIndicator, LOW);       // turn off grow lamp if room is bright
    Serial.println("LAMP OFF -- bright sunny day");    
  } else {
    digitalWrite(lampTriggerPin, LOW);
    digitalWrite(lampIndicator, HIGH);      // turn on grow lamp if room has diffuse daylight
    Serial.println("LAMP ON -- diffuse daylight");    
  }
  delay(waitTime);
}
