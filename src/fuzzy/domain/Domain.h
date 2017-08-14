//
// Created by vkolobara on 8/8/17.
//

#ifndef DIPLOMSKI_DOMAIN_H
#define DIPLOMSKI_DOMAIN_H

class DomainElement {

};

class Domain {

};

class DomainRange : public Domain {
private:
    double  start, step, end;
public:
    DomainRange(double start, double step, double end);
};

#endif //DIPLOMSKI_DOMAIN_H
