#include "led.h"

static uint16_t * ledPort;
static uint16_t LedToPortMask(uint8_t );

void LedInit(uint16_t * port)
{
  ledPort = port;
  *ledPort = 0x0000;
}

void LedOn(uint8_t led)
{
  /* *ledPort |= 1 << (led -1); */
  *ledPort |= LedToPortMask(led);
}

void LedOff(uint8_t led)
{
  /* *ledPort &= ~(1 << (led -1)); */
  *ledPort &= ~LedToPortMask(led);
}

void LedOnAll(void)
{
  *ledPort = 0xFFFF;
}

void LedOffAll(void)
{
  *ledPort = 0x0000;
}

static uint16_t LedToPortMask(uint8_t led)
{
  return (1 << (led -1));
}


