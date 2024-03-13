#include <stdio.h>

#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC55S69_cm33_core0.h"
#include "fsl_debug_console.h"
#include "fsl_power.h"

#include "game.h"

lpadc_conv_result_t g_LpadcResultConfigStruct;
uint16_t adcCh1 = 0, adcCh2 = 0;

bool swDebug = false;

void ADC_Callback(void)
{
	LPADC_GetConvResult(ADC0, &g_LpadcResultConfigStruct, 0U);
	adcCh1 = g_LpadcResultConfigStruct.convValue;

	LPADC_GetConvResult(ADC0, &g_LpadcResultConfigStruct, 0U);
	adcCh2 = g_LpadcResultConfigStruct.convValue;
}

void SW_Callback(pint_pin_int_t pintr ,uint32_t pmatch_status)
{
	if(!swDebug)
	{
		gameButton();
		swDebug = true;
	}
}

void SysTick_Handler(void)
{
	float x = (adcCh1/32768.0)-1;
	float y = (adcCh2/32768.0)-1;

	gameUpdate(x, y);

	if(swDebug){
		swDebug = false;
	}
}

int main(void)
{
	/* Disable LDOGPADC power down */
	POWER_DisablePD(kPDRUNCFG_PD_LDOGPADC);

	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();

	#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
	#endif

	PRINTF("Start \r\n");

	SysTick_Config(SystemCoreClock / 10U);

	gameInit(FLEXCOMM8_PERIPHERAL);

	while(1)
	{
		gameDraw();
	}

	return 0 ;
}
