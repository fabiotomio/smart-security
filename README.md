# Smart Security System

I'm looked and not founded anyone alarm system with specification below:
- Easy setup
- Great and functional mobile app and web interface
- Smart features
  - Automatic turn-on and off
  - Sensor low battery warning (frequency or behavior learning)
- Integrated with Apple Home Kit

The main idea of this project is to develop a simple but functional alarm platform using some DIY boards to resolve all listed points and learn more about IoT.

# Hardware
Espressif TTGO T-Call V1.3 ESP32
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
