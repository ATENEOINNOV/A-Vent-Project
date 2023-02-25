# Overview
Ateneo ventilator (A-vent) project is a low-cost and intelligent mechanical ventilator was developed under [Ateneo Innovation Center](https://www.ateneoinnovation.org/) (AIC) at [Ateneo de Manila University](https://www.ateneo.edu/) started during the peak of COVID-19 pandemic. The project development consist of 3 phases, the following are:
* **Phase 1** Design and development of intelligent A-vent unit
* **Phase 2** Modular alarm: real-time detection of PVA (patient-ventilator asynchrony) and machine problems
* **Phase 3** Wireless real-time monitoring: applied IoT (Internet of Things), digital twin of A-vent

## Phase 1
COVID-19 pandemic is a respiratory diseas resulted in high demand for mechanical ventilator. During the peak of pandemic, the healthcare provider around the world overwhelmed the healthcare system and lacks with mechanical ventilator unit for critically ill COVID-19 patients. The alternative solution for the ventilator demand is to use an open-source based ventilator machine was first introduced by [MIT emergency ventilator](https://emergency-vent.mit.edu/). The pandemic opens a new opportunity for institutions, and organizations worldwide to developed a low-cost ventilator machine, and the AIC was one of the respondent to that situation.

<img src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/avent%201.1.jpg" width="18%"></img>  <img 
src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/avent%201.2.jpg" width="18%"></img>  <img 
src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/avent%201.3.jpg" width="18%"></img>  <img 
src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/avent%201.4.jpg" width="18%"></img>  <img 
src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/avent%201.5.jpg" width="18%"></img>

A-vent was designed and development through the leadership of Engr. [Paul M. Cabacungan](https://2012.ateneo.edu/ls/sose/ateneo-innovation-center/faculty/paul-m-cabacungan) - AIC Operation Manager together with Mr. Reymond Cao and research assistant. The initial developement was made of easily available food-grade and low-cost materials, and enough to demonstrated a minimum viable prototype. Upon with the 1st development phase, we published a paper titled [*Design and Development of A-vent: A Low-Cost Ventilator with Cost-Effective Mobile Cloud Caching and Embedded Machine Learning*](https://ieeexplore.ieee.org/document/9550920). This paper demonstrate the A-vent minimum viable prototype and integration of AIC technologies such Mobile/Near Cloud Computing, and Machine Learning that predicts the type of PVA as proof of concept.

## Phase 2
The A-vent unit was modified and made it smaller for transportation ease of the unit and designed with touch screen HMI (human machine interface). This development phase emphasized the application of [embedded machine learning (TinyML)](https://www.tinyml.org/) to detect the PVA and machine problems to generate a real-time alarms for intelligent monitoring of machine-and-patient interaction.

<img src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/avent%202.1.jpg" width="15%"></img> <img src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/avent%202.2.jpg" width="15%"></img> <img src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/avent%202.3.jpg" width="15%"></img> <img src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/avent%202.4.jpg" width="15%"></img> <img src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/avent%202.5.jpg" width="15%"></img> <img src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/avent%202.6.jpg" width="15%"></img> 

The idea of the A-vent development phase was shift to the creation a modular alarm device can be suitable for any ventilator machines. The modular alarm device for open-source ventilator was first demonstrated by Illinois University, the project called [Illinois RapidAlarm](https://rapidvent.grainger.illinois.edu/rapidalarm). The Illinois RapidAlarm[[1](https://rapidalarm.github.io/#!index.md)] is a sensor and alarm module for use with emergency pressure-cycled ventilators such as the Illinois RapidVent that do not have built-in monitoring systems. The module connects to a ventilator circuit and monitors the pressure delivered to the patient airway. It produces an audible alarm when it detects a problem with the ventilator, such as a disconnection or obstruction, and also displays information about airway pressure and breathing rate. They published IEEE paper, [*Low-Complexity System and Algorithm for an Emergency Ventilator Sensor and Alarm*,](https://ieeexplore.ieee.org/document/9184284) reports the team’s work to build a low-cost, easy-to-produce electronic sensor and alarm system for pressure-cycled ventilators. The devices estimate clinically useful metrics, such as pressure and respiratory rate, and sound an alarm when the ventilator malfunctions.

The same algorithm was applied to A-vent alarm system, not only for pressure cycle, and flow rate, also applied for tidal volume alarm. Moreover, we added the applied Artificial Intelligence called TinyML for the recognition of PVA and machine problems with anomaly detection that will generate alarm in such event. This intelligent monitoring of mechanical ventilator will help hospital to monitor the critically-ill patients in real-time and assist healthcare workers that may reduce their workload. We presented a paper titled *Waveform Tracker Alarm for Automatic Patient-Ventilator Asynchrony (PVA) and Mechanical State Recognition for Mechanical Ventilators Using Embedded Deep Learning* at 11th [ICMCE (International Conference on Mechatronics and Control Engineering)](http://www.icmce.org/) 2023. In this paper, we demonstrated the detection of various type of PVA and machine problems, the event was emulated and generate an alarm signal in near real-time due to possitive alarm sequencing that avoid triggering of false alarm.

<img src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/PVA%20alarm.png" width="45%"></img> <img src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/Machine%20alarm.png" width="45%"></img>

## Phase 3
In this development phase is the application of wireless sensor network, and IoT combined with the intelligent alarm device. It demonstrate a digital replica of the system through a remote dashboard called Digital Twin. It stored the data on the local server database and display the ventilator waveform and diagnosis on the web dashboard that can be access through a WLAN (wireless local area network).

<img src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/avent%203.1.jpg" width="45%"></img> <img src="https://github.com/TronixLab/A-Vent-Project/blob/main/media/dashboard.png" width="45%"></img>

The dashboard consist of place holder images that represent the physical system. This this way, the data on the dashboard can be easily comprehended and to interpret. TinyML approach for ventilator machine alarm system demonstrated an decentralized processing or edge computing of the data, ensure the real-time operation for time-constrained applications are critical for medical devices.

# Main Components (Phase 2/3)
* [ESP32 DevKit Board](https://circuit.rocks/esp32-wifi-ble.html)
* [MPX5010DP Differential Pressure Sensor](https://www.digikey.com/en/products/detail/nxp-usa-inc/MPX5010DP/464054)
* [SFM3300 Sensirion Flow Meter](https://www.digikey.ph/en/products/detail/sensirion-ag/SFM3300-250-D/9857673)
* [4-Channel 16-bit Analog-to-Digital Converter Module](https://circuit.rocks/adc-16-bit-4-channel-ads1115-with-programmable-gain-amplifier)
* [4-Channel Logic Level Bidirectional Converter (3.3V/5V)](https://circuit.rocks/logic-converter-4-chanel-5v-3v)

# Schematic Diagram
![Schematic Diagram](https://github.com/TronixLab/A-Vent-Project/blob/main/media/Schematic%20Diagram.png)

# Dependencies
## Documentation
Prior to the replication of the prototype, it is important to read and study the following documentation for your reference.
* [Getting Started with ESP32](https://github.com/TronixLab/DOIT_ESP32_DevKit-v1_30P)
* [ESP32 Real-Time Operating System (FreeRTOS)](https://github.com/TronixLab/introduction-to-rtos)
* [MPX2010DP](https://github.com/TronixLab/MPX2010DP)
* [SFM3300](https://github.com/TronixLab/SFM3300)
* [BLE Fingertip Pulse Oximeter](https://github.com/TronixLab/BLE-Fingertip-Pulse-Oximeter-Jumper-Medical-)

## Arduino Libraries
See Arduino Documentation for [Installing Libraries](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries). Add the following libraries to your Arduino IDE.
* [PubSubClient](https://github.com/knolleary/pubsubclient)
* [ArduinoJson](https://github.com/bblanchon/ArduinoJson)
* [Adafruit_ADS1X15](https://github.com/adafruit/Adafruit_ADS1X15)
* [MovingAverageFloat](https://github.com/pilotak/MovingAverageFloat)
* [A-Vent_PVA_Detection_inferencing](https://github.com/TronixLab/A-Vent-Project/blob/main/libraries/ei-a-vent-pva-detection-arduino-1.0.6.zip)

## Software
The following software needed to install are:
* [Arduino IDE](https://docs.arduino.cc/software/ide-v1)
* [Eclipse Mosquitto MQTT Broker](https://mosquitto.org/)
* 

