#include <DallasTemperature.h>
#include <OneWire.h>
#include <Servo.h>
//Declarar Objeto

//Temperatura
float temperatura1;
float temperatura2;

#define pinoSensor1 12
#define pinoSensor2 13

OneWire sensor1(pinoSensor1);
OneWire sensor2(pinoSensor2);

DallasTemperature sensorHeh1(&sensor1);
DallasTemperature sensorHeh2(&sensor2);

DeviceAddress endereco_temp;




//Motores
//Bomba?
#define pinoBomba 9
//Servo
Servo SMotor;

#define pinoServoMotor 4

//Motor Dc
#define IN1 5  // Motor 1
#define IN2 6  // Motor 1
#define IN3 7  // Motor 2
#define IN4 8  // Motor 2

void setup() {
Serial.begin(9600);
//inicilizar motores
//Servo
SMotor.attach(pinoServoMotor);
pinMode(pinoServoMotor, OUTPUT);
//Dc
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);


//Inicilizar Sensores
sensorHeh1.begin();
sensorHeh2.begin();
}



void andarMotor(int vel1, int vel2, int vel3, int vel4) {
    digitalWrite(IN1, vel1);
    digitalWrite(IN2, vel2);
    digitalWrite(IN3, vel3);
    digitalWrite(IN4, vel4);
}


float medirTemp(DallasTemperature sensor) {

sensor.requestTemperatures();
float temperatura = sensor.getTempC(endereco_temp);
return temperatura;
}







void loop() {
  

if(!sensorHeh1.getAddress(endereco_temp, 0)){
}else if(!sensorHeh2.getAddress(endereco_temp, 0)){
temperatura1 = medirTemp(sensorHeh1);
temperatura2 = medirTemp(sensorHeh2);
}

while(temperatura1 <= 35 && temperatura2 <= 35 ){
temperatura1 = medirTemp(sensorHeh1);
temperatura2 = medirTemp(sensorHeh2);
 andarMotor(HIGH,LOW,HIGH,LOW);
   delay(2000);
  temperatura1 = medirTemp(sensorHeh1);
  temperatura2 = medirTemp(sensorHeh2);
   andarMotor(HIGH,LOW,LOW,LOW);
   delay(1000);
   temperatura1 = medirTemp(sensorHeh1);
temperatura2 = medirTemp(sensorHeh2);
 andarMotor(HIGH,LOW,HIGH,LOW);
   delay(2000);
  temperatura1 = medirTemp(sensorHeh1);
  temperatura2 = medirTemp(sensorHeh2);
   andarMotor(HIGH,LOW,LOW,LOW);
   delay(1000);
   temperatura1 = medirTemp(sensorHeh1);
temperatura2 = medirTemp(sensorHeh2);
 andarMotor(HIGH,LOW,HIGH,LOW);
   delay(2000);
  temperatura1 = medirTemp(sensorHeh1);
  temperatura2 = medirTemp(sensorHeh2);
   andarMotor(HIGH,LOW,LOW,LOW);
   delay(1000);
   temperatura1 = medirTemp(sensorHeh1);
temperatura2 = medirTemp(sensorHeh2);
 andarMotor(HIGH,LOW,HIGH,LOW);
   delay(4000);

}

if(temperatura1 > 35 && temperatura2 > 35 ){
SMotor.write(90);
digitalWrite(pinoBomba, HIGH);
delay(2000);
digitalWrite(pinoBomba, LOW);
}else if(temperatura1 > 35){
SMotor.write(180);
digitalWrite(pinoBomba, HIGH);
delay(2000);
digitalWrite(pinoBomba, LOW);
}else if(temperatura2 > 35){
SMotor.write(0);
digitalWrite(pinoBomba, HIGH);
delay(2000);
digitalWrite(pinoBomba, LOW);
}



}




