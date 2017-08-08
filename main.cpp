#include <iostream>
#include "fuzzy/MembershipFunctions.cpp"
#include "fuzzy/Operators.cpp"
#include "fuzzy/domain/Domain.h"

int main() {

    MembershipFunction *f1 = new LinearMembershipFunction::GammaMembershipFunction(10, 20);
    MembershipFunction *f2 = new LinearMembershipFunction::LambdaMembershipFunction(10, 20, 30);
    MembershipFunction *f3 = new LinearMembershipFunction::LMembershipFunction(10, 20);
    MembershipFunction *f4 = new LinearMembershipFunction::PiMembershipFunction(10, 20, 30, 40);

    std::cout << f1->valueAt(19.28282) << std::endl;
    std::cout << f2->valueAt(19.28282) << std::endl;
    std::cout << f3->valueAt(19.28282) << std::endl;
    std::cout << f4->valueAt(25) << std::endl;

    int *els = new int[3]{1,2,3};


    els[0] = 3;

    std::cout << el->values[0] << std::endl;

    return 0;
}