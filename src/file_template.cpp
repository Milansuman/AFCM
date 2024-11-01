#include "file_template.h"

#include <fstream>
#include <algorithm>

FileFormat::FileFormat(std::vector<uint8_t> header, std::vector<uint8_t> footer): header(header), footer(footer){}

std::vector<size_t> FileFormat::findHeaders(std::string filename){
    std::ifstream file;
    file.open(filename);

    std::vector<size_t> headers = std::vector<size_t>();

    file.seekg(file.end);
    size_t length = file.tellg();
    file.seekg(file.beg);

    size_t offset = 1024*1024*1024*10; //10MB

    for(int i=0; i <= length; i += offset){
        char *buffer = new char[offset];
        file.read(buffer, offset);

        std::vector<uint8_t> buf = std::vector<uint8_t>(buffer, buffer+offset);
        
        std::vector<uint8_t>::iterator it = buf.begin();
        while(true){
            it = std::search(it, buf.end(), this->header.begin(), this->header.end());

            if(it != buf.end()){
                headers.push_back(std::distance(buf.begin(), it)+i);
            }
        }

        delete[] buffer;
    }

    file.close();
}

std::vector<size_t> FileFormat::findFooters(std::string filename){
    
}

FileFormat::~FileFormat() = default;