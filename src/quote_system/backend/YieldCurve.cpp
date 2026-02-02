# include <map>
# include <stdexcept>
# include <vector>
# include "quote_system/backend/YieldCurve.h"

void YieldCurve::addRate(double rate, double time) {
    rates_[time] = rate;
}
double YieldCurve::getRate(double time) const {
    if (rates_.empty()) {
        throw std::runtime_error("No rates available");
    }

    // Find the two surrounding times
    auto upper = rates_.upper_bound(time);
    auto lower = std::prev(upper);

    // If exact match found
    if (lower != rates_.end() && lower->first == time) {
        return lower->second;
    }

    // If extrapolating beyond available data
    if (upper == rates_.end()) {
        return lower->second;
    }
    if (lower == rates_.end()) {
        return upper->second;
    }

    // Linear interpolation
    double t1 = lower->first;
    double t2 = upper->first;
    double r1 = lower->second;
    double r2 = upper->second;
    return r1 + (r2 - r1) * (time - t1) / (t2 - t1);
}