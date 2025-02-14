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

//Servo
Servo SMotor;

#define pinoServoMotor 4

//Motor Dc
#define pinoDcMotor1 5
#define pinoDcMotor2 6
#define pinoDcMotor3 7
#define pinoDcMotor4 8

void setup() {
Serial.begin(9600);
//inicilizar motores
//Servo
SMotor.attach(pinoServoMotor);
pinMode(pinoServoMotor, OUTPUT);
//Dc
pinMode(pinoDcMotor1, OUTPUT);
pinMode(pinoDcMotor2, OUTPUT);
pinMode(pinoDcMotor3, OUTPUT);
pinMode(pinoDcMotor4, OUTPUT);


//Inicilizar Sensores
sensorHeh1.begin();
sensorHeh2.begin();
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
 andarMotor(HIGH,HIGH,HIGH,HIGH);
   delay(2000);
  temperatura1 = medirTemp(sensorHeh1);
  temperatura2 = medirTemp(sensorHeh2);
  andarMotor(LOW,HIGH,LOW,LOW);
   delay(1000);
}

}


void andarMotor(int motor5, int motor6, int motor7, int motor8) {
    digitalWrite(pinoDcMotor1, motor5); 
    digitalWrite(pinoDcMotor2, motor6); 
    digitalWrite(pinoDcMotor3, motor7); 
    digitalWrite(pinoDcMotor4, motor8); 
}


float medirTemp(DallasTemperature sensor) {

sensor.requestTemperatures();
float temperatura = sensor.getTempC(endereco_temp);
return temperatura;
}