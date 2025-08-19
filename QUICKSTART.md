# Quick Start Guide

Get your 4-Wheel Line Following Robot up and running in minutes!

## 🚀 Quick Setup

### 1. Hardware Assembly
- Mount Arduino UNO on the acrylic chassis
- Connect BFD-1000 line sensor to pins 9-13
- Connect L298N motor driver to pins 4-7, A0-A1
- Connect ultrasonic sensors to pins 8, A2, A4, A5
- Connect encoders to pins 2-3
- Connect external battery pack via barrel jack

### 2. Software Setup
1. **Download Code**: Clone this repository
2. **Open Arduino IDE**: Open `main/main.ino`
3. **Select Board**: Tools → Board → Arduino Uno
4. **Select Port**: Tools → Port → (your Arduino port)
5. **Upload**: Click Upload button or Ctrl+U

### 3. First Test
1. **Power On**: Connect battery pack
2. **Place on Line**: Put robot on a black line on white surface
3. **Watch it Go**: Robot should automatically follow the line!

## ⚡ Quick Configuration

### Basic PID Tuning
```cpp
// In line_following_robot.ino, adjust these values:
const float Kp = 40;    // Start with 40, increase for faster response
const float Ki = 0;      // Keep at 0 initially
const float Kd = 45;     // Start with 45, increase for stability
```

### Speed Adjustment
```cpp
const int init_speed = 200;  // Base speed (0-255)
const int max_speed = 240;   // Maximum speed
```

### Obstacle Detection
```cpp
const float detect_obstacle = 20;  // Detection distance in cm
```

## 🔧 Common Issues & Solutions

### Robot Not Moving
- Check motor connections
- Verify battery voltage
- Check motor driver connections

### Poor Line Following
- Clean line sensor lenses
- Adjust PID values
- Check line contrast (black on white)

### Encoder Errors
- Verify encoder connections
- Check interrupt pins (2, 3)
- Ensure proper mounting

### Ultrasonic Issues
- Check sensor connections
- Verify trigger/echo pins
- Clean sensor surfaces

## 📊 Performance Optimization

### For Speed
- Increase `Kp` value
- Increase `init_speed`
- Reduce `Kd` value

### For Stability
- Increase `Kd` value
- Reduce `init_speed`
- Fine-tune `Kp`

### For Obstacle Avoidance
- Adjust `detect_obstacle` distance
- Modify avoidance algorithm in code
- Test different sensor positions

## 🎯 Competition Tips

1. **Calibrate Sensors**: Test on actual competition surface
2. **Optimize PID**: Fine-tune for track characteristics
3. **Battery Check**: Ensure full charge before competition
4. **Speed vs Accuracy**: Find optimal balance for your track
5. **Practice Runs**: Test on similar track layouts

## 📱 Serial Monitor

Connect to Arduino via Serial Monitor (9600 baud) to see:
- Current operating mode
- Sensor readings
- PID calculations
- Error values

## 🆘 Need Help?

- Check the main [README.md](README.md) for detailed information
- Review [project_config.md](project_config.md) for technical details
- Test individual components using the test libraries in `src/libraries/`
- Ensure all connections match the pin definitions

---

**Happy Robot Building! 🤖**
