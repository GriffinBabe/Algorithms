#include "string_load.h"
#include <fstream>
#include <string>

MyString utils::read_string(const char* filepath) {
    // https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
    std::ifstream ifs;

    ifs.open(filepath);
    
    ifs.seekg(0, std::ios::end);
    size_t lenght = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    // buffer
    char* data = new char[lenght];
    ifs.read(data, lenght);
    ifs.close();

    // data taken by smart pointer in custom string.
    MyString string(data, lenght);

    return string;
}