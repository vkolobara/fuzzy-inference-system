#include <iostream>
#include "fuzzy/MembershipFunctions.cpp"

int main() {

    MembershipFunction *f1 = new GammaMembershipFunction(10, 20);
    MembershipFunction *f2 = new LambdaMembershipFunction(10, 20, 30);
    MembershipFunction *f3 = new LMembershipFunction(10, 20);
    MembershipFunction *f4 = new PiMembershipFunction(10, 20, 30, 40);

    std::cout << f1->calculateValue(19.28282) << std::endl;
    std::cout << f2->calculateValue(19.28282) << std::endl;
    std::cout << f3->calculateValue(19.28282) << std::endl;
    std::cout << f4->calculateValue(25) << std::endl;

    return 0;
}