#include <iostream>
#include <memory>
#include "fuzzy/MembershipFunctions.cpp"

int main() {

    std::shared_ptr<MembershipFunction> f1 = std::shared_ptr<MembershipFunction>(new LinearMembershipFunction::GammaMembershipFunction(10, 20));

    std::cout << f1->valueAt(11.11) << std::endl;
    return 0;
}
