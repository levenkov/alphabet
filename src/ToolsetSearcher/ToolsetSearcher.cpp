#include <boost/filesystem.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>

#include <Toolset/Toolset.h>

#include "ToolsetSearcher.h"


using namespace abc;

using namespace std;
using namespace boost;
using namespace boost::filesystem;
using namespace boost::range;
using namespace boost::adaptors;


vector<Toolset> ToolsetSearcher::search()
{
    return copy_range<vector<Toolset>>(
        directory_iterator(toolsetsPath() / m_programName)
            | filtered(
                [](const directory_entry& e) {
                    return e.status().type() == file_type::directory_file;
                }
            )
            | transformed(
                [](const directory_entry& e) { return Toolset(e.path()); }
            )
    );
}

path ToolsetSearcher::toolsetsPath()
{
    return libPath() / "toolsets";
}

path ToolsetSearcher::libPath()
{
    return userHomeDirectory() / ".local/lib/alphabet";
}

path ToolsetSearcher::userHomeDirectory()
{
    return getenv("HOME");
}
