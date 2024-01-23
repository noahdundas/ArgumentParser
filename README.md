## Argument Parser
This project allows software developers to quickly and easily add basic command line argument specifications into their code.

For each argument, a developer can specify the name, expected type, and if the argument is required. 

The type of an Argument can be string, integer, double, boolean, or flag. Flag arguments are unique in that they also represent a boolean value, but are deemed true or false depending on if the user provides the flag on the command line or omits it, rather than extracting the value following the argument from the command line. Flag arguments must always be declared as non-required.

If a required argument is not provided, if the user attempts to provide an argument with no value, or if the user provides an argument with a conflicting type, corresponding errors will be thrown.

For example, if a developer wanted to create a program that took as arguments the information for a person, they could easily define five arguments as such:

```
Arguments::ArgumentParser args;
args.add_argument("-Name", Arguments::ArgType::STRING, true);
args.add_argument("-Age", Arguments::ArgType::INT, false);
args.add_argument("-Height", Arguments::ArgType::DOUBLE, false);
args.add_argument("-Married", Arguments::ArgType::BOOL, false);
args.add_argument("-Friendly", Arguments::ArgType::FLAG, false);
args.parse_args(argc, argv);
```

When running their program, the developer could then provide the arguments as shown below. The order in which these parameters are provided is unimportant, and any parameters not set as required can be omitted.

`$ ./a.out -Name "Simon Belmont" -Age 24 -Height 5.8 -Married false -Friendly`

The argument parser will match each argument to the value provided after it, and will store the values of those arguments in a map. Each argument's value can be read in code as such: 

```
std::string name = args.get_argument_string("-Name");    //"Simon Belmont"
int age = args.get_argument_int("-Age");                 //24
double height = args.get_argument_double("-Height");     //5.8
bool maritalStatus = args.get_argument_bool("-Married"); //false
bool saveData = args.get_argument_bool("-Friendly");     //true
```

Arguments can also be flexibly interpreted as other types. For example, integers can be converted into doubles and doubles into integers; values of 0 and 1 can be converted to their corresponding boolean values and vice versa; and all types of arguments can be converted into strings. For example:

`$ ./a.out -BoolArg true -IntArg 1`
```
Arguments::ArgumentParser args;
args.add_argument("-BoolArg", Arguments::ArgType::BOOL, true);
args.add_argument("-IntArg", Arguments::ArgType::INT, true);

args.parse_args(argc, argv);

std::string boolToString = args.get_argument_string("-BoolArg");  //true -> "true"
int boolToInt = args.get_argument_int("-BoolArg");                //true -> 1
bool intToBool = args.get_argument_bool("-IntArg");               //1 -> true
double intToDouble = args.get_argument_double("-IntArg");         //1 -> 1.0
```
