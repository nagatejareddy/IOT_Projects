const int rainSensorPin = A0;
const int greenLED = 2;
const int redLED = 3;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int rainValue = analogRead(rainSensorPin);
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainValue);

  if (rainValue < 500) {  // You can adjust this threshold as needed
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    Serial.println("Rain Detected!");
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    Serial.println("No Rain");
  }

  delay(1000);
}
