/*
 * GPIO.c
 *
 *  Created on: 3/1/2020
 *  Author: Andrew Koehn
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    //configure LEDs as outputs (set PyDIR)
    P1DIR = P1DIR | LED1;
    P2DIR = P2DIR | LED2_RED;
    P2DIR = P2DIR | LED2_GREEN;
    P2DIR = P2DIR | LED2_BLUE;
    P2DIR = P2DIR | BLED_RED;
    P2DIR = P2DIR | BLED_GREEN;
    P5DIR = P5DIR | BLED_BLUE;

    //configure buttons as inputs (clear PyDIR)
    P1DIR = P1DIR & ~L1;
    P1DIR = P1DIR & ~L2;
    P5DIR = P5DIR & ~B1;
    P3DIR = P3DIR & ~B2;

    //enable pull-up/down resistors on inputs (set PyREN)
    P1REN = P1REN | L1;
    P1REN = P1REN | L2;
    P5REN = P5REN | B1;
    P3REN = P3REN | B2;

    //enable pull-up resistors on inputs (set PyOUT)
    P1OUT = P1OUT | L1;
    P1OUT = P1OUT | L2;
    P5OUT = P5OUT | B1;
    P3OUT = P3OUT | B2;

    // Turn off all LEDs at the start.
    turnOff_LaunchpadLED1();
    turnOff_LaunchpadLED2Red();
    turnOff_LaunchpadLED2Green();
    turnOff_LaunchpadLED2Blue();
    turnOff_BoosterpackLEDRed();
    turnOff_BoosterpackLEDGreen();
    turnOff_BoosterpackLEDBlue();
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return (P1IN & L1);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return (P1IN & L2);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return (P5IN & B1);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return (P3IN & B2);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT = P1OUT | LED1;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT = P1OUT & ~LED1;
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT = P2OUT | LED2_RED;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT = P2OUT & ~LED2_RED;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT = P2OUT | LED2_GREEN;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT = P2OUT & ~LED2_GREEN;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT = P2OUT | LED2_BLUE;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT = P2OUT & ~LED2_BLUE;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT = P2OUT | BLED_RED;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT = P2OUT & ~BLED_RED;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT = P2OUT | BLED_GREEN;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT = P2OUT & ~BLED_GREEN;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT = P5OUT | BLED_BLUE;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT = P5OUT & ~BLED_BLUE;
}
