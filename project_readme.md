# Automatic Fire-Fighting Robot Using Arduino

An autonomous, low-cost robotics project designed to detect and extinguish fires in real-time, minimizing risks to human operators in hazardous environments. Developed as part of coursework at Green University of Bangladesh.

---

## 🚀 Features
* **Autonomous Fire Detection:** Uses three flame sensors (Left, Center/Forward, Right) to scan and locate fire sources.
* **Smart Navigation:** Equipped with DC motors and an L293D motor driver to move toward flames accurately.
* **Automated Suppression:** Automatically halts the robot, activates a water pump mechanism via a relay/driver module, and sweeps a servo-mounted nozzle to extinguish the fire.
* **Real-Time Response:** Built on an Arduino UNO platform for rapid execution.

---

## 🛠️ Hardware Components
* **Microcontroller:** Arduino UNO Board
* **Sensors:** 3x IR Flame Sensor Modules (Left, Forward, Right)
* **Mobility:** 4x DC Motors, 4x Wheels, L293D Motor Driver Module
* **Fire Suppression:** Mini DC Water Pump, Relay Module / L293D Driver, Micro Servo Motor (SG90)
* **Power Supply:** 7.4V–9V (18650 Li-ion Battery Pack)
* **Miscellaneous:** Jumper wires, breadboard, water reservoir/tank, tubing

---

## 📐 Pin Connections

| Component | Arduino Pin |
| :--- | :--- |
| **Forward Flame Sensor** | Digital Pin `8` |
| **Left Flame Sensor** | Digital Pin `9` |
| **Right Flame Sensor** | Digital Pin `10` |
| **Left Motor (`LM1`, `LM2`)** | Digital Pins `2`, `3` |
| **Right Motor (`RM1`, `RM2`)** | Digital Pins `4`, `5` |
| **Water Pump / Relay** | Digital Pin `6` |
| **Nozzle Servo Motor** | PWM Pin `11` |

*(Note: Refer to your circuit diagrams in the project report for detailed power and ground connections.)*

---

## 💻 Software & Installation
1. **Programming Environment:** Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. **Required Libraries:** `<Servo.h>` (built-in with Arduino IDE).
3. **Upload Steps:**
   * Open `fire_fighting_robot.ino` in the Arduino IDE.
   * Connect your Arduino UNO via USB.
   * Select **Board: Arduino Uno** and the appropriate **Port** under the `Tools` menu.
   * Click **Upload**.

---

## 🧪 Testing & Results
* Tested in controlled environments with varying flame distances and low-light conditions.
* Successfully detected small flames, navigated toward the fire source, and swept the water nozzle to suppress the fire.

---

## 👥 Author
* **Kamrul Hassan** (ID: 221902345)
* Department of Computer Science and Engineering, Green University of Bangladesh
* Course: CSE-304 (Microprocessors and Microcontrollers Lab)