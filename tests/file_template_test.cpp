#include <string>
#include <cassert>
#include <vector>
#include <iostream>
#include "../src/file_template.h"

int main(){
    std::vector<uint8_t> header = std::vector<uint8_t>{'h', 'e', 'l', 'l', 'o'};
    FileFormat format(header, std::vector<uint8_t>());

    std::vector<size_t> headerPos = format.findHeaders("../tests/data/file_template.dat");

    assert(headerPos.at(0) == 0 && headerPos.at(1) == 11); //header test
}