/**
 * @file Proc.h
 * @author Max Ortner
 * @brief Definitions for outputting to a DLL
 * @date 2020-02-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#ifndef PERCEUS_STATIC

#   ifdef _P_BUILD
#       define PDLL __declspec(dllexport)
#   else
#       define PDLL __declspec(dllimport)
#   endif

#else

#   define PDLL

#endif