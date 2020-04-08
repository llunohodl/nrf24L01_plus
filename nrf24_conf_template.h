#ifndef NRF24_conf
#define NRF24_conf

#include "nRF24L01.h"
#include <stdint.h>


#define nrf24_CONFIG ((1<<EN_CRC)|(0<<CRCO))
#define nrf24_ART 3 //retransmit trials up to 15

// 1 Mbps, TX gain: 0dbm
//#define nrf24_RFsetup (0<<RF_DR)|((0x03)<<RF_PWR)

// 2 Mbps, TX gain: -18dbm
#define nrf24_RFsetup (1<<RF_DR)|((0x00)<<RF_PWR)

/* low level interface ... */
//uint8_t spi_transfer(uint8_t tx);
uint8_t nrf24_spi_transfer(uint8_t tx);
#define spi_transfer(tx) nrf24_spi_transfer(tx)

/* -------------------------------------------------------------------------- */
/* You should implement the platform spesific functions in your code */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* In this function you should do the following things:
 *    - Set MISO pin input
 *    - Set MOSI pin output
 *    - Set SCK pin output
 *    - Set CSN pin output
 *    - Set CE pin output     */
/* -------------------------------------------------------------------------- */
extern void nrf24_setupPins();

/* -------------------------------------------------------------------------- */
/* nrf24 CE pin control function
 *    - state:1 => Pin HIGH
 *    - state:0 => Pin LOW     */
/* -------------------------------------------------------------------------- */
extern void nrf24_ce_digitalWrite(uint8_t state);

/* -------------------------------------------------------------------------- */
/* nrf24 CE pin control function
 *    - state:1 => Pin HIGH
 *    - state:0 => Pin LOW     */
/* -------------------------------------------------------------------------- */
extern void nrf24_csn_digitalWrite(uint8_t state);

/* -------------------------------------------------------------------------- */
/* nrf24 SCK pin control function
 *    - state:1 => Pin HIGH
 *    - state:0 => Pin LOW     */
/* -------------------------------------------------------------------------- */
extern void nrf24_sck_digitalWrite(uint8_t state);

/* -------------------------------------------------------------------------- */
/* nrf24 MOSI pin control function
 *    - state:1 => Pin HIGH
 *    - state:0 => Pin LOW     */
/* -------------------------------------------------------------------------- */
extern void nrf24_mosi_digitalWrite(uint8_t state);

/* -------------------------------------------------------------------------- */
/* nrf24 MISO pin read function
 * - returns: Non-zero if the pin is high */
/* -------------------------------------------------------------------------- */
extern uint8_t nrf24_miso_digitalRead();

/* -------------------------------------------------------------------------- */
/* nrf24 IRQ pin read function
 * - returns: Non-zero if the pin is low */
/* -------------------------------------------------------------------------- */
extern uint8_t nrf24_irq_digitalRead();

#endif //NRF24_conf