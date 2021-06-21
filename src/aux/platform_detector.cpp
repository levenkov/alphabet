#include "platform_detector.h"


using namespace std;

using namespace abc;


string Platform::os()
{
#ifdef __WINDOWS__
    return "windows";
#elif __MACOS__
    return "macos";
#elif __LINUX__
    return "linux";
#else
    #error "Unexpected OS"
#endif
}
