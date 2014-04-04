/**
  @file modulo_ultrasonico
  @brief Ejemplo de uso del modulo ultrasonico HC-SR04
  
  Con este modulo podremos leer la  distancia un objeto que se encuentre en un rango de hasta 4m. La configuracion de pines:
  
  VCC  -> (+)
  Trig -> (pin digital)
  Echo -> (pin digital)
  GND  -> (-)

  @author SCESI
  @date 04/2014

*/


/**
  @brief Variables de configuracion del dispositov y variables de salida

  @param echoPin  pin digital que resolvera el eco
  @param trigPin  pin digital que realizara el disparo del pulso sonico
  @param duracion respuesta del echo
  @param distancia_cm distancia calculada segun la duracion del eco en centimetros
  @param distancia_inch distancia calculada segun la duracion del eco en plugadas

  */

#define echoPin 3
#define trigPin 2 

long duracion;
long distancia_cm;
long distancia_inch; 

void setup() 
{
  Serial.begin (9600);
  // pin para trabajar como salida
  pinMode(trigPin, OUTPUT); 
  // pin para trabajar como entrada
  pinMode(echoPin, INPUT); 
}

void loop() {
  // pin con apagado logico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
 
  // devuelve la logitud del eco en us
  duracion = pulseIn(echoPin, HIGH);
  distancia_cm = microsegundosTransformarCentimetros(duracion);
  distancia_inch = microsegundosTransformarPulgadas(duracion);
 
  Serial.print("cm: ");
  Serial.print(distancia_cm);
  Serial.print(" inch: ");
  Serial.print(distancia_inch);
  Serial.print(" eco: ");
  Serial.println(duracion);
 
  // tiempo minimo de espera para que el eco se disipe 50ms
  // puede ser modificado
  delay(50);
}

/**
  @brief transformar microsegundos a pulgadas
  
  @param microsegundos valor del echo transcurrido
  @returns  valor convertido en pulgadas
*/
long microsegundosTransformarPulgadas(long microsegundos) 
{ 
  return microsegundos/148; 
}

/**
  @brief transformar microsegundos a centimetros
  
  @param microsegundos valor del echo transcurrido
  @returns  valor convertido en centimetros
*/
long microsegundosTransformarCentimetros(long microsegundos) 
{ 
  return microsegundos/58.2; 
}

