#include "ScalarConverter.hpp"
#include <cmath>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

enum input_type {
    NONE,
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    LITERALS
};

struct helper_vars
{
    bool is_impossible;
    bool ends_with_f;
    bool has_dot;
    bool is_literal;   //nan, nanf, +inf, +inff, -inf, -inff
    input_type real_type;
    char    char_val;
    int     int_val;
    float   float_val;
    double  double_val;
};

// ----------------------


// ----------------------

/* void    ScalarConverter::printChar() {
    if ( this->isLiteral() || (_int_val < 0 && ( _int_val >= 127 ) ) ) {
        std::cout << "Impossible";
    } else if ( !std::isprint( this->_int_val ) ) {
        std::cout << "None displayable";
    } else {
        std::cout << "'" << _char_val << "'";
    }
    std::cout << std::endl;
} */

bool    ft_isDigit(char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}

void    fill_helper_vars(std::string input, struct helper_vars *my_bools)
{
    my_bools->is_impossible = false;
    my_bools->ends_with_f = false;
    my_bools->has_dot = false;
    my_bools->is_literal = false;
    my_bools->real_type = NONE;
    my_bools->char_val = '\0';
    my_bools->int_val = 0;
    my_bools->float_val = 0.0f;
    my_bools->double_val = 0.0;

    //is literal?
    if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff" || input == "inf" || input == "inff")
    {
        my_bools->is_literal = true;
        return ;
    }

    //e.g. "a..."
    if (input.size() > 1 && !ft_isDigit(input[0]) /* && input[0] != '+' */ && input[0] != '-')
        my_bools->is_impossible = true;

    if (my_bools->is_impossible == false && input.size() > 1)
    {
        for (int i = 1; i < (int)input.size(); i++)
        {
            if (!ft_isDigit(input[i]) && input[i] != 'f' && input[i] != '.')
            {
                my_bools->is_impossible = true;
                return ;
            }
            else if (input[i] == 'f')
            {
                if (i != (int)input.size() - 1)    //e.g. "5f5"
                {
                    my_bools->is_impossible = true;
                    return ;
                }
                my_bools->ends_with_f = true;
            }
            else if (input[i] == '.')
            {
                if (my_bools->has_dot == true || i == (int)input.size() - 1)   //e.g. "5.5.5" or "5."
                {
                    my_bools->is_impossible = true;
                    return ;
                }
                my_bools->has_dot = true;
            }
        }
    }


}

void    determine_type(std::string input, struct helper_vars *my_bools)
{
    if (my_bools->is_literal == true)
    {
        my_bools->real_type = LITERALS;
        return ;
    }
    else if (my_bools->has_dot == false && my_bools->ends_with_f == false)
    {
        //it is an int or a char
        if (input.length() == 1 && (input[0] < '0' || input[0] > '9'))
            my_bools->real_type = CHAR;
        else
            my_bools->real_type = INT;
    }
    else if (my_bools->has_dot == true)
    {
        //it is a float or a double
        if (my_bools->ends_with_f == true)
            my_bools->real_type = FLOAT;
        else
            my_bools->real_type = DOUBLE;
    }
    else {
        my_bools->is_impossible = true;
    
    }
}

/* int ft_get_int_part(std::string input, struct my_vars *my_bools)
{
    int is_negative = 1;
    int int_part = 0;
    int i = 0;
    if (input[0] == '+' || input[0] == '-')
    {
        i++;
        if (input[0] == '-')
            is_negative = -1;
    }
    for (; i < input.length(); i++)
    {
        if (input[i] == '.')
            break ;
        int_part = int_part * 10 + (input[i] - '0');
    }
    return (int_part * is_negative);
} */
/* 
double  makeDouble(const char *str)
{
    double val = 0.0;
    double sign = 1.0;
    int i = 0;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1.0;
        i++;
    }
    for (; str[i] != '.'; i++)
    {
        if (val > (std::numeric_limits<double>::max() - (str[i] - '0')) / 10.0) {
            // Overflow detected
            return 0.0;
        }
        val = val * 10 + (str[i] - '0');
    }
    i++;
    double frac = 0.1;
    for (; str[i] != '\0'; i++)
    {
        if (val < std::numeric_limits<double>::min()) {
            // Underflow detected
            return 0.0;
        }
        if (val > (std::numeric_limits<double>::max() - (str[i] - '0') * frac)) {
            // Overflow detected
            return 0.0;
        }
        val += (str[i] - '0') * frac;
        frac *= 0.1;
    }
    return (val * sign);
}
 */
void    convert_implicitly(std::string input, struct helper_vars *my_vars)
{
    switch (my_vars->real_type)
    {
        case CHAR:
            my_vars->char_val = input[0];
            break ;
        case INT:
            my_vars->int_val = std::atoi(input.c_str());
            if ((input.size() > 10 && input[0] != '-')
                || (input.size() > 11 && input[0] == '-')
                || (input.size() == 10 && input[0] != '-' && input > "2147483647")
                || (input.size() == 11 && input[0] == '-' && input > "-2147483648"))
                my_vars->int_val = -1; 
            break ;
        case FLOAT:
            my_vars->float_val = std::atof(input.c_str());      //overflow results in +inf or -inf
            break ;
        case DOUBLE:
            my_vars->double_val = (double)std::atof(input.c_str());     //overflow results in +inf or -inf
            break ;
        case LITERALS:
            break ;
        default:
            break ;
    }
}

void    staticCastFromChar(struct helper_vars *my_vars)
{
    my_vars->int_val =  static_cast<int>(my_vars->char_val);
    my_vars->float_val =  static_cast<float>(my_vars->char_val);
    my_vars->double_val =  static_cast<double>(my_vars->char_val);
}

void    staticCastFromInt(struct helper_vars *my_vars)
{
    my_vars->char_val =  static_cast<int>(my_vars->int_val);
    my_vars->float_val =  static_cast<float>(my_vars->int_val);
    my_vars->double_val =  static_cast<double>(my_vars->int_val);
}

void    staticCastFromFloat(struct helper_vars *my_vars)
{
    my_vars->char_val =  static_cast<int>(my_vars->float_val);
    my_vars->int_val =  static_cast<float>(my_vars->float_val);
    my_vars->double_val =  static_cast<double>(my_vars->float_val);
}

void    staticCastFromDouble(struct helper_vars *my_vars)
{
    my_vars->char_val =  static_cast<int>(my_vars->double_val);
    my_vars->int_val =  static_cast<float>(my_vars->double_val);
    my_vars->float_val =  static_cast<double>(my_vars->double_val);
}

void    handleChar(std::string input, struct helper_vars *my_vars)
{
    (void)input;
    //since we know it is a char, we dont need to check anything, it is displayable since the user was able to input it
    std::cout << "Char: '" << my_vars->char_val << "'" << std::endl;
    //cast other 3 types
    staticCastFromChar(my_vars);
    //int
    std::cout << "Int: " << my_vars->int_val << std::endl;
    //float
    std::cout << "Float: " << std::fixed << std::setprecision(1) << my_vars->float_val << "f" << std::endl;
    //double
    std::cout << "Double: " << std::fixed << std::setprecision(1) << my_vars->double_val <<  std::endl;
}

void    handleInt(std::string input, struct helper_vars *my_vars)
{
    //char
    if (my_vars->int_val < 0 || my_vars->int_val > 127 )
        std::cout << "Char: Impossible" << std::endl;
    else if (my_vars->int_val < 32 || my_vars->int_val > 126)
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: '" << static_cast<char>(my_vars->int_val) << "'" << std::endl;
    
    //int
    if (my_vars->int_val == -1 && input != "-1")
    {
        std::cout << "Int: Out of range" << std::endl;
        std::cout << "Float: Int was out of range, sorry" << std::endl;
        std::cout << "Double: Int was out of range, sorry" << std::endl;
    }
    else
    {
        std::cout << "Int: " << my_vars->int_val << std::endl;   
        std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(my_vars->int_val) << "f" << std::endl;
        std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(my_vars->int_val)  << std::endl;
    }
}


void    handleFloat(std::string input, struct helper_vars *my_vars)
{
    (void)input;
    //char
    if (my_vars->float_val < 0 || my_vars->float_val > 127 )
        std::cout << "Char: Impossible" << std::endl;
    else if (my_vars->float_val < 32 || my_vars->float_val > 126)
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: '" << static_cast<char>(my_vars->float_val) << "'" << std::endl;
    
    //int
    if (my_vars->float_val > (float)2147483647 || my_vars->float_val < (float)-2147483648)
        std::cout << "Int: Out of range" << std::endl;
    else
        std::cout << "Int: " << static_cast<int>(my_vars->float_val) << std::endl; 
       
    //float
    if (my_vars->float_val == std::numeric_limits<float>::infinity())
        std::cout << "Float: inff" << std::endl;
    else if ( my_vars->float_val == -std::numeric_limits<float>::infinity())
        std::cout << "Float: -inff" << std::endl;
    else
        std::cout << "Float: " << std::fixed << std::setprecision(1) << my_vars->float_val << "f" << std::endl;

    //double
    std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(my_vars->float_val) << std::endl;
}

void    handleDouble(std::string input, struct helper_vars *my_vars)
{
    (void)input;

    //char
    if (my_vars->double_val < 0 || my_vars->double_val > 127 )
        std::cout << "Char: Impossible" << std::endl;
    else if (my_vars->double_val < 32 || my_vars->double_val > 126)
        std::cout << "Char: Non displayable" << std::endl;
    else
        std::cout << "Char: '" << static_cast<char>(my_vars->double_val) << "'" << std::endl;
    
    //int
    if (my_vars->double_val > 2147483647 || my_vars->double_val < -2147483648)
        std::cout << "Int: Out of range" << std::endl;
    else
        std::cout << "Int: " << static_cast<int>(my_vars->double_val) << std::endl;
    
    //float
    /* if (my_vars->double_val > std::numeric_limits<float>::max() || my_vars->double_val < std::numeric_limits<float>::min())
        std::cout << "Float: Out of range" << std::endl;
    else */
    my_vars->float_val = static_cast<float>(my_vars->double_val);
    if (my_vars->float_val == std::numeric_limits<float>::infinity())
        std::cout << "Float: inff" << std::endl;
    else if ( my_vars->float_val == -std::numeric_limits<float>::infinity())
        std::cout << "Float: -inff" << std::endl;
    else
        std::cout << "Float: " << std::fixed << std::setprecision(1) << my_vars->float_val << "f" << std::endl;
    
    std::cout << "Double: " << std::fixed << std::setprecision(1) << my_vars->double_val << std::endl;
}

void    handleLiterals(std::string input, struct helper_vars *my_vars)
{
    (void)my_vars;
    std::cout << "Char: Impossible" << std::endl;
    std::cout << "Int: Impossible" << std::endl;
    if (input == "nan" || input == "nanf")
    {
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
    }
    else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
    {
        std::cout << "Float: inff" << std::endl;
        std::cout << "Double: inf" << std::endl;
    }
    else if (input == "-inf" || input == "-inff")
    {
        std::cout << "Float: -inff" << std::endl;
        std::cout << "Double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(std::string input)
{
    helper_vars my_vars;
    fill_helper_vars(input, &my_vars);
    determine_type(input, &my_vars);
    if (my_vars.is_impossible == true)
        throw UnableToConvert();
    try{
        convert_implicitly(input, &my_vars);
    } catch (std::out_of_range &e)
    {
        throw OutOfRange();
    }

    void (*functionPTRS[])(std::string input, struct helper_vars *my_vars) = {&handleInt, &handleChar, &handleFloat, &handleDouble, &handleLiterals};
    int types[] = {INT, CHAR, FLOAT, DOUBLE, LITERALS};
    for (int i = 0; i < 5; i++)
    {
        if (my_vars.real_type == types[i])
        {
            functionPTRS[i](input, &my_vars);
            break ;
        }
    }

    /* switch(my_vars.real_type)
	{
		case CHAR:
			std::cout << "its a CHAR" << std::endl;
			break ;

		case DOUBLE:
			std::cout << "its a DOUBLE" << std::endl;
			break ;

		case INT:
			std::cout << "its a INT" << std::endl;
			break ;

		case FLOAT:
			std::cout << "its a FLOAT" << std::endl;
			break ;

		case LITERALS:
			std::cout << "its a LITERALS" << std::endl;
			break ;

		default:
			std::cerr << "Invalid." << std::endl;
	} */
}

ScalarConverter::ScalarConverter(std::string input)
{
    try{
        convert(input);
    }
    catch (ScalarConverter::UnableToConvert &e)
    {
        std::cout << e.what() << std::endl;
    }
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    if (this != &src)
        *this = src;
}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    if (this != &src)
    {
        *this = src;
    }
    return (*this);
}

// ----------------------

const char* ScalarConverter::OutOfRange::what() const throw()
{
    return "Error: Out of range";
}

const char* ScalarConverter::UnableToConvert::what() const throw()
{
    return "Error: Unable to convert";
}
