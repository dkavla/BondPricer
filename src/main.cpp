#include <iostream>
#include "Bond.h"
#include <vector>


void outputMenu();
Bond inputBondInfo();
void evaluateChoice(Bond &b, char choice);

int main() {

    std::vector<Bond> bonds;
    char choice;

    Bond bond;

    while(true)
    {
        std::cout << "Bond Pricing Program:\n";
        outputMenu();
        std::cout << "Choose menu option(q to quit): ";
        std::cin >> choice;

        if(choice == 'q')
        {
            std::cout << "Quitting Pricer\n";
            break;
        }

        if(choice == '1')
        {
            bond = inputBondInfo();
            bonds.push_back(bond);
        }

        if(choice == '2')
        {
            bond.outputBond();
        }

        if(choice == '3')
        {
            char option;
            while(true)
            {
                std::cout << "\tWhat would you like to edit:\n";
                std::cout << "\t1.) Yield to Maturity\n";
                std::cout << "\t2.) Face Value\n";
                std::cout << "\t3.) Coupon Rate\n";
                std::cout << "\t4.) Years to Maturity\n";
                std::cout << "\t5.) Frequency of Coupon Payments\n";
                std::cout << "\t(Enter q to quit the Edit menu)\n";
                std::cout << "\t> ";
                std::cin >> option;

                if(option == 'q')
                {
                    break;
                }

                evaluateChoice(bond, option);
                bond.outputBond();
            }
        }

        if(choice == '4')
        {
            double macDur = bond.MacaulayDur(bond.calcBondPrice());
            std::cout << "\n";
            std::cout << "The bond has a Macaulay Duration of " << macDur << "\n";
            std::cout << "\n";
        }

        if(choice == '5')
        {
            double modDur = bond.ModifiedDur(bond.calcBondPrice());
            std::cout << "\n";
            std::cout << "The bond has a Modified Duration of " << modDur << "\n";
            std::cout << "\n";
        }

        if(choice == '6')
        {
            double convex = bond.Convexity(bond.calcBondPrice());
            std::cout << "\n";
            std::cout << "The bond has a Convexity of " << convex << "\n";
            std::cout << "\n";
        }
    }

    std::cout << "Terminating program...\n";

    return 0;
}

void outputMenu()
{
    std::cout << "1.) Input Bond Info\n";
    std::cout << "2.) Print Bond Info\n";
    std::cout << "3.) Edit Bond Info\n";
    std::cout << "4.) Calculate Macaulay Duration\n";
    std::cout << "5.) Calculate Modified Duration\n";
    std::cout << "6.) Calculate Bond Convexity\n";
}

Bond inputBondInfo()
{
    double FV;
    double cpnRate;
    double years;
    double frequency;
    double yield;


    std::cout << "Enter the bond's face value: ";
    std::cin >> FV;
    std::cout << "\n";

    std::cout << "Enter the coupon rate (as a %): ";
    std::cin >> cpnRate;
    std::cout << "\n";

    std::cout << "Enter the years until maturity (if months enter the number of month divide by 12): ";
    std::cin >> years;
    std::cout << "\n";

    std::cout << "Enter the Yield to Maturity of the bond (as %): ";
    std::cin >> yield;
    std::cout << "\n";

    std::cout << "Enter the frequency of coupon payments(1, 2, 4, or 12 allowed only): ";
    std::cin >> frequency;
    std::cout << "\n";

    Bond bond(FV, cpnRate, years, yield, frequency);

    return bond;
}

void evaluateChoice(Bond &b, char choice)
{
    switch(choice)
    {
        case '1':
            double yield;
            std::cout << "Enter the new yield to maturity: ";
            std::cin >> yield;
            b.setYTM(yield);
            break;
        case '2':
            double fv;
            std::cout << "Enter the new face value: ";
            std::cin >> fv;
            b.setFV(fv);
            break;
        case'3':
            double cpn;
            std::cout << "Enter the new coupon rate: ";
            std::cin >> cpn;
            b.setCoupon(cpn, b.getFV());
            break;
        case '4':
            double years;
            std::cout << "Enter the years until maturity: ";
            std::cin >> years;
            b.setNumPeriods(years);
            break;
        case '5':
            double freq;
            std::cout << "Enter the frequency of payments: ";
            std::cin >> freq;
            b.setFrequency(freq);
            break;
    }
}








