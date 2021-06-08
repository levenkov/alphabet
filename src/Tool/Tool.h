#ifndef ABC_TOOL_H
#define ABC_TOOL_H


#include <string>
#include <boost/filesystem/path.hpp>

#include <ExecutionResult/ProbingResult.h>
#include <ExecutionResult/MediationResult.h>


namespace abc
{

class Toolset;

class Tool
{
public:
    Tool(const boost::filesystem::path& path) : m_path(path) { }

    ProbingResult probe(const std::vector<std::string> arguments);

    MediationResult execute();

private:
    boost::filesystem::path m_path;
    bool m_bProbed = false;
    std::string m_probingOutput;
};

}

#endif
