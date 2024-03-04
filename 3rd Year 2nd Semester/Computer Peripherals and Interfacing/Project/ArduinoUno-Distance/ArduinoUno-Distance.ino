const int trigPin = 9;  // Trigger pin of the ultrasonic sensor
const int echoPin = 10; // Echo pin of the ultrasonic sensor

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  float distance_cm;

  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the pulse duration on the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters with decimal points
  distance_cm = duration * 0.0343 / 2.0;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm, 2); // Print with two decimal places
  Serial.println(" cm");

  delay(1000); // Delay for a moment before taking the next measurement
}
