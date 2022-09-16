#include "gpio_init.h"
//TODO: проверить соответствие префиксов и, возможно, объединить в структуру(ы)
//
const gpio_pin_t GPO_Chr_Batt_App = GPIO_PIN(GPIOE, GPIO_PIN_3); /*2, PE3, GPIO_Output, Chr_Batt_App*/
const gpio_pin_t GPO_CS_DO_App = GPIO_PIN(GPIOE, GPIO_PIN_4); /*3, PE4, GPIO_Output, CS_DO_App*/
//
//
const gpio_pin_t GPO_CS_DI_App = GPIO_PIN(GPIOI, GPIO_PIN_8); /*7, PI8, GPIO_Output, CS_DI_App*/
const gpio_pin_t GPO_CS_PTC_App = GPIO_PIN(GPIOC, GPIO_PIN_13); /*8, PC13, GPIO_Output, CS_PTC_App*/
//
//
const gpio_pin_t GPO_Reset_DI_App = GPIO_PIN(GPIOI, GPIO_PIN_9); /*11, PI9, GPIO_Output, Reset_DI_App*/
const gpio_pin_t GPI_Int_DI_App = GPIO_PIN(GPIOI, GPIO_PIN_10); /*12, PI10, GPIO_Input, Int_DI_App*/
const gpio_pin_t GPO_nCLR_App = GPIO_PIN(GPIOI, GPIO_PIN_11); /*13, PI11, GPIO_Output, nCLR_App*/
//
//
//
//
//
//
//
//
//
//
const gpio_pin_t GPI_Dip0_App = GPIO_PIN(GPIOF, GPIO_PIN_10); /*28, PF10, GPIO_Input, Dip0_App*/
//
//
const gpio_pin_t GPI_Dip1_App = GPIO_PIN(GPIOC, GPIO_PIN_0); /*32, PC0, GPIO_Input, Dip1_App*/
//
const gpio_pin_t GPO_OutDis_I_AO_App = GPIO_PIN(GPIOC, GPIO_PIN_2); /*34, PC2, GPIO_Output, OutDis_I_AO_App*/
const gpio_pin_t GPI_EmStop_App = GPIO_PIN(GPIOC, GPIO_PIN_3); /*35, PC3, GPIO_Input, EmStop_App*/
const gpio_pin_t GPO_EN_DO_App = GPIO_PIN(GPIOA, GPIO_PIN_0); /*40, PA0/WKUP, GPIO_Output, EN_DO_App*/
//
//
const gpio_pin_t GPO_ETH_Reset_App = GPIO_PIN(GPIOH, GPIO_PIN_2); /*43, PH2, GPIO_Output, ETH_Reset_App*/
const gpio_pin_t GPI_Board_In1_App = GPIO_PIN(GPIOH, GPIO_PIN_3); /*44, PH3, GPIO_Input, Board_In1_App*/
const gpio_pin_t GPI_Board_In2_App = GPIO_PIN(GPIOH, GPIO_PIN_4); /*45, PH4, GPIO_Input, Board_In2_App*/
//
//
//
//
//
//
//
//
const gpio_pin_t GPO_Board_Out3_App = GPIO_PIN(GPIOB, GPIO_PIN_0); /*56, PB0, GPIO_Output, Board_Out3_App*/
const gpio_pin_t GPO_Board_Out4_App = GPIO_PIN(GPIOB, GPIO_PIN_1); /*57, PB1, GPIO_Output, Board_Out4_App*/
const gpio_pin_t GPI_BOOT1 = GPIO_PIN(GPIOB, GPIO_PIN_2); /*58, PB2/BOOT1, GPIO_Input, BOOT1*/
const gpio_pin_t GPO_NAND_nWP_App = GPIO_PIN(GPIOF, GPIO_PIN_11); /*59, PF11, GPIO_Output, NAND_nWP_App*/
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
const gpio_pin_t GPI_Lost_5V_App = GPIO_PIN(GPIOH, GPIO_PIN_7); /*84, PH7, GPIO_Input, Lost_5V_App*/
const gpio_pin_t GPO_Dir1_485_App = GPIO_PIN(GPIOH, GPIO_PIN_8); /*85, PH8, GPIO_Output, Dir1_485_App*/
const gpio_pin_t GPI_Panel_Detect_App = GPIO_PIN(GPIOH, GPIO_PIN_9); /*86, PH9, GPIO_Input, Panel_Detect_App*/
//
//
//
//
//
const gpio_pin_t GPI_AC_lost_App = GPIO_PIN(GPIOB, GPIO_PIN_14); /*94, PB14, GPIO_Input, AC_lost_App*/
const gpio_pin_t GPI_RVS2_App = GPIO_PIN(GPIOB, GPIO_PIN_15); /*95, PB15, GPIO_Input, RVS2_App*/
//
//
//
//
//
//
//
//
//
//
//
//
const gpio_pin_t GPO_ResetAI_App = GPIO_PIN(GPIOG, GPIO_PIN_6); /*110, PG6, GPIO_Output, ResetAI_App*/
const gpio_pin_t GPI_ErrorAO1_App = GPIO_PIN(GPIOG, GPIO_PIN_7); /*111, PG7, GPIO_Input, ErrorAO1_App*/
const gpio_pin_t GPI_ErrorAO2_App = GPIO_PIN(GPIOG, GPIO_PIN_8); /*112, PG8, GPIO_Input, ErrorAO2_App*/
//
//
//
const gpio_pin_t GPO_SDIO_PWR_App = GPIO_PIN(GPIOC, GPIO_PIN_9); /*118, PC9, GPIO_Output, SDIO_PWR_App*/
const gpio_pin_t GPI_SDIO_CD_App = GPIO_PIN(GPIOA, GPIO_PIN_8); /*119, PA8, GPIO_Input, SDIO_CD_App*/
//
//
const gpio_pin_t GPI_RVS1_App = GPIO_PIN(GPIOA, GPIO_PIN_11); /*122, PA11, GPIO_Input, RVS1_App*/
const gpio_pin_t GPO_NC = GPIO_PIN(GPIOA, GPIO_PIN_12); /*123, PA12, GPIO_Output, NC*/
//
const gpio_pin_t GPO_SYNCAO_App = GPIO_PIN(GPIOH, GPIO_PIN_13); /*128, PH13, GPIO_Output, SYNCAO_App*/
const gpio_pin_t GPO_CS1AI_App = GPIO_PIN(GPIOH, GPIO_PIN_14); /*129, PH14, GPIO_Output, CS1AI_App*/
const gpio_pin_t GPO_CS2AI_App = GPIO_PIN(GPIOH, GPIO_PIN_15); /*130, PH15, GPIO_Output, CS2AI_App*/
const gpio_pin_t GPO_OE_App = GPIO_PIN(GPIOI, GPIO_PIN_0); /*131, PI0, GPIO_Output, OE_App*/
//
//
//
//
//
//
//
//
//
//
//
const gpio_pin_t GPO_Dir2_485_App_Jmp = GPIO_PIN(GPIOD, GPIO_PIN_3); /*145, PD3, GPIO_Output, Dir2_485_App_Jmp*/
//
//
//
//
//
const gpio_pin_t GPO_nLDAC_App = GPIO_PIN(GPIOG, GPIO_PIN_10); /*153, PG10, GPIO_Output, nLDAC_App*/
//
const gpio_pin_t GPO_Relay1_DO_App = GPIO_PIN(GPIOG, GPIO_PIN_12); /*155, PG12, GPIO_Output, Relay1_DO_App*/
const gpio_pin_t GPO_Relay2_DO_App = GPIO_PIN(GPIOG, GPIO_PIN_13); /*156, PG13, GPIO_Output, Relay2_DO_App*/
const gpio_pin_t GPO_Relay3_DO_App = GPIO_PIN(GPIOG, GPIO_PIN_14); /*157, PG14, GPIO_Output, Relay3_DO_App*/
const gpio_pin_t GPO_Relay4_DO_App = GPIO_PIN(GPIOG, GPIO_PIN_15); /*160, PG15, GPIO_Output, Relay4_DO_App*/
//
const gpio_pin_t GPI_IO0_App_MC = GPIO_PIN(GPIOB, GPIO_PIN_4); /*162, PB4, GPIO_Input, IO0_App_MC*/
//
const gpio_pin_t GPO_Dir_Panel_App = GPIO_PIN(GPIOB, GPIO_PIN_6); /*164, PB6, GPIO_Output, Dir_Panel_App*/
const gpio_pin_t GPI_IO1_App_MC = GPIO_PIN(GPIOB, GPIO_PIN_7); /*165, PB7, GPIO_Input, IO1_App_MC*/
//
//
//
//
const gpio_pin_t GPI_Board_ID0 = GPIO_PIN(GPIOI, GPIO_PIN_4); /*173, PI4, GPIO_Input, Board_ID0_App*/
const gpio_pin_t GPI_Board_ID1 = GPIO_PIN(GPIOI, GPIO_PIN_5); /*174, PI5, GPIO_Input, Board_ID1_App*/
const gpio_pin_t GPI_Board_ID2 = GPIO_PIN(GPIOI, GPIO_PIN_6); /*175, PI6, GPIO_Input, Board_ID2_App*/
const gpio_pin_t GPI_Board_ID3 = GPIO_PIN(GPIOI, GPIO_PIN_7); /*176, PI7, GPIO_Input, Board_ID3_App*/

//TODO: проверить состояния пинов при инициализации по схеме
const gpio_pin_cfg_t gpio_init_array[GPIO_INIT_PINS_COUNT] = {
GPIO_PIN_CFG(GPIOE, GPIO_PIN_2, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_5, GPIO_STATE_OFF),		/*1, PE2,		SPI4_SCK,		OFF,		SCLK_DI_App*/
//GPIO_PIN_CFG(GPIOE, GPIO_PIN_3, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*2, PE3,		GPIO_Output,	ON,		Chr_Batt_App*/
GPIO_PIN_CFG(GPIOE, GPIO_PIN_4, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0, GPIO_STATE_ON),		/*3, PE4,		GPIO_Output,	ON,		CS_DO_App*/
GPIO_PIN_CFG(GPIOE, GPIO_PIN_5, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_5, GPIO_STATE_OFF),		/*4, PE5,		SPI4_MISO,		OFF,		MISO_DI_App*/
GPIO_PIN_CFG(GPIOE, GPIO_PIN_6, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_5, GPIO_STATE_OFF),		/*5, PE6,		SPI4_MOSI,		OFF,		MOSI_DI_App*/
GPIO_PIN_CFG(GPIOI, GPIO_PIN_8, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0, GPIO_STATE_ON),		/*7, PI8,		GPIO_Output,	ON,		CS_DI_App*/
GPIO_PIN_CFG(GPIOC, GPIO_PIN_13, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0, GPIO_STATE_ON),	/*8, PC13,		GPIO_Output,	ON,		CS_PTC_App*/
//GPIO_PIN_CFG(GPIOC, GPIO_PIN_14, , , , , GPIO_AF_ERR),																			/*9, PC14/		OSC32_IN,		OFF,		RCC_OSC32_IN, */
//GPIO_PIN_CFG(GPIOC, GPIO_PIN_15, , , , , GPIO_AF_ERR),																			/*10, PC15/		OSC32_OUT,		OFF,		RCC_OSC32_OUT, */
GPIO_PIN_CFG(GPIOI, GPIO_PIN_9, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0, GPIO_STATE_ON),		/*11, PI9,		GPIO_Output,	ON,		Reset_DI_App*/
GPIO_PIN_CFG(GPIOI, GPIO_PIN_10, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0, GPIO_STATE_OFF),	/*12, PI10,		GPIO_Input,		OFF,		Int_DI_App*/
//GPIO_PIN_CFG(GPIOI, GPIO_PIN_11, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*13, PI11,		GPIO_Output,	OFF,	nCLR_App*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_0, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*16, PF0,		FMC_A0,			OFF,		SRAM_A0_App*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_1, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*17, PF1,		FMC_A1,			OFF,		SRAM_A1_App*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_2, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*18, PF2,		FMC_A2,			OFF,		SRAM_A2_App*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_3, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*19, PF3,		FMC_A3,			OFF,		SRAM_A3_App*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_4, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*20, PF4,		FMC_A4,			OFF,		SRAM_A4_App*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_5, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*21, PF5,		FMC_A5,			OFF,		SRAM_A5_App*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_6, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_8),					/*24, PF6,		UART7_RX,		OFF,		Rx_Panel_App*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_7, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_8),					/*25, PF7,		UART7_TX,		OFF,		Tx_Panel_App*/
GPIO_PIN_CFG(GPIOF, GPIO_PIN_8, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_5, GPIO_STATE_OFF),		/*26, PF8,		SPI5_MISO,		OFF,		MISO_SPI5_App*/
GPIO_PIN_CFG(GPIOF, GPIO_PIN_9, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_5, GPIO_STATE_OFF),		/*27, PF9,		SPI5_MOSI,		OFF,		MOSI_SPI5_App*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_10, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*28, PF10,		GPIO_Input,		OFF,		Dip0_App*/
//GPIO_PIN_CFG(GPIOH, GPIO_PIN_0, , , , , GPIO_AF_ERR),																				/*29, PH0/		OSC_IN,			OFF,		RCC_OSC_IN, */
//GPIO_PIN_CFG(GPIOH, GPIO_PIN_1, , , , , GPIO_AF_ERR),																				/*30, PH1/		OSC_OUT,		OFF,		RCC_OSC_OUT, */
//GPIO_PIN_CFG(GPIOC, GPIO_PIN_0, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*32, PC0,		GPIO_Input,		OFF,		Dip1_App*/
//GPIO_PIN_CFG(GPIOC, GPIO_PIN_1, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_11),					/*33, PC1,		ETH_MDC,		OFF,		ETH_MDC_App*/
//GPIO_PIN_CFG(GPIOC, GPIO_PIN_2, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*34, PC2,		GPIO_Output,	OFF,	OutDis_I_AO_App*/
//GPIO_PIN_CFG(GPIOC, GPIO_PIN_3, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*35, PC3,		GPIO_Input,		OFF,		EmStop_App*/
GPIO_PIN_CFG(GPIOA, GPIO_PIN_0, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0, GPIO_STATE_OFF),	/*40, PA0/WKUP,	GPIO_Output,	OFF,	EN_DO_App*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_1, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_11),					/*41, PA1,		ETH_REF_CLK,	OFF,		ETH_OSCIN_App*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_2, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_11),					/*42, PA2,		ETH_MDIO,		OFF,		ETH_MDIO_App*/
//GPIO_PIN_CFG(GPIOH, GPIO_PIN_2, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*43, PH2,		GPIO_Output,	ON,		ETH_Reset_App*/
//GPIO_PIN_CFG(GPIOH, GPIO_PIN_3, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*44, PH3,		GPIO_Input,		OFF,		Board_In1_App*/
//GPIO_PIN_CFG(GPIOH, GPIO_PIN_4, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*45, PH4,		GPIO_Input,		OFF,		Board_In2_App*/
GPIO_PIN_CFG(GPIOH, GPIO_PIN_5, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0, GPIO_STATE_ON),		/*46, PH5,		GPIO_Output,	ON,		CS_SPI5_App*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_3, , , , , GPIO_AF_ERR),																				/*47, PA3,		ADC1_IN3,		OFF,		Board_AI_App*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_4, , , , , GPIO_AF_ERR),																				/*50, PA4,		DAC_OUT1,		OFF,		Board_AO_App*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_5, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_5),					/*51, PA5,		SPI1_SCK,		OFF,		SPI_SCK_App_MC*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_6, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_5),					/*52, PA6,		SPI1_MISO,		OFF,		SPI_MISO_App_MC*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_7, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_11),					/*53, PA7,		ETH_CRS_DV,		OFF,		ETH_CRS_DV_App*/
//GPIO_PIN_CFG(GPIOC, GPIO_PIN_4, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_11),					/*54, PC4,		ETH_RXD0,		OFF,		ETH_RXD0_App*/
//GPIO_PIN_CFG(GPIOC, GPIO_PIN_5, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_11),					/*55, PC5,		ETH_RXD1,		OFF,		ETH_RXD1_App*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_0, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*56, PB0,		GPIO_Output,	OFF,	Board_Out3_App*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_1, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*57, PB1,		GPIO_Output,	OFF,	Board_Out4_App*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_2, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*58, PB2/BOOT1,GPIO_Input,		OFF,		BOOT1*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_11, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*59, PF11,		GPIO_Output,	OFF,	NAND_nWP_App*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_12, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*60, PF12,		FMC_A6,			OFF,		SRAM_A6_App*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_13, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*63, PF13,		FMC_A7,			OFF,		SRAM_A7_App*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_14, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*64, PF14,		FMC_A8,			OFF,		SRAM_A8_App*/
//GPIO_PIN_CFG(GPIOF, GPIO_PIN_15, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*65, PF15,		FMC_A9,			OFF,		SRAM_A9_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_0, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*66, PG0,		FMC_A10,		OFF,		SRAM_A10_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_1, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*67, PG1,		FMC_A11,		OFF,		SRAM_A11_App*/
//GPIO_PIN_CFG(GPIOE, GPIO_PIN_7, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*68, PE7,		FMC_D4,			OFF,		SRAM_NAND_IO4_App*/
//GPIO_PIN_CFG(GPIOE, GPIO_PIN_8, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*69, PE8,		FMC_D5,			OFF,		SRAM_NAND_IO5_App*/
//GPIO_PIN_CFG(GPIOE, GPIO_PIN_9, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*70, PE9,		FMC_D6,			OFF,		SRAM_NAND_IO6_App*/
//GPIO_PIN_CFG(GPIOE, GPIO_PIN_10, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*73, PE10,		FMC_D7,			OFF,		SRAM_NAND_IO7_App*/
//GPIO_PIN_CFG(GPIOE, GPIO_PIN_11, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*74, PE11,		FMC_D8,			OFF,		SRAM_IO8_App*/
//GPIO_PIN_CFG(GPIOE, GPIO_PIN_12, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*75, PE12,		FMC_D9,			OFF,		SRAM_IO9_App*/
//GPIO_PIN_CFG(GPIOE, GPIO_PIN_13, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*76, PE13,		FMC_D10,		OFF,		SRAM_IO10_App*/
//GPIO_PIN_CFG(GPIOE, GPIO_PIN_14, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*77, PE14,		FMC_D11,		OFF,		SRAM_IO11_App*/
//GPIO_PIN_CFG(GPIOE, GPIO_PIN_15, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*78, PE15,		FMC_D12,		OFF,		SRAM_IO12_App*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_10, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_7),					/*79, PB10,		USART3_TX,		OFF,		Tx1_485_App*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_11, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_7),					/*80, PB11,		USART3_RX,		OFF,		Rx1_485_App*/
GPIO_PIN_CFG(GPIOH, GPIO_PIN_6, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_5, GPIO_STATE_OFF),		/*83, PH6,		SPI5_SCK,		OFF,		CLK_SPI5_App*/
//GPIO_PIN_CFG(GPIOH, GPIO_PIN_7, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*84, PH7,		GPIO_Input,		OFF,		Lost_5V_App*/
//GPIO_PIN_CFG(GPIOH, GPIO_PIN_8, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*85, PH8,		GPIO_Output,	OFF,	Dir1_485_App*/
//GPIO_PIN_CFG(GPIOH, GPIO_PIN_9, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*86, PH9,		GPIO_Input,		OFF,		Panel_Detect_App*/
GPIO_PIN_CFG(GPIOH, GPIO_PIN_10, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_2, GPIO_STATE_OFF),	/*87, PH10,		TIM5_CH1,		OFF,		B_LED_App*/
GPIO_PIN_CFG(GPIOH, GPIO_PIN_11, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_2, GPIO_STATE_OFF),	/*88, PH11,		TIM5_CH2,		OFF,		G_LED_App*/
GPIO_PIN_CFG(GPIOH, GPIO_PIN_12, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_2, GPIO_STATE_OFF),	/*89, PH12,		TIM5_CH3,		OFF,		R_LED_App*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_12, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_11),					/*92, PB12,		ETH_TXD0,		OFF,		ETH_TXD0_App*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_13, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_11),					/*93, PB13,		ETH_TXD1,		OFF,		ETH_TXD1_App*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_14, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*94, PB14,		GPIO_Input,		OFF,		AC_lost_App*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_15, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*95, PB15,		GPIO_Input,		OFF,		RVS2_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_8, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*96, PD8,		FMC_D13,		OFF,		SRAM_IO13_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_9, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*97, PD9,		FMC_D14,		OFF,		SRAM_IO14_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_10, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*98, PD10,		FMC_D15,		OFF,		SRAM_IO15_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_11, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*99, PD11,		FMC_A16 FMC_CLE,OFF,		SRAM_NAND_A16_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_12, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*100, PD12,	FMC_A17 FMC_ALE,OFF,		SRAM_NAND_A17_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_13, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*101, PD13,	FMC_A18,		OFF,		SRAM_A18_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_14, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*104, PD14,	FMC_D0,			OFF,		SRAM_NAND_IO0_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_15, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*105, PD15,	FMC_D1,			OFF,		SRAM_NAND_IO1_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_2, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*106, PG2,		FMC_A12,		OFF,		SRAM_A12_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_3, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*107, PG3,		FMC_A13,		OFF,		SRAM_A13_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_4, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*108, PG4,		FMC_A14,		OFF,		SRAM_A14_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_5, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*109, PG5,		FMC_A15,		OFF,		SRAM_A15_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_6, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*110, PG6,		GPIO_Output,	ON,		ResetAI_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_7, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*111, PG7,		GPIO_Input,		OFF,		ErrorAO1_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_8, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*112, PG8,		GPIO_Input,		OFF,		ErrorAO2_App*/
GPIO_PIN_CFG(GPIOC, GPIO_PIN_6, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_8, GPIO_STATE_OFF),		/*115, PC6,		USART6_TX,		OFF,		Tx_UART6_App*/
GPIO_PIN_CFG(GPIOC, GPIO_PIN_7, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_8, GPIO_STATE_OFF),		/*116, PC7,		USART6_RX,		OFF,		Rx_UART6_App*/
//GPIO_PIN_CFG(GPIOC, GPIO_PIN_8, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*117, PC8,		SDIO_D0,		OFF,		SDIO_DAT0_App*/
//GPIO_PIN_CFG(GPIOC, GPIO_PIN_9, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*118, PC9,		GPIO_Output,	ON,		SDIO_PWR_App*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_8, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*119, PA8,		GPIO_Input,		OFF,		SDIO_CD_App*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_9, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_7),					/*120, PA9,		USART1_TX,		OFF,		UART_Tx_App_Jmp*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_10, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_7),					/*121, PA10,	USART1_RX,		OFF,		UART_Rx_App_Jmp*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_11, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*122, PA11,	GPIO_Input,		OFF,		RVS1_App*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_12, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*123, PA12,	GPIO_Output,	OFF,	NC*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_13, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*124, PA13,	SYS_JTMS-SWDIO,	OFF,		SWDIO_App*/
//GPIO_PIN_CFG(GPIOH, GPIO_PIN_13, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*128, PH13,	GPIO_Output,	ON,		SYNCAO_App*/
//GPIO_PIN_CFG(GPIOH, GPIO_PIN_14, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*129, PH14,	GPIO_Output,	ON,		CS1AI_App*/
//GPIO_PIN_CFG(GPIOH, GPIO_PIN_15, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*130, PH15,	GPIO_Output,	ON,		CS2AI_App*/
GPIO_PIN_CFG(GPIOI, GPIO_PIN_0, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0, GPIO_STATE_ON),		/*131, PI0,		GPIO_Output,	ON,		OE_App*/
//GPIO_PIN_CFG(GPIOI, GPIO_PIN_1, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_5),					/*132, PI1,		SPI2_SCK,		OFF,		SCLKAIO_App*/
//GPIO_PIN_CFG(GPIOI, GPIO_PIN_2, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_5),					/*133, PI2,		SPI2_MISO,		OFF,		MISOAIO_App*/
//GPIO_PIN_CFG(GPIOI, GPIO_PIN_3, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_5),					/*134, PI3,		SPI2_MOSI,		OFF,		MOSIAIO_App*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_14, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*137, PA14,	SYS_JTCK-SWCLK,	OFF,		SWDCLK_App*/
//GPIO_PIN_CFG(GPIOA, GPIO_PIN_15, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_5),					/*138, PA15,	SPI1_NSS,		OFF,		SPI_CS_App_MC*/
//GPIO_PIN_CFG(GPIOC, GPIO_PIN_10, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_8),					/*139, PC10,	UART4_TX,		OFF,		Tx2_485_App_Jmp*/
//GPIO_PIN_CFG(GPIOC, GPIO_PIN_11, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_8),					/*140, PC11,	UART4_RX,		OFF,		Rx2_485_App_Jmp*/
//GPIO_PIN_CFG(GPIOC, GPIO_PIN_12, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*141, PC12,	SDIO_CK,		OFF,		SDIO_CLK_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_0, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*142, PD0,		FMC_D2,			OFF,		SRAM_NAND_IO2_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_1, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*143, PD1,		FMC_D3,			OFF,		SRAM_NAND_IO3_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_2, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*144, PD2,		SDIO_CMD,		OFF,		SDIO_CMD_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_3, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*145, PD3,		GPIO_Output,	OFF,	Dir2_485_App_Jmp*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_4, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*146, PD4,		FMC_NOE,		OFF,		SRAM_NAND_nOE_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_5, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*147, PD5,		FMC_NWE,		OFF,		SRAM_NAND_nWE_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_6, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*150, PD6,		FMC_NWAIT,		OFF,		NAND_R\nB_App*/
//GPIO_PIN_CFG(GPIOD, GPIO_PIN_7, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*151, PD7,		FMC_NE1,		OFF,		SRAM_nCE_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_9, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*152, PG9,		FMC_NCE3,		OFF,		NAND_nCE_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_10, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*153, PG10,	GPIO_Output,	OFF,	nLDAC_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_11, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_11),					/*154, PG11,	ETH_TX_EN,		OFF,		ETH_TX_EN_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_12, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*155, PG12,	GPIO_Output,	OFF,	Relay1_DO_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_13, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*156, PG13,	GPIO_Output,	OFF,	Relay2_DO_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_14, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*157, PG14,	GPIO_Output,	OFF,	Relay3_DO_App*/
//GPIO_PIN_CFG(GPIOG, GPIO_PIN_15, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*160, PG15,	GPIO_Output,	OFF,	Relay4_DO_App*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_3, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*161, PB3,		SYS_JTDO-SWO,	OFF,		SWO_App*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_4, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*162, PB4,		GPIO_Input,		OFF,		IO0_App_MC*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_5, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_5),					/*163, PB5,		SPI1_MOSI,		OFF,		SPI_MOSI_App_MC*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_6, GPIO_MODE_OUT, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*164, PB6,		GPIO_Output,	OFF,	Dir_Panel_App*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_7, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*165, PB7,		GPIO_Input,		OFF,		IO1_App_MC*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_8, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_9),					/*167, PB8,		CAN1_RX,		OFF,		APP_CAN_RX*/
//GPIO_PIN_CFG(GPIOB, GPIO_PIN_9, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_9),					/*168, PB9,		CAN1_TX,		OFF,		APP_CAN_TX*/
//GPIO_PIN_CFG(GPIOE, GPIO_PIN_0, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*169, PE0,		FMC_NBL0,		OFF,		SRAM_nBLE_App*/
//GPIO_PIN_CFG(GPIOE, GPIO_PIN_1, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_12),					/*170, PE1,		FMC_NBL1,		OFF,		SRAM_nBHE_App*/
//GPIO_PIN_CFG(GPIOI, GPIO_PIN_4, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*173, PI4,		GPIO_Input,		OFF,		Board_ID0_App*/
//GPIO_PIN_CFG(GPIOI, GPIO_PIN_5, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*174, PI5,		GPIO_Input,		OFF,		Board_ID1_App*/
//GPIO_PIN_CFG(GPIOI, GPIO_PIN_6, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*175, PI6,		GPIO_Input,		OFF,		Board_ID2_App*/
//GPIO_PIN_CFG(GPIOI, GPIO_PIN_7, GPIO_MODE_IN, GPIO_OTYPE_PP, GPIO_OSPEED_VERY_HIGH, GPIO_PUPD_NONE, GPIO_AF_0),					/*176, PI7,		GPIO_Input,		OFF,		Board_ID3_App*/
};
/*Elements count OK*/
