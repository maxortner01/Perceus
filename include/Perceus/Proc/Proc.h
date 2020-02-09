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