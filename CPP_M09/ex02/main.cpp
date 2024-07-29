#include "PmergeMe.hpp"
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>
#include <deque>


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <sequence of positive integers>" << std::endl;
        return(1);
    }
    std::vector<int> input(argc - 1);
    std::deque<int> input_d(argc - 1);
    
    clock_t start_v = clock();
    try {
        parse_input(argc, argv, input);
    } catch (std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return(1);
    }
    PmergeMe::print_nums(input, "Before:\t");
    PmergeMe::do_sort(input);
    clock_t end_v = clock();
    PmergeMe::print_nums(input, "After:\t");
    double elapsed_time_vec = static_cast<double>(end_v - start_v) / 1000000;

    //same but with deque
    clock_t start_deq = clock();
    parse_input(argc, argv, input_d);
    PmergeMe::do_sort(input_d);
    clock_t end_deq = clock();
    double elapsed_time_deq = static_cast<double>(end_deq - start_deq) / 1000000;

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector\t" << std::fixed << std::setprecision(5) << elapsed_time_vec << "s" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque\t" << std::fixed << std::setprecision(5) << elapsed_time_deq << "s" << std::endl;

    return 0;
}