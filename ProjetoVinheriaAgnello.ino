const int ledVerde = 2;       // Define o pino 2 para o LED verde (indicador de condição normal)
const int ledAmarelo = 3;     // Define o pino 3 para o LED amarelo (indicador de alerta)
const int ledVermelho = 4;    // Define o pino 4 para o LED vermelho (indicador de condição crítica)
const int buzzer = 5;         // Define o pino 5 para o buzzer (alarme sonoro)

void setup()
{
  Serial.begin(9600);               // Inicia a comunicação serial com velocidade de 9600 bps (para monitorar o valor do sensor no computador)

  pinMode(A0, INPUT);               // Define o pino analógico A0 (ligado ao LDR) como entrada
  pinMode(buzzer, OUTPUT);          // Define o pino do buzzer como saída
  pinMode(ledVerde, OUTPUT);        // Define o pino do LED verde como saída
  pinMode(ledVermelho, OUTPUT);     // Define o pino do LED vermelho como saída
  pinMode(ledAmarelo, OUTPUT);      // Define o pino do LED amarelo como saída
}


void loop()
{
  int luminosidade = analogRead(A0);  // Lê o valor analógico do sensor LDR (varia de 0 a 1023 conforme a luz ambiente)
  Serial.println(luminosidade);       // Imprime o valor lido no Monitor Serial (útil para diagnóstico e calibração)

  delay(500);                         // Aguarda 500 milissegundos antes de fazer a próxima leitura
 
  if (luminosidade < 920) {
    digitalWrite(ledVerde, HIGH);     // Acende o LED verde
    digitalWrite(ledAmarelo, LOW);    // Garante que o LED amarelo está apagado
    digitalWrite(ledVermelho, LOW);   // Garante que o LED vermelho está apagado
    digitalWrite(buzzer, LOW);        // Garante que o buzzer está desligado
  }

  
   else if (luminosidade >= 920 && luminosidade < 950) {
    digitalWrite(ledVerde, LOW);      // Apaga o LED verde
    digitalWrite(ledAmarelo, HIGH);   // Acende o LED amarelo
    digitalWrite(ledVermelho, LOW);   // Garante que o LED vermelho está apagado
    digitalWrite(buzzer, HIGH);       // Ativa o buzzer
    delay(3000);                      // Mantém o buzzer ligado por 3 segundos
    digitalWrite(buzzer, LOW);        // Desliga o buzzer após os 3 segundos
  }

    else {
    digitalWrite(ledVerde, LOW);      // Apaga o LED verde
    digitalWrite(ledAmarelo, LOW);    // Apaga o LED amarelo
    digitalWrite(ledVermelho, HIGH);  // Acende o LED vermelho
    digitalWrite(buzzer, HIGH);       // Mantém o buzzer ligado continuamente (só desliga se a luz cair)
  }
}
