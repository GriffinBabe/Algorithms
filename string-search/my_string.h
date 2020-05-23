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

        ~MyString() = default;

        // copy constructor
        MyString(const MyString& mat)
        {
            _data = mat._data;
        }

        // move constructor
        MyString(MyString&& mat)
        {
            _data = std::move(mat._data);
            mat._data = nullptr;
            // TODO set all meta data to null
        }

        // Copy assignement
        MyString& operator=(MyString& other)
        {
            _data = other._data;
            return *this;
        }

        // move asigment
        MyString& operator=(MyString&& other)
        {
            _data = std::move(other._data);
            other._data = nullptr;
            return *this;
        }

        const char* get_data() const
        {
            return _data.get();
        }

        friend std::ostream& operator<<(std::ostream& os, const MyString& str)
        {
            os << str.get_data();
            return os;
        }

};

#endif // MY_STRING_H