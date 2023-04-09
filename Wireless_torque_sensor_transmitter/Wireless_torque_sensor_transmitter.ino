/*
* Script: Wireless_torque_sensor_transmitter.ino
* Description: A wheatstone bridge consisting of 350ohm strain sensors
*              mounted on an aluminum bar are connected to a differential
*              operationa amplifier circuit. The output is measured with
*              and Arduino and transmitted to a reciever Arduino via XBee.
*
*
* Author: Kevin Rivera
* Creation date: 04/08/2023 v1.0
*/
#include <SoftwareSerial.h>

//////////////////////////////////////Variables//////////////////////////////////////////

const float V = 5.0;       // the default reference on a 5-volt board
const int analogPin = A0;  // battery is connected to analog pin 0
const float r = 0.028;     // [m] Inner diameter of shaft.
const float R = 0.031;     // [m] Outer diameter of shaft.
const float GF = 2.1;      // Gage factor of the BF350 strain gages.
const float E = 70E9;      // [N/m^2] Elastic modulus of aluminum.
const float v = 0.31;      // Poisson ratio of aluminum.
float Temp_T = 0;
float Temp_ue = 0;

bool flag = 1;
char TM[50];
char tot[100];
SoftwareSerial XBee(2, 3); // RX, TX pins

//////////////////////////////////////Functions//////////////////////////////////////////

void setup(){
  
  XBee.begin(9600);
  Serial.begin(9600);


  
}

void loop(){
  
  float value = analogRead(analogPin);    // Torque sensor output is read.
  float Vo = ((value / 1023) * V)/1000.0; // The actual output of the torque sensor is determined by dividing by the amplification factor.
  float T = (Vo*E*(3.14*(pow(R,4) - pow(r,4))))/(V*GF*(R*(1+v))); // Measured torque
  float ue = ((Vo)/(V*GF))*(1E6); // Measured torsional strain

  if (flag){
    Temp_T = T;
    Temp_ue = ue;
    flag = 0;
  }

  T = T-Temp_T;
  ue = ue-Temp_ue;
  
  //// Print value testing
  //Serial.println(Vo,6);
  //Serial.println(value,6);
  //Serial.println(T,6);
  //Serial.println(ue,6);
  //Serial.print(",100,200");
  //Serial.println();

  dtostrf(T, 6, 4, TM);
  strcat(tot,TM);
  
  XBee.println(tot);
  memset(TM, 0, sizeof(TM));
  memset(tot, 0, sizeof(tot));
  delay(10);
}
