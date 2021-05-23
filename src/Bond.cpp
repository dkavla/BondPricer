

#include "Bond.h"
#include <cmath>
#include <iostream>

Bond::Bond() : price(0.0), faceValue(0.0), couponPayment(0.0),
               numPeriods(0.0), yieldToMaturity(0.0), frequency(0) {}

Bond::Bond(double FV,
           double cpnRate,
           double periods,
           double YTM,
           int freq) :
        price(0), faceValue(FV),
        couponPayment((cpnRate / 100) * FV),
        numPeriods(periods), yieldToMaturity(YTM/100), frequency(freq) {}

/* Setter Methods */
void Bond::setPrice(double Price)
{
    price = Price;
}

void Bond::setFV(double FV)
{
    faceValue = FV;
}

void Bond::setCoupon(double cpnRate, double FV)
{
    couponPayment = (cpnRate / 100) * FV;
}

void Bond::setNumPeriods(double periods)
{
    numPeriods = periods;
}

void Bond::setYTM(double yield)
{
    yieldToMaturity = yield;
}

void Bond::setFrequency(int freq)
{
    frequency = freq;
}


/* Getters */
double Bond::getPrice()
{
    return price;
}

double Bond::getFV()
{
    return faceValue;
}

double Bond::getCoupon()
{
    return couponPayment;
}

double Bond::getPeriods()
{
    return numPeriods * (double) frequency;
}

double Bond::getYTM()
{
    return yieldToMaturity;
}

int Bond::getFrequency()
{
    return frequency;
}


/* Methods */
double Bond::calcBondPrice()
{
    if(couponPayment == 0){
        return zeroCpnBondPrice();
    }

    return cpnBondPrice();
}

double Bond::cpnBondPrice()
{
    double calculatedPrice = 0.00;
    int totalPeriods = (int) numPeriods * frequency;


    for(int i = 1; i <= totalPeriods; i++)
    {
        if(i == totalPeriods)
        {
            double cashFlow = (couponPayment / frequency) + faceValue;
            double PVFactor = 1 / std::pow(1 + (yieldToMaturity / frequency), i);
            calculatedPrice += cashFlow * PVFactor;
            break;
        }

        /*
            PV Factor = 1 / (1 + YTM/m)^n * m
        */

        double PVFactor = 1 / std::pow(1 + (yieldToMaturity / frequency), i);

        calculatedPrice += (couponPayment / frequency) * PVFactor;
    }

    return calculatedPrice;
}

double Bond::zeroCpnBondPrice()
{
    return  faceValue / std::pow( (1 + (yieldToMaturity / frequency) ), numPeriods * frequency );
}

double Bond::calcYTM()
{
    if(yieldToMaturity == 0)
    {
        double numerator =  couponPayment + ( (faceValue - price) / numPeriods);
        double denominator = ( (faceValue + price)) / 2;

        return numerator / denominator;
    }

    return yieldToMaturity;
}

double Bond::calcCurrentYield()
{
    return couponPayment / price;
}

// requires user input
double Bond::calcCurrentYield(double cpn, double YTM)
{
    return cpn / (YTM / 100);
}

double Bond::MacaulayDur(double marketPrice)
{
    double periods = numPeriods * frequency;
    double duration = 0;

    for(int i = 1; i <= periods; i++)
    {
        double PVCpn = calcPVOfCpn(i, periods);
        duration += (PVCpn / marketPrice) * i;
    }

    return duration / frequency;
}

double Bond::ModifiedDur(double marketPrice)
{
    double macDur = MacaulayDur(marketPrice);
    double denom = (1 + (yieldToMaturity / frequency) );

    return macDur / denom;
}

double Bond::calcPVOfCpn(double period, double totalPeriods)
{
    double PVFactor = 1 / std::pow(1 + (yieldToMaturity / frequency), period);
    // calculates the PV of the current periods cash flows
    if(period == totalPeriods)
    {
        return ( (couponPayment / frequency) + faceValue) * PVFactor;
    }

    return (couponPayment / frequency) * PVFactor;

}

double Bond::Convexity(double mktPrice)
{
    double periods = numPeriods * frequency;
    double sumOfConvex = 0;

    // discounts the coupon payments
    for(int i = 1; i <= periods; i++)
    {
        double PVCpn = calcPVOfCpn(i, periods);
        double factorYears = i + (i * i);

        // multiplies the discounted coupon by the factor years
        sumOfConvex += PVCpn * factorYears;
    }

    // calculates the parts of the convexity formula
    double num = sumOfConvex / std::pow((1 + yieldToMaturity), 2);
    double denom = mktPrice * std::pow((frequency), 2);

    // calculate the actual convexity of the bond
    return num / denom;
}