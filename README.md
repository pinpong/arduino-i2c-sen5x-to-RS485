### SEN5X docs https://github.com/Sensirion/arduino-i2c-sen5x

## Requirement

1. SENS SEN55-SDN-T
2. JST GHR 6 pin cacle
3. Arduino Nano Every
4. TTL to RS485, MAX485
5. (optional) USB-RS485-WE

The connection from SEN55 to Arduino Nano Every

| _SEN5X_ | _Arduino_   | _Jumper Wire_ |
| ------- | ----------- | ------------- |
| VCC     | 5V          | Red           |
| GND     | GND         | Black         |
| SDA     | SDA         | Green         |
| SCL     | SCL         | Yellow        |
| SEL     | GND for I2C | Blue          |

The connection from Arduino Nano Every to TTL to RS485

| _Arduino_ | _TTL to RS485_ | _Jumper Wire_ |
| --------- | -------------- | ------------- |
| TX        | DI             | Green         |
| RX        | RO             | Orange        |
| D2        | DE             | Brown         |
| D2        | RE             | Brown         |

The connection TTL to RS485 to USB-RS485-WE

| _TTL to RS485_ | _USB485_ | _Jumper Wire_ |
| -------------- | -------- | ------------- |
| A              | DATA+    | Orange        |
| B              | DATA-    | Yellow        |
