#ifndef _ESP_Configuration_h
#define _ESP_Configuration_h

#define ESP_FIRMWARE_VERSION "1.0"
#define ESP_HOSTNAME "ESP32"
#define ESP_FIRMWARE_NAME "ESP FIRMWARE"

/* Temporary */

/* Serial port speed */
#define ESP_CONFIG_SERIAL_SPEED 115200

/* Max size of the configuration HTML page */
#define ESP_MAX_PAGE_SIZE 12000
#define ESP_PAGE_CHUNK_SIZE 2048

#define ESP_NUMBER_OF_GPIOS 34

/* Device operating modes */
#define ESP_MODE_NORMAL 0
#define ESP_MODE_CONFIGURATION 1
#define ESP_MODE_ACCESS_POINT 2
#define ESP_MODE_NETWORK_NOT_SET 4
#define ESP_MODE_FIRST_TIME_LAUNCH 5

/* Types of URL requests */
#define ESP_SERVER_CMD_SAVE 1
#define ESP_SERVER_CMD_NONE 0

/* Not existing hardware item. Used as a default value */
#define ESP_HARDWARE_ITEM_NOT_EXIST 255
#define ESP_EMPTY_STRING '\0'

/* APIs */
#define ESP_CONFIG_API_MQTT

/* Firmware compilation. Hardware to compile in */
#define ESP_CONFIG_HARDWARE_I2C
#define ESP_CONFIG_HARDWARE_UART
#define ESP_CONFIG_HARDWARE_SWITCH
#define ESP_CONFIG_HARDWARE_LED
#define ESP_CONFIG_HARDWARE_ADS1115
#define ESP_CONFIG_HARDWARE_ADC
#define ESP_CONFIG_HARDWARE_NEXTION
#define ESP_CONFIG_HARDWARE_SENSOR_BINARY
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20
//#define ESP_CONFIG_HARDWARE_SENSOR_NTC
//#define ESP_CONFIG_HARDWARE_SENSOR_ACS758

/* Functionalities */
#define ESP_CONFIG_FUNCTIONALITY_BATTERYMETER

#ifdef ESP_CONFIG_HARDWARE_SENSOR_NTC
#ifndef ESP_CONFIG_HARDWARE_ADC
#define ESP_CONFIG_HARDWARE_ADC
#endif
#endif // ESP_CONFIG_HARDWARE_SENSOR_NTC

/* Hardware dependencies */
#ifdef ESP_CONFIG_HARDWARE_ADS1115
#ifndef ESP_CONFIG_HARDWARE_ADC
#define ESP_CONFIG_HARDWARE_ADC
#endif
#ifndef ESP_CONFIG_HARDWARE_I2C
#define ESP_CONFIG_HARDWARE_I2C
#endif
#endif // ESP_CONFIG_HARDWARE_ADS1115

#ifdef ESP_CONFIG_FUNCTIONALITY_BATTERYMETER
#ifndef ESP_CONFIG_HARDWARE_ADC
#define ESP_CONFIG_HARDWARE_ADC
#endif
#endif // ESP_CONFIG_FUNCTIONALITY_BATTERYMETER

#ifdef ESP_CONFIG_HARDWARE_SENSOR_DS18B20
#ifndef ESP_CONFIG_FUNCTIONALITY_TEMPERATURE
#define ESP_CONFIG_FUNCTIONALITY_TEMPERATURE
#endif
#endif // ESP_CONFIG_HARDWARE_SENSOR_DS18B20

#ifdef ESP_CONFIG_HARDWARE_SENSOR_NTC
#ifndef ESP_CONFIG_FUNCTIONALITY_TEMPERATURE
#define ESP_CONFIG_FUNCTIONALITY_TEMPERATURE
#endif
#endif // ESP_CONFIG_HARDWARE_SENSOR_NTC

#ifdef ESP_CONFIG_FUNCTIONALITY_TEMPERATURE
#define ESP_CONFIG_FUNCTIONALITY_TEMPERATURE_UNIT_CELSIUS 0
#define ESP_CONFIG_FUNCTIONALITY_TEMPERATURE_UNIT_FARENHIAT 1
#endif // ESP_CONFIG_FUNCTIONALITY_TEMPERATURE

/* Default configurations */
#ifdef ESP_CONFIG_API_MQTT

#define ESP_CONFIG_API_MQTT_MAX_NUMBER 1
#define ESP_CONFIG_API_MQTT_DEFAULT NUMBER 0
#define ESP_CONFIG_API_MQTT_DEFAULT_PORT 1883
#define ESP_CONFIG_API_MQTT_DEFAULT_TIMEOUT 5000
#define ESP_CONFIG_API_MQTT_DEFAULT_QOS 0
#define ESP_CONFIG_API_MQTT_DEFAULT_RETAIN false 

#define ESP_CONFIG_API_MQTT_FILE_NAME "/cfg-mqtt-broker-%d.json"
#define ESP_CONFIG_API_MQTT_FILE_BUFFER 200
#endif

#ifdef ESP_CONFIG_HARDWARE_I2C
#define ESP_CONFIG_HARDWARE_I2C_MAX_NUMBER 2
#define ESP_CONFIG_HARDWARE_I2C_DEFAULT_NUMBER 0
#define ESP_CONFIG_HARDWARE_I2C_1_DEFAULT_SDA 21
#define ESP_CONFIG_HARDWARE_I2C_1_DEFAULT_SCL 22
#define ESP_CONFIG_HARDWARE_I2C_2_DEFAULT_SDA 27
#define ESP_CONFIG_HARDWARE_I2C_2_DEFAULT_SCL 26
#define ESP_CONFIG_HARDWARE_I2C_LOW_FREQUENCY 100000
#define ESP_CONFIG_HARDWARE_I2C_HIGH_FREQUENCY 400000
#define ESP_CONFIG_HARDWARE_I2C_DEFAULT_FREQUENCY ESP_CONFIG_HARDWARE_I2C_LOW_FREQUENCY
#define ESP_CONFIG_HARDWARE_I2C_FILE_NAME "/cfg-i2c-%d.json"
#define ESP_CONFIG_HARDWARE_I2C_FILE_BUFFER 200
#endif // ESP_CONFIG_HARDWARE_I2C

#ifdef ESP_CONFIG_HARDWARE_UART
#define ESP_CONFIG_HARDWARE_UART_MAX_NUMBER 3
#define ESP_CONFIG_HARDWARE_UART_DEFAULT_NUMBER 0
#define ESP_CONFIG_HARDWARE_UART_1_RXD 3
#define ESP_CONFIG_HARDWARE_UART_1_TXD 1
#define ESP_CONFIG_HARDWARE_UART_2_RXD 9
#define ESP_CONFIG_HARDWARE_UART_2_TXD 10
#define ESP_CONFIG_HARDWARE_UART_3_RXD 16
#define ESP_CONFIG_HARDWARE_UART_3_TXD 17
#define ESP_CONFIG_HARDWARE_UART_FILE_NAME "/cfg-uart-%d.json"
#define ESP_CONFIG_HARDWARE_UART_FILE_BUFFER 200
#endif // ESP_CONFIG_HARDWARE_UART

#ifdef ESP_CONFIG_HARDWARE_SWITCH
#define ESP_CONFIG_HARDWARE_SWITCH_MAX_NUMBER 2
#define ESP_CONFIG_HARDWARE_SWITCH_DEFAULT_NUMBER 1
#define ESP_CONFIG_HARDWARE_SWITCH_TYPE_MONO_STABLE 0
#define ESP_CONFIG_HARDWARE_SWITCH_TYPE_BI_STABLE 1
#define ESP_CONFIG_HARDWARE_SWITCH_FUNCTIONALITY_NONE 0
#define ESP_CONFIG_HARDWARE_SWITCH_FUNCTIONALITY_MULTI 1
#define ESP_CONFIG_HARDWARE_SWITCH_DEFAULT_GPIO 0
#define ESP_CONFIG_HARDWARE_SWITCH_DEFAULT_TYPE ESP_CONFIG_HARDWARE_SWITCH_TYPE_MONO_STABLE
#define ESP_CONFIG_HARDWARE_SWITCH_DEFAULT_BOUNCING 50
#define ESP_CONFIG_HARDWARE_SWITCH_DEFAULT_PIN_MODE INPUT_PULLUP
#define ESP_CONFIG_HARDWARE_SWITCH_DEFAULT_FUNCTIONALITY ESP_CONFIG_HARDWARE_SWITCH_FUNCTIONALITY_MULTI
#define ESP_CONFIG_HARDWARE_SWITCH_FILE_NAME "/cfg-switch-%d.json"
#define ESP_CONFIG_HARDWARE_SWITCH_FILE_BUFFER 200
#define ESP_CONFIG_HARDWARE_SWITCH_PRESS_FUNCTIONS_INTERVAL 5000 // milliseconds
#endif // ESP_CONFIG_HARDWARE_SWITCH

#ifdef ESP_CONFIG_HARDWARE_LED
#define ESP_CONFIG_HARDWARE_LED_MAX_NUMBER 2
#define ESP_CONFIG_HARDWARE_LED_DEFAULT_NUMBER 1
#define ESP_CONFIG_HARDWARE_LED_DEFAULT_GPIO 2
#define ESP_CONFIG_HARDWARE_LED_DEFAULT_REVERSE 0
#define ESP_CONFIG_HARDWARE_LED_FILE_NAME "/cfg-led-%d.json"
#define ESP_CONFIG_HARDWARE_LED_FILE_BUFFER 200
#define ESP_CONFIG_HARDWARE_SYSTEM_LED_FILE_NAME "/cfg-system-led.json"
#define ESP_CONFIG_HARDWARE_SYSTEM_LED_FILE_BUFFER 50
#define ESP_CONFIG_HARDWARE_SYSTEM_LED_DEFAULT 0
#endif // ESP_CONFIG_HARDWARE_LED

#ifdef ESP_CONFIG_HARDWARE_ADC
#define ESP_CONFIG_HARDWARE_ADC_MAX_NUMBER 4
#define ESP_CONFIG_HARDWARE_ADC_DEFAULT_NUMBER 0
#define ESP_CONFIG_HARDWARE_ADC_DEFAULT_INTERVAL 60000
#define ESP_CONFIG_HARDWARE_ADC_DEFAULT_MAX_VCC 3.3
#define ESP_CONFIG_HARDWARE_ADC_DEFAULT_SAMPLES 10
#define ESP_CONFIG_HARDWARE_ADC_DEFAULT_DIVIDER_RESISTOR 0
#define ESP_CONFIG_HARDWARE_ADC_DEFAULT_RESOLUTION 4095
#define ESP_CONFIG_HARDWARE_ADC_FILE_NAME "/cfg-adc-%d.json"
#define ESP_CONFIG_HARDWARE_ADC_FILE_BUFFER 400
#endif // ESP_CONFIG_HARDWARE_ADC_VCC

#ifdef ESP_CONFIG_HARDWARE_ADS1115
#define ESP_CONFIG_HARDWARE_ADS1115_MAX_INPUTS 4
#define ESP_CONFIG_HARDWARE_ADS1115_DEFAULT_GAIN 0    // Gain 2/3 +/- 6.144
#define ESP_CONFIG_HARDWARE_ADS1115_DEFAULT_SAMPLES 0 // 128/sec
#define ESP_CONFIG_HARDWARE_ADS1115_DEFAULT_RESOLUTION 32766
#endif // ESP_CONFIG_HARDWARE_ADS1115

#ifdef ESP_CONFIG_HARDWARE_NEXTION
#define ESP_CONFIG_HARDWARE_NEXTION_DEBUGGER_SERIAL_SPEED  ESP_CONFIG_SERIAL_SPEED
#define ESP_CONFIG_HARDWARE_NEXTION_HARDWARE_SERIAL_SPEED 9600
#endif // ESP_CONFIG_HARDWARE_NEXTION

#ifdef ESP_CONFIG_HARDWARE_SENSOR_BINARY
#define ESP_CONFIG_HARDWARE_SENSOR_BINARY_MAX_NUMBER 4
#define ESP_CONFIG_HARDWARE_SENSOR_BINARY_DEFAULT_NUMBER 0
#define ESP_CONFIG_HARDWARE_SENSOR_BINARY_DEFAULT_BOUNCING 10
#define ESP_CONFIG_HARDWARE_SENSOR_BINARY_DEFAULT_INTERVAL 60000
#define ESP_CONFIG_HARDWARE_SENSOR_BINARY_FILE_NAME "/cfg-sensor-binary-%d.json"
#define ESP_CONFIG_HARDWARE_SENSOR_BINARY_FILE_BUFFER 100
#endif // ESP_CONFIG_HARDWARE_SENSOR_BINARY

#ifdef ESP_CONFIG_HARDWARE_SENSOR_DS18B20
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_MAX_NUMBER 4
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_ADDRESS_LENGTH 8
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_DEFAULT_NUMBER 0
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_DEFAULT_INTERVAL 60000
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_DEFAULT_CORRECTION 0
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_READ_TIMEOUT 10000
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_DEFAULT_UNIT  ESP_CONFIG_FUNCTIONALITY_TEMPERATURE_UNIT_CELSIUS
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_FILE_NAME "/cfg-sensor-ds18b20-%d.json"
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_FILE_BUFFER 300
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_DEFAULT_RESOLUTION_9B 9
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_DEFAULT_RESOLUTION_10B 10
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_DEFAULT_RESOLUTION_11B 11
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_DEFAULT_RESOLUTION_12B 12
#define ESP_CONFIG_HARDWARE_SENSOR_DS18B20_DEFAULT_RESOLUTION ESP_CONFIG_HARDWARE_SENSOR_DS18B20_DEFAULT_RESOLUTION_12B
#endif // ESP_CONFIG_HARDWARE_SENSOR_DS18B20

#ifdef ESP_CONFIG_HARDWARE_SENSOR_NTC
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_MAX_NUMBER  ESP_CONFIG_HARDWARE_ADC_MAX_NUMBER
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_DEFAULT_NUMBER 0
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_DEFAULT_INTERVAL 60000
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_DEFAULT_CORRECTION 0

#define ESP_CONFIG_HARDWARE_FLOAT_PRECISION_0 0
#define ESP_CONFIG_HARDWARE_FLOAT_PRECISION_3 1 // milli
#define ESP_CONFIG_HARDWARE_FLOAT_PRECISION_6 2 // mikro
#define ESP_CONFIG_HARDWARE_FLOAT_PRECISION_9 3 // nano

#define ESP_CONFIG_HARDWARE_SENSOR_NTC_DEFAULT_A 1.129148
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_DEFAULT_A_PRECISION ESP_CONFIG_HARDWARE_FLOAT_PRECISION_3
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_DEFAULT_B 234.125
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_DEFAULT_B_PRECISION ESP_CONFIG_HARDWARE_FLOAT_PRECISION_6
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_DEFAULT_C 87.6741
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_DEFAULT_C_PRECISION ESP_CONFIG_HARDWARE_FLOAT_PRECISION_9
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_DEFAULT_RESISTOR 10000
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_DEFAULT_VCC 5
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_DEFAULT_UNIT ESP_CONFIG_FUNCTIONALITY_TEMPERATURE_UNIT_CELSIUS
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_FILE_NAME "/cfg-sensor-ntc-%d.json"
#define ESP_CONFIG_HARDWARE_SENSOR_NTC_FILE_BUFFER 500
#endif // ESP_CONFIG_HARDWARE_SENSOR_NTC

#ifdef ESP_CONFIG_FUNCTIONALITY_BATTERYMETER
#define ESP_CONFIG_HARDWARE_BATTERYMETER_MAX_NUMBER ESP_CONFIG_HARDWARE_ADC_MAX_NUMBER
#define ESP_CONFIG_HARDWARE_BATTERYMETER_DEFAULT_NUMBER 0
#define ESP_CONFIG_HARDWARE_BATTERYMETER_DEFAULT_INTERVAL 60000
#define ESP_CONFIG_HARDWARE_BATTERYMETER_DEFAULT_MIN_VOLTAGE 3
#define ESP_CONFIG_HARDWARE_BATTERYMETER_DEFAULT_MAX_VOLTAGE 4.2
#define ESP_CONFIG_HARDWARE_BATTERYMETER_FILE_NAME "/cfg-batterymeter-%d.json"
#define ESP_CONFIG_HARDWARE_BATTERYMETER_FILE_BUFFER 300
#endif // ESP_CONFIG_FUNCTIONALITY_BATTERYMETER

#ifdef ESP_CONFIG_HARDWARE_SENSOR_ACS758

#define ESP_CONFIG_HARDWARE_SENSOR_ACS758LCB_050B 0
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758LCB_050U 1
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758LCB_100B 2
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758LCB_100U 3
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758KCB_150B 4
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758KCB_150U 5
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758ECB_200B 6
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758ECB_200U 7

#define ESP_CONFIG_HARDWARE_SENSOR_ACS758_TEMP_LOW_OFFSET 0
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758_TEMP_25_OFFSET 1
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758_TEMP_HIGH_OFFSET 2

#define ESP_CONFIG_HARDWARE_SENSOR_ACS758_MAX_NUMBER 4
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758_DEFAULT_NUMBER 0
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758_DEFAULT_INTERVAL 60000
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758_DEFAULT_TYPE ESP_HARDWARE_ITEM_NOT_EXIST
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758_DEFAULT_VCC 5
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758_DEFAULT_CURRENT_CUT_OFF 1 // Amper
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758_FILE_NAME "/cfg-sensor-asc758-%d.json"
#define ESP_CONFIG_HARDWARE_SENSOR_ACS758_FILE_BUFFER 200

#endif // ESP_CONFIG_HARDWARE_SENSOR_ACS758

#define ESP_CONFIG_NETWORK_DCHP 1
#define ESP_CONFIG_NETWORK_CONNECTION_ATTEMPTS 10
#define ESP_CONFIG_NETWORK_TIME_BETWEEN_CONNECTION_ATTEMPTS 1 // seconds
#define ESP_CONFIG_NETWORK_SLEEP_TIME_BETWEEN_FAILED_CONNECTION_ATTEMPTS  5 // seconds
#define ESP_FILE_NETWORK_CONFIGURATION "/cfg-network.json"
#define ESP_CONFIG_FILE_BUFFER_NETWORK 300
#define ESP_CONFIG_NETWORK_DEFAULT_SWITCH_NETWORK_AFTER 2
#define ESP_CONFIG_NETWORK_DEFAULT_NONE_SSID "<nOOn>"


/* Config sites IDs */
#define ESP_CONFIG_SITE_INDEX 0
#define ESP_CONFIG_SITE_INDEX_CONFIGURATION 1
#define ESP_CONFIG_SITE_EXIT 2
#define ESP_CONFIG_SITE_RESET 3
#define ESP_CONFIG_SITE_POST_RESET 4
#define ESP_CONFIG_SITE_FIRST_TIME 5
#define ESP_CONFIG_SITE_FIRST_TIME_CONNECTING 6
#define ESP_CONFIG_SITE_UPGRADE 7
#define ESP_CONFIG_SITE_POST_UPGRADE 8
#define ESP_CONFIG_SITE_DEVICE 9
#define ESP_CONFIG_SITE_NETWORK 10
#define ESP_CONFIG_SITE_LED 11
#define ESP_CONFIG_SITE_SWITCH 12
#define ESP_CONFIG_SITE_I2C 13
#define ESP_CONFIG_SITE_UART 14
#define ESP_CONFIG_SITE_ADC 15
#define ESP_CONFIG_SITE_BINARY_SENSOR 16
#define ESP_CONFIG_SITE_DS18B20_SENSOR 17
#define ESP_CONFIG_SITE_NTC_SENSOR 18
#define ESP_CONFIG_SITE_BATTERYMETER 19
#define ESP_CONFIG_SITE_ACS758 20
#define ESP_CONFIG_SITE_SYSTEM_LED 21

/* Form constants */
#define ESP_FORM_ITEM_TYPE_NUMBER "number"
#define ESP_FORM_ITEM_TYPE_TEXT "text"
#define ESP_FORM_ITEM_SKIP_PROPERTY "?"
#define ESP_FORM_ITEM_TYPE_PASSWORD "password"

/* Configuration files names */
#define ESP_FILE_DEVICE_MODE "/cfg-device-mode.json"
#define ESP_FILE_DEVICE_CONFIGURATION "/cfg-device.json"

#define ESP_CONFIG_FILE_BUFFER_DEVICE_MODE 31
#define ESP_CONFIG_FILE_BUFFER_DEVICE 405

#endif // _ESP_Configuration_h
