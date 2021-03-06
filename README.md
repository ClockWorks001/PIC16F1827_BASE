# PIC16F1827 BASE Project.
---
This is a base & demo sample project for PIC16F1827.

## Description

The [PIC16F1827][1] is a very low-cost 8-bit microcontroller with a good
amount of RAM, many peripherals. CPU Speed 8 MIPS / 32Mhz. RAM 384 Bytes. ROM 7 KBytes.

I use following peripherals for this BASE project.  
 * TMR1     :with interrupt. LED3 is blinked at 1 second interval.  
 * TMR2     :for PWM.  
 * ECCP2    :with TMR2. I use it for PWM output. Outputs are LED4, LED5. They are blinked at 1 second interval.  
 * GPIO     :input x2 for Switches, output x3 for LED1, LED2, LED3.  
 * EUSART   :serial console with 57600bps / NRZ.  
  
Other references.
  <https://docs.google.com/spreadsheets/d/18XYdP4BuEywOxAiw3yl_UnsTUrufz0ivfIZZy-oGmS4/edit?usp=sharing>


## Demo

![Alt text](/DEMO/PIC16F1827_BASE_DEMO001.gif)

## Prerequisites

I created this project using the free versions of the following tools:  
 * [Microchip MPLAB X][2] (v2.35)  
 * [Microchip XC8 Compiler][3] (v1.34)  
 * [MPLAB Code Configurator][4] (v2.25)(installed as plugin within MPLAB X)  

You will need to download and install these tools appropriately before you
can open this project and build it.
I use the [Microchip MPLAB PICkit3 In-Circuit Debugger][5] to program
the chip and debug it.  

Also, I use the [KI CAD][6] to draw the electric circuit schematic.
 * [KI CAD][6] (Build 2013-07-07 BZR 4022)

## Licence

[MIT](https://github.com/tcnksm/tool/blob/master/LICENCE)

## Author

Hiroshi Murakami  
<https://github.com/ClockWorks001>  


[1]: http://www.microchip.com/wwwproducts/Devices.aspx?dDocName=en538963 "PIC16F1827"
[2]: http://www.microchip.com/pagehandler/en-us/family/mplabx/ "MPLAB X"
[3]: http://www.microchip.com/pagehandler/en_us/devtools/mplabxc/ "MPLAB XC Compilers"
[4]: http://www.microchip.com/pagehandler/en-us/press-release/microchips-free-code-configura.html "MPLAB Code Configurator"
[5]: http://www.microchip.com/Developmenttools/ProductDetails.aspx?PartNO=PG164130 "MPLAB PICkit3 In-Circuit Debugger"
[6]: http://www.kicad-pcb.org/display/KICAD/KiCad+EDA+Software+Suite "KICAD"



