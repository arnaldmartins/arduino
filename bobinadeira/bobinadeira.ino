
const int pinoSensor = 2;
int valor = 0;
int cont = 0;
int maxVoltas = 0;
bool motorLigado;

void setup(){
  pinMode(pinoSensor, INPUT);
  Serial.begin(9600);
}
 
void loop(){
  if(maxVoltas == 0 && Serial.available() > 0){
    maxVoltas = Serial.parseInt();
    // responde com o dado recebido:
    Serial.print("Total de Voltas: ");
    Serial.println(maxVoltas);
  }
  if(maxVoltas > 0 && cont < maxVoltas){
    // ligar motor...
    if(motorLigado == false) {
      Serial.println("Ligando motor...");
      motorLigado = true;
    }
    valor = digitalRead(pinoSensor);
    if (valor == 0){
      cont++;
      Serial.print("+");
      Serial.println(cont);
      //delay(100);
    }
  }else if(maxVoltas > 0 && cont == maxVoltas){
    // desligar motor...
    if(motorLigado){
      Serial.println("Desligando motor...");
      motorLigado = false;
    }
    valor = digitalRead(pinoSensor);
    if (valor == 0){
      Serial.println("FIM!");
      delay(500);
    }    
  }
}
