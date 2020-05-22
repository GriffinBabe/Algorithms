#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include <ostream>
#include <memory>
#include <string.h>
#include <stdio.h>

class MyString {

    private:
        std::shared_ptr<char> _data;


    public:
        MyString(const char* data) 
        {
            size_t data_size = strlen(data);
            _data = std::shared_ptr<char>(new char[data_size], std::default_delete<char[]>());
            memcpy(_data.get(), data, data_size);
        }

        ~MyString() 
        {


        }

        std::ostream& operator<<(std::ostream& os) 
        {
            return os << _data.get();
        }

};

#endif // MY_STRING_H