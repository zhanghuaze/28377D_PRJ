//
// Included Files
//
#include "device.h"
#include "driverlib.h"
#include "BSP_IO.h"
#include "BSP_SCI.h"

//
// Globals
//
uint16_t loopCount;
uint16_t errorCount;

//
// Main
//
void main(void)
{
    uint16_t sendChar;
    uint16_t receivedChar;

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Initialize GPIO and configure the GPIO pin as a push-pull output
    //
    Device_initGPIO();
    BSP_IO_gpio_setup();
    
    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    // 配置外部中断
    BSP_IO_exint_setup();
    
	EALLOW;
	BSP_SCI_PinMux_init();
	BSP_SCI_init();
	EDIS;

    //
    // Enables CPU interrupts
    //
    Interrupt_enableMaster();

    //
    // Initialize counts
    //
    loopCount = 0;
    errorCount = 0;

    //
    // Send a character starting with 0
    //
    sendChar = 0;
    
    //
    // Loop Forever
    //
    for(;;)
    {
        SCI_writeCharNonBlocking(mySCI1_BASE, sendChar);

        //
        // Wait for RRDY/RXFFST = 1 for 1 data available in FIFO
        //
        while(SCI_getRxFIFOStatus(mySCI1_BASE) == SCI_FIFO_RX0)
        {
            ;
        }

        //
        // Check received character
        //
        receivedChar = SCI_readCharBlockingFIFO(mySCI1_BASE);

        //
        // Received character not correct
        //
        if(receivedChar != sendChar)
        {
            errorCount++;
            // asm("     ESTOP0");  // Uncomment to stop the test here
            for (;;);
        }

        //
        // Move to the next character and repeat the test
        //
        sendChar++;

        //
        // Limit the character to 8-bits
        //
        sendChar &= 0x00FF;
        loopCount++;
    }
}

//
// End of file
//

