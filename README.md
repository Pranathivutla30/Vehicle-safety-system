#  Vehicle Safety System Using IoT Sensors

An IoT-based system designed to enhance vehicle safety through intelligent sensing and automated response. This project integrates real-time alcohol detection, fire and obstacle sensing, GPS/GSM alerts, and remote communication for proactive accident prevention.

---

##  Project Summary

With road accidents caused by drunk driving and mechanical failures on the rise, this system offers a **proactive solution**. It combines **MQ-2 gas sensors, IR sensors, fire detection**, and **GSM/GPS modules** using **NodeMCU (ESP8266)** to create a **multi-layered vehicle safety platform**.

Key Features:
- Real-time **alcohol detection** at the steering
- **Fire sensing** in engine compartment
- **Obstacle and object detection** using IR
- Automated **SMS alerts** to family and authorities with live GPS location
- **LCD and buzzer** feedback for driver alerts

---

##  Repository Files

| File | Description |
|------|-------------|
| [`final ppt.pptx`](./final%20ppt.pptx) | Final project presentation |
| `sp.c` | Embedded C code for UART communication (optional microcontroller support) |
| `README.md` | This file |

---

##  System Components

###  Hardware:
- NodeMCU (ESP8266)
- MQ-2 Alcohol Sensor
- IR Obstacle Detection Sensor
- Fire (Flame) Sensor
- GPS Module
- GSM Module
- Buzzer + LCD Display
- Motor (Ignition lock simulation)

###  Software:
- Arduino IDE
- Embedded C (for UART)
- GSM/GPS libraries
- Serial and sensor libraries for ESP8266

---

##  How It Works

- If **alcohol** is detected above threshold, vehicle **ignition is cut**, buzzer sounds, and a **message is sent** via GSM.
- If **fire or extreme heat** is detected, the system **triggers alarms** and sends the vehicle’s location to emergency contacts.
- If the IR sensor detects **objects or obstacles**, warnings are given to the driver via display and buzzer.
- A **buzzer and LCD** give real-time feedback in the vehicle.
- The **system continuously monitors and sends alerts** over GSM and logs location with GPS.

---

##  Evaluation Metrics

| Feature | Metric |
|--------|--------|
| Alcohol Detection | Sensitivity, specificity vs. BAC threshold |
| Fire Detection | Response time in simulated scenarios |
| Object Detection | Detection rate, false positives |
| Communication | SMS delivery success rate |
| Alert System | Driver reaction time, user feedback |
| System Robustness | Environmental testing under heat, humidity |

---

##  Advantages

- Prevents drunk driving with automatic lock mechanism
- Early fire and hazard detection
- Real-time tracking and alert system via GSM/GPS
- Cost-effective implementation for real-world use
- Enhances overall vehicle security and passenger safety

---

##  Proposed Enhancements

-  Add AI for driver behavior prediction  
-  Integrate V2X communication for smart traffic systems  
-  Solar-powered sensors for energy efficiency  
-  Augmented Reality HUD for hazard overlays  
-  Sensor fusion using neural networks  

---

##  Reference Technologies

- NodeMCU (ESP8266)
- MQ-2, IR, and Flame sensors
- GSM/GPS modules
- Arduino-compatible IDEs
- IEEE research methodology

---

##  Authors

**Lakshmi Pranathi Vutla**,  
Dept. of Computer Science and Engineering (IoT)  
Visvodaya Engineering College, Kavali  
 [pranathiv23@gmail.com](mailto:pranathiv23@gmail.com)

**Guide:** Mr. SK. Shabbir Basha (Associate Professor)  
 [shabbirbasha.sk@visvodayata.ac.in](mailto:shabbirbasha.sk@visvodayata.ac.in)

---

##  Conclusion

This integrated safety system demonstrates how IoT technology can revolutionize vehicle safety. By detecting threats in real time, alerting users, and interacting with emergency services, it enhances both **driver security and public safety**.

---

## ⭐ Show Your Support

If you find this project useful, give it a ⭐ star, fork it, or share your feedback to help us improve further!
