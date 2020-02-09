#pragma once

#include <cstdio>
#define PERC_ASSERT(stmt) { int r = (int)(stmt); if (!r) { printf("Assertion in %s on line %d,\n\n%s\n\nhas failed with code %d.", __FILE__, __LINE__, #stmt, r); exit(1); } }

#include "./Graphics/Window.h"
#include "./Graphics/rend/VariableAPI.h"
#include "./Graphics/OpenGL/OpenAPI.h"

#include "./Math/Vector.h"