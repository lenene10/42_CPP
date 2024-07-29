#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <map>
#include <iostream>

BitcoinExchange::BitcoinExchange() {

    BitcoinExchange::fill_database_with_CSV(DATABASE_NAME);
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    if (this != &other)
    {
        _currencies_database.clear();
        _currencies_database = other._currencies_database;
    }
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
    if (this != &rhs) {
        *this = rhs;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    _currencies_database.clear();
}

//methods

void    BitcoinExchange::fill_database_with_CSV(const std::string& filename) {
    std::ifstream file(filename.c_str());
    std::string line;
    std::string dummyLine;

    // Skip the first line
    std::getline(file, dummyLine);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string key;
        float value;

        if (std::getline(ss, key, ',') && ss >> value) {
            _currencies_database[key] = value;
        }
    }
}

void    BitcoinExchange::print_database() const {
    for (std::map<std::string, float>::const_iterator it = _currencies_database.begin(); it != _currencies_database.end(); ++it) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

std::string BitcoinExchange::get_closest_date(std::string const &key) {
    std::map<std::string, float>::const_iterator closest_iter = _currencies_database.begin();

    for (std::map<std::string, float>::const_iterator it = _currencies_database.begin();
        it != _currencies_database.end() && it->first <= key;
        ++it) {
        closest_iter = it;
    }
    //std::cout << "Closest date: " << closest_iter->first << std::endl;
    if (closest_iter->first > key)      //if the searched date is smaller then the smallest one in the DB
        throw std::runtime_error("Error: Date not found");
    return closest_iter->first;
    
}

void    BitcoinExchange::execute(std::string const &key, float value) {

    // TODO: get closest early date
    std::string closest_date;
    try {
        closest_date = BitcoinExchange::get_closest_date(key);
    } catch (std::runtime_error &e) {
        throw;
    }
    
    std::map<std::string, float>::const_iterator it = _currencies_database.find(closest_date);
    if (it == _currencies_database.end()) {
        throw std::runtime_error("Error: Date not found");
    }
    std::cout << key << " => " << value <<  " = " << it->second * value << std::endl;
}

