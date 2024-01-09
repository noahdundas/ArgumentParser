#include "DoubleArgument.hpp"
#include "../ArgType.hpp"

/* DoubleArgument Constructor */
Arguments::DoubleArgument::DoubleArgument(const std::string& con_name, double con_value, bool con_required)
{
    set_name(con_name);
    value = con_value;
    set_required(con_required);
}

/* Set method for the argument value */
void Arguments::DoubleArgument::set_value(const std::string& input)
{
    try
    {
        value = stod(input);
    }
    catch (...)
    {
        throw std::invalid_argument("DoubleArgument must be given an double value!");
    }
}

/* Get method for the argument value*/
std::string Arguments::DoubleArgument::get_string_value()
{
    return std::to_string(value);
}

/* Get method for the argument value in int form*/
int Arguments::DoubleArgument::get_int_value()
{
    try
    {
        return static_cast<int>(round(value));
    }
    catch (...)
    {
        throw std::invalid_argument("Error converting DoubleArgument to int!");
    }
}

/* Get method for the argument value in double form*/
double Arguments::DoubleArgument::get_double_value()
{
    return value;
}

/* Get method for the argument value in bool form*/
bool Arguments::DoubleArgument::get_bool_value()
{
    if (value == 0.0)
    {
        return false;
    } 
    else if (value == 1.0)
    {
        return true;
    }
    else
    {
        throw std::invalid_argument("Error converting DoubleArgument to bool!");
    }
}

/* Get method for the argument type */
int Arguments::DoubleArgument::get_type()
{
    return Arguments::ArgType::DOUBLE;
}