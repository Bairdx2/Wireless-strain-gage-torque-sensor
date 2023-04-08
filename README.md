# Wireless strain gage torque sensor with microcontroller interface
Torque sensors are typically expensive and not adaptable in cases where one is not tightening a nut or bolt. Torsional forces exist in many different applications and measuring them is relatively easy. Typical torque sensors which are not part of a torque wrench are costly and only consist of four strain resistors placed close together and angled 45° apart. This is a short project related to making one of these types of resistive torque sensors while also adding long range wireless data transfer capabilities to accomodate cases where direct wire connections may not be suitable.

## Table of Contents:
- Items needed
- Schematic diagrams
- Project guidelines
- Considerations
##
### Items needed:

1. 2x - Microcontroller (I used the Arduino UNO but any microcontroller with PWM will work)
2. 2x - [XBee transceiver](https://www.sparkfun.com/products/15126)
3. 2x - [XBee shield](https://www.sparkfun.com/products/12847)
4. 1x - LM324N Op-Amp
5. 2x - 1MΩ resistor
6. 2x - 1kΩ resistor
7. 1x - 0.1μF capacitor
8. 4x - 350Ω strain gages (other standard value strain gages will work also)
##
### Schematic diagrams

![alt text](https://i.imgur.com/DV0KoyN.png)

***Figure 1***: Schematic diagram illustraing connections between the torque sensor and arduino.

![alt text](https://i.imgur.com/MDdYPOP.png)

***Figure 2***: Physical version of connected circuit.

![alt text](https://i.imgur.com/02jTyFM.png)

***Figure 3***: Schematic diagram of the Wheatstone bridge sensor and governing equations.

![alt text](https://i.imgur.com/krUzyjr.png)

***Figure 4***: Differential Opamp circuit and governing equations.


##
### Project guidelines

When all of the proper circuit connections are made, the reciever/transmitter code is uploaded to the respective Arduino module and the output can be measured instantly. Initially if the raw data is not filtered, the reciever Arduino will a value between 0 - 1023 which corresponds to the transmitter Arduino ADC reading (Fig. 5 + 6). When the data is converted from a raw reading to torque using the governing equations provided previously, the applied torque can be measured wirelessly in realtime (Fig 7). The torque was applied by holding the aluminum bar with the torque sensor at both ends. One end was held stationary while a rotational force was applied to the other. The amount of force that could be applied using this method was relatively small but since the differential Opamp circuit gaing was x1000, this force could easily be measured.

![alt text](https://i.imgur.com/1Jjgfig.png)

***Figure 5***: Raw output of the data sent from the transmitter Arduino to the reciever Arduino with various test types.

![alt text](https://i.imgur.com/BBpQnKR.png)

***Figure 6***: Raw output of the data sent from the transmitter Arduino to the reciever Arduino while applying and holding different torque amounts.

![alt text](https://i.imgur.com/R9qLphf.png)

***Figure 7***: Raw output converted to torque using the governing equations.


##
### Considerations

1. The accuracy of this method is very reliant on being able to place the sensors as closely as possible and more importantly, at as clost to 45° apart. If these parameters are not met, the voltage measured for equal an opposite applied torque values may not be equal.
2. The strain sensors were applied to using cyanoacrylate (super glue - gel type) and the curing process took several hours.
3. Simplified governing equations were used for the differential opamp circuit but assume that resistor pairs have equivalent values. Resistor values are always off by a certain percentage due to manufacturing processes and thus, these simplified equations may not be suitable for certain applications.
4. The XBee transceivers have to be set up in order to communicate with each other. The XCTU software must be used to facilitate this. Simple OSK/ASK wireless [transmitter](https://www.sparkfun.com/products/10534)/[receiver](https://www.sparkfun.com/products/10532) modules can be used instead but at the cost of range and lack of encryption.
