/*!
 * @file
 * @brief
 */

#include <Arduino.h>
#include <SPI.h>
#include "tiny_spi.h"
#include "tiny_utils.h"

static uint8_t transfer(i_tiny_spi_t* _self, uint8_t value) {
  reinterpret(self, _self, tiny_spi_t*);
  SPI.beginTransaction(
    SPISettings(
      self->_private.baud,
      static_cast<decltype(MSBFIRST)>(self->_private.bitOrder),
      self->_private.mode));
  return SPI.transfer(value);
}

static const i_tiny_spi_api_t api = { transfer };

extern "C" void tiny_spi_init(tiny_spi_t* self, uint32_t baud, uint8_t bitOrder, uint8_t mode) {
  self->interface.api = &api;
  self->_private.baud = baud;
  self->_private.bitOrder = bitOrder;
  self->_private.mode = mode;

  SPI.begin();
}
