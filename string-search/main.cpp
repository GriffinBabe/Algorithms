#include <iostream>
#include <assert.h>
#include "string_load.h"
#include "string_search.h"

int main(int argc, char** argv)
{
    // checks argcount
    if (argc != 3)
    {
        fprintf(stderr, "Exactly two arguments are required.\nUsage: string_load.exe <file> <pattern>\n");
        return EXIT_FAILURE;
    }

    const char* test_file_path = argv[1];
    char* raw_pattern = argv[2];

    MyString data = utils::read_string(test_file_path);
    MyString pattern(raw_pattern, strlen(raw_pattern));

    std::cout << "Data file have " << data.size() << " characters. " << std::endl;

    StringSearch search(data, pattern);
    search.execute();

    return 0;
}