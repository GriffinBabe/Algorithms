#include "string_search.h"

#include <algorithm>

StringSearch::StringSearch(const MyString& data, const MyString& pattern) : _data(data), _pattern(pattern)
{
    if (data.size() < pattern.size()) {
        throw std::runtime_error("Pattern is bigger than source. No match can be found.");
    }
    _precompute_table();
} 

void StringSearch::_precompute_table()
{
    int p_length = _pattern.size(); // pattern lenght
    for (int i = 0; i < p_length; i++) {
        int value = std::max(1, p_length - i - 1);
        char character = _pattern[i];
        _bad_table[character] = value;
    }
}

void StringSearch::execute()
{
    uint right_index = _pattern.size() - 1; // rightmost index
    while (right_index < _data.size()) {
        char bad_character;
        bool match = substring_match(static_cast<MyString>(_data).get(right_index),
                                    static_cast<MyString>(_pattern).get(), &bad_character);
        if (match) {
            std::cout << "Match found at character " << right_index - _pattern.size() + 1 << std::endl;
            right_index += _pattern.size();
        } 
        else {
            int shift_size = _bad_table[bad_character];
            right_index += shift_size;
            continue;
        }
    }

}

bool StringSearch::substring_match(const char* data, const char* pattern, char* mismatch_info) const
{
    for (int i = _pattern.size() - 1; i >= 0; i--) {
        if (pattern[i] != data[i]) {
            *mismatch_info = pattern[i];
            return false;
        }
    }
    return true;
}