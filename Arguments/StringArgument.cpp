#include "StringArgument.hpp"
#include "../ArgType.hpp"

#include <algorithm>
#include <cctype>
#include <string>

/* StringArgument Constructor */
Arguments::StringArgument::StringArgument(const std::string& con_name, std::string con_value, bool con_required)
{
    set_name(con_name);
    value = con_value;
    set_required(con_required);
}

/* Set method for the argument value*/
void Arguments::StringArgument::set_value(const std::string& input)
{
    value = input;
}

/* Get method for the argument value*/
std::string Arguments::StringArgument::get_string_value()
{
    return value;
}

/* Get method for the argument value in int form*/
int Arguments::StringArgument::get_int_value()
{
    try
    {
        return std::stoi(value);
    }
    catch (...)
    {
        throw std::invalid_argument("Error converting StringArgument to int!");
    }
}

/* Get method for the argument value in double form*/
double Arguments::StringArgument::get_double_value()
{
    try
    {
        return std::stod(value);
    }
    catch (...)
    {
        throw std::invalid_argument("Error converting StringArgument to double!");
    }
}

/* Get method for the argument value in bool form*/
bool Arguments::StringArgument::get_bool_value()
{
    // Checks the lowercase version of the argument value
    std::string temp_value = value;
    std::transform(temp_value.begin(), temp_value.end(), temp_value.begin(), [](unsigned char c){ return std::tolower(c); });
    
    if(temp_value == "true")
    {
        return true;
    }
    else if(temp_value == "false")
    {
        return false;
    }
    else
    {
        throw std::invalid_argument("Error converting StringArgument to bool!");
    }
}

/* Get method for the argument type */
int Arguments::StringArgument::get_type()
{
    return Arguments::ArgType::STRING;
}