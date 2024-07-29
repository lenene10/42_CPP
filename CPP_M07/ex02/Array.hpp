#pragma once

#include <iostream>

template <typename T> class Array
{
    private:
        T* _array;
        unsigned int _size;
    public:
        Array() : _array(NULL), _size(0) {
            _array = new T[0]();
        }
        Array(unsigned int n) : _array(new T[n]()), _size(n) {}
        Array(Array const &src) : _array(NULL), _size(0) { 
            *this = src;
        }
        ~Array() {
            delete [] _array;
        }

        Array &operator=(Array const &rhs)
        {
            if (this != &rhs)
            {
                if (_array != NULL)
                    delete [] _array;
                _array = new T[rhs._size];
                _size = rhs._size;
                for (unsigned int i = 0; i < _size; i++)    
                    _array[i] = rhs._array[i];
            }
            return *this;
        }

        T &operator[](unsigned int i)
        {
            if (i >= _size)
                throw std::out_of_range("Array index out of bounds");
            return _array[i];
        }

        T &operator[](unsigned int i) const
        {
            if (i >= _size)
                throw std::out_of_range("Array index out of bounds");
            return _array[i];
        }

        unsigned int size() const {
            return _size;
        }

};