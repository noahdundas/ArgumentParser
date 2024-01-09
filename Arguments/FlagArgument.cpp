#include "FlagArgument.hpp"
#include "../ArgType.hpp"

/* FlagArgument Constructor */
Arguments::FlagArgument::FlagArgument(const std::string& con_name, bool con_value, bool con_required)
{
    set_name(con_name);
    value = con_value;
    set_required(con_required);
}

/* Set method for the argument value*/
void Arguments::FlagArgument::set_value(const std::string& input)
{
    if(input == "true")
    {
        value = true;
    }
    else if(input == "false")
    {
        value = false;
    }
    else
    {
        throw std::invalid_argument("FlagArgument's value can only be 'true' or 'false'!");
    }
}

/* Get method for the argument value in string form*/
std::string Arguments::FlagArgument::get_string_value()
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
int Arguments::FlagArgument::get_int_value()
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
double Arguments::FlagArgument::get_double_value()
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
bool Arguments::FlagArgument::get_bool_value()
{
    return value;
}

/* Get method for the argument type */
int Arguments::FlagArgument::get_type()
{
    return Arguments::ArgType::FLAG;
}