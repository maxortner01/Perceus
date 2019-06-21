#include "Perceus/Util/File.h"

#include <fstream>
#include <string>

namespace pcs
{
    File::File(const char* location) :
        fileLocation(location)
    {
        
    }

    const char* File::getFileContents() const
    {
        std::fstream file(fileLocation);
        std::string contents;

        for (std::string line; std::getline(file, line);)
        {
            contents += line + "\n";
        }

        return contents.c_str();
    }
}