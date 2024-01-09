#ifndef FLAG_ARGUMENT_HPP
#define FLAG_ARGUMENT_HPP

#include <string>
#include <iostream>

#include "Argument.hpp"
#include "../ArgType.hpp"

/**
 * @brief Namespace for parsing command-line arguments
 */
namespace Arguments
{
    /**
     * @class FlagArgument
     * @brief This type of Argument is built to handle the bool type.
     */
    class FlagArgument : public Argument
    {
    private:
        /**
         * @brief This stores the argument's value.
         */
        bool value;

    public:
        /**
         * @brief Construct a new FlagArgument.
         * @param con_name The name given in the constructor.
         * @param value The value given by the constructor.
         * @param con_required The requirement status given by the constructor.
         */
        FlagArgument(const std::string &con_name, bool value, bool con_required);

        /**
         * @brief Gets the value of the argument in the form of a string.
         * @return Returns the value of the argument in string form.
         */
        std::string get_string_value() override;

        /**
         * @brief Gets the value of the argument in the form of an int.
         * @return Returns the value of the argument in int form.
         */
        int get_int_value() override;

        /**
         * @brief Gets the value of the argument in the form of a double.
         * @return Returns the value of the argument in double form.
         */
        double get_double_value() override;

        /**
         * @brief Gets the value of the argument in the form of a bool.
         * @return Returns the value of the argument in bool form.
         */
        bool get_bool_value() override;

        /**
         * @brief Sets the value of this object.
         * @param value The new value to set this argument's value to.
         */
        void set_value(const std::string &value) override;

        /**
         * @brief Gets the type of argument
         * @return A string representing the type of argument
         */
        int get_type() override;
    };
} /* End of Arguments Namespace */

#endif /* FLAG_ARGUMENT_HPP */