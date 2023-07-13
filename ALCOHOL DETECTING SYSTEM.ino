
#define sensorDigital 6
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define LED2 13
#define LED1 9
#define buzzer 7
#define sensorAnalog A1
int RelayPin = 8;

void setup() {
  pinMode(sensorDigital, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(RelayPin,OUTPUT);
  lcd.begin(16, 2);  
  Serial.begin(9600);
}
void loop() {
  bool digital = digitalRead(sensorDigital);
  int analog = analogRead(sensorAnalog);

  Serial.print("Analog value : ");
  Serial.print(analog);
  Serial.print("\t");
  Serial.print("Digital value :");
  Serial.println(digital);
  
  if (digital == 0) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(buzzer, HIGH);
    digitalWrite (RelayPin , HIGH );
    lcd.setCursor(4,0);
    lcd.print("WARNING..");
    lcd.setCursor(0,1);     
    lcd.print("ALCOHOL DETECTED");
     
    
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2,HIGH);    
    digitalWrite(buzzer, LOW);
    digitalWrite(RelayPin, LOW);    
    lcd.clear();
    lcd.setCursor(4,0);    
    lcd.print("NORMAL..:)");
    lcd.setCursor(0,1);
    lcd.print("AlcoholNotDetect");
    
  }

}
