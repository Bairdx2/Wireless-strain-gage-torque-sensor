# Wireless strain gage torque sensor with microcontroller interface
Torque sensors are typically expensive and not adaptable in cases where one is not tightening a nut or bolt. Torsional forces exist in many different applications and measuring them is relatively easy. Typical torque sensors which are not part of a torque wrench are costly and only consist of four strain resistors placed close together and angled 45° apart. This is a short project related to making one of these types of resistive torque sensors while also adding long range wireless data transfer capabilities to accomodate cases where direct wire connections may not be suitable.

## Table of Contents:
- Items needed
- Schematic diagram
- Useful application
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
### Schematic diagram

![alt text](https://i.imgur.com/DV0KoyN.png)

***Figure 1***: Schematic diagram illustraing connections between the torque sensor and arduino.

![alt text](https://i.imgur.com/MDdYPOP.png)

***Figure 2***: Physical version of connected circuit.

![alt text](https://i.imgur.com/02jTyFM.png)

***Figure 2***: Schematic diagram of the Wheatstone bridge sensor and governing equations.

