# Dual-mode relay controller with battery status monitoring.

Development Environment: STM32CubeIDE

Hardware Components:
- STM32F411CEU6 microcontroller (STM32 BlackPill board)
- 3.3V relay module
- 3.3V 1A LDO voltage regulator (e.g., AMS1117)
- Power supply (max 6.6V)
- Momentary pushbutton (Normally Open)
- Yellow LED
- Resistors: 1x 220Ω, 2x 100kΩ

All operational logic is contained within the `app.c` and `app.h` files.
Location: `trial_task_smart_relay/Core/Src` and `Inc`

The project uses active-low (0V) control logic.

Delays are used in the code during:
* entering sleep mode (for button debouncing)
* changing the relay operating mode (for LED indication)

State machine diagram:
![State Machine Diagram](stateDiagram.png)



