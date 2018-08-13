/*
 * hello.c              Copyright NXP 2016
 * Description:  Simple program to exercise GPIO
 * 2015 Mar 31 S Mihalik/ O Romero - initial version
 *
 */

/*	Include headers */
#include "features.h"	 /* include features flags */
#include "embedded101.h" /* include peripheral declarations S32K144 */
#include "functions.h"   /* include functions */


int main(void) {
  int counter = 0;
  WDOG_disable();             /* Disable Watchdog in case it is not done in startup code */

  /* When you want to enable an output port
   * 1) enable clock  ---> PCC
   * 2) pin direction ---> PDDR
   * 3) Port function ---> PCR
   * 4) turn on LED   ---> PSOR/PCOR
   */

  // 1) Port clock control ---> enable
  *(PCC_PORT_D) |= PCC_ENABLE_PORT_MASK;

  // 2) Pin Direction ---> PDDR 1 << x
  (((GPIO_map_tp) PORT_D)->PDDR) |= LED_RED;

  // 3) Port function ---> PCR.Mux : 001b = GPIO
  PCR_PORT_D[PTD15] |= PCR_GPIO_MODE_MASK;

  // 4) Turn on LED
  ((GPIO_map_tp) PORT_D)->PCOR |= LED_RED;

  for(;;) {

    counter++;
  }

























}
