# Project Structure Overview

## 📁 Complete File Organization

```
4-Wheel-Line-Following-Robot/
├── README.md                    # Main project documentation
├── QUICKSTART.md               # Quick start guide
├── project_config.md           # Technical configuration details
├── PROJECT_STRUCTURE.md        # This file - project overview
├── Class Diagram.docx          # Original class diagram
├── Midterm Assessment.pdf      # Course assessment document
├── robot.heic                  # Robot image
│
├── src/                        # Main source code
│   ├── line_following_robot.ino    # Main Arduino program
│   ├── Encoder_Read.cpp            # Encoder library implementation
│   ├── Encoder_Read.h              # Encoder library header
│   ├── LFsensor.cpp                # Line sensor library implementation
│   ├── LFsensor.h                  # Line sensor library header
│   ├── Motor_Driver.cpp            # Motor driver library implementation
│   ├── Motor_Driver.h              # Motor driver library header
│   ├── SimpleKalmanFilter.cpp      # Kalman filter implementation
│   ├── SimpleKalmanFilter.h        # Kalman filter header
│   ├── Ultrasonic.cpp              # Ultrasonic sensor library
│   └── Ultrasonic.h                # Ultrasonic sensor header
│
├── src/libraries/              # Testing and development libraries
│   ├── BFD1000/               # Line sensor testing
│   │   └── BFD1000.ino
│   ├── PID Calculation/       # PID control algorithms
│   │   ├── PID Calculation.ino
│   │   ├── PIDcal.cpp
│   │   └── PIDcal.h
│   ├── Test encoder lib/      # Encoder testing
│   │   ├── Encoder_Read.cpp
│   │   ├── Encoder_Read.h
│   │   └── Test encoder lib.ino
│   ├── Test LF sensor/        # Line sensor testing
│   │   └── sketch_nov13c/
│   │       ├── LFsensor.cpp
│   │       ├── LFsensor.h
│   │       └── sketch_nov13c.ino
│   ├── test motor/            # Motor driver testing
│   │   └── test motor.ino
│   ├── Test obstacle avoidance/ # Obstacle avoidance testing
│   │   ├── Encoder_Read.cpp
│   │   ├── Encoder_Read.h
│   │   ├── Motor_Driver.cpp
│   │   ├── Motor_Driver.h
│   │   ├── SimpleKalmanFilter.cpp
│   │   ├── SimpleKalmanFilter.h
│   │   ├── Test obstacle avoidance.ino
│   │   ├── Ultrasonic.cpp
│   │   └── Ultrasonic.h
│   ├── Test ultrasonic lib/   # Ultrasonic testing
│   │   ├── Test ultrasonic lib.ino
│   │   ├── Ultrasonic.cpp
│   │   └── Ultrasonic.h
│   ├── Turning angles/        # Turning angle testing
│   │   └── Turning angles.ino
│   └── Ultrasonic - Measuring distance/ # Distance measurement
│       └── Measuring distance/
│           ├── Measuring distance.ino
│           ├── UTSN_MeasDist.cpp
│           └── UTSN_MeasDist.h
│
├── src/3d_models/             # 3D printable parts
│   ├── adjusting pad v1.stl   # Sensor adjustment mount
│   ├── adjusting pad v1_0.15mm_PLA_MK3S_24m.gcode
│   ├── BFD1000 pad v1.stl     # Line sensor mount
│   └── BFD1000 pad v1_0.15mm_PLA_MK3S_1h4m.gcode
│
└── docs/                      # Additional documentation
    └── (future documentation files)
```

## 🔄 File Renaming Summary

### Original → New Names
- `Main_program.ino` → `line_following_robot.ino`
- `Main_program/` → `src/` (main source code)
- `Arduino Libs - Robot Studio/` → `src/libraries/`
- `3Dparts_LineFollowingSensor/` → `src/3d_models/`

### Key Benefits of New Structure
1. **Clear Separation**: Source code, libraries, and 3D models are clearly organized
2. **Standard Naming**: Follows common Arduino project conventions
3. **Easy Navigation**: Logical grouping of related files
4. **Professional Appearance**: Suitable for GitHub and portfolio use

## 📚 Library Organization

### Core Libraries (in src/)
These are the main libraries used by the robot:
- **Motor_Driver**: Controls L298N motor driver
- **LFsensor**: Interfaces with BFD-1000 line sensor
- **Encoder_Read**: Handles H206 encoder readings
- **Ultrasonic**: Manages HC-SR04 sensors
- **SimpleKalmanFilter**: Reduces sensor noise

### Testing Libraries (in src/libraries/)
These are for development and testing:
- **BFD1000**: Line sensor testing and calibration
- **PID Calculation**: PID algorithm development
- **Test encoder lib**: Encoder functionality testing
- **Test LF sensor**: Line sensor testing
- **test motor**: Motor driver testing
- **Test obstacle avoidance**: Obstacle avoidance testing
- **Test ultrasonic lib**: Ultrasonic sensor testing
- **Turning angles**: Turning precision testing

## 🎯 Usage Guidelines

### For End Users
1. Use files in `src/` for the main robot
2. Refer to `README.md` for setup instructions
3. Use `QUICKSTART.md` for quick setup
4. Check `project_config.md` for technical details

### For Developers
1. Use `src/libraries/` for component testing
2. Modify main code in `src/line_following_robot.ino`
3. Test individual components before integration
4. Use provided test libraries for debugging

### For Educators
1. Use as a complete robotics project example
2. Demonstrate PID control implementation
3. Show sensor fusion techniques
4. Illustrate modular software design

## 🚀 GitHub Repository Structure

This structure is optimized for GitHub with:
- Clear documentation at the top level
- Organized source code in `src/`
- Comprehensive testing libraries
- 3D models for hardware reproduction
- Professional README and guides

## 📝 Maintenance Notes

- Keep original files as backup until new structure is verified
- Update documentation when modifying code
- Test all components after any changes
- Maintain consistent naming conventions
- Version control all changes
