#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include <vector>
#include <string>
#include <iostream>


class Transferfunction
{
public:
    Transferfunction(std::vector<double> num, std::vector<double> den);

    void calculate(std::string inputFile);

    std::vector<double> makeInput(int numSamples);

private:
    std::vector<double> _num;
    std::vector<double> _den;

    std::vector<double> readFile(std::string inputFile);

    void shiftVector(std::vector <double> &vec, const double &newFirst) {
        vec.pop_back();
        std::vector <double>::iterator it = vec.begin();
        vec.insert(it,newFirst);
    }
};

#endif // TRANSFERFUNCTION_H
