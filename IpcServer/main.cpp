#include "jsccb.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(argc < 3 )
    {
        printf("%s i2c_addr reg [value]", argv[0]);
        return 0;
    }
    int addr = strtol(argv[1], NULL, 16);
    int reg = strtol(argv[2], NULL, 16);
    if(argc == 3) // read
    {
        printf("%02x:%02x=%02x", addr, reg, JSccb(addr).Value(reg));
    }
    else
    {
        int value = strtol(argv[3], NULL, 16);
        JSccb(addr).SetValue(reg, value);
        printf("%02x:%02x=%02x", addr, reg, JSccb(addr).Value(reg));
    }
    return 0;
}
