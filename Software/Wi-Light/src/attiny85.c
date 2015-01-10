/*
 * attiny85.c
 *
 * Created: 2014-11-28 
 *  Author: J. Stencel
 */

#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay_basic.h>
#include <avr/interrupt.h>
#include "spi_via_usi_driver.h"

#define LED PB4
#define DO PB1
#define DI PB0
#define SCK PB2
#define SPIMODE 0	// Sample on leading _rising_ edge, setup on trailing _falling_ edge.

uint8_t flag = 0; //flag is set if new data received
void read_data(void);

ISR(PCINT0_vect) 
{
	if (!(PINB & (1 << PB3)))
	{
		flag = 1;
		GIFR |= (1 << INTF0) | (1 << PCIF); //clear interrupt flags
	}
	
}
void enter_sleepmode()
{
	sleep_cpu();
}
void read_data(void)
{
	uint8_t status_temp = spiX_readreg(0x07);
	if (!(status_temp & RX_DR) || (~PORTB & PB3)) //if there is data in RX_FIFO
	{
		char data_r = spiX_readreg(R_RX_PAYLOAD);
		if (data_r == 0xAC) LED_ON_f();
		if (data_r == 0xCA) LED_OFF();
		spiX_readreg(RX_FLUSH); //clear received data FIFO in receiver
		NRF_WriteReg(NRF_GetRegCommand(STATUS, WRITE), (status_temp | (1 << RX_DR))); //clear data received flag in receiver
		
	}
	spiX_free_slavemodule();
}
int main(void) {
	
	PCMSK = (1 << PCINT3); //pin change interrupt mask (only change on pin 2)
	DDRB &= ~(1 << PB3); //set irq line as input 
	sei(); //enable interrupts
	delay_ms(2000);
	spiX_initmaster(SPIMODE);
	spiX_init_slavemodule();
	NRF_configure_RX();
	GIMSK = (1 << PCIE); //pin change interrupt enable
	MCUCR |= (1 << SE)|(1 << SM1); //sleep mode settings
	while(1) 
	{
	if ((flag) && (!(PINB & (1 << PB3)))) //if flag in ISR was set and there is a low state on irq line 
	{
		GIMSK &= ~(1 << PCIE); //disable pin change interrupt
		read_data(); flag = 0; //read data and clear the flag
		GIMSK = (1 << PCIE); //enable pin change interrupt
		//
		}
	else 
	{
		if (!(PINB & (1 << PB3))) NRF_WriteReg(NRF_GetRegCommand(STATUS, WRITE), ((1 << RX_DR))); //clear data received flag in receiver
		else
		{
			delay_ms(2);
		}
	}
	enter_sleepmode(); //go to sleep (wake up on pin change interrupt)
	}
	return 0;
}