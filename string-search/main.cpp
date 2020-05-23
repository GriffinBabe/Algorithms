#include <iostream>
#include <assert.h>
#include "string_load.h"

int main(int argc, char** argv)
{
    assert(argc == 2);
    const char* test_file_path = argv[1];

    MyString data = utils::read_string(test_file_path);
    std::cout << data << std::endl;
    
    return 0;
}