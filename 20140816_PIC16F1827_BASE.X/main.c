/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <xc.h>         /* XC8 General Include File */

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "mcc_generated_files/mcc.h"
#include "vCLOCK01.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

#define SWITCH1_ON  IO_RA4_GetValue() == 0
#define SWITCH1_OFF IO_RA4_GetValue() == 1
#define SWITCH2_ON  IO_RA3_GetValue() == 0
#define SWITCH2_OFF IO_RA3_GetValue() == 1
#define LED1_ON()	IO_RB3_SetHigh()
#define LED1_OFF()	IO_RB3_SetLow()
#define LED2_ON()	IO_RB4_SetHigh()
#define LED2_OFF()	IO_RB4_SetLow()
#define LED3_ON()	IO_RB5_SetHigh()
#define LED3_OFF()	IO_RB5_SetLow()

char cCount10msec;
/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void main(void)
{
	SYSTEM_Initialize();

    /* Configure the oscillator for the device */
    OSCILLATOR_Initialize();

    /* Initialize I/O and Peripherals for application */

    // Start Peripherals
    INTERRUPT_PeripheralInterruptEnable();
    INTERRUPT_GlobalInterruptEnable();
    TMR1_StartTimer();
    TMR2_StartTimer();
    // User add cording
    vClock01_Clear();

    while(1)
    {
        /* TODO <INSERT USER APPLICATION CODE HERE> */
		vClock01();
		if(SWITCH1_ON){
			LED1_ON();
		} else {
			LED1_OFF();
		}

		if(SWITCH2_ON){
			LED2_ON();
		} else {
			LED2_OFF();
		}

		if((ucSec01 % 2) == 0){
			LED3_ON();
		} else {
			LED3_OFF();
		}

		if(cFlag10mSec_ON()){
                    cCount10msec++;
                    if (cCount10msec >= 100){
//                        EUSART_Write('A');
                        printf("Hello\r\n");
                        cCount10msec=0;
                    }
		}
		
	}

}

