/**
 * @file    BaseAPI.h
 * @author  Max Ortner
 * @date    2020-02-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

namespace pcs
{
namespace rend
{
    #define CORE_METHODS(bef, aft)\
        bef void init() const aft;\
        bef void terminate() const aft;

    #define WINDOW_METHODS(bef, aft) \
        bef void* create_window(const unsigned int width, const unsigned int height) const aft;\
        bef void make_context_current(void* context) const aft;

    #define ALL_METHODS(bef, aft)\
        CORE_METHODS(bef, aft)\
        WINDOW_METHODS(bef, aft)

    /**
     * @brief Completely abstract class for holding all the functionality of a rendering api.
     */
    class BaseAPI
    {
    public:
        ALL_METHODS(virtual, = 0);
    };

    #define DERIVED_API : public rend::BaseAPI { public: ALL_METHODS(, override); }
}
}