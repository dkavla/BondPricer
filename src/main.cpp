#include <iostream>
#include "Bond.h"

int main() {

    Bond bond(1000.0, 5.0, 5.0, 7.0, 1);

    std::cout << "=========================\n";
    std::cout << "Bond Face Value: " << bond.getFV() << "\n";
    std::cout << "Bond Annual Yield to Maturity: " << bond.getYTM() * 100 << "%\n";
    std::cout << "Periods Until Maturity: " << bond.getFV() << "\n";
    std::cout << "Bond Calculated Price: " << bond.calcBondPrice() << "\n";
    std::cout << "Macaulay Duration: " << bond.MacaulayDur(bond.calcBondPrice()) << "\n";
    std::cout << "Modified Duration: " << bond.ModifiedDur(bond.calcBondPrice()) << "\n";
    std::cout << "=========================\n";



    return 0;
}
