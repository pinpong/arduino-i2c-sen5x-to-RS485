### SEN5X docs https://github.com/Sensirion/arduino-i2c-sen5x

## Requirement

1. SENS SEN55-SDN-T
2. JST GHR 6 pin cacle
3. Arduino Nano Every
4. TTL to RS485, MAX485
5. (optional) USB-RS485-WE

The connection from SEN55 to Arduino Nano Every

- SEN55 black to Arduino Nano Every GND
- SEN55 white to Arduino Nano Every +5v
- SEN55 yellow to Arduino Nano Every SCL / D19
- SEN55 green to Arduino Nano Every SDA / D18
- SEN55 red not in use
- SEN55 blue not in use

The connection from Arduino Nano Every to TTL to RS485

- Arduino TX (1) to TTL to RS485 DI
- Arduino RX (2) to TTL to RS485 RO
- Arduino D2 to TTL to RS485 DE
- Arduino D2 to TTL to RS485 RE

The connection TTL to RS485 to USB-RS485-WE

- TTL to RS485 B to USB485 Data-
- TTL to RS485 A to USB485 Data+





