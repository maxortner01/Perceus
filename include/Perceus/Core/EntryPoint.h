#pragma once

#include <iostream>
#include "Perceus/Core.h"

extern pcs::Application* pcs::CreateApplication();

int main()
{
    pcs::Application* app = pcs::CreateApplication();
    std::cout << "hello" << std::endl;
    delete app;
}