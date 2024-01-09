#include "BoolArgument.hpp"
#include "../ArgType.hpp"
#include <algorithm>
#include <cctype>
#include <string>

/* BoolArgument Constructor */
Arguments::BoolArgument::BoolArgument(const std::string& con_name, bool con_value, bool con_required)
{
    set_name(con_name);
    value = con_value;
    set_required(con_required);
}

/* Set method for the argument value*/
void Arguments::BoolArgument::set_value(const std::string& input)
{
    std::string mod_input = input;
    // Sets the input to lowercase
    std::transform(mod_input.begin(), mod_input.end(), mod_input.begin(), [](unsigned char c){ return std::tolower(c); });
    
    if(mod_input == "true")
    {
        value = true;
    }
    else if(mod_input == "false")
    {
        value = false;
    }
    else
    {
        throw std::invalid_argument("BoolArgument's value can only be 'true' or 'false'!");
    }
}

/* Get method for the argument value in string form*/
std::string Arguments::BoolArgument::get_string_value()
{
    if(value)
    {
        return std::string("true");
    }
    else 
    {
        return std::string("false");
    }
}

/* Get method for the argument value in int form*/
int Arguments::BoolArgument::get_int_value()
{
    if(value)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

/* Get method for the argument value in double form*/
double Arguments::BoolArgument::get_double_value()
{
    if(value)
    {
        return 1.0;
    }
    else 
    {
        return 0.0;
    }
}

/* Get method for the argument value in bool form*/
bool Arguments::BoolArgument::get_bool_value()
{
    return value;
}

/* Get method for the argument type */
int Arguments::BoolArgument::get_type()
{
    return Arguments::ArgType::BOOL;
}