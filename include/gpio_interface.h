#pragma once

class IGPIO {
public:
    virtual int read(int pin) = 0;        // read pin value (0 or 1)
    virtual void write(int pin, int value) = 0; // write pin value
    virtual ~IGPIO() {}
};