# Drowsiness Detection System

An embedded system for detecting drowsiness in drivers, utilizing sensors and a buzzer alert. This project aims to improve road safety by alerting drivers when signs of drowsiness are detected.

## Project Overview

This system is designed to detect drowsiness in drivers and trigger alerts to keep them attentive. It includes an IR sensor for detecting eye closure, an LED indicator, a buzzer for auditory alerts, and is implemented on an Arduino Nano microcontroller.

### Features

- **Drowsiness Detection**: Detects eye closure using an IR sensor.
- **Real-Time Alerts**: Sounds a buzzer and lights an LED when drowsiness is detected.
- **Simulation**: Tested in a virtual environment using Proteus (no physical implementation).

## Components

- **IR Sensor**: Detects eye closure to indicate drowsiness.
- **LED**: Provides a visual alert when drowsiness is detected.
- **Buzzer**: Emits an auditory alert.
- **Arduino Nano**: Microcontroller used to run the system.

## Files in Repository

- **project1.pdsprj**: Proteus project file for simulating the embedded system.
- **sketch_oct24a.ino**: Arduino code file for the drowsiness detection system.
- **sketch_oct24a.ino.hex**: Compiled Arduino code for simulation in Proteus.

## Getting Started

### Requirements

- **Software**: 
  - [Proteus Design Suite](https://www.labcenter.com/) (for simulation)
  - [Arduino IDE](https://www.arduino.cc/en/software) (for compiling and uploading code)
  
- **Hardware** (Optional for real implementation):
  - Arduino Nano
  - IR Sensor
  - LED
  - Buzzer

### Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-username/your-repo-name.git
   cd your-repo-name
