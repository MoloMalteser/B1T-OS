#include "neuron.h"

static Neuron* active_queue[MAX_ACTIVE];
static int active_count = 0;

void neuron_add_active(Neuron* n) {
    if (active_count < MAX_ACTIVE) {
        active_queue[active_count++] = n;
    }
}

void neuron_tick() {
    for (int i = 0; i < active_count; i++) {
        Neuron* n = active_queue[i];
        if (n->value >= n->threshold) {
            for (int j = 0; j < n->output_count; j++) {
                Neuron* out = n->outputs[j];
                out->value += n->value * n->weight;
                neuron_add_active(out);
            }
            n->value = 0;
        }
    }
    active_count = 0;
}

void neuron_init() {
    static Neuron n1 = {0.5, 1.0, 0.9, {0}, 0};
    static Neuron n2 = {0.0, 1.0, 0.9, {0}, 0};
    n1.outputs[0] = &n2;
    n1.output_count = 1;

    neuron_add_active(&n1);
}
