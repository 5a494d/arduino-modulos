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


// Sensor de Humedad   
      
// Conectamos el sensor de la siguiente forma:      
// GND    -> GND      
// VCC    -> 5V      
// DAT    -> A0    
// Por ejemplo conectamos a las entrada Analógica 0      
// http://arubia45.blogspot.com.es/     


// Descripción de valores del Sensor

// 0  -300     Seco 
// 300-700     Húmedo
// 700-950     En Agua

int Valor;
int Val;

void setup(){
  Serial.begin(9600);
  //Serial.println("http://arubia45.blogspot.com.es");
}

   void loop(){
      Serial.print("Sensor de Humedad valor:");
      Valor = map(analogRead(0),0,1024,1024,0);
      Val = map(analogRead(0),0,1024,1024,0);
      Serial.print("Valor uno: ");
      Serial.println(Valor);
      Serial.print("Valor dos: ");
      Serial.println(Val);
      
      if (Valor <= 300)
        Serial.println(" Seco, necesitas regar");
      if ((Valor > 300) and (Valor <= 700))
        Serial.println(" Humedo, no regar");
      if (Valor > 700)
        Serial.println(" Encharcado");
      delay(1000);
   }






