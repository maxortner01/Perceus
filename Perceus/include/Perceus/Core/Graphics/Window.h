#pragma once

#include "Perceus/Data/Status.h"
#include "Perceus/Data/ObjectID.h"

#include "Rendering/Events.h"
#include "Rendering/RenderSurface.h"

namespace pcs
{
    /**
     * An enum that represents the status of a window object.
     */
    enum class WindowStatus
    {
        Ok,
        APIInitFailure,
        CreationFailure,
        None
    };

    /**
     * @brief Class that handles window functionality.
     * Uses the specified RenderAPI to construct a window as well
     * as manipulate the size and location.
     */
    class Window : 
        public rend::RenderSurface<unsigned int>, public Data::Status<WindowStatus>, public Data::ObjectUID
    {
        friend class Engine;

        /**
         * @brief Constructs a new Window object.
         * This constructor is only to be accessed through the Create
         * method.
         * 
         * @param width Width (in px) of the window
         * @param height Height (in px) of the window
         */
        Window(const unsigned int, const unsigned int);

    public:

        /**
         * @brief Destroys the Window instance and renderapi object.
         */
        virtual ~Window();

        /**
         * @brief Creates a new window object.
         * 
         * @param width Width (in px) of the window
         * @param height Height (in px) of the window
         * @return Window* Pointer to the window instance
         */
        static Window* Create(const unsigned int width, const unsigned int height);

        /**
         * @brief Method to check whether the window is open.
         * 
         * @return true The window is open
         * @return false The window is not open
         */
        bool isOpen();

        /**
         * @brief Swaps the buffer attached to the window.
         * 
         * @return true Render was successful
         * @return false Render was unsuccessful
         */
        bool render();

        void bind()   /***/ override;
        void unbind() const override;

        /**
         * @brief 
         * 
         * @return true Polling was successful
         * @return false Polling was unsuccessful
         */
        bool pollEvents();

        bool resize(unsigned int width, unsigned int height);
    };
}