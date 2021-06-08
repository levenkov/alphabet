#ifndef ABC_MAIN_H
#define ABC_MAIN_H

#include <vector>
#include <string>


namespace abc
{

class Main
{
public:
    static int run(const std::string programName, const std::vector<std::string> arguments);

    static int runDirectMode(const std::vector<std::string> arguments);
    static int runMediatorMode(
        const std::string programName,
        const std::vector<std::string> arguments
    );

private:
    Main()=default;
    Main(Main&)=default;
};

}

#endif
