// C++ code
//
int saida1 = 9;
int saida2 = 11;
int saidaBotao = 4;
int estadoBotao;
int estadoBotaoTeste = 0;
int saidaBotao2 = 5;
int estadoBotao2;
int estadoBotaoTeste2 = 0;
int HL1 = 1;
int HL2 = 0;

void setup()
{
 pinMode(saida1, OUTPUT);
 pinMode(saida2, OUTPUT);
 pinMode(saidaBotao, INPUT);
 pinMode(saidaBotao2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  estadoBotao = digitalRead(saidaBotao);
   estadoBotao2 = digitalRead(saidaBotao2);
  Serial.println(estadoBotaoTeste2);
  
  if(estadoBotao == 1){
    estadoBotaoTeste ++;
    delay(2000);
  }
  
  if(estadoBotao2 == 1){
    estadoBotaoTeste2 ++;
    delay(2000);
  }
  
   if(estadoBotaoTeste2%2 != 0){  
HL1 = 1;
HL2 = 0;
  }else if(estadoBotaoTeste2%2 == 0){
HL1 = 0;
HL2 = 1;
  }
  
 if(estadoBotaoTeste%2 != 0){  
 digitalWrite(11, HL1);
 digitalWrite(9, HL2);
  }else if(estadoBotaoTeste%2 == 0){
 digitalWrite(11, LOW);
 digitalWrite(9, LOW);
  }



}
