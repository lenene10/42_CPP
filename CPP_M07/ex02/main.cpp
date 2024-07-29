#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> arr_empty;
    const Array<int> const_arr;
    Array<int> arr_empty2(2);
    try{
        std::cout << "Array arr_empty2[0]: " << arr_empty2[0] << std::endl;
        arr_empty2[0] = 42;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    Array<int> arr(5);
    Array<int> arr2(5);

    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i;
    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = 5 + i;

    Array<int> arr3(arr);

    arr3[0] = 42;

    std::cout << "Array arr3: ";
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout << "Array arr2: ";
    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;
    std::cout << "Array arr3: ";
    for (unsigned int i = 0; i < arr3.size(); i++)
        std::cout << arr3[i] << " ";
    std::cout << std::endl;

    std::cout << "Array const_arr: ";
    for (unsigned int i = 0; i < const_arr.size(); i++)
        std::cout << const_arr[i] << " ";

    try{
        std::cout << "Array arr[25]: " << arr[25] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Array<char> arr_char(5);
    for (unsigned int i = 0; i < arr_char.size(); i++)
        arr_char[i] = 'a' + i;
    std::cout << "Array arr_char: ";
    for (unsigned int i = 0; i < arr_char.size(); i++)
        std::cout << arr_char[i] << " ";
    std::cout << std::endl;
    return 0;
}