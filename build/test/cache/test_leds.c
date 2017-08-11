#include "build/temp/_test_leds.c"
#include "led.h"
#include "unity.h"




static uint16_t ledPort;



void setUp(void)

{

  LedInit(&ledPort);

}



void tearDown(void)

{

}



void test_LedsOffAfterCreate(void)

{



  uint16_t ledPort = 0xFFFF;

  LedInit(&ledPort);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledPort)), (

 ((void *)0)

 ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_HEX16);

}



void test_LedOn(void)

{

  LedOn(1);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0001)), (UNITY_INT)(UNITY_INT16)((ledPort)), (

 ((void *)0)

 ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_HEX16);

}



void test_LedOff(void)

{

  LedOff(1);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledPort)), (

 ((void *)0)

 ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_HEX16);

}



void testLedsOn(void)

{

  ledPort = 0x0000;

  LedOn(8);

  LedOn(9);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0180)), (UNITY_INT)(UNITY_INT16)((ledPort)), (

 ((void *)0)

 ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_HEX16);

}



void testLedsOff(void)

{

  ledPort = 0xFFFF;

  LedOff(8);

  LedOff(9);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFE7F)), (UNITY_INT)(UNITY_INT16)((ledPort)), (

 ((void *)0)

 ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_HEX16);

}



void test_LedOnAll(void)

{

  ledPort = 0x0000;

  LedOnAll();

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledPort)), (

 ((void *)0)

 ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_HEX16);

}



void test_LedOffAll(void)

{

  ledPort = 0xFFFF;

  LedOffAll();

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledPort)), (

 ((void *)0)

 ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_HEX16);

}
