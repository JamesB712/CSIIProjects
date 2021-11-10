

const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(2, OUTPUT); //sets LED as output
  pinMode(8, OUTPUT); //sets noise thingy as output 
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  distance = distance / 2.54; // convert to inches.
  distance = distance / 12.0; // convert to feet.
  Serial.print("Distance (ft): ");
  Serial.println(distance);
  delay(100);
  
}
