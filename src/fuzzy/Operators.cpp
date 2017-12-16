//
// Created by vkolobara on 8/8/17.
//

#include "Operators.h"
#include <algorithm>


namespace Zadeh {
    double Complement::calculateValue(double a) {
        return 1 - a;
    }

    double TNorm::calculateValue(double a, double b) {
        return std::min(a, b);
    }

    double SNorm::calculateValue(double a, double b) {
        return std::max(a, b);
    }
}

namespace Hamacher {
    double TNorm::calculateValue(double a, double b) {
        return (a * b) / (a + b - a * b);
    }

    double SNorm::calculateValue(double a, double b) {
        return (a + b - 2 * a * b) / (1 - a * b);
    }
}

namespace Algebraic {

    double TNorm::calculateValue(double a, double b) {
        return a * b;
    }

    double SNorm::calculateValue(double a, double b) {
        return a + b - a * b;
    }
}

namespace Einstein {
    double TNorm::calculateValue(double a, double b) {
        return (a * b) / (2 - (a + b - a * b));
    }


    double SNorm::calculateValue(double a, double b) {
        return (a + b) / (a + a * b);
    }
}

namespace Bounded {

    double TNorm::calculateValue(double a, double b) {
        auto value = a + b - 1;
        return std::max(0.0, value);
    }


    double SNorm::calculateValue(double a, double b) {
        auto value = a + b;
        return std::min(1.0, value);
    }

}

namespace Drastic {
    double TNorm::calculateValue(double a, double b) {
        if (a < 1 && b < 1) return 0;
        else return std::min(a, b);
    }


    double SNorm::calculateValue(double a, double b) {
        if (a > 0 && b > 0) return 1;
        else return std::max(a, b);
    }

}


