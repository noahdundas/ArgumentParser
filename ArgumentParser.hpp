#ifndef ARGUMENT_PARSER_HPP
#define ARGUMENT_PARSER_HPP

#include <string>
#include <vector>
#include <type_traits>
#include <map>
#include <cstring>

#include "Arguments/Argument.hpp"
#include "Arguments/IntArgument.hpp"
#include "Arguments/DoubleArgument.hpp"
#include "Arguments/StringArgument.hpp"
#include "Arguments/BoolArgument.hpp"
#include "Arguments/FlagArgument.hpp"
#include "ArgType.hpp"

/**
 * @brief Namespace for parsing command-line arguments
 */
namespace Arguments
{
    /**
     * @class ArgumentParser
     * @brief This class is responsible for registering and parsing arguments, and returning their value.
     */
    class ArgumentParser
    {
    private:
        /**
         * @brief The map holding each argument added into the argument parser.
         */
        std::map<std::string, Argument*> arg_map;

    public:
        /**
         * @brief Adds an argument of the given type with given name and requirement to the arg_map.
         * @param name The name of the new argument.
         * @param type The type of the new argument, given in ArgumentParser::ArgType::TYPE form.
         * @param required Whether or not the argument is required.
         * @exception invalid_argument add_argument() has been given a name already registered.
         * @exception invalid_argument add_argument() has been given a type that is not supported.
         * @return Returns an integer code that indicates if adding the node was successful: 0 if yes.
         */
        int add_argument(std::string name, Arguments::ArgType type, bool required)
        {
            if (arg_map.count(name) > 0)
            {
                throw std::invalid_argument("The map already contains an argument with this name!");
            }

            switch (type)
            {
            case Arguments::ArgType::INT:
                //Create a new IntArgument and add it to the map
                arg_map.insert(std::make_pair(name, new IntArgument(name, 0, required)));
                break;
            case Arguments::ArgType::DOUBLE:
                //Create a new DoubleArgument and add it to the map
                arg_map.insert(std::make_pair(name, new DoubleArgument(name, 0.0, required)));
                break;
            case Arguments::ArgType::STRING:
                //Create a new StringArgument and add it to the map
                arg_map.insert(std::make_pair(name, new StringArgument(name, "", required)));
                break;
            case Arguments::ArgType::BOOL:
                //Create a new BoolArgument and add it to the map
                arg_map.insert(std::make_pair(name, new BoolArgument(name, false, required)));
                break;
            case Arguments::ArgType::FLAG:
                // //Create a new FlagArgument and add it to the map
                arg_map.insert(std::make_pair(name, new FlagArgument(name, false, false)));
                break;
            default:
                //Type not supported
                throw std::invalid_argument("The type given is not supported!");
            }
            return 0;
        }

        /**
         * @brief Reads the argv array and detects what arguments have been passed, and records their values.
         * @param argc The number of elements in the command line.
         * @param argv The array of character pointer arguments given on the command line.
         * @exception invalid_argument This exception is thrown when an argument that is registered as required is absent from the command line.
         */
        void parse_args(int argc, char **argv)
        {
            //For each registered argument:
            for (auto a : arg_map)
            {
                //Get the name of that argument
                std::string argument_name = a.first;

                //Check the command line for that argument
                const char *char_name = argument_name.c_str();

                if (cmdline_contains_argument(argv, argv + argc, char_name))
                {
                    if (a.second->get_type() == Arguments::ArgType::FLAG) //In this case, the argument has no value
                    {
                        a.second->set_value(std::string("true"));
                    }
                    else //In this case, the argument has exactly one value
                    {
                        try
                        {
                            //Get the value of that argument
                            char *cvalue = cmdline_agument_value(argv, argv + argc, argument_name.c_str());
                            //Assign that value to the Argument
                            a.second->set_value(std::string(cvalue));
                        }
                        catch (...)
                        {
                            throw std::invalid_argument("You must provide a value for the argument!");
                        }
                    }
                }
                else if (a.second->get_required() == true)
                {
                    throw std::invalid_argument("Missing a required argument!");
                }
            }
        }

        /**
         * @brief Finds whether or not the command line contains a specified argument
         * @param begin The beginning of the command line
         * @param end The end of the command line
         * @param argument The argument to check the command line for
         * @return Returns a boolean value representing whether or not the argument was found
         */
        bool cmdline_contains_argument(char ** begin, char ** end, const char * argument)
        {
            for (size_t i = 0; i < (size_t)(end - begin); ++i) {
                if (strcmp(begin[i], argument) == 0) {
                    return true;
                }
            }
            return false;
        }

        /**
         * @brief Finds the value of a provided argument within the given bounds of a command line
         * @param begin The beginning of the command line
         * @param end The end of the command line
         * @param argument The argument to find the value of
         * @return Returns the value of the argument, if it's found
         */
        char * cmdline_agument_value(char ** begin, char ** end, const char * argument)
        {
            // Finds the argument in the command string
            size_t i = 0;
            size_t end_i = (size_t)(end - begin);
            for (; i < end_i; ++i) {
                if (strncmp(begin[i], argument, strlen(argument)) == 0) {
                    break;
                }
            }

            // Returns the value of the argument
            if (i < end_i - 1 && begin[i++] != NULL) {
                return begin[i];
            }

            return NULL;
        }

        /**
         * @brief Returns the value of a specified argument, called after parse_args.
         * @param name The name of the argument to return the value of.
         * @return Returns the argument's value in string form.
         */
        std::string get_argument_string(std::string name)
        {
            if (arg_map.count(name) > 0)
            {
                return arg_map[name]->get_string_value();
            }

            throw std::invalid_argument("The given Argument name is not contained in the map!");
        }

        /**
         * @brief Returns the value of a specified argument, called after parse_args.
         * @param name The name of the argument to return the value of.
         * @return Returns the argument's value in int form.
         */
        int get_argument_int(std::string name)
        {
            if (arg_map.count(name) > 0)
            {
                return arg_map[name]->get_int_value();
            }

            throw std::invalid_argument("The given Argument name is not contained in the map!");
        }

        /**
         * @brief Returns the value of a specified argument, called after parse_args.
         * @param name The name of the argument to return the value of.
         * @return Returns the argument's value in double form.
         */
        double get_argument_double(std::string name)
        {
            if (arg_map.count(name) > 0)
            {
                return arg_map[name]->get_double_value();
            }

            throw std::invalid_argument("The given Argument name is not contained in the map!");
        }

        /**
         * @brief Returns the value of a specified argument, called after parse_args.
         * @param name The name of the argument to return the value of.
         * @return Returns the argument's value in boolean form.
         */
        bool get_argument_bool(std::string name)
        {
            if (arg_map.count(name) > 0)
            {
                return arg_map[name]->get_bool_value();
            }

            throw std::invalid_argument("The given Argument name is not contained in the map!");
        }
    };
} /* End of Arguments Namespace */

#endif /* ARGUMENT_PARSER_HPP */