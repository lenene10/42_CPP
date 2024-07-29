#pragma once

#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

template <typename T>
void merge(T& arr, int left, int mid, int right);

template <typename T>
void    parse_input(int argc, char **argv, T& vec);

template <typename T>
int    make_pairs(T& vec, std::vector<std::pair<int, int> > &pairs);

class PmergeMe {
    private:
        PmergeMe();
        PmergeMe &operator=(const PmergeMe &rhs);
        PmergeMe(const PmergeMe &rhs);
        ~PmergeMe();
    public:
        template <typename T>
        static void     merge_sort(T& pairs, int left, int right);

        template <typename T>
        static int*     parse_input(int argc, char **argv, T &vec);
        
        template <typename T>
        static void     do_sort(T& input);

        template <typename T>
        static void     print_nums(T& nums, std::string prefix);
};

template <typename T>
void    PmergeMe::print_nums(T& nums, std::string prefix)
{
    std::cout << prefix;
    for (unsigned int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
        if (i == 5)
        {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
}

template <typename T>
void    PmergeMe::do_sort(T& input)
{
    //1. making the paris
    std::vector < std::pair <int, int> > pairs;
    if (input.size() == 1)
    {
        return;
    }
    int stray = make_pairs(input, pairs);

    //2. merge sort the tops
    PmergeMe::merge_sort(pairs, 0, pairs.size() - 1);

    //3. split the paris so that tops are in 1 array (sorted) and bottoms are in another.
    input.clear();
    T bottoms;
    for (unsigned int i = 0; i < pairs.size(); i++)
    {
        input.push_back(pairs[i].first);
        bottoms.push_back(pairs[i].second);
    }

    //4. put the very first from the bottoms to the top's array's first pos
    input.insert(input.begin(), bottoms[0]);  //skipping the first element, just drag and drop to the beginning
    bottoms.erase(bottoms.begin());
    unsigned int i = 0;
    int jakob_number[] = {1 * 2, 1 * 2, 3 * 2, 5 * 2, 11 * 2, 21 * 2, 43 * 2, 85 * 2, 171 * 2, 341 * 2 , 683 * 2, 1365 * 2, 2731 * 2, 5461 * 2, 10923 * 2, 21845 * 2, 43691 * 2};
    for (typename T::iterator it = bottoms.begin(); it != bottoms.end();)
    {
        int actual_jakob_num = jakob_number[i];
        for (int j = actual_jakob_num - 1 ; j >= 0; j--) {
            if (j > (int)bottoms.size() - 1)
            {
                j = (int)bottoms.size() - 1;
            }
            int range = std::pow(2, i + 2) - 1;
            if (range > (int)input.size())
                range = input.size();
            std::advance(it, j);
            input.insert(std::upper_bound(input.begin(), input.begin() + range, *it), *it);
            bottoms.erase(it);
            it = bottoms.begin();
        }
        i++;
    }

    if (stray != -1)
    {
        input.insert(std::upper_bound(input.begin(), input.end(), stray), stray);
    }
}

template <typename T>
void    PmergeMe::merge_sort(T& pairs, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        PmergeMe::merge_sort(pairs, left, mid);
        PmergeMe::merge_sort(pairs, mid + 1, right);

        // Merge the sorted halves
        merge(pairs, left, mid, right);
    }
}

template <typename T>
int    make_pairs(T& vec, std::vector<std::pair<int, int> > &pairs)
{
    bool   is_odd = vec.size() % 2 == 1;
    int stray = -1;
    if (is_odd)
    {
        stray = vec.back();
    }
    unsigned int vec_size = is_odd ? vec.size() - 1 : vec.size();
    for (unsigned int i = 0; i < vec_size; i += 2)
    {
        if (vec[i] > vec[i + 1])
        {
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        }
        else
        {
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
        }
    }
    return stray;
}

template <typename T>
void    parse_input(int argc, char **argv, T& vec)
{
    std::string tempstr(argv[1]);
    if (tempstr.empty())
    {
        throw std::runtime_error("Invalid input: Empty string");
    }
    for (int i = 1; i < argc; i++)
    {
        std::string str(argv[i]);
        if (str.empty())
        {
            throw std::runtime_error("Invalid input: Empty string");
        }
        //std::cout << str << std::endl;
        if (str.size() > 10)    //verify that the input is a positive integer
        {
            throw std::runtime_error("Invalid input: " + str);
        } else if (str.size() == 10 && str > std::string("2147483647")) //TODO: IT ENTERS ALL THE TIME, BECAUSE COMPARES ONLY  the firstcharacter (5 vs 2 e.g.)
        {
            throw std::runtime_error("Invalid input: " + str);
        }
        for (std::string::iterator it = str.begin(); it != str.end(); ++it)
        {
            if (!isdigit(*it))    //verify that each character in the string is a digit (we dont accept - or +)
            {
                throw std::runtime_error("Invalid input: " + str);
            }
        }
        vec[i - 1] = std::atoi(argv[i]);
    }
}

template <typename T>
void merge(T& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<std::pair <int, int > > L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}
