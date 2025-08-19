# Project Configuration

## Pin Definitions

### Motor Driver (L298N)
```cpp
#define ENA A0    // Left motor speed control
#define ENB A1    // Right motor speed control
#define IN1 4     // Left motor direction 1
#define IN2 5     // Left motor direction 2
#define IN3 6     // Right motor direction 1
#define IN4 7     // Right motor direction 2
```

### Line Sensors (BFD-1000)
```cpp
#define S1 9      // Leftmost sensor
#define S2 10     // Left sensor
#define S3 11     // Center sensor
#define S4 12     // Right sensor
#define S5 13     // Rightmost sensor
```

### Ultrasonic Sensors
```cpp
#define Trig 8    // Trigger pin (shared)
#define Front A2  // Front sensor echo
#define Right A4  // Right sensor echo
#define Left A5   // Left sensor echo
```

### Encoders
```cpp
#define leftEncoder 2   // Left wheel encoder
#define rightEncoder 3  // Right wheel encoder
```

## Control Parameters

### PID Control
```cpp
const float Kp = 40;           // Proportional gain
const float Ki = 0;            // Integral gain
const float Kd = 45;           // Derivative gain
const int init_speed = 200;    // Base speed
const int min_speed = 0;       // Minimum speed
const int max_speed = 240;     // Maximum speed
const int turn_speed = 170;    // Turning speed
```

### Obstacle Detection
```cpp
const float detect_obstacle = 20;  // Detection distance in cm
const float front_obstacle = 20;   // Front obstacle threshold
```

### Encoder Configuration
```cpp
const int delay_90deg = 450;   // Delay for 90-degree turn
```

### Kalman Filter
```cpp
const float mea_e = 2;         // Measurement uncertainty
const float est_e = 2;         // Estimation uncertainty
const float q = 0.07;          // Process variance
```

## Operating Modes

```cpp
const int FINISH = 0;              // Finish line detected
const int FOLLOWING_LINE = 1;      // Normal line following
const int STOP = 2;                // No line detected
const int TURNING_left = 3;        // Turning left
const int TURNING_right = 4;       // Turning right
const int AVOIDING_OBSTACLE = 5;   // Obstacle avoidance
```

## Hardware Specifications

### Motors
- **Type**: DC Motors with H-bridge control
- **Control**: PWM speed control (0-255)
- **Direction**: Bidirectional control

### Sensors
- **Line Sensor**: BFD-1000 5-channel IR array
- **Distance**: HC-SR04 ultrasonic (2-400cm range)
- **Encoders**: H206 quadrature encoders

### Power
- **Voltage**: External battery pack
- **Connection**: Barrel jack
- **Regulation**: Arduino UNO voltage regulation

## Calibration Values

### Line Sensor Thresholds
- **Black Line**: Digital LOW (0)
- **White Surface**: Digital HIGH (1)

### Encoder Calculations
- **Wheel Diameter**: Configured in Encoder_Read library
- **Pulses per Revolution**: 40 pulses per revolution
- **Distance Calculation**: Based on wheel circumference

### Ultrasonic Calibration
- **Speed of Sound**: 340 m/s (standard)
- **Temperature Compensation**: Not implemented
- **Filtering**: Kalman filter for noise reduction
