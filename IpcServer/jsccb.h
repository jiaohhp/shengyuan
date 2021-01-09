#ifndef JSCCB_H
#define JSCCB_H

class JSccb
{
public:
    JSccb(int addr);
    ~JSccb();
    int Value(int reg);
    void SetValue(int reg, int value);
private:
    int _fd;
    int _addr;
};

#endif // JSCCB_H
