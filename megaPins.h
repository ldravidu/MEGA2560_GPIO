#ifndef MEGA_PINS_H
#define MEGA_PINS_H

#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef _STDINT
#include <stdint.h>
#endif

class megaPins
{
private:
    const uint8_t Port;
    const uint8_t Bit;

protected:
    static const uint8_t portMap[54][3];

public:
    megaPins(const uint8_t pin);

    enum GPIO_Mode
    {
        GPIO_INPUT,
        GPIO_OUTPUT
    };

    enum RegType
    {
        DDRx,
        PORTx,
        PINx
    };

    uint8_t getPort();
    uint8_t getPortBit();

    void setBit(const RegType reg);
    static void setBit(const RegType reg, const uint8_t port, const uint8_t bit);
    static void setBit(const RegType reg, const uint8_t pin);

    void clearBit(const RegType reg);
    static void clearBit(const RegType reg, const uint8_t port, const uint8_t bit);
    static void clearBit(const RegType reg, const uint8_t pin);

    void setPinMode(GPIO_Mode mode);
    static void setPinMode(GPIO_Mode mode, const uint8_t port, const uint8_t bit);
    static void setPinMode(GPIO_Mode mode, const uint8_t pin);

    void GPIO_DigitalWrite(bool value);
    static void GPIO_DigitalWrite(bool value, const uint8_t port, const uint8_t bit);
    static void GPIO_DigitalWrite(bool value, const uint8_t pin);
};

#endif