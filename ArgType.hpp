#ifndef ARG_TYPE_HPP
#define ARG_TYPE_HPP

/**
 * @brief Namespace for parsing command-line arguments
 */
namespace Arguments
{
    /**
     * @brief An enumerator registering the data types that the ArgumentParser can handle.
     * The type passed through the add_argment method corresponds the the type of Argument that will be made.
     */
    typedef enum ArgType
    {
        INT,    /* Represents the int type, and will create an IntArgument. */
        DOUBLE, /* Represents the double type, and will create an DoubleArgument. */
        STRING, /* Represents the std::string type, and will create a StringArgument. */
        BOOL,   /* Represents the bool type, and will create a BoolArgument. */
        FLAG    /* Represents a bool type that will be called via the presence or omission of an argument, and will create a FlagArgument. */
    } ArgType;
} /* End of Arguments Namespace */

#endif /* ARG_TYPE_HPP */