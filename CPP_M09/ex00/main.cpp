#include "BitcoinExchange.hpp"

#include <cmath>
#include <cstring>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <map>
#include <stdexcept>
#include <string>
#include <utility>

typedef std::multimap<std::string, float> multimap;

std::string remove_spaces(const std::string &str) {
    std::string result = "";
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] != ' ') {
            result += str[i];
        }
    }
    return result;
}

bool is_valid_date(int year, int month, int day) {
    int isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int daysInMonth[] = {31, 28 + isLeapYear, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_in_month = daysInMonth[month - 1];
    return day <= days_in_month;
}

std::string get_current_date() {
    std::time_t currentTime = std::time(NULL);
    std::tm* timeInfo = std::localtime(&currentTime);

    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeInfo);

    std::string currentDate(buffer);

    return currentDate;
}

void   store_input_data(const std::string& filename, multimap &input_db) {
    std::ifstream file(filename.c_str());
    std::string line;
    std::string dummyline;

    std::getline(file, dummyline);  // skip first line
    while (std::getline(file, line)) {
        std::cout   << remove_spaces(line) << std::endl;
        std::stringstream ss(remove_spaces(line));
        std::string key;
        float value;

        if (std::getline(ss, key, '|') && ss >> value) {
            input_db.insert(std::make_pair(key, value));
        }
    }
}

int     count_occurence_of_char(const std::string &str, char c)
{
    int count = 0;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[i] == c)
            count++;
    }
    return count;
}

bool is_string_really_number(const std::string &str)
{
    if (str.empty() || str.size() > 10 || (str.size() == 10 && str > "2147483647"))
        return false;
    int dots = 0;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            if (str[i] == '.' && dots == 0)
                dots++;
            else
                return false;
        }
    }
    return true;
}

bool    starts_with_zeros(const std::string &str)
{
    if (str[0] == '0' && str.size() > 1 && str[1] != '.')
        return false;
    return true;
}

void    ft_validate_line_for_database(const std::string &line)
{
    int year = 0;
    int month = 0;
    int day = 0;
    int num_beg = 0;
    float rate = 0;
    if (line.empty())
        throw std::runtime_error("Error: CSV: Empty line");
    int i = 0;
    while (i < (int)line.size() && line[i] != ',')
    {
        if (line[i] == '-' && num_beg == 0)
        {
            year = atoi(line.substr(num_beg, i - num_beg).c_str());
            if (year < 1)
                throw std::runtime_error("Error: CSV: Invalid year");
            num_beg = i + 1;
        }
        else if (line[i] == '-' && num_beg == 5)
        {
            month = atoi(line.substr(num_beg, i - num_beg).c_str());
            if (month < 1 || month > 12)
                throw std::runtime_error("Error: CSV: Invalid month");
            num_beg = i + 1;
        } 
        i++;
    }
    if (num_beg == 0)
        throw std::runtime_error("Error: CSV: Missing date");
    else if (line[i] == ',' && num_beg == 8)
    {
        day = atoi(line.substr(num_beg, i - num_beg).c_str());
        if (day < 1 || day > 31)
            throw std::runtime_error("Error: CSV: Invalid day");
        num_beg = i + 1;
    }
    if (num_beg != 11)
        throw std::runtime_error("Error: CSV: Wrong date");
    //check for future date
    if (line.substr(0, i).c_str() > get_current_date())
        throw std::runtime_error("Future date");

    if (line[i++] != ',')
        throw std::runtime_error("Error: CSV: Separator incorrectly positioned");
    num_beg = i;
    std::string rate_temp = line.substr(num_beg, line.size() - num_beg);
    rate = atof(rate_temp.c_str());
    if (rate == 0 && rate_temp != "0")
        throw std::runtime_error("Error: CSV: Wrong amount");
    if (starts_with_zeros(rate_temp) == false)
        throw std::runtime_error("Error: CSV: Wrong amount");
    if (is_string_really_number(rate_temp) == false)
        throw std::runtime_error("Error: CSV: Wrong amount");
    if (rate < 0 )
        throw std::runtime_error("Error: CSV: Rate must be positive");
    if (is_valid_date(year, month, day) == false)
        throw std::runtime_error("Error: CSV: Invalid date");
}

void    ft_validate_line(const std::string &line)
{
    int year = 0;
    int month = 0;
    int day = 0;
    int num_beg = 0;
    float amount = 0;
    if (line.empty())
        throw std::runtime_error("Error: Empty line");
    int i = 0;
    while (i < (int)line.size() && line[i] != ' ')
    {
        if (line[i] == '-' && num_beg == 0)
        {
            year = atoi(line.substr(num_beg, i - num_beg).c_str());
            if (year < 1)
                throw std::runtime_error("Error: Invalid year");
            num_beg = i + 1;
        }
        else if (line[i] == '-' && num_beg == 5)
        {
            month = atoi(line.substr(num_beg, i - num_beg).c_str());
            if (month < 1 || month > 12)
                throw std::runtime_error("Error: Invalid month");
            num_beg = i + 1;
        }
        i++;
    }
    if (line[i] == ' ' && num_beg == 8)
    {
        day = atoi(line.substr(num_beg, i - num_beg).c_str());
        if (day < 1 || day > 31)
            throw std::runtime_error("Error: Invalid day");
        num_beg = i + 1;
    }
    if (num_beg != 11)
        throw std::runtime_error("Error: Wrong date");
    //wrong date
    if (num_beg == 0)
        throw std::runtime_error("Error: Wrong date");
    else if (month == 0)
        throw std::runtime_error("Error: Wrong date");
    else if (day == 0)
        throw std::runtime_error("Error: Wrong date");
    //check for future date
    if (line.substr(0, i).c_str() > get_current_date())
        throw std::runtime_error("Error: Future date");
    i++;
    if (line[i++] != '|')
        throw std::runtime_error("Error: Separator incorrectly positioned");
    if (line[i++] != ' ')
        throw std::runtime_error("Error: Space after separator missing");
    num_beg = i;
    std::string amount_temp = line.substr(num_beg, line.size() - num_beg);
   /*  int dots = count_occurence_of_char(amount_temp, '.');
    if (dots > 1)
        throw std::runtime_error("Error: Wrong amount"); */
    if (is_string_really_number(amount_temp) == false)
        throw std::runtime_error("Error: Wrong amount");
    amount = atof(amount_temp.c_str());
    if (starts_with_zeros(amount_temp) == false)
        throw std::runtime_error("Error: Wrong amount");
    if ((amount == 0 && amount_temp != "0") )
        throw std::runtime_error("Error: Incorrect input number (0.0 should be just 0)");
    if (amount < 0 || amount > 1000)
        throw std::runtime_error("Error: Amount must be between 0 and 1000");
    if (is_valid_date(year, month, day) == false)
        throw std::runtime_error("Error: Invalid date");
}


void ft_parse_db(const std::string &filename)
{
    bool entered = false;
    std::ifstream filee(filename.c_str());
    if (!filee.is_open())
        throw std::runtime_error("Error: File not found");
    std::string line;
    std::string dummyline;
    if (!getline(filee, dummyline))  // skip first line
        throw std::runtime_error("Error: File needs to have at least 2 lines");
    if (dummyline != "date,exchange_rate")
        throw std::runtime_error("Error: First line must be 'date,exchange_rate'");

    while (std::getline(filee, line))
    {
        try {
            ft_validate_line_for_database(line);
        } catch (std::runtime_error &e) {
            throw ;
        }
        entered = true;
    }
    if (!entered)
        throw std::runtime_error("Error: File needs to have at least 2 lines");
}


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./ex00 [filename]" << std::endl;
        return 1;
    }
    try{
        ft_parse_db(DATABASE_NAME);
    } catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    BitcoinExchange be;
    std::ifstream file(argv[1]);
    std::string line;
    std::string dummyline;
    bool entered = false;

    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open file" << std::endl;
        return 1;
    }
    if (!getline(file, dummyline))  // skip first line
    {
        std::cerr << "Error: File needs to have at least 2 lines" << std::endl;
        return 1;
    }
    if (dummyline != "date | value")
    {
        std::cerr << "Error: First line must be 'date | value'" << std::endl;
        return 1;
    }
    while (std::getline(file, line)) {
        entered = true;
        //std::cout   << remove_spaces(line) << std::endl;
        try {
            ft_validate_line(line);

            std::stringstream ss(remove_spaces(line));
            std::string key;
            float       value;
            std::getline(ss, key, '|');
            ss >> value;
            be.execute(key, value);
        } catch (std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    if (!entered)
    {
        std::cerr << "Error: File needs to have at least 2 lines" << std::endl;
        return 1;
    }
    return 0;
}