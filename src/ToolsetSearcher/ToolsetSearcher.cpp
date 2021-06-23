#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/numeric.hpp>

#include <Toolset/Toolset.h>
#include <auxilary/platform_detector.h>
#include <auxilary/vector.h>

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
        accumulate(
            toolsetPaths() | (
                transformed(
                    [this](auto toolsetsPath) {
                        const auto toolsetsSubpath = toolsetsPath / m_programName;

                        return is_directory(toolsetsSubpath) ? (
                            copy_range<vector<directory_entry>>(
                                directory_iterator(toolsetsSubpath) | (
                                    filtered(
                                        [](const directory_entry& e) {
                                            return e.status().type() == file_type::directory_file;
                                        }
                                    )
                                )
                            )
                        ) : (
                            vector<directory_entry>()
                        );
                    }
                )
            ),
            vector<directory_entry>(),
            [](const vector<directory_entry>& sum, const vector<directory_entry>& entry) {
                return sum + entry;
            }
        ) | transformed(
            [](auto dir_entry) { return Toolset(dir_entry); }
        )
    );
}

vector<path> ToolsetSearcher::toolsetPaths()
{
    return copy_range<vector<path>>(
        (
            vector<path>{
                toolsetsPath(systemLibPath()),
                toolsetsPath(userLibPath())
            } + (
                currentWorkingDirectoryAndParentsToolsetPaths()
            )
        ) | (
            uniqued
        )
    );
}

vector<path> ToolsetSearcher::currentWorkingDirectoryAndParentsToolsetPaths()
{
    return collectToolsetPathsFromSpecifiedRecursively(vector<path>(), currentWorkingDirectory());
}

vector<path> ToolsetSearcher::collectToolsetPathsFromSpecifiedRecursively(
    const vector<path>& initialPaths,
    const path& path
)
{
    auto result = initialPaths;
    auto parentPath = path.parent_path();
    auto toolsetsPathInCurrentDir = toolsetsPath(regularDirLibPath(path));

    if (is_directory(toolsetsPathInCurrentDir))
        result.push_back(toolsetsPathInCurrentDir);

    if (parentPath != filesystem::path())
        result = collectToolsetPathsFromSpecifiedRecursively(result, parentPath);

    return result;
}

path ToolsetSearcher::toolsetsPath(const path& basePath)
{
    return basePath / "toolsets";
}

path ToolsetSearcher::systemLibPath()
{
    if(Platform::os() == "windows")
        return path(getenv("PROGRAMFILES")) / "abc" / "lib" / "alphabet";

    if(Platform::os() == "macos")
        return "/Applications/abc.app/Contents/lib/alphabet";

    return "/usr/lib/alphabet";
}

path ToolsetSearcher::userLibPath()
{
    return userHomePath() / ".local" / "lib" / "alphabet";
}

path ToolsetSearcher::regularDirLibPath(const path& regularDir)
{
    return regularDir / ".alphabet";
}

path ToolsetSearcher::userHomePath()
{
    return getenv("HOME");
}

path ToolsetSearcher::currentWorkingDirectory()
{
    return getenv("PWD");
}
