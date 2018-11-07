#include <iostream>
#include "transferfunction.h"
#include "cascade_filter.h"
#include "section.h"

using namespace std;

int main()
{
    //opgave 7
    // Initialiserer 2. ordens sektioner.
    std::vector <double> h1denum;   std::vector <double> h2denum;  std::vector <double> h3denum;
    std::vector <double> h1num; std::vector <double> h2num; std::vector <double> h3num;
    std::vector <Section> secVector;
    //std::string filepath = KASPER_PATH;

    // Udfyld vektorer med resultater fra matlab.
    h1num.push_back(1);
    h1num.push_back(2.164);
    h1num.push_back(1);

    h1denum.push_back(1);
    h1denum.push_back(-0.4959);
    h1denum.push_back(0.6041);

    h2num.push_back(1);
    h2num.push_back(2.2854);
    h2num.push_back(1.472);
    h2denum.push_back(1);
    h2denum.push_back(-0.3701);
    h2denum.push_back(0.1962);
    h3num.push_back(1);
    h3num.push_back(1.5526);
    h3num.push_back(0.6793);

    h3denum.push_back(1);
    h3denum.push_back(-0.3219);
    h3denum.push_back(0.0424);

    Section s1(h1num,h1denum), s2(h2num,h2denum), s3(h3num,h3denum);

    secVector.push_back(s3);
    secVector.push_back(s2);
    secVector.push_back(s1);

    Cascade_filter filter(secVector);
    filter.calculate("", "", 0.0103);

    //opgave 6
    std::cout << "opgave 6" << std::endl;
    std::vector<double> num(7);
    std::vector<double> den(7);
    num[0] = 0.01031;
    num[1] = 0.06188;
    num[2] = 0.1547;
    num[3] = 0.2063;
    num[4] = num[2];
    num[5] = num[1];
    num[6] = num[0];

    den[0] = 1;
    den[1] = -1.188;
    den[2] = 1.305;
    den[3] = -0.6743;
    den[4] = 0.2635;
    den[5] = -0.05175;
    den[6] = 0.005023;

    Transferfunction a(num, den);

    a.calculate("");


    return 0;
}
