#pragma once

namespace pcs
{
    class File
    {
        const char* fileLocation;

    public:
        File(const char* location);

        const char* getFileContents() const;
    };
}