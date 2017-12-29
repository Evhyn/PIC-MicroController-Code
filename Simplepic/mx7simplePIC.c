//This is a modified simplePIC.c which is originally written for NU32 board 
//to be used stand alone (w/o bootloader) on the Chipkit Pro MX7 board
//Changes:
//LD1: from RF0 to RG12 (active low to active high)
//LD2: from RF1 to RG13 (active low to active high)
//BTN1: from RD7 to RG6 (active low to active high)

//use the following command to compile the 

#include <xc.h>          // Load the proper header for the processor

// Device Configuration Registers
#pragma config DEBUG = OFF          // Background Debugger disabled
#pragma config FWDTEN = OFF         // WD timer: OFF
#pragma config WDTPS = PS4096       // WD period: 4.096 sec
#pragma config POSCMOD = HS         // Primary Oscillator Mode: High Speed crystal
#pragma config FNOSC = PRIPLL       // Oscillator Selection: Primary oscillator w/ PLL
#pragma config FPLLMUL = MUL_20     // PLL Multiplier: Multiply by 20
#pragma config FPLLIDIV = DIV_2     // PLL Input Divider:  Divide by 2
#pragma config FPLLODIV = DIV_1     // PLL Output Divider: Divide by 1
#pragma config FPBDIV = DIV_1       // Peripheral Bus Clock: Divide by 1
#pragma config UPLLEN = ON          // USB clock uses PLL
#pragma config UPLLIDIV = DIV_2     // Divide 8 MHz input by 2, mult by 12 for 48 MHz
#pragma config FUSBIDIO = ON        // USBID controlled by USB peripheral when it is on
#pragma config FVBUSONIO = ON       // VBUSON controlled by USB peripheral when it is on
#pragma config FSOSCEN = OFF        // Disable second osc to get pins back
#pragma config BWP = ON             // Boot flash write protect: ON
#pragma config ICESEL = ICS_PGx2    // ICE pins configured on PGx2
#pragma config FCANIO = OFF         // Use alternate CAN pins
#pragma config FMIIEN = OFF         // Use RMII (not MII) for ethernet
#pragma config FSRSSEL = PRIORITY_6 // Shadow Register Set for interrupt priority 6

void delay(void);

int main(void) {
  TRISG = 0x0FFF;        // bit 12,13,14,15 set to 0 as output
						 // while others '1' as input
						 // 0x0FFF = 0000 1111 1111 1111

  LATGbits.LATG12 = 0;    // Turn LED1 on and LED2 off.  These pins source current
  LATGbits.LATG13 = 0;    // on the MX7, so "high" (1) = "on" and "low" (0) = "off"
  LATGbits.LATG14 = 0;
  LATGbits.LATG15 = 0;
  
  //LATGSET = 0x0000;

  while(1) {
	  
    delay();
	if(PORTGbits.RG7){
		LATGINV = 0x6000;   //0110 0000 0000 0000
	}else{
		LATGINV = 0x9000;   //1001 0000 0000 0000
	}
	

  }
  return 0;
}

void delay(void) {
  int j;
  for (j = 0; j < 1000000; j++) { // number is 1 million
    while(PORTGbits.RG6) {
        ;   // Pin RG6 is the USER switch, high (TRUE) if pressed.
    }
  }
}
