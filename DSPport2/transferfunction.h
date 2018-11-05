#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include <vector>


class Transferfunction
{
public:
    Transferfunction();

    Transferfunction(std::vector<double> num, std::vector<double> den);

    void DirectForm2();

private:
    std::vector<double> _num;
    std::vector<double> _den;
};

#endif // TRANSFERFUNCTION_H
