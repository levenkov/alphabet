#ifndef ABC_TOOLSET_SEARCHER_H
#define ABC_TOOLSET_SEARCHER_H

#include <vector>
#include <boost/filesystem/path.hpp>


namespace abc
{

class Toolset;


class ToolsetSearcher
{
public:
    ToolsetSearcher(
        const std::string programName,
        const std::vector<std::string> arguments
    ) : m_arguments(arguments), m_programName(programName) { }

    std::vector<Toolset> search();

private:
    static boost::filesystem::path toolsetsPath();
    static boost::filesystem::path libPath();
    static boost::filesystem::path userHomeDirectory();

private:
    std::string m_programName;
    std::vector<std::string> m_arguments;
};

}

#endif
