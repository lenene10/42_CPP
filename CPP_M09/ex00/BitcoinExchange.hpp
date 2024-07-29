#pragma once

#include <map>
#include <string>

#define DATABASE_NAME "data.csv"

class BitcoinExchange {
    
    std::map<std::string, float> _currencies_database;
    void fill_database_with_CSV(const std::string& filename);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        ~BitcoinExchange();

        //methods
        void    print_database() const;
        std::string get_closest_date(std::string const &key);
        void    execute(std::string const &key, float value);


        /* class InputError : public std::runtime_error {
            public:
                InputError(std::string const &message);                
        }; */
};