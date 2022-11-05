#include <Arduino.h>
#include <ArduinoModbus.h>
#include <SensirionI2CSen5x.h>
#include <Wire.h>


// The used commands use up to 48 bytes. On some Arduino's the default buffer
// space is not large enough
#define MAXBUF_REQUIREMENT 48

#if (defined(I2C_BUFFER_LENGTH) && (I2C_BUFFER_LENGTH >= MAXBUF_REQUIREMENT)) || (defined(BUFFER_LENGTH) && BUFFER_LENGTH >= MAXBUF_REQUIREMENT)
#define USE_PRODUCT_INFO
#endif


RS485Class _RS485(Serial1, RS485_DEFAULT_TX_PIN, RS485_DEFAULT_DE_PIN, RS485_DEFAULT_RE_PIN);
SensirionI2CSen5x sen5x;

void setup() {
  ModbusRTUServer.begin(_RS485, 42, 9600);
  ModbusRTUServer.configureHoldingRegisters(0x00, 9);

  Wire.begin();
  sen5x.begin(Wire);

  sen5x.deviceReset();

  float tempOffset = 0.0;
  sen5x.setTemperatureOffsetSimple(tempOffset);
  sen5x.startMeasurement();
}

void loop() {
  ModbusRTUServer.poll();

  uint16_t error;

  float massConcentrationPm1p0;
  float massConcentrationPm2p5;
  float massConcentrationPm4p0;
  float massConcentrationPm10p0;
  float ambientHumidity;
  float ambientTemperature;
  float vocIndex;
  float noxIndex;

  error = sen5x.readMeasuredValues(
    massConcentrationPm1p0, massConcentrationPm2p5, massConcentrationPm4p0,
    massConcentrationPm10p0, ambientHumidity, ambientTemperature, vocIndex,
    noxIndex);

  if (error) {
    ModbusRTUServer.holdingRegisterWrite(0x08, error);
  }

  if (isnan(massConcentrationPm1p0) || isnan(massConcentrationPm2p5) || isnan(massConcentrationPm4p0) || isnan(massConcentrationPm10p0) || isnan(ambientHumidity) || isnan(ambientTemperature) || isnan(vocIndex) || isnan(noxIndex)) {
    return;
  }

  ModbusRTUServer.holdingRegisterWrite(0x00, static_cast<int>(massConcentrationPm1p0 * 100));
  ModbusRTUServer.holdingRegisterWrite(0x01, static_cast<int>(massConcentrationPm2p5 * 100));
  ModbusRTUServer.holdingRegisterWrite(0x02, static_cast<int>(massConcentrationPm4p0 * 100));
  ModbusRTUServer.holdingRegisterWrite(0x03, static_cast<int>(massConcentrationPm10p0 * 100));
  ModbusRTUServer.holdingRegisterWrite(0x04, static_cast<int>(ambientHumidity * 100));
  ModbusRTUServer.holdingRegisterWrite(0x05, static_cast<int>(ambientTemperature * 100));
  ModbusRTUServer.holdingRegisterWrite(0x06, static_cast<int>(vocIndex * 100));
  ModbusRTUServer.holdingRegisterWrite(0x07, static_cast<int>(noxIndex * 100));
  ModbusRTUServer.holdingRegisterWrite(0x08, 0);
}