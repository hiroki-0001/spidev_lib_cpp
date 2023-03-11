#ifndef _SPI_LIB_HPP
#define _SPI_LIB_HPP

#include <stdint.h>
#include <string>

typedef struct {
    uint8_t mMode;
    uint8_t mBits_per_word;
    uint32_t mSpeed;
    uint16_t mDelay;
} spi_config_t;

class SPI{
    private:
        const std::string mDevice;
        int mSpifd;
        bool mOpen;
        spi_config_t mSpiconfig;

    public:
        SPI(const std::string& device);
        ~SPI();
        bool setSpeed(uint32_t speed);
        bool setMode(uint8_t mode);
        bool setBitPerWord(uint8_t bit);

};

#endif