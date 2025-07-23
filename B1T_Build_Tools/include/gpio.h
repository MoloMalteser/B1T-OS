#ifndef GPIO_H
#define GPIO_H

void gpio_init();
void gpio_poll_buttons();
int gpio_button1_pressed();
int gpio_button2_pressed();

#endif
