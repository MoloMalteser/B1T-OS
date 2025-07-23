#include "gpio.h"
#include <stdint.h>

// Einfaches Neuronenfeld (z.B. 8x8)
#define NEURON_COUNT 64

typedef struct {
    uint8_t active;
    uint8_t threshold;
    uint8_t growth; // Wachstumspotential (für spätere Erweiterung)
} neuron_t;

static neuron_t neurons[NEURON_COUNT];

// Init Neuronenfeld
void neurons_init() {
    for (int i = 0; i < NEURON_COUNT; i++) {
        neurons[i].active = 0;
        neurons[i].threshold = 5;  // Beispielschwelle
        neurons[i].growth = 0;
    }
}

// Einfacher Update-Zyklus
void neurons_update(int reward, int punishment) {
    for (int i = 0; i < NEURON_COUNT; i++) {
        if (reward) {
            if (neurons[i].threshold > 0) neurons[i].threshold--;
        }
        if (punishment) {
            if (neurons[i].threshold < 255) neurons[i].threshold++;
        }

        // Zufälliges Aktivieren
        neurons[i].active = (neurons[i].threshold < 10) ? 1 : 0;
    }
}

void kernel_main() {
    gpio_init();
    neurons_init();

    int reward = 0;
    int punishment = 0;

    while(1) {
        gpio_poll_buttons();

        // Beispiel: Buttons setzen Belohnung/Strafe Flags
        if (gpio_button1_pressed()) {
            reward = 1;
            punishment = 0;
        }
        else if (gpio_button2_pressed()) {
            reward = 0;
            punishment = 1;
        } else {
            reward = 0;
            punishment = 0;
        }

        neurons_update(reward, punishment);

        // TODO: Visualisierung, Ton, etc.
    }
}
