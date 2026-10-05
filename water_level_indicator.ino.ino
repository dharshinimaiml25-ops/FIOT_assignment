const int trigPin = 7;
const int echoPin = 8;

const int greenLED = 6;
const int blueLED = 5;
const int redLED = 4;

long duration;
float distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn LEDs OFF
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, LOW);

  // Water level
  if (distance > 20)
  {
    digitalWrite(greenLED, HIGH);
  }
  else if (distance > 10)
  {
    digitalWrite(blueLED, HIGH);
  }
  else
  {
    digitalWrite(redLED, HIGH);
  }

  delay(500);
}