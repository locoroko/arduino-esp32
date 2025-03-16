
#include "ZigbeeEnvSensor.h"
#include "esp_zigbee_core.h"
#include "esp_zigbee_zcl_common.h"

ZigbeeEnvSensor::ZigbeeEnvSensor(uint8_t endpointNumber)
: ZigbeeDevice(endpointNumber, ESP_ZB_HA_DEVICE_ID_SIMPLE_SENSOR) {
    addCluster(ESP_ZB_ZCL_CLUSTER_ID_TEMP_MEASUREMENT);
    addCluster(ESP_ZB_ZCL_CLUSTER_ID_REL_HUMIDITY_MEASUREMENT);
    addCluster(ESP_ZB_ZCL_CLUSTER_ID_CO2_MEASUREMENT);
    addCluster(ESP_ZB_ZCL_CLUSTER_ID_PM2_5_MEASUREMENT);
    addCluster(ESP_ZB_ZCL_CLUSTER_ID_ANALOG_INPUT);

    // Custom attributes for Analog Input Cluster
    addAttributeCustom(ESP_ZB_ZCL_CLUSTER_ID_ANALOG_INPUT, 0x0100, ESP_ZB_ZCL_ATTR_TYPE_U16, 0);  // VOC
    addAttributeCustom(ESP_ZB_ZCL_CLUSTER_ID_ANALOG_INPUT, 0x0101, ESP_ZB_ZCL_ATTR_TYPE_U16, 0);  // NOx
    addAttributeCustom(ESP_ZB_ZCL_CLUSTER_ID_ANALOG_INPUT, 0x0102, ESP_ZB_ZCL_ATTR_TYPE_U16, 0);  // PM1.0
    addAttributeCustom(ESP_ZB_ZCL_CLUSTER_ID_ANALOG_INPUT, 0x0103, ESP_ZB_ZCL_ATTR_TYPE_U16, 0);  // PM4.0
    addAttributeCustom(ESP_ZB_ZCL_CLUSTER_ID_ANALOG_INPUT, 0x0104, ESP_ZB_ZCL_ATTR_TYPE_U16, 0);  // PM10.0
}

void ZigbeeEnvSensor::setTemperature(float temperature) {
    int16_t value = temperature * 100; // Zigbee uses 0.01°C units
    setAttributeValue(ESP_ZB_ZCL_CLUSTER_ID_TEMP_MEASUREMENT, ESP_ZB_ZCL_ATTR_TEMP_MEASUREMENT_VALUE_ID, &value);
}

void ZigbeeEnvSensor::setHumidity(float humidity) {
    uint16_t value = humidity * 100;  // Zigbee uses 0.01% units
    setAttributeValue(ESP_ZB_ZCL_CLUSTER_ID_REL_HUMIDITY_MEASUREMENT, ESP_ZB_ZCL_ATTR_REL_HUMIDITY_MEASUREMENT_VALUE_ID, &value);
}

void ZigbeeEnvSensor::setCO2(uint16_t co2) {
    setAttributeValue(ESP_ZB_ZCL_CLUSTER_ID_CO2_MEASUREMENT, ESP_ZB_ZCL_ATTR_MEASURED_VALUE_ID, &co2);
}

void ZigbeeEnvSensor::setPM25(uint16_t pm25) {
    setAttributeValue(ESP_ZB_ZCL_CLUSTER_ID_PM2_5_MEASUREMENT, ESP_ZB_ZCL_ATTR_MEASURED_VALUE_ID, &pm25);
}

// Custom analog attributes
void ZigbeeEnvSensor::setVOC(uint16_t voc) {
    setAttributeValue(ESP_ZB_ZCL_CLUSTER_ID_ANALOG_INPUT, 0x0100, &voc);
}

void ZigbeeEnvSensor::setNOx(uint16_t nox) {
    setAttributeValue(ESP_ZB_ZCL_CLUSTER_ID_ANALOG_INPUT, 0x0101, &nox);
}

void ZigbeeEnvSensor::setPM1(uint16_t pm1) {
    setAttributeValue(ESP_ZB_ZCL_CLUSTER_ID_ANALOG_INPUT, 0x0102, &pm1);
}

void ZigbeeEnvSensor::setPM4(uint16_t pm4) {
    setAttributeValue(ESP_ZB_ZCL_CLUSTER_ID_ANALOG_INPUT, 0x0103, &pm4);
}

void ZigbeeEnvSensor::setPM10(uint16_t pm10) {
    setAttributeValue(ESP_ZB_ZCL_CLUSTER_ID_ANALOG_INPUT, 0x0104, &pm10);
}

void ZigbeeEnvSensor::report() {
    esp_zb_zcl_report_attr_cmd_t report = {};
    // Implement reporting for changed attributes (custom logic)
    sendReport();
}
