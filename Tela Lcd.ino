// C++ code
//
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int saidaBotao = 6;
int estadoBotao;
int estadoBotaoTeste = 0;

void setup()
{
  lcd.begin(16, 2);
   pinMode(saidaBotao, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.flush();
  estadoBotao = digitalRead(saidaBotao);
  Serial.println(estadoBotaoTeste);
  
  if(estadoBotao == 1){
    estadoBotaoTeste ++;
    delay(2000);
 
  }
  
  if(estadoBotaoTeste%2 != 0){  
	for(int t = 10; t >= 0; t--){
  	lcd.setCursor(0, 0);
  	lcd.print("Tempo Restante");
	lcd.setCursor(0, 1);
    lcd.print(t);
    delay(1000);
    lcd.clear();
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tempo Esgotado");
    delay(5000);
    lcd.clear();
  }
  estadoBotaoTeste = 0;
}
