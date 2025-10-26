#include "gpio_interface.h"

#ifdef __APPLE__
#include "gpio_mock.cpp"
#else
#include "gpio_lgpio.cpp"
#endif

int main() {
    IGPIO* gpio;

#ifdef __APPLE__
    gpio = new MockGPIO();
#else
    gpio = new LgGPIO();
#endif

    gpio->write(4, 1);                  // simulate writing to pin 4
    int val = gpio->read(4);            // read pin 4
    std::cout << "Read pin 4 = " << val << std::endl;

    delete gpio;
    return 0;
}
