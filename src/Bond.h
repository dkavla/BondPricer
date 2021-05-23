
#ifndef BONDPRICER_BOND_H
#define BONDPRICER_BOND_H


class Bond {
    // member variables
    double price;
    double faceValue;
    double couponPayment;
    double numPeriods;
    double yieldToMaturity;
    int frequency;


public:
    // Constructors
    Bond();
    Bond(double FV, double cpnRate,
         double periods, double YTM,
         int freq);

    // Setters
    void setPrice(double Price);
    void setFV(double FV);
    void setCoupon(double cpnRate, double FV);
    void setNumPeriods(double periods);
    void setYTM(double yield);
    void setFrequency(int freq);

    // Getters
    double getPrice();
    double getFV();
    double getCoupon();
    double getPeriods();
    double getYTM();
    int getFrequency();

    // Methods
    double calcBondPrice();
    double cpnBondPrice();
    double zeroCpnBondPrice();
    double calcYTM();
    double calcCurrentYield();
    double calcCurrentYield(double cpn, double YTM);
    double MacaulayDur(double marketPrice);
    double ModifiedDur(double marketPrice);
    double Convexity(double mktPrice);

    // Helper Methods
    double calcPVOfCpn(double period, double totalPeriods);
};


#endif //BONDPRICER_BOND_H
