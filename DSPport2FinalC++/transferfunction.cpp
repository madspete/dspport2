#include "transferfunction.h"
#include <iostream>
#include <fstream>

Transferfunction::Transferfunction(std::vector<double> num, std::vector<double> den){
    _num = num;
    _den = den;
}

void Transferfunction::calculate(std::string inputFile){
    std::vector<double> input;
    double vv;
    std::vector<double> w(_den.size()-1);
    std::vector<double> output;
    for(unsigned int i = 0; i < w.size(); ++i){
        w[i] = 0;
    }
    //input = readFile(inputFile);
    input = makeInput(30);
    for(unsigned int i = 0; i < input.size(); ++i){
        vv = input[i];
        double out = 0;
        for(unsigned int w1 = 1; w1 < _den.size(); ++w1){ //udregner w_k værdierne
                vv += _den[w1]*w[w1-1]*(-1);
            }
        for(unsigned int y = 0; y < _num.size(); ++y){ //udregner y_k værdierne
            if(y == 0){
                out += _num[0]*vv;
            }
            else{
                out += _num[y]*w[y-1];
            }
        }

        output.push_back(out);
        shiftVector(w,vv);
     }
    for(unsigned int i = 0; i < output.size(); ++i){
        std::cout << "y[" << i <<"] = " << output[i] << std::endl;
    }

}
//læser inputtet til en fil
std::vector <double> Transferfunction::readFile(std::string inputFile ) {
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
//laver et simpelt stepsignal
std::vector<double> Transferfunction::makeInput(int numSamples){
    std::vector<double> input(numSamples);
    for(int i = 0; i < numSamples; ++i){
        input[i] = 1;
    }
    return input;
}

