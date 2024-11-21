# Suolaaja - BadUSB HID Attack with Arduino

![](suolaaja.webp)

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Requirements](#requirements)
4. [Installation and Setup](#installation-and-setup)
   - [1. Hardware Setup](#1-hardware-setup)
   - [2. Code Modification](#2-code-modification)
   - [3. Uploading the Code](#3-uploading-the-code)
5. [How to Use](#how-to-use)
6. [Disclaimer](#disclaimer)

---

## Introduction
This script automates the deployment of a Salt Minion to a target machine via a USB HID attack device. It uses the Arduino HID library to simulate keyboard input and execute commands on the target system.

---

## Features
- Automatically opens PowerShell as an administrator.
- Downloads and installs the Salt Minion software.
- Configures the minion to communicate with a predefined Salt Master server.

---

## Requirements
1. **Hardware**: 
   - Arduino-compatible HID device (e.g., Digispark, Arduino Leonardo, etc.).
2. **Software**:
   - Arduino IDE installed on your computer.
   - Required libraries: `Keyboard` and `KeyboardLayout_sv_SE`.

---

## Installation and Setup

### 1. Hardware Setup
- Connect your HID-compatible device (e.g., arduino pro micro) to your computer.

### 2. Code Modification
Before uploading the code, modify the **master IP address** to match your Salt Master server's IP:

```cpp
String masterIP = "127.0.0.1";
```
Replace 127.0.0.1 with your desired Salt Master's IP address. For example:

```
String masterIP = "192.168.1.100";
```

Replace `KeyboardLayout_sv_SE` with target keyboard layout.

### 3. Uploading the Code
- Open the Arduino IDE.
- Select your HID device from **Tools > Board**.
- Select the correct **port** from **Tools > Port**.
- Click **Upload** to flash the script onto the device.

---

## How to Use
1. Connect the programmed HID device to the target machine's USB port.
2. Wait for the device to execute the script automatically (this process takes approximately 10–15 seconds).
3. Verify the Salt Minion installation by checking the master server's status.

---

## Disclaimer
**This project is for educational and authorized testing purposes only.**  
Misuse of this script may violate local, state, or federal laws.  
The author is not responsible for any unauthorized or malicious use of this code.

---



