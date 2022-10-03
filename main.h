#include <stdint.h>

#ifndef MAIN_H_
#define MAIN_H_

typedef struct 
{
    uint32_t gpio_a_en      :1;
    uint32_t gpio_b_en      :1;
    uint32_t gpio_c_en      :1;
    uint32_t gpio_d_en      :1;
    uint32_t gpio_e_en      :1;
    uint32_t gpio_f_en      :1;
    uint32_t gpio_g_en      :1;
    uint32_t gpio_h_en      :1;
    uint32_t gpio_i_en      :1;
    uint32_t reserved0      :3;
    uint32_t crc_en         :1;
    uint32_t reserved1      :5;
    uint32_t bkp_sram_en    :1;
    uint32_t reserved2      :1;
    uint32_t ccm_dataram_en :1;
    uint32_t dma1_en        :1;
    uint32_t dma2_en        :1;
    uint32_t reserved3      :2;
    uint32_t ethmac_en      :1;   // ethernet mac clock enable
    uint32_t ethmac_tx_en   :1;   // ethernet write/transmit clock enable
    uint32_t ethmac_rx_en   :1;   // ethernet read/receive clock enable 
    uint32_t ethmac_ptp_en  :1;   // ethernet p2p clock enable
    uint32_t otg_hs_en      :1;   // usb otg hs clock enable 
    uint32_t otg_hs_ulpi_en :1;
    uint32_t reserved4      :1;
} RCC_AHB1ENR_t;

// gpio mode register
typedef struct
{
    uint32_t moder_0  :2;
    uint32_t moder_1  :2;
    uint32_t moder_2  :2;
    uint32_t moder_3  :2;
    uint32_t moder_4  :2;
    uint32_t moder_5  :2;
    uint32_t moder_6  :2;
    uint32_t moder_7  :2;
    uint32_t moder_8  :2;
    uint32_t moder_9  :2;
    uint32_t moder_10 :2;
    uint32_t moder_11 :2;
    uint32_t moder_12 :2;
    uint32_t moder_13 :2;
    uint32_t moder_14 :2;
    uint32_t moder_15 :2;
} GPIOx_MODE_REGSTR_t;

// gpio output data register
typedef struct
{
    uint32_t odr_0      :1;
    uint32_t odr_1      :1;
    uint32_t odr_2      :1;
    uint32_t odr_3      :1;
    uint32_t odr_4      :1;
    uint32_t odr_5      :1;
    uint32_t odr_6      :1;
    uint32_t odr_7      :1;
    uint32_t odr_8      :1;
    uint32_t odr_9      :1;
    uint32_t odr_10     :1;
    uint32_t odr_11     :1;
    uint32_t odr_12     :1;
    uint32_t odr_13     :1;
    uint32_t odr_14     :1;
    uint32_t odr_15     :1;
    uint32_t reserved   :15;
} GPIO_OUTPUT_DATA_REGSTR_t;

enum LED {
    OFF = (uint32_t)0,
    ON = (uint32_t)1
};
// typedef enum : uint32_t {
//     OFF,
//     ON
// } LED_t;

#endif /* MAIN_H_ */