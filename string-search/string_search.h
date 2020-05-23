#ifndef STRING_SEARCH_HG
#define STRING_SEARCH_HG

#include "my_string.h"

class Search {
    private:
    const MyString _data;
    const MyString _pattern;

    public:

    Search(const MyString& data, const MyString& pattern);
    ~Search() = default;

    void execute();

};
#endif // STRING_SEARCH_HG