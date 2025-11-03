#include <Arduino.h>
#include <string.h> 

void atividade1(); 
void atividade2(); 
void atividade3(); 
void atividade4(); 

bool state = false; 

void setup() {
  Serial.begin(9600); 
  Serial.println("Sistema pronto. Iniciando...");
  Serial.println("--------------------------------");
  
  atividade2(); 
  
  Serial.println("--------------------------------");
  atividade3(); 
  
  Serial.println("--------------------------------");
  atividade4(); 

  Serial.println("--------------------------------");
  Serial.println("Aguardando comandos (ex: LED ON, LED OFF)...");
}

void loop() {
  atividade1();
}

void atividade1() {
  if (Serial.available() > 0) {
    String texto = Serial.readStringUntil('\n');
    texto.trim(); 

    if (texto.length() > 0) {
      if (texto.endsWith("ON")) {
        Serial.println("LIGAR LED");
        state = true; 
      } else if (texto.endsWith("OFF")) {
        Serial.println("DESLIGAR LED");
        state = false; 
      } else {
        Serial.println("COMANDO INVÁLIDO");
      }

      Serial.printf("Voce digitou: %s\n", texto.c_str());
      Serial.printf("O estado atual é: %s\n\n", state ? "LIGADO" : "DESLIGADO");
    }
  }
}

void atividade2() {
  Serial.println("Executando Atividade 2...");
  
  String mensagem = "Temperatura = 27C";
  int startIndex = mensagem.indexOf('=') + 1;
  int endIndex = mensagem.indexOf('C');
  String numberString = mensagem.substring(startIndex, endIndex);
  numberString.trim();
  int tempCelsius = numberString.toInt();
  float tempFahrenheit = (tempCelsius * 9.0 / 5.0) + 32.0;

  Serial.printf("Mensagem Original: %s", mensagem);
  Serial.print("Número Extraído: ");
  Serial.println(numberString);
  Serial.print("Valor em Celsius: ");
  Serial.print(tempCelsius);
  Serial.println(" C");
  Serial.print("Valor em Fahrenheit: ");
  Serial.print(tempFahrenheit);
  Serial.println(" F");
}

void atividade3() {
  Serial.println("Executando Atividade 3...");
  
  char sentence[] = "ESTAMOS APRENDENDO ARDUINO NA AULA";
  char* keyword = "ARDUINO";

  Serial.print("Frase: ");
  Serial.println(sentence);

  if (strstr(sentence, keyword) != NULL) {
    Serial.println("CONTEÚDO RELACIONADO A ARDUINO DETECTADO");
  } else {
    Serial.println("NÃO ENCONTRADO");
  }
}

void atividade4() {
  Serial.println("Executando Atividade 4...");
  
  String message = "sEnAi eSp32 ArDuInO";
  Serial.print("Original: ");
  Serial.println(message);

  message.toUpperCase();
  Serial.print("Maiúsculo: ");
  Serial.println(message);

  message.toLowerCase();
  Serial.print("Minúsculo: ");
  Serial.println(message);

  if (message.length() > 0) {
    String firstLetter = message.substring(0, 1);
    firstLetter.toUpperCase(); 
    
    String restOfSentence = message.substring(1);
    restOfSentence.toLowerCase();

    message = firstLetter + restOfSentence;
  }
  Serial.print("Primeira Maiúscula: ");
  Serial.println(message);
}