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
    ToolsetSearcher(const std::string programName)
        : m_programName(programName) { }

    std::vector<Toolset> search();

private:
    static std::vector<boost::filesystem::path> toolsetPaths();

    static boost::filesystem::path toolsetsPath(const boost::filesystem::path& basePath);

    static boost::filesystem::path systemLibPath();
    static boost::filesystem::path userLibPath();

    static boost::filesystem::path userHomePath();

private:
    std::string m_programName;
};

}

#endif
