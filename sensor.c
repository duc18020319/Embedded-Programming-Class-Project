#include "sensor.h"
#include "MKL46Z4.h"
#include "stdio.h"


#define RS 0x04  /* PTA2 mask */
#define RW 0x10  /* PTA4 mask */
#define EN 0x20 /* PTA5 mask */

void initSystem()
{
    
};

void delay(int numberOfSeconds)
{
    int i = 0;
    for (i = 0;i < numberOfSeconds * 1000;i++)
    {
        
    }
};

void handleLCD(unsigned char command)
{
    PTA->PCOR = RS | RW; /* RS = 0, R/W = 0 */
    PTE->PDOR = (command<<16); // PTE->PDOR(23-16)=Command
    PTA->PSOR = EN; /* pulse E */
    delay(0);
    PTA->PCOR = EN;
    if (command < 4)
    {
        delay(4); /* command 1 and 2 needs up to 1.64ms */
    }
    else
    {
        delay(1); /* all others 40 us */
    }
};

void initLCD()
{
    /*Enable Clock Access: The first part of the pin configuration step is enabling clock access to the port that contains the pins used for GPIO. In the provided code, SIM->SCGC5 |= (1u<<13); enables clock access to Port E by setting the corresponding bit (bit 13) in the System Clock Gating Control Register 5 (SCGC5). This step ensures that the microcontroller can communicate with the GPIO pins of Port E.*/
    SIM->SCGC5 |= (1u<<13); /* enable clock to Port E */
    
    /*Pin Function Selection: Once clock access is enabled, the code configures the selected pins for GPIO operation. In the provided code, PORTE->PCR[x] = (1u<<8); sets the selected pins (PTE0 to PTE7) of Port E to function as GPIO pins. The specific pin numbers may vary depending on the board and LCD connection. This step tells the microcontroller that the selected pins will be used for general-purpose input and output.*/
    PORTE->PCR[0] = (1u<<8); /* make PTE0 pin as GPIO */
    PORTE->PCR[1] = (1u<<8); /* make PTE1 pin as GPIO */
    PORTE->PCR[2] = (1u<<8); /* make PTE2 pin as GPIO */
    PORTE->PCR[3] = (1u<<8); /* make PTE3 pin as GPIO */
    PORTE->PCR[4] = (1u<<8); /* make PTE4 pin as GPIO */
    PORTE->PCR[5] = (1u<<8); /* make PTE5 pin as GPIO */
    PORTE->PCR[6] = (1u<<8); /* make PTE6 pin as GPIO */
    PORTE->PCR[7] = (1u<<8); /* make PTE7 pin as GPIO */
    
    /*Data Direction: After configuring the pins for GPIO operation, the code sets the data direction for the pins. In the provided code, PTE->PDDR = (0xFFu<<16); sets pins PTE23 to PTE16 as output pins. These pins are used for transmitting data from the microcontroller to the LCD. By setting the data direction to output, the microcontroller can send data to the LCD through these pins.*/
    PTE->PDDR = (0xFFu<<16); /* make PTE23-16 as output pins */
    SIM->SCGC5 |= 0x0200; /* enable clock to Port A */
    PORTA->PCR[2] = 0x100; /* make PTA2 pin as GPIO */
    PORTA->PCR[4] = 0x100; /* make PTA4 pin as GPIO */
    PORTA->PCR[5] = 0x100; /* make PTA5 pin as GPIO */
    PTA->PDDR |= 0x34; /* make PTA5, 4, 2 as output pins */
    delay(1); /* initialization sequence */
    handleLCD(0x30);
    delay(1);
    handleLCD(0x30);
    delay(1);
    handleLCD(0x30);
    handleLCD(0x38); /* set 8-bit data, 2-line, 5×7 font */
    handleLCD(0x06); /* move cursor right */
    handleLCD(0x01); /* clear screen, move cursor to home */
    handleLCD(0x0F); /* turn on display, cursor blinking */
};

void startAlarm()
{
    
};

int senseDriverIn(void)
{
    return 1;
};

int senseDriverOut()
{
    return 0;
};

void alertDriverIn()
{
    
};

void alertDriverOut()
{
    
};

int verifySeatbeltStatus()
{
    
};

void alertDriverAsync(int time)
{
    
};