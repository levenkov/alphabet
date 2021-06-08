#ifndef ABC_TOOLSET_H
#define ABC_TOOLSET_H

#include <vector>
#include <boost/filesystem.hpp>


namespace abc
{

class Tool;


class Toolset
{
public:
    Toolset(const boost::filesystem::path& path) : m_path(path) { }

    std::vector<Tool> tools();

    boost::filesystem::path path() const { return m_path; };

private:
    boost::filesystem::path m_path;
};

}

#endif
