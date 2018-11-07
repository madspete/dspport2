#include <iostream>
#include "transferfunction.h"
#include "cascade_filter.h"

using namespace std;

#define OUT_PATH ""
#define KASPER_PATH "/home/kasper/Documents/DSP/port2/to_git_rep/dspport2/data.txt"
#define GAIN 0.0103

int main()
{
    // Initialiserer 2. ordens sektioner.
    std::vector <double> h1denum;   std::vector <double> h2denum;  std::vector <double> h3denum;
    std::vector <double> h1num; std::vector <double> h2num; std::vector <double> h3num;
    std::vector <Section> secVector;
    std::string filepath = KASPER_PATH;

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

    filter.calculate(filepath,OUT_PATH, GAIN);


    // Til Opgave 6
    /*
    std::vector<double> num(3);
    std::vector<double> den(3);
    den[0] = 0.36;
    den[1] = 1.3;
    den[2] = 1;

    num[0] = -0.5;
    num[1] = 0;
    num[2] = 0.5;

    Transferfunction a(num, den);

    a.DirectForm2();
    */

    return 0;
}
