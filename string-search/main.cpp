#include <iostream>
#include <assert.h>
#include "string_load.h"

int main(int argc, char** argv)
{
    // checks argcount
    if (argc != 2)
    {
        fprintf(stderr, "Exactly two arguments are required.\nUsage: string_load.exe <file>\n");
        return EXIT_FAILURE;
    }

    const char* test_file_path = argv[1];
    MyString data = utils::read_string(test_file_path);
    std::cout << data << std::endl;
 
    return 0;
}