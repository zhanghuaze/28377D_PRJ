#include "BSP_SCI.h"
#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void BSP_SCI_PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//
	
	//
	// SCIB -> mySCI1 Pinmux
	//
	GPIO_setPinConfig(mySCI1_SCIRX_PIN_CONFIG);
	GPIO_setPadConfig(mySCI1_SCIRX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(mySCI1_SCIRX_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(mySCI1_SCITX_PIN_CONFIG);
	GPIO_setPadConfig(mySCI1_SCITX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(mySCI1_SCITX_GPIO, GPIO_QUAL_ASYNC);
}

//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
void BSP_SCI_init()
{
	BSP_SCI_mySCI1_init();
}

void BSP_SCI_mySCI1_init()
{
	SCI_clearInterruptStatus(mySCI1_BASE, SCI_INT_RXFF | SCI_INT_TXFF | SCI_INT_FE | SCI_INT_OE | SCI_INT_PE | SCI_INT_RXERR | SCI_INT_RXRDY_BRKDT | SCI_INT_TXRDY);
	SCI_clearOverflowStatus(mySCI1_BASE);
	SCI_resetTxFIFO(mySCI1_BASE);
	SCI_resetRxFIFO(mySCI1_BASE);
	SCI_resetChannels(mySCI1_BASE);
	SCI_setConfig(mySCI1_BASE, DEVICE_LSPCLK_FREQ, mySCI1_BAUDRATE, (SCI_CONFIG_WLEN_8|SCI_CONFIG_STOP_ONE|SCI_CONFIG_PAR_NONE));
	SCI_enableLoopback(mySCI1_BASE);
	SCI_performSoftwareReset(mySCI1_BASE);
	SCI_setFIFOInterruptLevel(mySCI1_BASE, SCI_FIFO_TX0, SCI_FIFO_RX0);
	SCI_enableFIFO(mySCI1_BASE);
	SCI_enableModule(mySCI1_BASE);
}

