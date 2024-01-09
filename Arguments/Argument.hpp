#ifndef ARGUMENT_HPP
#define ARGUMENT_HPP

#include <string>
#include <iostream>

/**
 * @brief Namespace for parsing command-line arguments
 */
namespace Arguments
{
    /**
     * @class Argument
     * @brief This is the base class for various inherited Argument types used by the ArgumentParser.
     */
    class Argument
    {
    private:
        /**
         * @brief The name of the argument.
         */
        std::string name;

        /**
         * @brief The requirement status of the argument.
         */
        bool required;

    public:
        /**
         * @brief Constructs a new Argument object - used for compiling, not actually called.
         */
        Argument();

        /**
         * @brief Destroy the Argument object - used for compiling, not actually called.
         */
        ~Argument();

        /**
         * @brief Gets the name of the argument.
         */
        std::string get_name();

        /**
         * @brief Gets the requirement status of the argument.
         */
        bool get_required();

        /**
         * @brief Sets the name of the argument.
         * @param name The name to set the argument's name to.
         */
        void set_name(const std::string &name);

        /**
         * @brief Sets the requirement status of the argument.
         * @param required Whether or not this argument is required.
         */
        void set_required(bool required);

        /**
         * @brief Gets the argument's value in the form of a string.
         * @return The value of the argument in string form.
         */
        virtual std::string get_string_value() = 0;

        /**
         * @brief Gets the argument's value in the form of an int.
         * @return The value of the argument in string form.
         */
        virtual int get_int_value() = 0;

        /**
         * @brief Gets the argument's value in the form of a double.
         * @return The value of the argument in string form.
         */
        virtual double get_double_value() = 0;

        /**
         * @brief Gets the argument's value in the form of a bool.
         * @return The value of the argument in bool form.
         */
        virtual bool get_bool_value() = 0;

        /**
         * @brief Sets the value of the argument.
         * @param value The new value to set the argument's value to.
         */
        virtual void set_value(const std::string &value) = 0;

        /**
         * @brief Gets the type of the argument.
         * @return The type of the argument.
         */
        virtual int get_type() = 0;
    };
} /* End of Arguments Namespace */

#endif /* ARGUMENT_HPP */