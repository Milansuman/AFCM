#pragma once

#include <vector>
#include <cstdint>
#include <string>

class FileFormat {
private:
    std::vector<uint8_t> header;
    std::vector<uint8_t> footer;
public:
    FileFormat(std::vector<uint8_t> header, std::vector<uint8_t> footer);
    std::vector<size_t> findHeaders(std::string filename);
    std::vector<size_t> findFooters(std::string filename);
    ~FileFormat();
};