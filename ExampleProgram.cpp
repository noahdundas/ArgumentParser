#include "ArgumentParser.hpp"
#include "ArgType.hpp"

// In this simple example, we declare an argument of each type, and set the -String, -Int, and -Double arguments as 
// required, meaning that they must be provided or an error will be thrown.

// We can run the program like this: 
// ExampleProgram.exe -String "Hello world!" -Int 5 -Double 2.3 -Bool True -Flag
// and the output message will print the values passed in on the command line
int main(int argc, char* argv[]) {
    Arguments::ArgumentParser args;
    args.add_argument("-String", Arguments::ArgType::STRING, true);
    args.add_argument("-Int", Arguments::ArgType::INT, true);
    args.add_argument("-Double", Arguments::ArgType::DOUBLE, true);
    args.add_argument("-Bool", Arguments::ArgType::BOOL, false);
    args.add_argument("-Flag", Arguments::ArgType::FLAG, false);
    
    args.parse_args(argc, argv);

    std::cout << "String: " << args.get_argument_string("-String") << std::endl;
    std::cout << "Int: " << args.get_argument_int("-Int") << std::endl;             
    std::cout << "Double: " << args.get_argument_double("-Double") << std::endl;     
    std::cout << "Bool: " << args.get_argument_string("-Bool") << std::endl; 
    std::cout << "Flag: " << args.get_argument_string("-Flag") << std::endl; 
}