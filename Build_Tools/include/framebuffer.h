#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <stdint.h>

typedef struct {
    uint32_t* buffer;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint32_t isrgb;
} FrameBuffer;

void fb_init(FrameBuffer* fb);
void fb_draw_pixel(FrameBuffer* fb, int x, int y, uint32_t color);
void fb_draw_char(FrameBuffer* fb, int x, int y, char c, uint32_t fg, uint32_t bg);
void fb_draw_text(FrameBuffer* fb, int x, int y, const char* text, uint32_t fg, uint32_t bg);
void fb_draw_logo(FrameBuffer* fb);

#endif
