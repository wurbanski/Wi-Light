/**
  ******************************************************************************
  * @file    nrf24l01_comm.c
  * @author  M.Targan
  * @version V1.0.0
  * @date    06-October-2014
  * @brief   Set of functions for communication with wireless module
  ******************************************************************************
  */

#include "nrf24l01_comm.h"
#include "spi_comm.h"
#include "stm32f4xx_gpio.h"

unsigned char TX_ADDRESS[TX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x01}; // Define a static TX address

/** @brief Local functions declarations */
static status_t NRF_WriteReg(uint8_t RegCommand, uint8_t Value);
static uint8_t NRF_GetRegCommand(uint8_t Reg, uint8_t Operation);
static void NRF_WriteRegData(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize);
static void NRF_ReadRegData(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize);
static void delay(uint32_t nCount);

#ifdef TEST
static status_t NRF_WriteRegRX(uint8_t Reg, uint8_t* pData, uint8_t DataSize);
#endif

/**
 * @brief	None
 *
 * @param	None
 *
 * @return	None
 */
void NRF_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	// configure pin - CE
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Pin = NRF_CE_PIN;

	CE_H();
	GPIO_Init(NRF_GPIO_PORT, &GPIO_InitStructure);
}

#ifdef TEST
void NRF_ConfigureRX(void)
{

}

static status_t NRF_WriteRegRX(uint8_t Reg, uint8_t* pData, uint8_t DataSize)
{
	uint8_t RegCommand;
	uint8_t Status;

	RegCommand = NRF_GetRegCommand(Reg, WRITE);
	CSN_L();
	SPI_WriteRead(SPI1, RegCommand);
	SPI_WriteData(SPI1, pData, DataSize);
	CSN_H();
}
#endif

void NRF_ConfigureTX(void)
{
	delay(10000);
	CE_L();
	//NRF_WriteRegData(NRF_GetRegCommand(TX_ADDR, WRITE), TX_ADDRESS, TX_ADR_WIDTH);
	NRF_ReadRegData(NRF_GetRegCommand(TX_ADDR, READ), TX_ADDRESS, TX_ADR_WIDTH);
	/*
	NRF_WriteRegData(NRF_GetRegCommand(RX_ADDR_P0, WRITE), TX_ADDRESS, TX_ADR_WIDTH);
	NRF_WriteRegData(NRF_GetRegCommand(WR_TX_PLOAD, WRITE), BUF, TX_PLOAD_WIDTH); // Writes data to TX payload
	NRF_WriteReg(NRF_GetRegCommand(EN_AA, WRITE), 0x01);
	SPI2_readWriteReg(WRITE_REG + EN_AA, 0x01);
	// Enable Auto.Ack:Pipe0
	SPI2_readWriteReg(WRITE_REG + EN_RXADDR, 0x01); // Enable Pipe0
	SPI2_readWriteReg(WRITE_REG + SETUP_RETR, 0x1a); // 500us + 86us, 10 retrans...
	SPI2_readWriteReg(WRITE_REG + RF_CH, 40);
	// Select RF channel 40
	SPI2_readWriteReg(WRITE_REG + RF_SETUP, 0x07);
	// TX_PWR:0dBm, Datarate:2Mbps,
//      LNA:HCURR
	SPI2_readWriteReg(WRITE_REG + CONFIG, 0x0e);
	// Set PWR_UP bit, enable CRC(2 bytes)
	//& Prim:TX. MAX_RT & TX_DS enabled..
	*/
	CE_H();
}
/**
 * @brief	Write register
 *
 * @param   Reg					Register map to be configured
 * @param	pData				Pointer to data to be send to the register
 * @param	DataSize			Number of data bytes
 *
 * @return	None
 */
static status_t NRF_ConfigureReg(uint8_t Reg, uint8_t* pData, uint8_t DataSize)
{
	uint8_t RegCommand;
	uint8_t Status;

	RegCommand = NRF_GetRegCommand(Reg, WRITE);
	CSN_L();
	Status = SPI_WriteRead(SPI2, RegCommand);
	SPI_WriteData(SPI2, pData, DataSize);
	CSN_H();
	return Status;
}

/**
 * @brief	Get command for register write/read operation
 *
 * @param   Reg					Register map to be configured
 * @param	Operation			Read or Write operation
 *
 * @return	Command byte for r/w operation on given register
 */
static uint8_t NRF_GetRegCommand(uint8_t Reg, uint8_t Operation)
{
	uint8_t OperationMask;

	OperationMask = (Operation ? REGISTER_WRITE : REGISTER_READ);
	return (OperationMask | (REGISTER_MASK & Reg));
}

/**
 * @brief	None
 * @param	None
 * @return	None
 */
static void NRF_WriteRegData(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize)
{
	uint8_t ii;
	uint8_t Status;

	CSN_L();
	Status = SPI_WriteRead(SPI2, RegCommand);

	for(ii = 0; ii < DataSize; ii++)
	{
		/* catching status just for proper data flow, not used */
		Status = SPI_WriteRead(SPI2, pData[ii]);
	}
	CSN_H();
}

static void NRF_ReadRegData(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize)
{
	uint8_t ii;
	uint8_t Status;

	CSN_L();
	SPI_WriteRead(SPI2, RegCommand);

	for(ii = 0; ii < DataSize; ii++)
	{
		pData[ii] = SPI_WriteRead(SPI2, 0);
	}
	CSN_H();
}

static status_t NRF_WriteReg(uint8_t RegCommand, uint8_t Value)
{
	status_t Status;

	CSN_L();
	Status = SPI_WriteRead(SPI2, RegCommand);
	Status = SPI_WriteRead(SPI2, Value);
	CSN_H();
	return Status;
}

static uint8_t NRF_ReadReg(uint8_t RegCommand)
{
	uint8_t Byte;

	CSN_L();
	SPI_WriteRead(SPI2, RegCommand);
	Byte = SPI_WriteRead(SPI2, 0);
	CSN_H();
	return Byte;
}

static void delay(uint32_t nCount)
{
  uint32_t index = 0;
  for(index = (100000 * nCount); index != 0; index--)
  {
  }
}


