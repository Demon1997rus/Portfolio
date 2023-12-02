#include "functions.h"

#include <vector>
#include <string>
#include <sys/stat.h>
#include <exception>

std::string rdi::searchConfig(const std::string& name)
{
    using Path = std::string;
    using Paths = std::vector<Path>;
    Paths paths;
    paths.push_back("../data/");
    paths.push_back("../Portfolio/data/");
    for (Path& path : paths)
    {
        path += name;
        struct stat sb;
        if (stat(path.c_str(), &sb) == 0)
        {
            std::cout << "Using config file " << path << std::endl;
            return path;
        }
    }

    for (const Path& path : paths)
    {
        std::cout << path << " not found" << std::endl;
    }
    throw std::runtime_error("Cannot find config file " + name);
    return nullptr;
}
