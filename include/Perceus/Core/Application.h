#pragma once

namespace pcs
{
    class Application
    {
    public:
        Application();
        virtual ~Application();
    };

    Application* CreateApplication();
}