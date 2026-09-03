#ifndef BSP_IO_H
#define BSP_IO_H

// LED
#define GPIO_PIN_LED1   94U
#define GPIO_PIN_LED2   99U
#define GPIO_PIN_LED3   133U
#define GPIO_CFG_LED1   GPIO_94_GPIO94
#define GPIO_CFG_LED2   GPIO_99_GPIO99
#define GPIO_CFG_LED3   GPIO_133_GPIO133

// KEY
#define GPIO_PIN_KEY1   29U
#define GPIO_PIN_KEY2   30U
#define GPIO_PIN_KEY3   36U
#define GPIO_PIN_KEY4   28U
#define GPIO_CFG_KEY1   GPIO_29_GPIO29
#define GPIO_CFG_KEY2   GPIO_30_GPIO30
#define GPIO_CFG_KEY3   GPIO_36_GPIO36
#define GPIO_CFG_KEY4   GPIO_28_GPIO28


void BSP_IO_gpio_setup(void);
void BSP_IO_exint_setup(void);

//
// Interrupt Handler
//
__interrupt void gpioInterrupt1Handler(void);
__interrupt void gpioInterrupt2Handler(void);
__interrupt void gpioInterrupt3Handler(void);
__interrupt void gpioInterrupt4Handler(void);

#endif
