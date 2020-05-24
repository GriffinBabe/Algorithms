#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include <ostream>
#include <memory>
#include <string.h>
#include <stdio.h>
#include <exception>

typedef unsigned int uint;

class MyString {

    private:
        std::shared_ptr<char> _data;
        uint _lenght;


    public:
        MyString(char* data, uint length) 
        {
            _lenght = length;
            _data = std::shared_ptr<char>(data);
        }

        ~MyString() = default;

        // copy constructor
        MyString(const MyString& mat)
        {
            _data = mat._data;
            _lenght = mat._lenght;
        }

        // move constructor
        MyString(MyString&& mat)
        {
            _data = std::move(mat._data);
            _lenght = mat._lenght;
            mat._data = nullptr;
            mat._lenght = 0;
            // TODO set all meta data to null
        }

        // Copy assignement
        MyString& operator=(MyString& other)
        {
            _data = other._data;
            _lenght = other._lenght;
            return *this;
        }

        // move asigment
        MyString& operator=(MyString&& other)
        {
            _data = std::move(other._data);
            _lenght = other._lenght;
            other._lenght = 0;
            other._data = nullptr;
            return *this;
        }

        char operator [](uint index) const
        {
            // range check during debugging only
            #ifdef _DEBUG
                if (index >= _lenght) {
                    throw std::runtime_error("operator[] argument out of bounds");
                }
            #endif
            return _data.get()[index];
        }
        
        friend std::ostream& operator<<(std::ostream& os, const MyString& str)
        {
            os << str._data.get();
            return os;
        }

        const char* get(uint pos)
        {
            if (pos >= _lenght) {
                throw std::runtime_error("operator[] argument out of bounds");
            }
            return &(_data.get()[pos]);
        } 

        const char* get()
        {
            return _data.get();
        }

        const uint size() const
        {
            return _lenght;
        }

};

#endif // MY_STRING_H