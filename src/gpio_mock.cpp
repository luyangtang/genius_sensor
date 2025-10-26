#include "gpio_interface.h"
#include <iostream>
#include <unordered_map>
#include <cstdlib>  // for rand()

class MockGPIO : public IGPIO {
private:
    std::unordered_map<int, int> pin_states;  // track pin values
public:
    int read(int pin) override {
        // Return stored state, or simulate input
        if (pin_states.find(pin) != pin_states.end()) {
            return pin_states[pin];
        }
        // Random 0/1 for simulation
        return rand() % 2;
    }

    void write(int pin, int value) override {
        pin_states[pin] = value;
        std::cout << "[MockGPIO] pin " << pin << " set to " << value << std::endl;
    }
};
