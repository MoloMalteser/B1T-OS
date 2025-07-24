#include "framebuffer.h"
#include <stddef.h>
#include <string.h>

extern unsigned char _binary_assets_logo_raw_start[];

void fb_init(FrameBuffer* fb) {
    fb->width = 1024;
    fb->height = 768;
    fb->pitch = fb->width * 4;
    fb->buffer = (uint32_t*) 0x100000;
    fb->isrgb = 1;
}

void fb_draw_pixel(FrameBuffer* fb, int x, int y, uint32_t color) {
    if (x >= 0 && x < fb->width && y >= 0 && y < fb->height) {
        fb->buffer[y * fb->width + x] = color;
    }
}

void fb_draw_char(FrameBuffer* fb, int x, int y, char c, uint32_t fg, uint32_t bg) {
    for (int dy = 0; dy < 8; dy++) {
        for (int dx = 0; dx < 8; dx++) {
            fb_draw_pixel(fb, x + dx, y + dy, dx == dy ? fg : bg);
        }
    }
}

void fb_draw_text(FrameBuffer* fb, int x, int y, const char* text, uint32_t fg, uint32_t bg) {
    while (*text) {
        fb_draw_char(fb, x, y, *text, fg, bg);
        x += 8;
        text++;
    }
}

void fb_draw_logo(FrameBuffer* fb) {
    int logo_w = 200, logo_h = 200;
    unsigned char* logo_data = _binary_assets_logo_raw_start;
    for (int y = 0; y < logo_h; y++) {
        for (int x = 0; x < logo_w; x++) {
            uint32_t pixel = ((uint32_t*)logo_data)[y * logo_w + x];
            fb_draw_pixel(fb, 412 + x, 100 + y, pixel);
        }
    }
}
