# Autonomous-Green-House-Maintenance
Smart greenhouse system built with ESP32, MQTT, DHT11, LDR, and soil moisture sensors for real-time monitoring, automated irrigation, and climate control.

## Overview
This project presents an IoT-based smart greenhouse monitoring and control system designed to automate key environmental parameters required for healthy plant growth. The system monitors temperature, humidity, soil moisture, and light intensity using sensors connected to an ESP32 microcontroller. It uses MQTT communication through HiveMQ for real-time data transmission and remote monitoring, while an HTML-based interface allows users to observe sensor values and control actuators easily.

The system was developed using two greenhouse compartments:
- **Greenhouse 1** for soil moisture and humidity control
- **Greenhouse 2** for temperature, humidity, and light intensity monitoring

The goal of this project is to reduce manual effort, improve resource efficiency, and support sustainable agriculture through automation.

---

## Features
- Real-time monitoring of:
  - Temperature
  - Humidity
  - Soil moisture
  - Light intensity
- Automated humidity control using a humidifier
- Soil moisture-based irrigation decision support
- Light intensity monitoring using an LDR sensor
- ESP32-based data processing and control
- MQTT-based communication using HiveMQ
- Remote access and monitoring
- HTML-based user interface for visualization and control
- OLED output for local sensor status display
- Two separate greenhouse environments for targeted parameter management

---

## Objectives
- Automate greenhouse monitoring using low-cost IoT hardware
- Reduce water waste through soil moisture monitoring
- Improve humidity regulation for better plant growth
- Optimize energy usage through dynamic light monitoring
- Enable remote greenhouse supervision and control

---

## System Architecture
The smart greenhouse system is centered around the **ESP32 microcontroller**, which reads sensor data, processes it based on threshold conditions, and communicates with the MQTT broker.

### Data flow
1. Sensors collect environmental data
2. ESP32 processes the data
3. Data is sent to HiveMQ via MQTT
4. User views readings through the HTML dashboard
5. Actuators are triggered automatically or manually depending on conditions

### Greenhouse compartments
#### Greenhouse 1
- DHT11 sensor
- Capacitive soil moisture sensor
- Humidifier

This compartment is focused on maintaining proper soil moisture and humidity conditions.

#### Greenhouse 2
- DHT11 sensor
- LDR sensor

This compartment is focused on monitoring temperature, humidity, and light intensity for plants needing better light regulation.

---

## Hardware Components
- ESP32 microcontroller
- DHT11 temperature and humidity sensor
- LDR module
- Capacitive soil moisture sensor
- USB humidifier / atomizer
- OLED display
- Breadboard / copper PCB
- Jumper wires
- 5V power supply

---

## Software and Technologies Used
- Arduino IDE
- Embedded C/C++ for ESP32 programming
- MQTT protocol
- HiveMQ broker
- HTML for local dashboard interface
- Wi-Fi communication
- OLED display integration

---

## Working Principle

### Temperature and Humidity Monitoring
The DHT11 sensor is used to monitor temperature and humidity inside the greenhouse compartments. These readings are continuously collected and transmitted through the ESP32.

### Soil Moisture Monitoring
The capacitive soil moisture sensor measures the water content in soil. Based on the observed values, the system identifies whether the soil condition is:
- **Below 40%**: Too much moisture
- **40% to 60%**: Good moisture
- **Above 60%**: Poor moisture / irrigation needed

### Humidity Control
The humidifier is automatically switched on when the humidity falls below the desired level. This helps maintain greenhouse humidity in the optimal range for plant growth.

### Light Intensity Monitoring
The LDR module is used to detect the ambient light level. When the light intensity condition indicates the greenhouse is too dark, the system can support light-related decision making or future automated lighting control.

### Remote Monitoring
The ESP32 sends real-time sensor values to the HiveMQ MQTT broker via Wi-Fi. These values can then be visualized remotely through the HTML-based interface.

---

## Control Logic

### Humidity threshold
- Humidity target range: **70% - 80%**
- Humidifier activates when humidity drops below the defined threshold

### Soil moisture classification
- **< 40%**: Too much moisture
- **40% - 60%**: Good
- **> 60%**: Poor moisture / needs irrigation

### LDR behavior
- High percentage values indicate lower light intensity
- When LDR percentage goes above **70%**, the condition is treated as **too dark**
- Bright exposure causes the reading to drop significantly

---

## MQTT Communication
The system uses **HiveMQ** as the MQTT broker to support lightweight and real-time communication between the ESP32 and the user interface.

### MQTT is used for:
- Publishing sensor readings
- Receiving control commands
- Enabling remote monitoring
- Supporting real-time greenhouse management

### Example topic structure
You can customize these based on your code:

```text
greenhouse1/temperature
greenhouse1/humidity
greenhouse1/soil_moisture
greenhouse2/temperature
greenhouse2/humidity
greenhouse2/light
greenhouse/control/humidifier
greenhouse/control/irrigation
