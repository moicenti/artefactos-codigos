#define LM35 15

int rgb[] = {25,26,27};



void setup(){
  pinMode(rgb[0],OUTPUT);
  pinMode(rgb[1],OUTPUT);
  pinMode(rgb[2],OUTPUT);
 
  Serial.begin(115200);

}


float calcularTemperatura(){

  float lectura = analogRead(LM35);
  Serial.print("lectura ");
  Serial.println(lectura);
  float voltaje = (lectura * 500.0 );
  float temp = voltaje / 1024.0;

  Serial.print("Temperatura ");
  Serial.println(temp);

  return temp;

}

void cambioColor(int r, int g, int b){

  analogWrite(rgb[0],b);
  analogWrite(rgb[1],g);
  analogWrite(rgb[2],r);
}


void loop(){

  float temp = calcularTemperatura();



  if(temp > 25){

    cambioColor(255,0,0);

}else if(temp > 20){
    cambioColor(255,255,0);

  }else{
    cambioColor(178,255,255);
  }
  delay(500);

}
