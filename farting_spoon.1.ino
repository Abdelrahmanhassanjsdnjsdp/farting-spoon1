#include <Servo.h>

const int trigPin = 9;    
const int echoPin = 10;   
const int servoPin = A0;  

Servo myServo;  

void setup() {
    Serial.begin(9600);
    
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    
    myServo.attach(servoPin);  
    myServo.write(0);  
}

void loop() {
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    
    float distance = duration * 0.0343 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance > 0 && distance <= 10) {
        myServo.write(90);
    } else {
        myServo.write(0); 
    }

    delay(500); 
}
