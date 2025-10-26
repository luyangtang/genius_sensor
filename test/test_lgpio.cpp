#include <lgpio.h>
#include <iostream>

int main() {
    int h = lgGpiochipOpen(0);          // Open /dev/gpiochip0
    if (h < 0) {
        std::cerr << "Failed to open gpiochip" << std::endl;
        return 1;
    }

    int val = lgGpioRead(h, 4);         // Read GPIO 4
    std::cout << "GPIO 4 value: " << val << std::endl;

    lgGpiochipClose(h);
    return 0;
}