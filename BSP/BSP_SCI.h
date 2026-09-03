#ifndef BSP_SCI_H
#define BSP_SCI_H

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// SCIB -> mySCI1 Pinmux
//
//
// SCIRXDB - GPIO Settings
//
#define GPIO_PIN_SCIRXDB 55
#define mySCI1_SCIRX_GPIO 55
#define mySCI1_SCIRX_PIN_CONFIG GPIO_55_SCIRXDB
//
// SCITXDB - GPIO Settings
//
#define GPIO_PIN_SCITXDB 54
#define mySCI1_SCITX_GPIO 54
#define mySCI1_SCITX_PIN_CONFIG GPIO_54_SCITXDB

//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
#define mySCI1_BASE SCIB_BASE
#define mySCI1_BAUDRATE 9600
#define mySCI1_CONFIG_WLEN SCI_CONFIG_WLEN_8
#define mySCI1_CONFIG_STOP SCI_CONFIG_STOP_ONE
#define mySCI1_CONFIG_PAR SCI_CONFIG_PAR_NONE
#define mySCI1_FIFO_TX_LVL SCI_FIFO_TX0
#define mySCI1_FIFO_RX_LVL SCI_FIFO_RX0

void BSP_SCI_PinMux_init();
void BSP_SCI_init();
void BSP_SCI_mySCI1_init();

#endif
