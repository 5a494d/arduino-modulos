/**
  @file sensor_humedad_tierra.ino
  @brief Ejemplo de uso del sensor de humedad de tierra con la version YL-38
  
  Con este modulo podremos leer la temperatura actual de la tierra al en unn rango de 2m aproximadamente.Los valores de lectura son de: 
  
  1. 0  -300     Seco 
  2. 300-700     Húmedo
  3. 700-950     En Agua
  
  La distribucion de pines para el YL-38 es:
  
  VCC  -> (+)
  GND  -> (-)
  D0   -> (pin digital)
  A0   -> (pin digital)

  @author SCESI
  @date 04/2014

*/


/**
  @brief Valores de configuracion para la lectura de datos

  @param salida_a  pin analogico que lee la humedad relativa
  @param salida_d  pin analogico que se establece para realizar la diferencia

 */

#define DATO_A 2
#define DATO_D 3

int salida_a;
int salida_d;

void setup(){
  Serial.begin(9600);
  Serial.println(" - iniciando sensor de humedad");
}

void loop(){
  Serial.print("Sensor de Humedad valor:");
  salida_a = map(analogRead(DATO_A),0,1024,1024,0);
  salida_d = map(analogRead(DATO_D ),0,1024,1024,0);
  Serial.print("Valor  a:");
  Serial.print(salida_a);
  Serial.print(" d:");
  Serial.println(salida_d);
  
  Serial.print(" - estado: ");    
  if (salida_a <= 300)
  {
    Serial.println("seco, necesitas regar");
  }
  
  if ((salida_a > 300) and (salida_a <= 700))
  {  
    Serial.println("humedo, no regar");
  }
  
  if (salida_a > 700)
  {  
    Serial.println(" muy remojado, te pasaste");    
  }
  
  delay(1000);
}
