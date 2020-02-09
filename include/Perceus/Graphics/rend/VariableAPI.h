/**
 * @file    VariableAPI.h
 * @author  Max Ortner
 * @date    2020-02-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include "BaseAPI.h"

namespace pcs
{
namespace rend
{
    /**
     * @brief Simple class for holding a static instance of a rendering api.
     */
    class VariableAPI
    {
        static BaseAPI* const baseAPI;

    protected:
        const BaseAPI* const api() const
        {
            return baseAPI;
        }

    public:
        template<typename _BaseAPI>
        static void setAPI()
        {
            if (baseAPI) delete baseAPI;
            baseAPI = new _BaseAPI();
        }
    };
}
}