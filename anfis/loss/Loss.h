//
// Created by vkolobara on 18.1.2018..
//

#ifndef FUZZY_LOSS_H
#define FUZZY_LOSS_H


class Loss {
public:
    virtual double loss(double pred, double real) = 0;
};

class MSE : public Loss {
public:
    double loss(double pred, double real) override;
};


#endif //FUZZY_LOSS_H
