#include "quote_system/backend/YieldCurve.h"

int main() {
    YieldCurve yc;
    yc.addRate(0.05, 1.0);  // 5% at 1 year
    yc.addRate(0.06, 2.0);  // 6% at 2 years
    yc.addRate(0.07, 3.0);  // 7% at 3 years

    double rate1 = yc.getRate(1.5); // Should interpolate between 5% and 6%
    double rate2 = yc.getRate(2.5); // Should interpolate between 6% and 7%
    double rate3 = yc.getRate(3.0); // Should return 7%

    // compare with expected values
    if (std::abs(rate1 - 0.055) > 1e-6) return 1;
    if (std::abs(rate2 - 0.065) > 1e-6) return 1;
    if (std::abs(rate3 - 0.07) > 1e-6) return 1;

    return 0;
}