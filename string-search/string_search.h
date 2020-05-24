#ifndef STRING_SEARCH_HG
#define STRING_SEARCH_HG

#include <map>
#include "my_string.h"

class StringSearch {
    private:
    const MyString _data;
    const MyString _pattern;

    std::map<char, int> _bad_table; // bad character method table

    void _precompute_table();

    bool substring_match(const char* data, const char* pattern, char* mismatch_info) const;

    public:

    StringSearch(const MyString& data, const MyString& pattern);
    ~StringSearch() = default;

    void execute();

};
#endif // STRING_SEARCH_HG