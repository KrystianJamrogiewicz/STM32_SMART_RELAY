# Dual-mode relay controller with battery status monitoring.

Link to video demonstration: https://www.linkedin.com/posts/krystian-jamrogiewicz-8b3770280_stm32-stm32cubeide-statemachine-activity-7438691549200175105-r073?utm_source=share&utm_medium=member_desktop&rcm=ACoAAER00AcB6L5q64HzB6NpWSs6syZ06z8OhkU

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



### Functions Overview

* **`App_Init`**: The initialization function that sets the initial states of the relay and LED to OFF.
* **`App_Loop`**: The main function executed in the infinite loop, containing the core control logic.

The device operates in 3 distinct states: **IDLE** (Sleep mode), **RUN** (Active operation), and **BATTERY LOW** (Emergency mode).
The functions handling these specific states are: `HandleIdleState`, `HandleRunState`, and `HandleBatteryLowState`.

**Helper / Execution Functions:**
* **`CheckButtonEvent`**: Determines the type of button press (long / short / no press).
* **`ManageRelayInterval`**: Manages the relay operation mode (toggling the time interval).
* **`GetBatteryVoltage`**: Reads the current battery voltage.
* **`HAL_GPIO_EXTI_Callback`**: Handles the external interrupt triggered by the button press.

---

### Device Operation

1. Upon power-up, the device enters **Sleep mode** to conserve energy.
2. Pressing the button triggers an interrupt that wakes up the microcontroller and starts normal operation (switching relay and LED states, monitoring battery voltage, and polling the button state).
   * **a)** A **short press** returns the device to Sleep mode.
   * **b)** A **long press** changes the relay's toggling interval from 1s to 10s (or vice versa).
   * **c)** If a low battery voltage is detected, the device enters the **"Low Battery"** emergency mode.
3. In the emergency mode, the device turns off the relay and uses a fast-blinking LED to indicate a fault condition.
   * **a)** The device can automatically exit the emergency mode and return to the **RUN** state once the battery is sufficiently recharged.
   * **b)** The device can also exit the emergency mode and return to the **IDLE** (Sleep) state upon a button press.
