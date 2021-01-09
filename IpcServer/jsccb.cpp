#include "jsccb.h"

#include "jexception.h"
#include <fcntl.h>
#include <sys/ioctl.h>

#define I2C_DEV  "/dev/gpioi2c"

JSccb::JSccb(int addr)
    :_addr(addr)
{
    _fd = open(I2C_DEV, O_RDWR);
    if(_fd < 0) THROW_ERRNO("open %s", I2C_DEV);
}

JSccb::~JSccb()
{
    close(_fd);
}

int JSccb::Value(int reg)
{
    int value = ((_addr&0xff)<<24) | ((reg&0xff)<<16);

    int ret = ioctl(_fd, 0x01, &value);
    if (ret != 0) THROW_ERRNO("ioctl r,%x:%x", _addr, reg);

    value &= 0xff;

    return value;
}

void JSccb::SetValue(int reg, int v)
{
    int value = ((_addr&0xff)<<24) | ((reg&0xff)<<16) | (v&0xff);

    int ret = ioctl(_fd, 0x03, &value);
    if(ret != 0) THROW_ERRNO("ioctl w,%x:%x=%x", _addr, reg, v);
}
