//
// Created by vkolobara on 8/8/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_OPERATORS_H
#define FUZZY_INFERENCE_SYSTEM_OPERATORS_H

class BinaryFunction {
public:
    virtual double calculateValue(double a, double b) = 0;
};

class UnaryFunction {
public:
    virtual double calculateValue(double a) = 0;
};

namespace BaseOperator {

    class SNorm : public BinaryFunction {
    };

    class TNorm : public BinaryFunction {
    };

    class Complement : public UnaryFunction {
    };
}

namespace Zadeh {
    class Complement : public BaseOperator::Complement {
    public:
        double calculateValue(double a);
    };

    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b);
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b);
    };
}

namespace Hamacher {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b);
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b);
    };
}

namespace Algebraic {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b);
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b);
    };
}

namespace Einstein {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b);
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b);
    };
}

namespace Bounded {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b);
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b);
    };
}

namespace Drastic {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b);
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b);
    };
}


#endif //FUZZY_INFERENCE_SYSTEM_OPERATORS_H
