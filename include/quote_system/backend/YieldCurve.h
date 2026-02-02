#pragma once
# include <map>

class YieldCurve{
public:
    void addRate(double rate, double time);
    double getRate(double time) const;
private:
    std::map<double, double> rates_;
};
