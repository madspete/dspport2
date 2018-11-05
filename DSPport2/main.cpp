#include <iostream>
#include "transferfunction.h"

using namespace std;

int main()
{
    std::vector<double> num(3);
    std::vector<double> den(3);
    num[0] = 0.36;
    num[1] = 1.3;
    num[2] = 1;

    den[0] = -0.5;
    den[1] = 0;
    den[2] = 0.5;

    Transferfunction a(num, den);

    a.DirectForm2();

    return 0;
}
