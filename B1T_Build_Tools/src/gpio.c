#include "gpio.h"
#include <stdint.h>

#define GPIO_BASE 0x3F200000UL

volatile uint32_t* const gpio = (volatile uint32_t*)GPIO_BASE;

#define BUTTON1_PIN 17
#define BUTTON2_PIN 27

static int button1_state = 0;
static int button2_state = 0;

void delay(volatile int count) {
    while(count--) { __asm__ volatile ("nop"); }
}

void gpio_init() {
    // Pins als Input (0b000)
    int reg = BUTTON1_PIN / 10;
    int shift = (BUTTON1_PIN % 10) * 3;
    gpio[reg] &= ~(7 << shift);

    reg = BUTTON2_PIN / 10;
    shift = (BUTTON2_PIN % 10) * 3;
    gpio[reg] &= ~(7 << shift);

    // Pull-Up/Down deaktivieren
    gpio[37] = 0;
    delay(150);
    gpio[38] = (1 << BUTTON1_PIN) | (1 << BUTTON2_PIN);
    delay(150);
    gpio[37] = 0;
    gpio[38] = 0;
}

int gpio_read(int pin) {
    uint32_t level = gpio[13]; // GPLEV0
    return (level & (1 << pin)) != 0;
}

void gpio_poll_buttons() {
    button1_state = (gpio_read(BUTTON1_PIN) == 0);
    button2_state = (gpio_read(BUTTON2_PIN) == 0);
}

int gpio_button1_pressed() {
    return button1_state;
}

int gpio_button2_pressed() {
    return button2_state;
}
