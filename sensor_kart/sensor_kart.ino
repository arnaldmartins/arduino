
int pinoSensor = 2;
int valor = 0;

void setup(){
  pinMode(pinoSensor, INPUT);
  Serial.begin(9600);
}
 
void loop(){
  valor = digitalRead(pinoSensor);
  if (valor == 0){
    Serial.println("1");
    delay(500);
  }else{
    //Serial.println(valor);
    //delay(500);
  }
}
