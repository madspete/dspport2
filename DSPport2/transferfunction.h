#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include <vector>


class Transferfunction
{
public:
    Transferfunction();

    Transferfunction(const std::vector<double> &num, const std::vector<double> &den);

    void DirectForm2();

private:
    std::vector<double> _num;
    std::vector<double> _den;
};

#endif // TRANSFERFUNCTION_H
