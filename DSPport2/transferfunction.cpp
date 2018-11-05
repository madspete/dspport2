#include "transferfunction.h"
#include <iostream>

Transferfunction::Transferfunction()
{

}
Transferfunction::Transferfunction(const std::vector<double> &num, const std::vector<double> &den){
    if(num[num.size()-1] != 1){
        std::cout << "not a valid input, the last number in the vector has to be 1" << std::endl;
    }
    else{
    _num = num;
    _den = den;
    }
}

void Transferfunction::DirectForm2(){
    //starter med at finde størrelsen på tæller og nævner
    unsigned int sizeNum, sizeDen;
    sizeNum = _num.size();
    sizeDen = _den.size();

    //ændrer fortegnet på alle tal i nævneren
    for(unsigned int i = 0; i < sizeNum; ++i){
        _num[i] = _num[i] * (-1);
    }
    //beregner w(n)
    std::cout << "w(n) = x(n) + ";
    int j = 1;
    for(int i = sizeNum-2; i >= 0; --i){
        //Hvis tallet er 0 skrives den ikke med i brøkken.
        if(_num[i] != 0){
            if(i != 0){
                std::cout<< _num[i] << "w(n - " << j << ") + ";
            }
            else{
                std::cout<< _num[i] << "w(n - " << j << ")";
            }
        }
        else{
            continue;
        }
        ++j;
    }
    std::cout << std::endl;
    //beregner y(n)
    std::cout << "y(n) = ";
    int k = 0;
    for(int i = sizeDen -1; i >=0; --i){
        if(_den[i] != 0){
            if(i != 0){
                std::cout << _den[i] << "w(n - " << k << ") + ";
            }
            else{
                std::cout << _den[i] << "w(n - " << k << ")";
            }
        }
        else{
            continue;
        }
        ++k;
    }

}
