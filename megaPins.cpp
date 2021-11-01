#include "megaPins.h"

const uint8_t megaPins::portMap[54][3] = {"E0", "E1", "E4", "E5", "G5", "E3", "H3", "H4",
                                          "H5", "H6", "B4", "B5", "B6", "B7", "J1", "J0",
                                          "H1", "H0", "D3", "D2", "D1", "D0", "A0", "A1",
                                          "A2", "A3", "A4", "A5", "A6", "A7", "B7", "B6",
                                          "B5", "B4", "B3", "B2", "B1", "B0", "D7", "G2",
                                          "G1", "G0", "L7", "L6", "L5", "L4", "L3", "L2",
                                          "L1", "L0", "B3", "B2", "B1", "B0"};

megaPins::megaPins(const uint8_t pin) : Port(portMap[pin][0]), Bit(portMap[pin][1] - '0') {}

uint8_t megaPins::getPort()
{
    return this->Port;
}

uint8_t megaPins::getPortBit()
{
    return this->Bit;
}

void megaPins::setBit(RegType reg)
{
    if (reg == DDRx)
    {
        switch (this->Port)
        {
        case 'A':
            DDRA |= 1 << Bit;
            break;
        case 'B':
            DDRB |= 1 << Bit;
            break;
        case 'D':
            DDRD |= 1 << Bit;
            break;
        case 'E':
            DDRE |= 1 << Bit;
            break;
        case 'G':
            DDRG |= 1 << Bit;
            break;
        case 'H':
            DDRH |= 1 << Bit;
            break;
        case 'J':
            DDRJ |= 1 << Bit;
            break;
        case 'L':
            DDRL |= 1 << Bit;
            break;

        default:
            break;
        }
    }
    else if (reg == PORTx)
    {
        switch (this->Port)
        {
        case 'A':
            PORTA |= 1 << Bit;
            break;
        case 'B':
            PORTB |= 1 << Bit;
            break;
        case 'D':
            PORTD |= 1 << Bit;
            break;
        case 'E':
            PORTE |= 1 << Bit;
            break;
        case 'G':
            PORTG |= 1 << Bit;
            break;
        case 'H':
            PORTH |= 1 << Bit;
            break;
        case 'J':
            PORTJ |= 1 << Bit;
            break;
        case 'L':
            PORTL |= 1 << Bit;
            break;

        default:
            break;
        }
    }
    else if (reg == PINx)
    {
        switch (this->Port)
        {
        case 'A':
            PINA |= 1 << Bit;
            break;
        case 'B':
            PINB |= 1 << Bit;
            break;
        case 'D':
            PIND |= 1 << Bit;
            break;
        case 'E':
            PINE |= 1 << Bit;
            break;
        case 'G':
            PING |= 1 << Bit;
            break;
        case 'H':
            PINH |= 1 << Bit;
            break;
        case 'J':
            PINJ |= 1 << Bit;
            break;
        case 'L':
            PINL |= 1 << Bit;
            break;

        default:
            break;
        }
    }
}

void megaPins::setBit(const RegType reg, const uint8_t port, const uint8_t bit)
{
    if (reg == DDRx)
    {
        switch (port)
        {
        case 'A':
            DDRA |= 1 << bit;
            break;
        case 'B':
            DDRB |= 1 << bit;
            break;
        case 'D':
            DDRD |= 1 << bit;
            break;
        case 'E':
            DDRE |= 1 << bit;
            break;
        case 'G':
            DDRG |= 1 << bit;
            break;
        case 'H':
            DDRH |= 1 << bit;
            break;
        case 'J':
            DDRJ |= 1 << bit;
            break;
        case 'L':
            DDRL |= 1 << bit;
            break;

        default:
            break;
        }
    }
    else if (reg == PORTx)
    {
        switch (port)
        {
        case 'A':
            PORTA |= 1 << bit;
            break;
        case 'B':
            PORTB |= 1 << bit;
            break;
        case 'D':
            PORTD |= 1 << bit;
            break;
        case 'E':
            PORTE |= 1 << bit;
            break;
        case 'G':
            PORTG |= 1 << bit;
            break;
        case 'H':
            PORTH |= 1 << bit;
            break;
        case 'J':
            PORTJ |= 1 << bit;
            break;
        case 'L':
            PORTL |= 1 << bit;
            break;

        default:
            break;
        }
    }
    else if (reg == PINx)
    {
        switch (port)
        {
        case 'A':
            PINA |= 1 << bit;
            break;
        case 'B':
            PINB |= 1 << bit;
            break;
        case 'D':
            PIND |= 1 << bit;
            break;
        case 'E':
            PINE |= 1 << bit;
            break;
        case 'G':
            PING |= 1 << bit;
            break;
        case 'H':
            PINH |= 1 << bit;
            break;
        case 'J':
            PINJ |= 1 << bit;
            break;
        case 'L':
            PINL |= 1 << bit;
            break;

        default:
            break;
        }
    }
}

void megaPins::setBit(const RegType reg, const uint8_t pin)
{
    const uint8_t port = portMap[pin][0];
    const uint8_t bit = portMap[pin][1] - '0';

    setBit(reg, port, bit);
}

void megaPins::clearBit(RegType reg)
{
    if (reg == DDRx)
    {
        switch (this->Port)
        {
        case 'A':
            DDRA &= ~(1 << Bit);
            break;
        case 'B':
            DDRB &= ~(1 << Bit);
            break;
        case 'D':
            DDRD &= ~(1 << Bit);
            break;
        case 'E':
            DDRE &= ~(1 << Bit);
            break;
        case 'G':
            DDRG &= ~(1 << Bit);
            break;
        case 'H':
            DDRH &= ~(1 << Bit);
            break;
        case 'J':
            DDRJ &= ~(1 << Bit);
            break;
        case 'L':
            DDRL &= ~(1 << Bit);
            break;

        default:
            break;
        }
    }
    else if (reg == PORTx)
    {
        switch (this->Port)
        {
        case 'A':
            PORTA &= ~(1 << Bit);
            break;
        case 'B':
            PORTB &= ~(1 << Bit);
            break;
        case 'D':
            PORTD &= ~(1 << Bit);
            break;
        case 'E':
            PORTE &= ~(1 << Bit);
            break;
        case 'G':
            PORTG &= ~(1 << Bit);
            break;
        case 'H':
            PORTH &= ~(1 << Bit);
            break;
        case 'J':
            PORTJ &= ~(1 << Bit);
            break;
        case 'L':
            PORTL &= ~(1 << Bit);
            break;

        default:
            break;
        }
    }
    else if (reg == PINx)
    {
        switch (this->Port)
        {
        case 'A':
            PINA &= ~(1 << Bit);
            break;
        case 'B':
            PINB &= ~(1 << Bit);
            break;
        case 'D':
            PIND &= ~(1 << Bit);
            break;
        case 'E':
            PINE &= ~(1 << Bit);
            break;
        case 'G':
            PING &= ~(1 << Bit);
            break;
        case 'H':
            PINH &= ~(1 << Bit);
            break;
        case 'J':
            PINJ &= ~(1 << Bit);
            break;
        case 'L':
            PINL &= ~(1 << Bit);
            break;

        default:
            break;
        }
    }
}

void megaPins::clearBit(const RegType reg, const uint8_t port, const uint8_t bit)
{
    if (reg == DDRx)
    {
        switch (port)
        {
        case 'A':
            DDRA &= ~(1 << bit);
            break;
        case 'B':
            DDRB &= ~(1 << bit);
            break;
        case 'D':
            DDRD &= ~(1 << bit);
            break;
        case 'E':
            DDRE &= ~(1 << bit);
            break;
        case 'G':
            DDRG &= ~(1 << bit);
            break;
        case 'H':
            DDRH &= ~(1 << bit);
            break;
        case 'J':
            DDRJ &= ~(1 << bit);
            break;
        case 'L':
            DDRL &= ~(1 << bit);
            break;

        default:
            break;
        }
    }
    else if (reg == PORTx)
    {
        switch (port)
        {
        case 'A':
            PORTA &= ~(1 << bit);
            break;
        case 'B':
            PORTB &= ~(1 << bit);
            break;
        case 'D':
            PORTD &= ~(1 << bit);
            break;
        case 'E':
            PORTE &= ~(1 << bit);
            break;
        case 'G':
            PORTG &= ~(1 << bit);
            break;
        case 'H':
            PORTH &= ~(1 << bit);
            break;
        case 'J':
            PORTJ &= ~(1 << bit);
            break;
        case 'L':
            PORTL &= ~(1 << bit);
            break;

        default:
            break;
        }
    }
    else if (reg == PINx)
    {
        switch (port)
        {
        case 'A':
            PINA &= ~(1 << bit);
            break;
        case 'B':
            PINB &= ~(1 << bit);
            break;
        case 'D':
            PIND &= ~(1 << bit);
            break;
        case 'E':
            PINE &= ~(1 << bit);
            break;
        case 'G':
            PING &= ~(1 << bit);
            break;
        case 'H':
            PINH &= ~(1 << bit);
            break;
        case 'J':
            PINJ &= ~(1 << bit);
            break;
        case 'L':
            PINL &= ~(1 << bit);
            break;

        default:
            break;
        }
    }
}

void megaPins::clearBit(const RegType reg, const uint8_t pin)
{
    const uint8_t port = portMap[pin][0];
    const uint8_t bit = portMap[pin][1] - '0';

    clearBit(reg, port, bit);
}

void megaPins::setPinMode(GPIO_Mode mode)
{
    if (mode == GPIO_INPUT)
        this->clearBit(DDRx);
    else if (mode == GPIO_OUTPUT)
        this->setBit(DDRx);
}

void megaPins::setPinMode(GPIO_Mode mode, const uint8_t port, const uint8_t bit)
{
    if (mode == GPIO_INPUT)
        clearBit(DDRx, port, bit);
    else if (mode == GPIO_OUTPUT)
        setBit(DDRx, port, bit);
}

void megaPins::setPinMode(GPIO_Mode mode, const uint8_t pin)
{
    const uint8_t port = portMap[pin][0];
    const uint8_t bit = portMap[pin][1] - '0';

    setPinMode(mode, port, pin);
}

void megaPins::GPIO_DigitalWrite(bool value)
{
    if (value)
        this->setBit(PORTx);
    else
        this->clearBit(PORTx);
}

void megaPins::GPIO_DigitalWrite(bool value, const uint8_t port, const uint8_t bit)
{
    if (value)
        setBit(PORTx, port, bit);
    else
        clearBit(PORTx, port, bit);
}

void megaPins::GPIO_DigitalWrite(bool value, const uint8_t pin)
{
    const uint8_t port = portMap[pin][0];
    const uint8_t bit = portMap[pin][1] - '0';

    GPIO_DigitalWrite(value, port, bit);
}