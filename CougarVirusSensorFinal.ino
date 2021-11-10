
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
   if(distance < 1) 
      {
      digitalWrite(2, HIGH);
      tone(8, 15
      );
      delay(100);
      digitalWrite(2, LOW);
      noTone(8);
      delay(100);
      }
      else if(distance < 2)
      {
      digitalWrite(2, HIGH); 
      tone(8, 10);
      delay(250);
      digitalWrite(2, LOW);
      noTone(8);
      delay(250);
      } 
      else if (distance < 3) 
      {
      digitalWrite(2, HIGH);
      tone(8, 5);
      delay(500);
      digitalWrite(2, LOW);
      noTone(8);
      delay(500);
        }
      else 
      {
      digitalWrite(2, LOW);
      noTone(8);
      }
     
}
