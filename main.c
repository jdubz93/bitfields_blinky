#include <stdio.h>
#include <stdint.h>
#include "main.h"

void ledOn(GPIOx_MODE_REGSTR_t *pModeReg, GPIO_OUTPUT_DATA_REGSTR_t *pOutputData);
void ledOff(GPIOx_MODE_REGSTR_t *pModeReg, GPIO_OUTPUT_DATA_REGSTR_t *pOutputData);
void delayFunc(void);
void clearBits(GPIOx_MODE_REGSTR_t *pModeReg, GPIO_OUTPUT_DATA_REGSTR_t *pOutputData);

int main(void)
{
    RCC_AHB1ENR_t *pAhb1enr;
    pAhb1enr = (RCC_AHB1ENR_t*)0x40023830;

    GPIOx_MODE_REGSTR_t *pGpiodModePtr;
    pGpiodModePtr = (GPIOx_MODE_REGSTR_t*)0x40020C00;

    GPIO_OUTPUT_DATA_REGSTR_t *pGpioOutputData;
    pGpioOutputData = (GPIO_OUTPUT_DATA_REGSTR_t*)0x40020C14;

    pAhb1enr->gpio_d_en = 1;


    while(1) 
    {
        ledOn(pGpiodModePtr, pGpioOutputData);
        delayFunc();
        ledOff(pGpiodModePtr, pGpioOutputData);
        delayFunc();
    }



    return 0;
}

void ledOn(GPIOx_MODE_REGSTR_t *pModeReg, GPIO_OUTPUT_DATA_REGSTR_t *pOutputData) 
{
    clearBits(pModeReg, pOutputData);
    // set pint 5
    pModeReg->moder_5 = 1;
    pOutputData->odr_5 = 1;
}

void ledOff(GPIOx_MODE_REGSTR_t *pModeReg, GPIO_OUTPUT_DATA_REGSTR_t *pOutputData) 
{
    clearBits(pModeReg, pOutputData);
    pOutputData->odr_5 = 0;
    pModeReg->moder_5 = 0;
}

void delayFunc(void) 
{
	for(uint32_t i = 0; i < 500000; i++) 
    {
		// do nothing just a timeout
	}
}

void clearBits(GPIOx_MODE_REGSTR_t *pModeReg, GPIO_OUTPUT_DATA_REGSTR_t *pOutputData)
{
    memset(pModeReg, 0, sizeof(GPIOx_MODE_REGSTR_t));
    memset(pOutputData, 0, sizeof(GPIO_OUTPUT_DATA_REGSTR_t));
}