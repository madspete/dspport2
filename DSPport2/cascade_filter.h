#ifndef CASCADE_FILTER_H
#define CASCADE_FILTER_H
#include <vector>
#include <iostream>
#include "section.h"
#include <string>
#include <fstream>

class Cascade_filter
{
public:

    Cascade_filter(const std::vector <Section> &sections);

    void calculate(std::string inputfile, std::string outputpath, double gain); //udregner output givet en input vector

    double calcSection(std::vector <double> &w, const Section &section, double in ); //udregner y_k for en kaskade

private:

    std::vector <double> readFile(std::string inputFile); //læser input fil (Kun til CSV)
    void writeFile(const std::vector<double> &values, std::string out_path); //TODO

    void shiftVector(std::vector <double> &vec, const double &newFirst) {
        vec.pop_back();
        std::vector <double>::iterator it = vec.begin();
        vec.insert(it,newFirst);
    }

    std::vector<double> makeInput(int numSamples); //laver stepsignal med numSamples samples
    std::vector <Section> _section;
};

#endif // CASCADE_FILTER_H
