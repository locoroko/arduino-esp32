#ifndef ZIGBEE_ENVSENSOR_H
#define ZIGBEE_ENVSENSOR_H

#include "ZigbeeDevice.h"

class ZigbeeEnvSensor : public ZigbeeDevice {
public:
    ZigbeeEnvSensor(uint8_t endpointNumber);

    void setTemperature(float temperature);
    void setHumidity(float humidity);
    void setCO2(uint16_t co2);
    void setPM25(uint16_t pm25);

    void setVOC(uint16_t voc);
    void setNOx(uint16_t nox);
    void setPM1(uint16_t pm1);
    void setPM4(uint16_t pm4);
    void setPM10(uint16_t pm10);

    void report();  // sends updates to Zigbee network
};

#endif
