# Smart Trash Can – Servo Controller

**Part of the ASR (Amirali Smart Room) system**

---

## About this project

This is the code for the **smart trash can** in my smart room.  
It connects to the main ASR system via `SoftwareSerial` and controls two servos:

- **Servo 1** (pin 7) – opens/closes the lid  
- **Servo 2** (pin 8) – activates the bag replacement mechanism

The trash can can be triggered in two ways:

1. **From the main ASR panel** – via Bluetooth or joystick (sends commands `1`, `2`, or `3`)  
2. **Manually** – with a push button connected to pin 9

---

## Features

- Opens lid automatically when triggered  
- Closes lid after a short delay  
- Bag replacement mode (full rotation of servo 2)  
- Two‑way serial communication (confirms action back to main system)  
- Manual button as backup / demo trigger  

---

## Serial commands

| Command | Action |
|---------|--------|
| `1`     | Normal open/close cycle |
| `2`     | Bag replacement cycle |
| `3`     | Extended open mode (keeps lid open for 15 seconds) |

After each command, the trash can replies back with `1` over `SoftwareSerial` to confirm execution.

---

## Hardware

| Component      | Pin  | Notes                          |
|----------------|------|--------------------------------|
| Servo 1 (lid)  | 7    | Sweeps 7° – 70°                |
| Servo 2 (bag)  | 8    | Sweeps 100° – 240°             |
| Button         | 9    | Pull‑up (LOW = pressed)        |
| SoftwareSerial | 11 (TX), 10 (RX) | Connected to main ASR board |

---

## Code

Full Arduino code is below.  
Uses the built‑in `Servo.h` and `SoftwareSerial.h` libraries.
