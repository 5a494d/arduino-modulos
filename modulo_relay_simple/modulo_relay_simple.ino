/**
  @file sensor_temperatura
  @brief Ejemplo de uso del modulo de temperatura y humedad compatible para las placas arduino
  
  Con este modulo podremos leer la  temperatura y humedad actual correspondiente al modulo dht11. Este dispositivo cuenta con tres pines:
  
  VCC  -> (+)
  DATA -> (pin digital) 
  GND  -> (-)

  @author SCESI
  @date 04/2014

*/

// Basic 4 Realy board connection
// Each relay is turned on for 2 seconds and then off.
// You can here them click as there state changes from off to on and on to
// off.
// You will also see the corresponding Red LED on the 4 Relay board
// light up when the relay is on.
 
 //  define names for the 4 Digital pins On the Arduino 7,8,9,10
 //  These data pins link to 4 Relay board pins IN1, IN2, IN3, IN4

#define RELAY1  6                        
#define RELAY2  7                        
#define RELAY3  8                        
#define RELAY4  9
 
void setup()
{    
// Initialise the Arduino data pins for OUTPUT
  pinMode(RELAY1, OUTPUT);       
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
}
 
 void loop()
{
   digitalWrite(RELAY1,LOW);           // Turns ON Relays 1
   delay(2000);                                      // Wait 2 seconds
   digitalWrite(RELAY1,HIGH);          // Turns Relay Off
 
   digitalWrite(RELAY2,LOW);           // Turns ON Relays 2
   delay(2000);                                      // Wait 2 seconds
   digitalWrite(RELAY2,HIGH);          // Turns Relay Off
 
   digitalWrite(RELAY3,LOW);           // Turns ON Relays 3
   delay(2000);                                      // Wait 2 seconds
   digitalWrite(RELAY3,HIGH);          // Turns Relay Off
 
   digitalWrite(RELAY4,LOW);           // Turns ON Relays 4
   delay(2000);                                      // Wait 2 seconds
   digitalWrite(RELAY4,HIGH);          // Turns Relay Off
