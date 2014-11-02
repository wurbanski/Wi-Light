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
#include "stm32f4xx_gpio.h"

/** @brief Global variables */
uint8_t TX_ADDRESS[TX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x01}; // Define default TX address
uint8_t RX_ADDRESS[TX_ADR_WIDTH]  = {0x34,0x43,0x10,0x10,0x02}; // Define default RX address

/** @brief Local functions declarations */
static status_t NRF_WriteReg(uint8_t RegCommand, uint8_t Value);
static uint8_t NRF_GetRegCommand(uint8_t Reg, uint8_t Operation);
static void NRF_WriteRegData(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize);
static void NRF_ReadRegData(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize);
static uint8_t NRF_ReadReg(uint8_t RegCommand);
static void delay(uint32_t nCount);
static void NRF_PowerUpTX();
static void NRF_PowerDownTX();


#ifdef TEST
static void NRF_WriteRegDataRX(uint8_t Reg, uint8_t* pData, uint8_t DataSize);
static status_t NRF_WriteRegRX(uint8_t RegCommand, uint8_t Value);
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

#ifdef TEST
	GPIO_InitStructure.GPIO_Pin = NRF_CE_PIN | NRF_CE_PIN_RX;
	CE_H_RX();
#endif

	//TODO: is CE high needed or not?
	CE_H();
	GPIO_Init(NRF_GPIO_PORT, &GPIO_InitStructure);
}

#ifdef TEST
/**
 * @brief	None
 * @param	None
 * @return	None
 */
static uint8_t NRF_ReadRegRX(uint8_t RegCommand)
{
	uint8_t Byte;

	CSN_L_RX();
	SPI_WriteRead(SPI1, RegCommand);
	Byte = SPI_WriteRead(SPI1, 0);
	CSN_H_RX();
	return Byte;
}
/**
 * @brief	None
 * @param	None
 * @return	None
 */
static void NRF_WriteRegDataRX(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize)
{
	uint8_t ii;
	uint8_t Status;

	CSN_L_RX();
	Status = SPI_WriteRead(SPI1, RegCommand);

	for(ii = 0; ii < DataSize; ii++)
	{
		/* catching status just for proper data flow, not used */
		Status = SPI_WriteRead(SPI1, pData[ii]);
	}
	CSN_H_RX();
}

/**
 * @brief	None
 * @param	None
 * @return	None
 */
static void NRF_ReadRegDataRX(uint8_t RegCommand, uint8_t* pData, uint8_t DataSize)
{
	uint8_t ii;
	uint8_t Status;

	CSN_L_RX();
	SPI_WriteRead(SPI1, RegCommand);

	for(ii = 0; ii < DataSize; ii++)
	{
		pData[ii] = SPI_WriteRead(SPI1, 0);
	}
	CSN_H_RX();
}

/**
 * @brief	None
 * @param	None
 * @return	None
 */
static status_t NRF_WriteRegRX(uint8_t RegCommand, uint8_t Value)
{
	status_t Status;

	CSN_L_RX();
	Status = SPI_WriteRead(SPI1, RegCommand);
	Status = SPI_WriteRead(SPI1, Value);
	CSN_H_RX();
	return Status;
}

/**
 * @brief	None
 * @param	None
 * @return	None
 */
static void NRF_PowerUpRX()
{
	uint8_t RegValue;
	CE_L_RX();
	//can be done by checking every time the real value of register as shown below
	//RegValue = NRF_ReadReg(NRF_GetRegCommand(CONFIG, READ));
	RegValue = CONFIG_DEFAULT | ((FLG_SET << PWR_UP) | (FLG_SET << PRIM_RX));
	NRF_WriteRegRX(NRF_GetRegCommand(CONFIG, WRITE), RegValue);
	CE_H_RX();
}

static void NRF_PowerDownRX()
{
	CE_L_RX();
	NRF_WriteRegRX(NRF_GetRegCommand(CONFIG, WRITE), CONFIG_DEFAULT);
	CE_H_RX();
}
void NRF_ConfigureRX(void)
{
	delay(10000);
	// enter standby mode
	CE_L_RX();

	// set receiver address, for only two modules present the same address is acceptable
	NRF_WriteRegData(NRF_GetRegCommand(RX_ADDR_P0, WRITE), TX_ADDRESS, TX_ADR_WIDTH);
	// enable auto ack
	NRF_WriteReg(NRF_GetRegCommand(EN_AA, WRITE), 0x01);
	// enable pipe 0
	NRF_WriteReg(NRF_GetRegCommand(EN_RXADDR, WRITE), 0x01);
	// set payload width to 1 byte
	NRF_WriteReg(NRF_GetRegCommand(RX_PW_P0, WRITE), TX_PLOAD_WIDTH);
	// select RF channel 40
	NRF_WriteReg(NRF_GetRegCommand(RF_CH, WRITE), 40);
	// set 2Mbps bit rate and 0dBm output power level
	NRF_WriteReg(NRF_GetRegCommand(RF_SETUP, WRITE), 0x07);

	NRF_PowerUpRX();
}

#endif

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

/**
 * @brief	None
 * @param	None
 * @return	None
 */
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

/**
 * @brief	None
 * @param	None
 * @return	None
 */
static status_t NRF_WriteReg(uint8_t RegCommand, uint8_t Value)
{
	status_t Status;

	CSN_L();
	Status = SPI_WriteRead(SPI2, RegCommand);
	Status = SPI_WriteRead(SPI2, Value);
	CSN_H();
	return Status;
}

/**
 * @brief	None
 * @param	None
 * @return	None
 */
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

static void NRF_PowerUpTX()
{
	uint8_t RegValue;
	CE_L();
	//can be done by checking every time the real value of register as shown below
	//RegValue = NRF_ReadReg(NRF_GetRegCommand(CONFIG, READ));
	//RegValue &= ~(FLG_SET << PRIM_RX);
	RegValue = CONFIG_DEFAULT | (FLG_SET << PWR_UP);
	NRF_WriteReg(NRF_GetRegCommand(CONFIG, WRITE), RegValue);
	CE_H();
}

static void NRF_PowerDownTX()
{
	CE_L();
	NRF_WriteReg(NRF_GetRegCommand(CONFIG, WRITE), CONFIG_DEFAULT);
	CE_H();
}

void NRF_ConfigureTX(void)
{
	delay(10000);
	// enter standby mode
	CE_L();

	// set TX address
	NRF_WriteRegData(NRF_GetRegCommand(TX_ADDR, WRITE), TX_ADDRESS, TX_ADR_WIDTH);
	// set the same address for receiving auto ack
	/*NRF_WriteRegData(NRF_GetRegCommand(RX_ADDR_P0, WRITE), TX_ADDRESS, TX_ADR_WIDTH);
	//NRF_WriteRegData(NRF_GetRegCommand(WR_TX_PLOAD, WRITE), BUF, TX_PLOAD_WIDTH); // Writes data to TX payload
	// enable auto ack
	NRF_WriteReg(NRF_GetRegCommand(EN_AA, WRITE), 0x01);
	// enable pipe 0
	NRF_WriteReg(NRF_GetRegCommand(EN_RXADDR, WRITE), 0x01);
	// set retransmission timings, 500us and 10 retries
	NRF_WriteReg(NRF_GetRegCommand(SETUP_RETR, WRITE), 0x1a);
	// select RF channel 40
	NRF_WriteReg(NRF_GetRegCommand(RF_CH, WRITE), 40);
	// set 2Mbps bit rate and 0dBm output power level
	NRF_WriteReg(NRF_GetRegCommand(RF_SETUP, WRITE), 0x07);
	*/
}

void NRF_Send(uint8_t Data)
{
	uint8_t Status;
	uint8_t SentFlag = FLG_CLRD;

	CE_L();
	Status = NRF_ReadReg(NRF_GetRegCommand(STATUS, READ));

	while(FLG_CLRD == SentFlag)
	{
		if(FLG_CLRD != (Status & STATUS_SENT))
		{
			SentFlag = FLG_SET;
		}
	}

	NRF_WriteReg(W_TX_PAYLOAD, Data);
	NRF_PowerUpTX();

	CE_H();
}





