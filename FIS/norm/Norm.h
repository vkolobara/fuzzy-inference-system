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

    struct SNorm : public BinaryFunction {
    };

    struct TNorm : public BinaryFunction {
    };

    struct Complement : public UnaryFunction {
    };
}

namespace Zadeh {
    class Complement : public BaseOperator::Complement {
    public:
        double calculateValue(double a) override;
    };

    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b) override;

    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b) override;

    };
}

namespace Hamacher {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b) override;
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b) override;
    };
}

namespace Algebraic {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b) override;
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b) override;
    };
}

namespace Einstein {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b) override;
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b) override;
    };
}

namespace Bounded {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b) override;
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b) override;
    };
}

namespace Drastic {
    class TNorm : public BaseOperator::TNorm {
    public:
        double calculateValue(double a, double b) override;
    };

    class SNorm : public BaseOperator::SNorm {
    public:
        double calculateValue(double a, double b) override;
    };
}


#endif //FUZZY_INFERENCE_SYSTEM_OPERATORS_H
