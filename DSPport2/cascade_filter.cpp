#include "cascade_filter.h"

Cascade_filter::Cascade_filter(const std::vector <Section> &sections) {
    _section = sections;
}

void Cascade_filter::calculate(std::string inputfile, std::string outputpath) {

    std::vector <double> inputValues = readFile(inputfile); // Indeholder inputværdier
    std::vector <double> outputValues; // Indeholder outputværdier.
    std::vector <std::vector <double> > w(_section.size()); // Buffer, til at holde tidligere udregnede værdier for w_k(n-a).

    // Initialiser w-vectoren, så størrelsen stemmer overens med tidligere input.
    for (unsigned int i = 0; i < w.size(); i++) {
        for (int j = 0; j < 2; j++) {
            w[i].push_back(NULL);
        }
    }

    for (unsigned int in = 0; in < inputValues.size(); in++) { // Løber gennem alle inputværdierne.
        double output = inputValues[in];
        for (unsigned int sec = 0; sec < _section.size(); sec++ ) { // Udregn outputtet af hver kaskade.
            if (sec == 0) {
                for ( unsigned int i = 0; i < _section[sec]._num.size(); i++) {
                    _section[sec]._num[i]*=0.0103;
                }
            }
            output = calcSection(w[sec], _section[sec], output);

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
    double out = 0;
    for (unsigned int a = 1; a < (section._denum.size()); a++ ) { // Udregning af w_k.
        if (w[a] == NULL) {
            continue;
        }
        vv += section._denum[a]*w[a]*(-1.0);
    }

    for (unsigned int b = 0; b < (section._num.size()); b++ ) { // Udregning af y_k.
        if (w[b] == NULL) {
            continue;
        }
        if (b == 0) {
            out += section._num[b]*vv;
        }
        out += section._num[b]*w[b];
    }

    shiftVector(w,vv);

    return out;
}
