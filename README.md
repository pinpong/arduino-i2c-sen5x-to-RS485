### SEN5X docs https://github.com/Sensirion/arduino-i2c-sen5x

## Requirement

1. SENS SEN55-SDN-T
2. JST GHR 6 pin cable
3. Arduino Nano Every
4. TTL to RS485, MAX485
5. (optional) USB-RS485-WE

The connection from SEN55 to Arduino

| _SEN5X_ | _Arduino_   | _Jumper Wire_ |
| ------- | ----------- | ------------- |
| VCC     | 5V          | Red           |
| GND     | GND         | Black         |
| SDA     | SDA         | Green         |
| SCL     | SCL         | Yellow        |
| SEL     | GND for I2C | Blue          |

The connection from to TTL to RS485

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

## Installation

1. Download the latest SensirionI2CSen5x release with [Arduino IDE](http://www.arduino.cc/en/main/software) via

   `Sketch => Include Library => Manage Libraries => Search for SensirionI2CSen5x and install it`

2. Open the `arduino_nano_every` file within the Arduino IDE

3. Click the `Upload` button in the Arduino IDE or

   Sketch => Upload

## Read the data

- Mode: RTU
- Baudrate: 96000
- Slave ID: 42
- Parity: None
- Data bits: 8
- Stop bits: 8

| _Holding Register_ | _Data_      |
|--------------------|-------------|
| 0x00               | PM1         |
| 0x01               | PM2.5       |
| 0x02               | PM4         |
| 0x03               | PM10        |
| 0x04               | Humidity    |
| 0x05               | Temperature |
| 0x06               | Vox         |
| 0x07               | Nox         |
| 0x08               | Error       |

## Troubleshooting

If you want use another Arduino device initialize the RS485Class with the proper serial port.
