#include "mandelbrot.h"

#include <stdio.h>

uint16_t get_for_px(uint8_t px, uint8_t py)
{
  static float x0 = 0.0f;
  static float y0 = 0.0f;

  static float x = 0.0f;
  static float xtemp = 0.0f;
  static float y = 0.0f;

  static uint8_t iter = 0;

  x0 = MB_LUT_X[px];
  y0 = MB_LUT_Y[py];
  x = 0.0f;
  y = 0.0f;

  iter = 0;
  while (x * x + y * y <= 2 * 2 && iter < MB_ITERS)
  {
    xtemp = x * x - y * y + x0;
    y = 2 * x * y + y0;
    x = xtemp;
    iter++;
  }

  return RGB565_PALETTE[iter % MB_RGB565_COLS];
}
