#include <boost/filesystem.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>

#include <Tool/Tool.h>

#include "Toolset.h"


using namespace std;
using namespace boost;
using namespace boost::filesystem;
using namespace boost::range;
using namespace boost::adaptors;

using namespace abc;


std::vector<Tool> Toolset::tools()
{
    return copy_range<vector<Tool>>(
        directory_iterator(m_path)
            | filtered(
            [](const directory_entry& e) {
                auto status = e.status();
                return (
                    status.type() == file_type::regular_file &&
                        (status.permissions() & perms::others_exe) != perms::no_perms
                );
            }
        )
            | transformed(
            [](const directory_entry& e) { return Tool(e.path()); }
        )
    );
}