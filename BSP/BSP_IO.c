//
// Included Files
//
#include "BSP_IO.h"
#include "driverlib.h"


void BSP_IO_gpio_setup(void)
{
    /* 配置LED */
    // 配置GPIO94
    GPIO_setMasterCore(GPIO_PIN_LED1, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_CFG_LED1);
    GPIO_setPadConfig(GPIO_PIN_LED1, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(GPIO_PIN_LED1, GPIO_DIR_MODE_OUT);
    GPIO_setControllerCore(GPIO_PIN_LED1, GPIO_CORE_CPU1);
    GPIO_writePin(GPIO_PIN_LED1, 1);

    // 配置GPIO99
    GPIO_setMasterCore(GPIO_PIN_LED2, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_CFG_LED2);
    GPIO_setPadConfig(GPIO_PIN_LED2, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(GPIO_PIN_LED2, GPIO_DIR_MODE_OUT);
    GPIO_setControllerCore(GPIO_PIN_LED2, GPIO_CORE_CPU1);
    GPIO_writePin(GPIO_PIN_LED2, 1);

    // 配置GPIO133
    GPIO_setMasterCore(GPIO_PIN_LED3, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_CFG_LED3);
    GPIO_setPadConfig(GPIO_PIN_LED3, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(GPIO_PIN_LED3, GPIO_DIR_MODE_OUT);
    GPIO_setControllerCore(GPIO_PIN_LED3, GPIO_CORE_CPU1);
    GPIO_writePin(GPIO_PIN_LED3, 1);

    /* 配置KEY */
    // key1 配置GPIO29
    GPIO_setMasterCore(GPIO_PIN_KEY1, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_CFG_KEY1);
    GPIO_setPadConfig(GPIO_PIN_KEY1, GPIO_PIN_TYPE_PULLUP);
    GPIO_setDirectionMode(GPIO_PIN_KEY1, GPIO_DIR_MODE_IN);
    GPIO_setControllerCore(GPIO_PIN_KEY1, GPIO_CORE_CPU1);
    GPIO_setQualificationPeriod(GPIO_PIN_KEY1, 20);
    GPIO_setQualificationMode(GPIO_PIN_KEY1, GPIO_QUAL_6SAMPLE);

    // key2 配置GPIO30
    GPIO_setMasterCore(GPIO_PIN_KEY2, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_CFG_KEY2);
    GPIO_setPadConfig(GPIO_PIN_KEY2, GPIO_PIN_TYPE_PULLUP);
    GPIO_setDirectionMode(GPIO_PIN_KEY2, GPIO_DIR_MODE_IN);
    GPIO_setControllerCore(GPIO_PIN_KEY2, GPIO_CORE_CPU1);
    GPIO_setQualificationPeriod(GPIO_PIN_KEY2, 20);
    GPIO_setQualificationMode(GPIO_PIN_KEY2, GPIO_QUAL_6SAMPLE);

    // key3 配置GPIO36
    GPIO_setMasterCore(GPIO_PIN_KEY3, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_CFG_KEY3);
    GPIO_setPadConfig(GPIO_PIN_KEY3, GPIO_PIN_TYPE_PULLUP);
    GPIO_setDirectionMode(GPIO_PIN_KEY3, GPIO_DIR_MODE_IN);
    GPIO_setControllerCore(GPIO_PIN_KEY3, GPIO_CORE_CPU1);
    GPIO_setQualificationPeriod(GPIO_PIN_KEY3, 20);
    GPIO_setQualificationMode(GPIO_PIN_KEY3, GPIO_QUAL_6SAMPLE);

    // key4 配置GPIO28
    GPIO_setMasterCore(GPIO_PIN_KEY4, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_CFG_KEY4);
    GPIO_setPadConfig(GPIO_PIN_KEY4, GPIO_PIN_TYPE_PULLUP);
    GPIO_setDirectionMode(GPIO_PIN_KEY4, GPIO_DIR_MODE_IN);
    GPIO_setControllerCore(GPIO_PIN_KEY4, GPIO_CORE_CPU1);
    GPIO_setQualificationPeriod(GPIO_PIN_KEY4, 20);
    GPIO_setQualificationMode(GPIO_PIN_KEY4, GPIO_QUAL_6SAMPLE);
}

void BSP_IO_exint_setup(void)
{
    GPIO_setInterruptType(GPIO_INT_XINT1, GPIO_INT_TYPE_FALLING_EDGE);
    GPIO_setInterruptPin(GPIO_PIN_KEY1, GPIO_INT_XINT1);
    GPIO_enableInterrupt(GPIO_INT_XINT1);

    GPIO_setInterruptType(GPIO_INT_XINT2, GPIO_INT_TYPE_FALLING_EDGE);
    GPIO_setInterruptPin(GPIO_PIN_KEY2, GPIO_INT_XINT2);
    GPIO_enableInterrupt(GPIO_INT_XINT2);

    GPIO_setInterruptType(GPIO_INT_XINT3, GPIO_INT_TYPE_FALLING_EDGE);
    GPIO_setInterruptPin(GPIO_PIN_KEY3, GPIO_INT_XINT3);
    GPIO_enableInterrupt(GPIO_INT_XINT3);

    GPIO_setInterruptType(GPIO_INT_XINT4, GPIO_INT_TYPE_FALLING_EDGE);
    GPIO_setInterruptPin(GPIO_PIN_KEY4, GPIO_INT_XINT4);
    GPIO_enableInterrupt(GPIO_INT_XINT4);

    Interrupt_register(INT_XINT1, &gpioInterrupt1Handler);
    Interrupt_enable(INT_XINT1);

    Interrupt_register(INT_XINT2, &gpioInterrupt2Handler);
    Interrupt_enable(INT_XINT2);

    Interrupt_register(INT_XINT3, &gpioInterrupt3Handler);
    Interrupt_enable(INT_XINT3);

    Interrupt_register(INT_XINT4, &gpioInterrupt4Handler);
    Interrupt_enable(INT_XINT4);
}

__interrupt void gpioInterrupt1Handler(void)
{
    GPIO_togglePin(GPIO_PIN_LED1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}

__interrupt void gpioInterrupt2Handler(void)
{
    GPIO_togglePin(GPIO_PIN_LED2);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}

__interrupt void gpioInterrupt3Handler(void)
{
    GPIO_togglePin(GPIO_PIN_LED1);
    GPIO_togglePin(GPIO_PIN_LED2);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP12);
}

__interrupt void gpioInterrupt4Handler(void)
{
    GPIO_togglePin(GPIO_PIN_LED3);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP12);
}
