#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <string.h>
#include <iostream>

#include <linux/spi/spidev.h>

#include "spidev.hpp"

SPI::SPI(const std::string& device) : mDevice(device)
{
	if ((mSpifd = open(mDevice.c_str(), O_RDWR)) < 0) {
		throw std::runtime_error("Unable to open device");
	}
}

SPI::~SPI(){
}

bool SPI::setBitPerWord(uint8_t p_bit){
    /* Set bits per word*/
    if (ioctl(mSpifd, SPI_IOC_WR_BITS_PER_WORD, &p_bit) < 0) {
        return false;
    }
    if (ioctl(mSpifd, SPI_IOC_RD_BITS_PER_WORD, &p_bit) < 0) {
        return false;
    }
    m_spiconfig.bits_per_word = p_bit;
    return true;
}

bool SPI::setSpeed(uint32_t speed){
    /* Set SPI speed*/
    if (ioctl(mSpifd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0) {
        return false;
    }
    if (ioctl(mSpifd, SPI_IOC_RD_MAX_SPEED_HZ, &speed) < 0) {
        return false;
    }
    m_spiconfig.speed = speed;
    return true;
}

bool SPI::setMode(uint8_t mode){
    /* Set SPI_POL and SPI_PHA */
    if (ioctl(mSpifd, SPI_IOC_WR_MODE, &mode) < 0) {
        return false;
    }
    if (ioctl(mSpifd, SPI_IOC_RD_MODE, &mode) < 0) {
        return false;
    }
    m_spiconfig.mode = mode;
    return true;


}