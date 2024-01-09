#include "IntArgument.hpp"
#include "../ArgType.hpp"

/* IntArgument Constructor */
Arguments::IntArgument::IntArgument(const std::string& con_name, int con_value, bool con_required)
{
    set_name(con_name);
    value = con_value;
    set_required(con_required);
}

/* Set method for the argument value*/
void Arguments::IntArgument::set_value(const std::string& input)
{
    try
    {
        value = stoi(input);
    }
    catch (...)
    {
        throw std::invalid_argument("IntArgument must be given an int value!");
    }
}

/* Get method for the argument value*/
std::string Arguments::IntArgument::get_string_value()
{
    return std::to_string(value);
}

/* Get method for the argument value in int form*/
int Arguments::IntArgument::get_int_value()
{
    return value;
}

/* Get method for the argument value in double form*/
double Arguments::IntArgument::get_double_value()
{
    try
    {
        return static_cast<double>(value);
    }
    catch (...)
    {
        throw std::invalid_argument("Error converting IntArgument to double!");
    }
}

/* Get method for the argument value in bool form*/
bool Arguments::IntArgument::get_bool_value()
{
    if (value == 0)
    {
        return false;
    } 
    else if (value == 1)
    {
        return true;
    }
    else
    {
        throw std::invalid_argument("Error converting IntArgument to bool!");
    }
}

/* Get method for the argument type */
int Arguments::IntArgument::get_type()
{
    return Arguments::ArgType::INT;
}