#include <vector>
#include <boost/filesystem/path.hpp>

#include "Main/Main.h"

using namespace boost::filesystem;

using namespace abc;

int main(int argc, char* argv[]) {
    std::vector<std::string> arguments(argv + 1, argv + argc);

    const auto programName = path(argv[0]).filename().string();

    return Main::run(programName, arguments);
}
