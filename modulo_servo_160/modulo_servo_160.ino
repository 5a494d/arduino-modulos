/**
  @file modulo_servo_160
  @brief Ejemplo de uso de un motor servo de 160 grados
  
  Se utiliza una libreria provista por el IDE de arduino llamada Servo. Esta libreria puede ser manejada en forma de una clase, con lo que se puede instanciar varios servomotores a la vez. La distribucion de pines varia en cada version, para nuestro ejemplo estamos utilizando una version pequenia con un angulo de recorrido de 160 grados:
  
  GND     -> (-)
  VCC     -> (+)
  Control -> (pin digital)

  @author SCESI
  @date 04/2014

*/

/**
  @brief Variables de configuracion del dispositivo

  @param PIN_SERVO pin digital conectado al arduino
  @param servo_control  instancia de clase para el control del servo
  @param posicion  entero que establece la posicion en grados respecto a la rotacion del motor servo
  */

#include <Servo.h> 

#define PIN_SERVO 2

Servo servo_control;   
int   posicion = 0;    
 
void setup() 
{ 
  servo_control.attach(PIN_SERVO);
} 
 
 
void loop() 
{ 
  
  Serial.println(" - inicializar rotacion a la izquierda");
  for(posicion = 0; posicion < 160; posicion += 1)  
  {                                  
    servo_control.write(posicion);   
    delay(1);                       
  }
 
  Serial.println(" - inicializar rotacion a la derecha"); 
  for(posicion = 160; posicion>=1; posicion-=1)  
  {                                
    servo_control.write(pos);     
    delay(20);                    
  } 
}
