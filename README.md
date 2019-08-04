# ESP32-MyLog
Log output functions similar to the Arduino-ESP32 log function, but used for application code output only without the system level log output 

# Why?
When enabling the Arduino-ESP32 log output to create log files that is great when you have problems with the Arduino-ESP32 core. But what if you want to have the same log output for your application only? If you use the system log_v, log_d, ... log_e functions you have to enable the Arduino-ESP32 core log levels. And that means your application log output is mixed up with all the core log output.    
With ESP32-MyLog you can have the same log levels and get the same log output format, but with your application logs only, not mixed with the core logs.    
Then you can get a nice log output with only your application logs:
```
[V][main.cpp:24] setup(): =====================================
[V][main.cpp:25] setup(): SX126x ESP32 collector test
[V][main.cpp:26] setup(): =====================================
[V][main.cpp:28] setup(): Version: 1.00
[V][main.cpp:29] setup(): Compiled: Aug  4 2019 18:13:55
[V][main.cpp:30] setup(): SDK version: v3.2.2-44-ga8916daeb
[D][wifi.cpp:86] getPreferences(): Preferences: primary SSID: private pw: unknown secondary SSID: private pw: unknown
[D][wifi.cpp:111] createName(): Device name: PPGcoll-240AC40535E0
[D][wifi.cpp:168] scanWiFi(): Start scanning for networks
[D][wifi.cpp:188] scanWiFi(): Found AP: MHC2 RSSI: -40
[D][wifi.cpp:188] scanWiFi(): Found AP: MyLTE RSSI: -67
[D][wifi.cpp:191] scanWiFi(): Found primary AP
[D][wifi.cpp:198] scanWiFi(): Found secondary AP
[D][wifi.cpp:222] scanWiFi(): RSSI Prim: -67 Sec: -67
[D][wifi.cpp:253] connectWiFi(): Start connection to private
[V][ble.cpp:195] initBLE(): Initialize BLE
[V][lora.cpp:73] initLora(): Starting lora_hardware_init
[V][lora.cpp:84] initLora(): Starting Radio.Init
[V][lora.cpp:86] initLora(): Starting Radio.SetChannel
[V][lora.cpp:88] initLora(): Starting Radio.SetTxConfig
[V][lora.cpp:94] initLora(): Starting Radio.SetRxConfig
[V][lora.cpp:101] initLora(): Starting Radio.Rx
[V][main.cpp:55] setup(): Starting loop
```
As you can see, verbose log level is enabled, I have the same nice format as with the core log functions, but the logs are not mixed up with the core logs.    
Using the core log functions for your application in verbose log level would result in
```
[main.cpp:24] setup(): =====================================
[V][main.cpp:25] setup(): SX126x ESP32 collector test
[V][main.cpp:26] setup(): =====================================
[V][main.cpp:28] setup(): Version: 1.00
[V][main.cpp:29] setup(): Compiled: Aug  4 2019 19:45:04
[V][main.cpp:30] setup(): SDK version: v3.2.2-44-ga8916daeb
[D][wifi.cpp:86] getPreferences(): Preferences: primary SSID: private pw: unknown secondary SSID: private pw: unknown
[D][WiFiGeneric.cpp:337] _eventCallback(): Event: 0 - WIFI_READY
[D][WiFiGeneric.cpp:337] _eventCallback(): Event: 2 - STA_START
[D][wifi.cpp:111] createName(): Device name: PPGcoll-240AC40535E0
[D][wifi.cpp:168] scanWiFi(): Start scanning for networks
[D][WiFiGeneric.cpp:337] _eventCallback(): Event: 0 - WIFI_READY
[D][WiFiGeneric.cpp:337] _eventCallback(): Event: 2 - STA_START
[D][WiFiGeneric.cpp:337] _eventCallback(): Event: 2 - STA_START
[D][WiFiGeneric.cpp:337] _eventCallback(): Event: 1 - SCAN_DONE
[D][wifi.cpp:188] scanWiFi(): Found AP: private RSSI: -44
[D][wifi.cpp:188] scanWiFi(): Found AP: private RSSI: -70
[D][wifi.cpp:191] scanWiFi(): Found primary AP
[D][wifi.cpp:198] scanWiFi(): Found secondary AP
[D][wifi.cpp:222] scanWiFi(): RSSI Prim: -70 Sec: -70
[D][WiFiGeneric.cpp:337] _eventCallback(): Event: 0 - WIFI_READY
[D][WiFiGeneric.cpp:337] _eventCallback(): Event: 2 - STA_START
[D][WiFiGeneric.cpp:337] _eventCallback(): Event: 2 - STA_START
[D][wifi.cpp:253] connectWiFi(): Start connection to private
[V][ble.cpp:195] initBLE(): Initialize BLE
[V][BLEDevice.cpp:453] setPower(): >> setPower: 7
[V][BLEDevice.cpp:458] setPower(): << setPower
[V][BLEDevice.cpp:82] createServer(): >> createServer
[V][BLEServer.cpp:281] registerApp(): >> registerApp - 0
[D][FreeRTOS.cpp:157] take(): Semaphore taking: name: RegisterAppEvt (0x3ffee1d4), owner: <N/A> for registerApp
[D][FreeRTOS.cpp:166] take(): Semaphore taken:  name: RegisterAppEvt (0x3ffee1d4), owner: registerApp
[V][FreeRTOS.cpp:63] wait(): >> wait: Semaphore waiting: name: RegisterAppEvt (0x3ffee1d4), owner: registerApp for registerApp
[D][BLEDevice.cpp:108] gattServerEventHandler(): gattServerEventHandler [esp_gatt_if: 4] ... Unknown
[V][BLEUtils.cpp:1530] dumpGattServerEvent(): GATT ServerEvent: Unknown
[V][BLEUtils.cpp:1720] dumpGattServerEvent(): dumpGattServerEvent: *** NOT CODED ***
[V][BLEServer.cpp:144] handleGATTServerEvent(): >> handleGATTServerEvent: Unknown
[V][FreeRTOS.cpp:111] give(): Semaphore giving: name: RegisterAppEvt (0x3ffee1d4), owner: registerApp
[V][FreeRTOS.cpp:77] wait(): << wait: Semaphore released: name: RegisterAppEvt (0x3ffee1d4), owner: <N/A>
[V][BLEServer.cpp:271] handleGATTServerEvent(): << handleGATTServerEvent
[V][BLEServer.cpp:285] registerApp(): << registerApp
[V][BLEDevice.cpp:89] createServer(): << createServer
[V][BLEServer.cpp:67] createService(): >> createService - 0000aaaa-ead2-11e7-80c1-9a214cf093
[D][FreeRTOS.cpp:157] take(): Semaphore taking: name: CreateEvt (0x3ffee42c), owner: <N/A> for createService
[D][FreeRTOS.cpp:166] take(): Semaphore taken:  name: CreateEvt (0x3ffee42c), owner: createService
[V][BLEService.cpp:60] executeCreate(): >> executeCreate() - Creating service (esp_ble_gatts_create_service) service uuid: 0000aaaa-ead2-11e7-80c1-9a214cf093
[D][FreeRTOS.cpp:157] take(): Semaphore taking: name: CreateEvt (0x3ffee690), owner: <N/A> for executeCreate
[D][FreeRTOS.cpp:166] take(): Semaphore taken:  name: CreateEvt (0x3ffee690), owner: executeCreate
[V][FreeRTOS.cpp:63] wait(): >> wait: Semaphore waiting: name: CreateEvt (0x3ffee690), owner: executeCreate for executeCreate
[D][BLEDevice.cpp:108] gattServerEventHandler(): gattServerEventHandler [esp_gatt_if: 4] ... Unknown
[V][BLEUtils.cpp:1530] dumpGattServerEvent(): GATT ServerEvent: Unknown
[V][BLEUtils.cpp:1720] dumpGattServerEvent(): dumpGattServerEvent: *** NOT CODED ***
[V][BLEServer.cpp:144] handleGATTServerEvent(): >> handleGATTServerEvent: Unknown
[V][FreeRTOS.cpp:111] give(): Semaphore giving: name: CreateEvt (0x3ffee42c), owner: createService
[V][BLEService.cpp:194] setHandle(): >> setHandle - Handle=0x28, service UUID=0000aaaa-ead2-11e7-80c1-9a214cf093)
[V][BLEService.cpp:200] setHandle(): << setHandle
[V][FreeRTOS.cpp:111] give(): Semaphore giving: name: CreateEvt (0x3ffee690), owner: executeCreate
[V][BLEServer.cpp:271] handleGATTServerEvent(): << handleGATTServerEvent
[V][FreeRTOS.cpp:77] wait(): << wait: Semaphore released: name: CreateEvt (0x3ffee690), owner: <N/A>
[V][BLEService.cpp:76] executeCreate(): << executeCreate
[V][FreeRTOS.cpp:63] wait(): >> wait: Semaphore waiting: name: CreateEvt (0x3ffee42c), owner: <N/A> for createService
[V][FreeRTOS.cpp:77] wait(): << wait: Semaphore released: name: CreateEvt (0x3ffee42c), owner: <N/A>
[V][BLEServer.cpp:83] createService(): << createService
[V][BLEService.cpp:222] addCharacteristic(): >> addCharacteristic()
[D][BLEService.cpp:225] addCharacteristic(): Adding characteristic: uuid=00005555-ead2-11e7-80c1-9a214cf093 to service: UUID: 0000aaaa-ead2-11e7-80c1-9a214cf093, handle: 0x0028
[V][BLEService.cpp:237] addCharacteristic(): << addCharacteristic()
[V][BLECharacteristic.cpp:553] setCallbacks(): >> setCallbacks: 0x3ffeea08
[V][BLECharacteristic.cpp:555] setCallbacks(): << setCallbacks
[V][BLEService.cpp:134] start(): >> start(): Starting service (esp_ble_gatts_start_service): UUID: 0000aaaa-ead2-11e7-80c1-9a214cf093, handle: 0x0028
[V][BLECharacteristic.cpp:78] executeCreate(): >> executeCreate()
[D][BLECharacteristic.cpp:89] executeCreate(): Registering characteristic (esp_ble_gatts_add_char): uuid: 00005555-ead2-11e7-80c1-9a214cf093, service: UUID: 0000aaaa-ead2-11e7-80c1-9a214cf093, handle: 0x0028
[D][FreeRTOS.cpp:157] take(): Semaphore taking: name: CreateEvt (0x3ffee914), owner: <N/A> for executeCreate
[D][FreeRTOS.cpp:166] take(): Semaphore taken:  name: CreateEvt (0x3ffee914), owner: executeCreate
[V][FreeRTOS.cpp:63] wait(): >> wait: Semaphore waiting: name: CreateEvt (0x3ffee914), owner: executeCreate for executeCreate
[D][BLEDevice.cpp:108] gattServerEventHandler(): gattServerEventHandler [esp_gatt_if: 4] ... Unknown
[V][BLEUtils.cpp:1530] dumpGattServerEvent(): GATT ServerEvent: Unknown
[V][BLEUtils.cpp:1720] dumpGattServerEvent(): dumpGattServerEvent: *** NOT CODED ***
[V][BLEServer.cpp:144] handleGATTServerEvent(): >> handleGATTServerEvent: Unknown
[V][BLECharacteristic.cpp:570] setHandle(): >> setHandle: handle=0x2a, characteristic uuid=00005555-ead2-11e7-80c1-9a214cf093
[V][BLECharacteristic.cpp:572] setHandle(): << setHandle
[V][BLECharacteristic.cpp:197] handleGATTServerEvent(): >> handleGATTServerEvent: Unknown
[V][FreeRTOS.cpp:111] give(): Semaphore giving: name: CreateEvt (0x3ffee914), owner: executeCreate
[V][BLECharacteristic.cpp:453] handleGATTServerEvent(): << handleGATTServerEvent
[V][FreeRTOS.cpp:77] wait(): << wait: Semaphore released: name: CreateEvt (0x3ffee914), owner: <N/A>
[V][BLEServer.cpp:271] handleGATTServerEvent(): << handleGATTServerEvent
[V][BLECharacteristic.cpp:115] executeCreate(): << executeCreate
[D][FreeRTOS.cpp:157] take(): Semaphore taking: name: StartEvt (0x3ffee750), owner: <N/A> for start
[D][FreeRTOS.cpp:166] take(): Semaphore taken:  name: StartEvt (0x3ffee750), owner: start
[V][FreeRTOS.cpp:63] wait(): >> wait: Semaphore waiting: name: StartEvt (0x3ffee750), owner: start for start
[D][BLEDevice.cpp:108] gattServerEventHandler(): gattServerEventHandler [esp_gatt_if: 4] ... Unknown
[V][BLEUtils.cpp:1530] dumpGattServerEvent(): GATT ServerEvent: Unknown
[V][BLEUtils.cpp:1720] dumpGattServerEvent(): dumpGattServerEvent: *** NOT CODED ***
[V][BLEServer.cpp:144] handleGATTServerEvent(): >> handleGATTServerEvent: Unknown
[V][FreeRTOS.cpp:111] give(): Semaphore giving: name: StartEvt (0x3ffee750), owner: start
[V][BLECharacteristic.cpp:197] handleGATTServerEvent(): >> handleGATTServerEvent: Unknown
[V][FreeRTOS.cpp:77] wait(): << wait: Semaphore released: name: StartEvt (0x3ffee750), owner: <N/A>
[V][BLECharacteristic.cpp:453] handleGATTServerEvent(): << handleGATTServerEvent
[V][BLEService.cpp:159] start(): << start()
[V][BLEServer.cpp:271] handleGATTServerEvent(): << handleGATTServerEvent
[I][BLEDevice.cpp:560] getAdvertising(): create advertising
[D][BLEDevice.cpp:562] getAdvertising(): get advertising
[V][BLEAdvertising.cpp:177] start(): >> start: customAdvData: 0, customScanResponseData: 0
[D][BLEAdvertising.cpp:189] start(): - advertising service: 0000aaaa-ead2-11e7-80c1-9a214cf093
[V][BLEAdvertising.cpp:237] start(): << start
[V][lora.cpp:73] initLora(): Starting lora_hardware_init
[V][lora.cpp:84] initLora(): Starting Radio.Init
[V][BLEUtils.cpp:1817] gapEventToString(): gapEventToString: Unknown event type 0 0x00
[V][BLEUtils.cpp:1049] dumpGapEvent(): Received a GAP event: Unknown event type
[V][BLEUtils.cpp:1264] dumpGapEvent(): *** dumpGapEvent: Logger not coded ***
[D][BLEDevice.cpp:562] getAdvertising(): get advertising
[D][BLEAdvertising.cpp:491] handleGAPEvent(): handleGAPEvent [event no: 0]
[V][BLEUtils.cpp:1817] gapEventToString(): gapEventToString: Unknown event type 1 0x01
[V][BLEUtils.cpp:1049] dumpGapEvent(): Received a GAP event: Unknown event type
[V][lora.cpp:86] initLora(): Starting Radio.SetChannel
[V][BLEUtils.cpp:1264] dumpGapEvent(): *** dumpGapEvent: Logger not coded ***
[D][WiFiGeneric.cpp:337] _eventCallback(): Event: 4 - STA_CONNECTED
[D][BLEDevice.cpp:562] getAdvertising(): get advertising
[D][BLEDevice.cpp:562] getAdvertising(): get advertising
[D][BLEAdvertising.cpp:491] handleGAPEvent(): handleGAPEvent [event no: 1]
[V][lora.cpp:94] initLora(): Starting Radio.SetRxConfig
[V][BLEUtils.cpp:1817] gapEventToString(): gapEventToString: Unknown event type 6 0x06
[V][lora.cpp:101] initLora(): Starting Radio.Rx
[V][BLEUtils.cpp:1049] dumpGapEvent(): Received a GAP event: Unknown event type
[V][main.cpp:55] setup(): Starting loop
```
When you look close you can see all the application logs inside surrounded by the core logs. Difficult to read.    

And you can mix any core log level with your app log level, e.g. set core log level to **`ARDUHAL_LOG_LEVEL_ERROR`** to see core errors and your app log level to **`MYLOG_LOG_LEVEL_DEBUG`** do see debug output from your app.    

# How?
Include my-log.h in your application. On **ArduinoIDE** you have to copy the file into your **.INO** project folder. In **PlatformIO** you can copy it into the `include` folder or just install this library.

# Usage    
Include **`<my-log.h>`** and in your code use the commands
```
myLog_v()
myLog_d()
myLog_i()
myLog_w()
myLog_e()
myLog_n()
```
the same way you would use the core level functions `log_v() log_d() log_i() log_w() log_e() Log_n()`   
Example:
```
myLog_v("Version: %s", swVersion);
```
to create a log output if the log level is set to verbose.

Available log levels are the same as in the core log functions    
 - NONE    
   - MYLOG_LOG_LEVEL_NONE    
 - ERROR
   - MYLOG_LOG_LEVEL_ERROR
 - WARN
   - MYLOG_LOG_LEVEL_WARN
 - INFO
   - MYLOG_LOG_LEVEL_INFO
 - DEBUG
   - MYLOG_LOG_LEVEL_DEBUG
 - VERBOSE
   - MYLOG_LOG_LEVEL_VERBOSE    
   
### Setup log level in PlatformIO
In the `platformio.ini` file define the log level you want for your application log with `build_flags = -DMYLOG_LOG_LEVEL=MYLOG_LOG_LEVEL_VERBOSE`    
Example:
```
[env:ESP32]
platform = espressif32
board = esp32dev
framework = arduino
build_flags = -DMYLOG_LOG_LEVEL=MYLOG_LOG_LEVEL_VERBOSE
```
to enable verbose logs from your application code. Change ***`MYLOG_LOG_LEVEL_DEBUG`** to the log level you want.

### Setup log level in ArduinoIDE
Edit the file **`my-log.h`** and change the lines 
```
#ifndef MYLOG_LOG_LEVEL
#define MYLOG_LOG_LEVEL MYLOG_LOG_LEVEL_NONE
#endif
```
to
```
//#ifndef MYLOG_LOG_LEVEL
#define MYLOG_LOG_LEVEL MYLOG_LOG_LEVEL_DEBUG
//#endif
```
to enable debug logs from your application code. Change ***`MYLOG_LOG_LEVEL_DEBUG`** to the log level you want.
