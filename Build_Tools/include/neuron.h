#ifndef NEURON_H
#define NEURON_H

#define MAX_OUTPUTS 8
#define MAX_ACTIVE 1024

typedef struct Neuron {
    float value;
    float threshold;
    float weight;
    struct Neuron* outputs[MAX_OUTPUTS];
    int output_count;
} Neuron;

void neuron_tick();
void neuron_add_active(Neuron* n);
void neuron_init();

#endif
