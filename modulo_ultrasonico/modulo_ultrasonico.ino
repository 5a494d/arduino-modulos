/**
  @file modulo_ultrasonico
  @brief Ejemplo de uso del modulo ultrasonico
  
  Con este modulo podremos leer la  disntacia de objetos en centimetros hasta un rango de 4m
  
  VCC  -> (+)
  DATA -> (pin digital) 
  GND  -> (-)

  @author SCESI
  @date 04/2014

*/

/*
 HC-SR04 Ping distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 9 
 Trig to Arduino pin 11 
 */


// pin del eco
#define echoPin 3 // Echo Pin

//pin del disparador
#define trigPin 2 // Trigger Pin


long duracion, distancia_cm, distancia_inch; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT); // pin como salida
 pinMode(echoPin, INPUT); // pin como entrada
 digitalWrite(trigPin, LOW);  // apagado de forma logica
}

void loop() {

 delayMicroseconds(2); 
 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 
 
 // devuelve la logitud del pulso del pin en us
 duration = pulseIn(echoPin, HIGH);
 
 microsecondsToInches()
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 Serial.print("distancia   ");
 Serial.println(distance);
 delay(50);
}

