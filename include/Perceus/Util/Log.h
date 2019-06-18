#pragma once

#include <memory>
#include "spdlog/spdlog.h"

namespace pcs
{
    class Log
    {
        static spdlog::logger* coreLogger;
        static spdlog::logger* clientLogger;

    public:
        static bool init();

        inline static spdlog::logger* getCore()   { return coreLogger;   }
        inline static spdlog::logger* getClient() { return clientLogger; }
    };
}

// Core Logger Macros
#define PS_CORE_INFO(...)  ::pcs::Log::getCore()->info(__VA_ARGS__)
#define PS_CORE_WARN(...)  ::pcs::Log::getCore()->warn(__VA_ARGS__)
#define PS_CORE_ERROR(...) ::pcs::Log::getCore()->error(__VA_ARGS__)
#define PS_CORE_TRACE(...) ::pcs::Log::getCore()->trace(__VA_ARGS__)
#define PS_CORE_DEBUG(...) ::pcs::Log::getCore()->debug(__VA_ARGS__)

#define PS_CORE_SET_LEVEL(...) ::pcs::Log::getCore()->set_level(__VA_ARGS__)

// Client Logger Macros
#define PS_CLIENT_INFO(...)  ::pcs::Log::getClient()->info(__VA_ARGS__)
#define PS_CLIENT_WARN(...)  ::pcs::Log::getClient()->warn(__VA_ARGS__)
#define PS_CLIENT_ERROR(...) ::pcs::Log::getClient()->error(__VA_ARGS__)
#define PS_CLIENT_TRACE(...) ::pcs::Log::getClient()->trace(__VA_ARGS__)