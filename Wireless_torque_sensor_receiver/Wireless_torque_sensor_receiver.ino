/*
* Script: Wireless_torque_sensor_reciever.ino
* Description: An Arduino with an XBee recieves data transmitted by another
*              Arduino with an XBee which is interfaced with a torque sensor.
*
*
* Author: Kevin Rivera
* Creation date: 04/08/2023 v1.0
*/
#include <SoftwareSerial.h>


SoftwareSerial XBee(2, 3); // RX, TX pins

//////////////////////////////////////Functions//////////////////////////////////////////

void setup()
{

  XBee.begin(9600);
  Serial.begin(9600);
}

void loop()
{

  if (XBee.available())
  { 
    Serial.write(XBee.read());

  }
}
