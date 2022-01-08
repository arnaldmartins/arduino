/*
   Tutorial de como usar o sensor de tensão DC de 0 a 25 volts
   SeuRobo.com.br
*/
//configura a porta analogica A0 para o sensor (pino S de sinal)
#define sensorTensaoDC  A2
#define rele 12

//declarações de variaveis
float valorTensaoDC;  // variavel para receber o valor lido do sensor
int amostragem = 1000; // varivel para der uma media de calculos
float mediaTotalTensaoDC = 0; // variavel para soma das medias
float valorFinalTensaoDC = 0; //variavel para recerber o valor final de Volts
//VARIAVEIS COM OS VALORES DOS RESISTORES DO SENSOR DE TENSÃO DC
float voltsporUnidade = 0.004887586;// DECLARAÇÃO DA VARIÁVEL DA CONSTANTE DO ADC 5%/1023
float R1 = 30000.0; // Medir o resitor com o multimetro na escala 200k de omegas do lado negativo
float R2 = 7500.0; // Medir o resitor com o multimetro na escala 200k de omegas do lado positivo


//função para configurar os dispositivos
void setup() {
  Serial.begin(9600); //incia a comunicação serial com o monitor serial
  pinMode(rele, OUTPUT);
}

void loop() {
  mediaTotalTensaoDC = 0; //zera o valor medio para não dar erro de calculo
  for (int i = 0; i < amostragem ; i++) {// repete por 1000 vezes para der uma precisão melhor
    valorTensaoDC = analogRead(sensorTensaoDC);//recebe o valor do sensor que vai de 0 até 1023
    valorTensaoDC = (valorTensaoDC * voltsporUnidade); //calcula o valor com base na resolução do ADC
    mediaTotalTensaoDC = mediaTotalTensaoDC + (valorTensaoDC / (R2 / (R1 + R2))); //faz o calculo matematico
  }

  valorFinalTensaoDC = mediaTotalTensaoDC / amostragem; //calcula a media dos valores
  //escreve no monitor serial os valores
  Serial.print("Valor: "); 
  Serial.print(valorFinalTensaoDC);
  Serial.println(" VOLTS");

  if(valorFinalTensaoDC >= 10){
    digitalWrite(rele, HIGH);
  }else{
    digitalWrite(rele, LOW);
  }

  delay(5000);//aguarda um segundo para a proxima leitura
}
