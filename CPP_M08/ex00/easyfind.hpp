#pragma once

#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <iostream>

template <typename T> typename T::iterator easyFind(T& intcontainer, int value)
{
    typename T::iterator res = std::find(intcontainer.begin(), intcontainer.end(), value);
    if (res == intcontainer.end())
        throw std::exception();
    return res;
}