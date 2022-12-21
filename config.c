/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////

#include "c8051f300.h"

// Peripheral specific initialization functions,
// Called from the Init_Device() function
void Reset_Sources_Init()
{
    RSTSRC    = 0x04;
}

void PCA_Init()
{
    PCA0MD    &= ~0x40;
    PCA0MD    = 0x00;
}

void Timer_Init()
{
    TCON      = 0x10;
    TMOD      = 0x02;
    CKCON     = 0x02;
    TH0       = 0x56;
}

void UART_Init()
{

}

void ADC_Init()
{

}

void Voltage_Reference_Init()
{

}

void Port_IO_Init()
{

    //P0MDOUT   = 0x04;
	P0MDOUT   = 0x04;
    XBR2      = 0x40;
}

void Oscillator_Init()
{
    OSCICN    = 0x07;
}

void Interrupts_Init()
{
    IE        = 0x82;
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Reset_Sources_Init();
    PCA_Init();
    Timer_Init();
    UART_Init();
    ADC_Init();
    Voltage_Reference_Init();
    Port_IO_Init();
    Oscillator_Init();
    Interrupts_Init();
}