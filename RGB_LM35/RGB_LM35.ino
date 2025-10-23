#define LDR 15

int rgb[] = {25,26,27};



void setup(){

  pinMode(rgb[0],OUTPUT);
  pinMode(rgb[1],OUTPUT);
  pinMode(rgb[2],OUTPUT);

  Serial.begin(115200);

}


float calcularLuz(){
   int lectura = analogRead(LDR);

   float voltaje = (lectura * 3.3) / 4095 ;
   Serial.print("Voltaje: ");
   Serial.println(voltaje);

   float porcentajeVoltaje = voltaje / 3.3 ; 

   return porcentajeVoltaje * 255 ;
}

void cambioColor(int r, int g, int b){

  analogWrite(rgb[0],b);
  analogWrite(rgb[1],r);
  analogWrite(rgb[2],g);
}


void loop(){

  long voltaje = calcularLuz();
  


  cambioColor(voltaje,voltaje,voltaje);
  delay(500);




}
