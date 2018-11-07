#ifndef SECTION_H
#define SECTION_H
#include <vector>

class Section {
public:
    std::vector <double> _num;
    std::vector <double> _denum;
    Section(std::vector <double> num, std::vector <double> denum) {
        _num = num;
        _denum = denum;
    }
};

#endif // SECTION_H
