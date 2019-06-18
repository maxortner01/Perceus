#pragma once

#include <iostream>

#include "Perceus/Core/Application.h"
#include "Perceus/Util/Log.h"

extern pcs::Application* pcs::CreateApplication();

int main()
{

    // Create the application from client implementation
    pcs::Application* app = pcs::CreateApplication();

    // Capture the exit code of run
    int exit_code = app->run();

    // Delete the instance
    delete app;

    // Report the exit code to the logger
    PS_CORE_ERROR("Program exited with code {0}: {1}", 
        exit_code, pcs::getExitValue(exit_code));
}