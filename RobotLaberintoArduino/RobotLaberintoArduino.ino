int izqDist = 0;
int derDist = 0;
int frontDist = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(13, HIGH);
  delayMicroseconds(10);
  digitalWrite(13, LOW);
  pinMode(12, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(12, HIGH);
}

long readUltrasonicDistance2(int triggerPin, int echoPin)
{
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(11, HIGH);
  delayMicroseconds(10);
  digitalWrite(11, LOW);
  pinMode(10, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(10, HIGH);
}

long readUltrasonicDistance3(int triggerPin, int echoPin)
{
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);
  pinMode(8, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(8, HIGH);
}

void setup()
{
  Serial.begin(9600);
  
  digitalWrite(7, HIGH); // Cables azules
  digitalWrite(6, HIGH);
  
}

void loop()
{
  
  izqDist = 0.01723 * readUltrasonicDistance(13, 12);
  Serial.print("DistIzq = ");
  Serial.print(izqDist);
  Serial.print("cm | ");
  
  derDist = 0.01723 * readUltrasonicDistance2(11, 10);
  Serial.print("DistDer = ");
  Serial.print(derDist);
  Serial.print("cm | ");
  delay(100); // Wait for 100 millisecond(s)
  
  frontDist = 0.01723 * readUltrasonicDistance3(9, 8);
  Serial.print("DistFront = ");
  Serial.print(frontDist);
  Serial.println("cm");
  delay(100); // Wait for 100 millisecond(s)
  
  // Comprobación de distancias  
  
  digitalWrite(4, HIGH); // Arrancamos el auto
  digitalWrite(5, LOW);

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  
  if (frontDist < 5) {
  
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    
    if (izqDist > 5) {
      delay(2000);
      digitalWrite(4, LOW);
        digitalWrite(5, LOW);

        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        delay(1000);
      
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);

        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
    }
    
    else if (derDist > 5) {
    
      delay(2000);
      digitalWrite(4, HIGH);
        digitalWrite(5, LOW);

        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        delay(1000);
      
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);

        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
      
    }
    
    else if (derDist > 5 && izqDist > 5) {
    
      delay(2000);
      digitalWrite(4, HIGH);
        digitalWrite(5, LOW);

        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        delay(1000);
      
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);

        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
      
    }
  
  }
  
}
