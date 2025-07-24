#include "framebuffer.h"
#include "neuron.h"

FrameBuffer fb;

void boot_menu() {
    fb_init(&fb);
    fb_draw_logo(&fb);
    fb_draw_text(&fb, 440, 320, "B1TOS", 0xFFFFFF, 0x000000);
    fb_draw_text(&fb, 420, 340, "Bootloader", 0xAAAAAA, 0x000000);

    fb_draw_text(&fb, 420, 400, "> Boot", 0x00FF00, 0x000000);
    fb_draw_text(&fb, 420, 420, "  Erweiterungen", 0xFFFFFF, 0x000000);
    fb_draw_text(&fb, 420, 440, "  Einstellungen", 0xFFFFFF, 0x000000);

    while (1) {
        neuron_tick();
    }
}

void main() {
    neuron_init();
    boot_menu();
}
