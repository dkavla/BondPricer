#include <iostream>
#include <iomanip>
#include "Bond.h"

int main() {

    std::cout.precision(3);

    Bond bond(1000.0, 6.25, 5.0, 6.79, 2);

    std::cout << "=========================\n";
    std::cout << "Bond Face Value: " << bond.getFV() << "\n";
    std::cout << "Bond Annual Yield to Maturity: " << bond.getYTM() * 100 << "%\n";
    std::cout << "Periods Until Maturity: " << (int)bond.getPeriods() << "\n";
    std::cout << "Bond Calculated Price: " << bond.calcBondPrice() << "\n";
    std::cout << "Macaulay Duration: " << bond.MacaulayDur(bond.calcBondPrice()) << "\n";
    std::cout << "Modified Duration: " << bond.ModifiedDur(bond.calcBondPrice()) << "\n";
    std::cout << "Convexity of Bond: " << bond.Convexity(bond.calcBondPrice()) << "\n";
    std::cout << "=========================\n";

    return 0;
}
