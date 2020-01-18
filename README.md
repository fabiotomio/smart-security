# Smart Security System

I'm researched and not founded anyone alarm system with all specs below:
- Easy sensor setup
- Functional mobile app and web interface
- Smart features
  - Automatic turn-on and off
  - Sensor low battery warning (frequency or behavior learning)
- Integrated with Apple Home Kit

The main idea of this project is to develop a simple but functional alarm platform using some DIY boards to resolve all listed points and learn more about IoT.
That is an unambitious project. The focus is to relax and to learn something.

# Hardware
[Espressif TTGO T-Call V1.3 ESP32](https://github.com/Xinyuan-LilyGO/TTGO-T-Call)
433MHz transmitter and receiver
Commercial alarm sensors

# RF
- Wifi
- GSM + GPRS
- 433,92MHz

# Communication
- MQTT
- HTTP

# Roadmap
- API Base + Wifi setup
- MQTT + Google Cloud IoT over Wifi
- GSM + GPRS (connection priority and automatic interchange)
- Attach 433,92MHz receiver module
- Pair new sensor functionality (ENCODER HT6P20B)
- Fire events from the sensor to cloud
- Attach 433,92MHz transmitter module
- Pair new actuators functionality
- Transmit commands over 433,92MHz

# Development environment

- Step 1 - [Install prerequisites](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/macos-setup.html#install-prerequisites)

- Step 2 - [Get ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html#step-2-get-esp-idf)

- Step 3 - [Set up tools](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html#step-3-set-up-the-tools)

- Step 4 - export IDF_PATH=~/esp/esp-idf

- Step 5 - [USB Driver - Silabs](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

# Project interaction
## Config the project
```
make menuconfig
```

## Build
```
make all
```

## Auto Building
```
./watcher.sh
```

## Flash
```
make flash
```

## Serial monitor
```
make monitor
```
(To exit the serial monitor, type ``Ctrl-]``.)

# References
- [HT6P20B](https://acturcato.wordpress.com/2013/12/20/decodificador-para-o-encoder-ht6p20b-em-arduino/)
