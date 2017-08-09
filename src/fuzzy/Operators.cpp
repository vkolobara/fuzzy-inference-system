//
// Created by vkolobara on 8/8/17.
//

#include "Operators.h"

namespace Zadeh {
    class Complement : public BaseOperator::Complement {
    public:
        double calculateValue(double a) {
            return 1 - a;
        }
    };

    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b) {
            if (a < b) return a;
            return b;
        }
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b) {
            if (a > b) return a;
            return b;
        }
    };
}

namespace Hamacher {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b) {
            return (a * b) / (a + b - a*b);
        }
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b) {
            return (a + b - 2 *a*b) / (1 - a*b);
        }
    };
}

namespace Algebraic {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b) {
            return a*b;
        }
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b) {
            return a + b - a*b;
        }
    };
}

namespace Einstein {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b) {
            return (a * b) / (2 - (a + b - a*b));
        }
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b) {
            return (a + b) / (a + a*b);
        }
    };
}

namespace Bounded {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b) {
            auto value = a + b - 1;
            if (value < 0) return 0;
            return value;
        }
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b) {
            auto value = a + b;
            if (value > 1) return 1;
            else return value;
        }
    };
}

namespace Drastic {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b) {
            if (a < 1 && b < 1) return 0;
            else if (a < b) return a;
            else return b;
        }
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b) {
            if (a > 0 && b > 0) return 1;
            else if (a > b) return a;
            else return b;
        }
    };
}


