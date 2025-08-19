# 4-Wheel Line Following Robot

An Arduino-based autonomous line following robot designed for competitive racing and educational purposes. This project demonstrates advanced robotics concepts including PID control, sensor fusion, obstacle avoidance, and differential drive navigation.

**Video Demo:** [Watch the robot in action](https://www.youtube.com/watch?v=uRDj3uBrsaU)

## Project Overview

This project represents my complete understanding and implementation of advanced robotics concepts. Every library, algorithm, and control logic was personally developed, written, and tested by me through extensive experimentation and iterative development.

## Key Features

- **4-Wheel Differential Drive**: Precise control with independent motor control
- **Advanced Line Following**: BFD-1000 5-channel IR sensor array with custom PID control algorithm
- **Obstacle Avoidance**: Personal ultrasonic sensor integration and avoidance logic
- **Encoder Feedback**: Custom H206 encoder reading and calculation algorithms
- **Kalman Filtering**: Personal sensor noise reduction implementation
- **Modular Design**: Easy component mounting and maintenance
- **Competition Ready**: Optimized for line following competitions through personal testing and tuning

## Hardware Components

| Component | Model | Purpose |
|-----------|-------|---------|
| **Microcontroller** | Arduino UNO | Main control unit |
| **Line Sensor** | BFD-1000 | 5-channel IR tracking module |
| **Motors** | 4x DC Motors | Differential drive system |
| **Motor Driver** | L298N H-bridge | Motor control and direction |
| **Distance Sensors** | HC-SR04 Ultrasonic | Obstacle detection |
| **Encoders** | H206 | Position and speed feedback |
| **Chassis** | Acrylic | Lightweight and modular design |
| **Power** | External Battery Pack | Barrel jack connection |

## Project Structure

```
main/
├── main.ino                    # Main robot program (100% custom written by me)
├── libraries/                   # Custom Arduino libraries
│   ├── BFD1000/               # Line sensor library
│   ├── PID Calculation/       # PID control algorithms
│   ├── Test encoder lib/      # Encoder testing
│   ├── Test LF sensor/        # Line sensor testing
│   ├── Test motor/            # Motor driver testing
│   ├── Test obstacle avoidance/ # Obstacle avoidance testing
│   └── Ultrasonic - Measuring distance/ # Distance measurement
├── 3d_models/                 # 3D printable parts
│   ├── adjusting pad v1.stl   # Sensor adjustment mount
│   └── BFD1000 pad v1.stl     # Line sensor mount
└── docs/                      # Documentation and schematics
```

## Personal Development Work

**All libraries and algorithms in this project were personally developed, written, and tested by me.** This includes:

### Libraries
- **Motor_Driver.h/cpp**: L298N motor driver control library
- **LFsensor.h/cpp**: BFD-1000 line sensor interface library
- **Encoder_Read.h/cpp**: H206 encoder reading and calculations library
- **Ultrasonic.h/cpp**:  HC-SR04 ultrasonic sensor control library
- **SimpleKalmanFilter.h/cpp**: sensor noise filtering implementation

### Control Algorithms (Personally Developed)
- **PID Control**: Custom PID algorithm written, tested, and fine-tuned through experimentation
- **Obstacle Avoidance**: Personal obstacle detection and avoidance logic
- **Encoder-Based Navigation**: Custom distance and angle calculation algorithms
- **State Management**: Complete state machine for robot operating modes

### Development Process
Every algorithm, library function, and control logic was:
1. Designed from scratch based on component datasheets
2. Written entirely by me in C++ for Arduino
3. Tested through extensive experimentation with real hardware
4. Fine-tuned through iterative development and performance optimization
5. Integrated into a complete system through systematic testing

## Main Program Development

### main.ino - My Complete Robot Control System
This main Arduino program represents my complete understanding and implementation of:

- **Complete State Machine**: All robot operating modes (line following, obstacle avoidance, turning, etc.)
- **PID Control Integration**: My custom PID algorithm integrated with motor control
- **Sensor Management**: Coordination of all sensors (line sensors, ultrasonic, encoders)
- **Motor Control Logic**: Integration with my custom motor driver library
- **Interrupt Handling**: Custom encoder interrupt routines for precise position tracking
- **Error Handling**: Robust error detection and recovery mechanisms
## Technical Specifications

### PID Parameters
```cpp
const float Kp = 40;    // Proportional gain
const float Ki = 0;      // Integral gain  
const float Kd = 45;     // Derivative gain
const int init_speed = 200;  // Base speed
const int max_speed = 240;   // Maximum speed
```

### Pin Connections
```cpp
// Motor Driver (L298N)
#define ENA A0, ENB A1
#define IN1 4, IN2 5, IN3 6, IN4 7

// Line Sensors (BFD-1000)
#define S1 9, S2 10, S3 11, S4 12, S5 13

// Ultrasonic Sensors
#define Trig 8, Front A2, Right A4, Left A5

// Encoders
#define leftEncoder 2, rightEncoder 3
```

## Getting Started

### Prerequisites
- Arduino IDE 1.8.x or later
- Arduino UNO board
- Required hardware components (see Hardware Components table)

### Installation
1. Clone this repository
2. Open `main/main.ino` in Arduino IDE
3. Connect hardware according to pin definitions
4. Upload to Arduino UNO

## Personal Achievement

This project represents my complete understanding and implementation of advanced robotics concepts:

- **From Theory to Practice**: Implemented PID control, sensor fusion, and navigation algorithms
- **Hardware Integration**: Successfully integrated multiple sensors and actuators
- **Software Architecture**: Designed modular, maintainable code structure
- **Testing & Optimization**: Fine-tuned performance through extensive experimentation
- **Problem Solving**: Developed solutions for real-world robotics challenges
