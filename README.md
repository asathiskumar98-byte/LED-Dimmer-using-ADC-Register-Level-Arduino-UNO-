# 💡 LED Dimmer using ADC — Register-Level (Arduino UNO)

This project demonstrates **analog-to-digital conversion (ADC)** and **Pulse Width Modulation (PWM)** using the **ATmega328P (Arduino UNO)** — implemented entirely through **register-level programming**.  
A **potentiometer** connected to the ADC input controls the **LED brightness** in real time.

---

## ⚙️ Hardware Used
- Arduino UNO (ATmega328P)
- 10kΩ Potentiometer
- LED connected to pin **D9 (OC1A)**
- 330Ω current-limiting resistor
- Breadboard and jumper wires

---

## 🔌 Pin Configuration

| Component | Function | Arduino Pin | Port |
|------------|-----------|--------------|------|
| Potentiometer Output | ADC Input | A0 | PC0 (ADC0) |
| LED | PWM Output | D9 | PB1 (OC1A) |
| VCC | Power | +5V | — |
| GND | Ground | GND | — |

---

## 🧩 Code Explanation

### Registers Used
| Register | Purpose |
|-----------|----------|
| **ADMUX** | Selects ADC input channel and reference voltage |
| **ADCSRA** | Controls ADC enable, start, interrupt, and prescaler |
| **TCCR1A / TCCR1B** | Configure PWM mode and prescaler |
| **OCR1A** | Output Compare Register — sets LED brightness (duty cycle) |
| **SREG** | Global Interrupt Enable register |

### ADC + PWM Configuration
- **ADC Channel:** ADC0 (PC0)
- **ADC Prescaler:** 16 → 1 MHz ADC clock
- **PWM Mode:** Fast PWM (10-bit)
- **PWM Output:** Non-inverting on OC1A
- **Timer1 Prescaler:** 64
- **PWM Frequency:** ~490 Hz  
- **Output Pin:** OC1A → PB1 → D9

---

## ⚙️ Working Principle
1. The **ADC** continuously reads the potentiometer voltage (0–5 V).  
2. Each ADC conversion triggers an **interrupt (ISR)** automatically.  
3. Inside the ISR, the ADC value (0–1023) updates the **PWM duty cycle** via `OCR1A`.  
4. The LED brightness changes smoothly based on the potentiometer position.

| Potentiometer Voltage | ADC Output | LED Brightness |
|------------------------|-------------|----------------|
| 0 V | 0 | OFF |
| 2.5 V | ~512 | Medium |
| 5 V | 1023 | Full Brightness |

---

## 🧰 Build & Upload
1. Compile using **AVR-GCC / Atmel Studio / PlatformIO / Arduino IDE**.  
2. Flash the HEX file to the **Arduino UNO**.  
3. Rotate the potentiometer and observe the LED brightness change dynamically.

---

## 🧠 Applications
- LED light dimming control  
- Variable motor speed control  
- Analog sensor signal visualization  
- ADC–PWM interfacing practice  
