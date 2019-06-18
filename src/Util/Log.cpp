#include "Perceus/Util/Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace pcs
{
    spdlog::logger* Log::coreLogger = nullptr;
    spdlog::logger* Log::clientLogger = nullptr;

    bool Log::init()
    {
        spdlog::set_pattern("%^[%X] %n: %v%$");
        coreLogger = spdlog::stdout_color_mt("PERCEUS").get();
        
        #ifdef _PCS_DEBUG
        coreLogger->set_level(spdlog::level::debug);
        #else
        coreLogger->set_level(spdlog::level::trace);
        #endif

        clientLogger = spdlog::stdout_color_mt("CLIENT").get();
        clientLogger->set_level(spdlog::level::trace);



        return true;
    }
}