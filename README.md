# 🛩️ RC Plane with Arduino UNO/Nano

A 4-channel radio-controlled (RC) airplane project using Arduino and standard RC components. This project allows control over throttle, rudder, elevator, and aileron using a hobby-grade RC transmitter and receiver.

---

## 📦 Components Required

| Component                | Quantity | Description                          |
|--------------------------|----------|--------------------------------------|
| Arduino UNO or Nano      | 1        | Microcontroller                      |
| 4-Channel RC Transmitter | 1        | With corresponding receiver (e.g., FS-i6) |
| Servo Motors (SG90/Metal)| 3        | Controls rudder, elevator, aileron   |
| Brushless Motor + ESC    | 1 each   | For throttle (propulsion)            |
| Propeller (6x4, 8x4)     | 1        | Choose based on motor compatibility  |
| LiPo Battery (3S 11.1V)  | 1        | Power source                         |
| Foam Board / Balsa Wood  | As needed | For airframe construction            |
| Jumper Wires             | 8+       | Signal and power connections         |
| Battery Connector (XT60) | 1        | Battery to ESC                       |

---

## 🔌 Wiring & Connections

### Receiver to Arduino Inputs

| RC Channel | Arduino Pin |
|------------|-------------|
| Throttle   | D2          |
| Rudder     | D3          |
| Elevator   | D4          |
| Aileron    | D5          |

### Arduino to Output Devices

| Function  | Arduino Pin | Device            |
|-----------|-------------|--------------------|
| Throttle  | D9          | ESC               |
| Rudder    | D10         | Rudder Servo      |
| Elevator  | D11         | Elevator Servo    |
| Aileron   | D12         | Aileron Servo     |

Ensure a common ground between receiver, Arduino, and ESC BEC.

---

## 🧠 Arduino Code Summary

The Arduino sketch reads PWM signals from the receiver using `pulseIn()` and writes them directly to the servos and ESC using `writeMicroseconds()`. This provides near real-time control with minimal latency.

- PWM Input Range: 1000 – 2000 microseconds
- Output: Real-time servo/motor commands

---

## 🧪 Testing Instructions

1. Bind transmitter and receiver  
2. Upload the Arduino code  
3. Power system through USB or ESC’s BEC  
4. Move transmitter sticks to test response:  
   - Throttle → Motor spins  
   - Rudder → Servo rotates  
   - Elevator → Servo pitches up/down  
   - Aileron → Servo rolls left/right  

---

## ⚠️ Troubleshooting

| Symptom               | Possible Cause           | Solution                     |
|----------------------|--------------------------|------------------------------|
| No servo response     | Wrong wiring or no power | Check GND, pins, and power   |
| ESC doesn’t arm       | PWM out of range         | Recalibrate ESC manually     |
| Laggy response        | Software delay           | Optimize loop, debounce      |

---

## 🚀 Future Enhancements

- Add flight stabilization (MPU6050 IMU)  
- Implement GPS-based autopilot  
- Use FPV (First Person View) camera system  
- Design frame using CAD/3D printing  

---

## 📄 License & Contact

**License:** MIT License  
**Author:** Jaywing Technology  
**Support:** support@jaywingtech.in  

Contributions and forks are welcome! Fly safe ✈️
