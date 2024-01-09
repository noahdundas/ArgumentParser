#include "Argument.hpp"

/* Default constructor */
Arguments::Argument::Argument() = default;

/* Default destructor */
Arguments::Argument::~Argument() = default;

/* Get method for argument name */
std::string Arguments::Argument::get_name()
{
    return name;
}

/* Get method for argument requirement status */
bool Arguments::Argument::get_required()
{
    return required;
}

/* Set method for argument name */
void Arguments::Argument::set_name(const std::string& new_name)
{
    name = new_name;
}

/* Set method for argument requirement status */
void Arguments::Argument::set_required(bool new_required)
{
    required = new_required;
}