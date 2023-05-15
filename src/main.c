#include <stdint.h>
#include <stdio.h>

#include "pico/stdlib.h"
#include "pico_display.h"

#include "mandelbrot.h"

static pico_display_config_spi_t pd_config;
static pico_display_t disp;

static rgb565_frame_buffer_t frame = {};

void init()
{
  stdio_init_all();

  pd_config = pico_display_get_default_config();
  disp = pico_display_init(&pd_config);
  printf("Initialised display\n");

  pico_display_lcd_set_backlight(&disp, 255);
  pico_display_led_set_brightness(&disp, 0);
}

void main()
{
  init();

  for (uint8_t x = 0; x < MB_WIDTH; x++)
  {
    for (uint8_t y = 0; y < MB_HEIGHT; y++)
    {
      frame[y * MB_WIDTH + x] = get_for_px(x, y);
    }
  }

  printf("Generated set\n");
  pico_display_lcd_update(&disp, frame);

  for (;;) tight_loop_contents();
}