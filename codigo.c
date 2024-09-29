#include <LiquidCrystal.h>

#define UMIDITY A1
#define FLOATER 10
#define VALV 9
#define BUZZER 8
#define FLOW 2

int umidity_sensor = 0;
int cistern = 1;
int valv = 0;
int buzz_rain = 1;
int buzz_cistern = 1;

int comporta = 0;

double flow; //Water flow L/Min 
unsigned long currentTime;
unsigned long lastTime;
unsigned long pulse_freq;

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup() {
  pinMode(UMIDITY, INPUT);
  pinMode(FLOATER, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(VALV, OUTPUT);
  pinMode(FLOW, INPUT);
  digitalWrite(BUZZER, LOW);
  Serial.begin(9600);
  attachInterrupt(0, pulse, RISING); 
  currentTime = millis();
  lastTime = currentTime;

  lcd.begin(16, 2);

}

void loop() {

  char buffer[10];

  delay(500);
  digitalWrite(VALV, !valv);

  currentTime = millis();
   if(currentTime >= (lastTime + 500))
   {
      lastTime = currentTime; 
      flow = (pulse_freq / 7.5); 
      pulse_freq = 0;
      //Limpa a tela
      lcd.clear();
      //Posiciona o cursor na coluna 3, linha 0;
      lcd.setCursor(3, 0);
      //Envia o texto entre aspas para o LCD
      dtostrf(flow, 6, 2, buffer);
      lcd.print(buffer);
      lcd.print(" L/Min");
      Serial.print(flow, DEC); 
      Serial.println(" L/Min");
      
   }


  umidity_sensor = analogRead(UMIDITY);
  cistern = digitalRead(FLOATER);
  Serial.println(umidity_sensor);
  Serial.println(cistern);
  Serial.println(valv);
  Serial.println("");
  
  if(cistern == 1) {
    if(buzz_cistern) {
      buzz_cistern = 0;
      buzzing(200, 3);
      lcd.clear();
      //Posiciona o cursor na coluna 3, linha 0;
      lcd.setCursor(3, 0);
      //Envia o texto entre aspas para o LCD
      lcd.print("Está cheio.");
      Serial.println("Está cheio.");
    }
    valv = 0;
  }
  else {
    buzz_cistern = 1;
  }
  
  if(umidity_sensor < 200 && cistern == 0) {
    if(buzz_rain) {
      buzzing(100, 5);
      delay(2000);
      buzz_rain = 0;
    }
    valv = 1;

    if (comporta == 1){
      lcd.clear();
      //Posiciona o cursor na coluna 0, linha 0;
      lcd.setCursor(0, 0);
      //Envia o texto entre aspas para o LCD
      lcd.print("Comporta aberta");
      Serial.println("Comporta aberta");
      comporta = 0;
    }
  }
  else {
    buzz_rain = 1;
    valv = 0;

    if (comporta == 0){
      lcd.clear();
      //Posiciona o cursor na coluna 0, linha 0;
      lcd.setCursor(0, 0);
      //Envia o texto entre aspas para o LCD
      lcd.print("Comporta fechada");
      Serial.println("Comporta fechada");
      comporta = 1;
    }
  }
}

void buzzing(int time, int count) {
  for(int i = 0; i < count; i++) {
    digitalWrite(BUZZER, HIGH);
    delay(time);
    digitalWrite(BUZZER, LOW);
    delay(time);
  }
}

void pulse () // Interrupt function

{
  pulse_freq++;
}

void display() {
  lcd.clear();
  lcd.setCursor(0, 0);
  if (valv) {
    lcd.print("");
  } else {

  }
}
