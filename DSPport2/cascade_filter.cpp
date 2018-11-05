#include "cascade_filter.h"

Cascade_filter::Cascade_filter(const std::vector <Section> &sections) {
    _section = sections;
}

void Cascade_filter::calculate(std::string inputfile, std::string outputpath) {
    std::vector <double> inputValues = readFile(inputfile);
    std::vector <double> outputValues;
    std::vector <std::vector <double> > w(_section.size());

    // Initialiser w-vectoren.
    for (unsigned int i = 0; i < w.size(); i++) {
        for (int j = 0; j < 2; j++) {
            w[i].push_back(NULL);
        }
    }

    for (unsigned int in = 0; in < inputValues.size(); in++) {
        double output = inputValues[in];
        for (unsigned int sec = 0; sec < _section.size(); sec++ ) {
            output += calcSection(w[sec], _section[sec], output);

        }
        outputValues.push_back(output);
    }

    for (unsigned int i = 0; i < outputValues.size(); i++) {
        std::cout << "y[" << i+1 << "] = " << outputValues[i] << std::endl;
    }
}

std::vector <double> Cascade_filter::readFile(std::string inputFile ) {
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cout << inputFile << " Invalid!" << std::endl;
        exit(1);
    }
    std::vector <double> returnVector;
    double buffer;
    while (file >> buffer) {
        returnVector.push_back(buffer);
    }
    return returnVector;
}

double Cascade_filter::calcSection(std::vector <double> &w, const Section &section, double in ) {

    double vv = in;
    double out = in;
    for (unsigned int a = 0; a < (section._num.size()-1); a++ ) { // Udregning af w.
        if (w[a] == NULL) {
            continue;
        }
        vv += section._num[a]*w[a];
    }

    for (unsigned int b = 0; b < (section._denum.size()-1); b++ ) { // Udregning af y_k.
        if (w[b] == NULL) {
            continue;
        }
        out += section._num[b]*w[b];
    }

    shiftVector(w,vv);

    return out;
}
