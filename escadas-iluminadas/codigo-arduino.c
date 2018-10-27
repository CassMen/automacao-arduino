
#define PINO_LEDSTRIP 6 // Pino ligado à fita LED.
#define PINO_PIR 3 // Pino ligado ao sensor PIR. 
long tempoAcionamento;

void setup()
{
  pinMode(PINO_LEDSTRIP, OUTPUT); // Define LEDStrip como saída.
  pinMode(PINO_PIR, INPUT); // Define pino do sensor como entrada.
}

void loop()
{
  int acionamento = digitalRead(PINO_PIR); // Lê o valor do sensor PIR.
  long timestamp = millis(); // Lê o tempo atual.
  bool acionado;

  if (acionamento == HIGH && acionado == false)
 {
    // Com movimento, liga LEDs.
    digitalWrite(PINO_LEDSTRIP, HIGH);
    tempoAcionamento = timestamp;
    acionado = true;
 }

  if (acionado && (timestamp - tempoAcionamento) >= 10000) {
    // Verifica se já se passou o tempo necessário e desliga os LEDs.
    // No caso, são 10 segundos.
    acionado = false;
    digitalWrite(PINO_LEDSTRIP, LOW);  
 } 

}
