#include <Perceus/Perceus.h>

// Graphics

#include "./Graphics/Window.cpp"

// Rend

// Initialize the VariableAPI's static variable
pcs::rend::BaseAPI* const pcs::rend::VariableAPI::baseAPI = new pcs::rend::OpenAPI;

// OpenGL

#include "./Graphics/OpenGL/inc.cpp"
#include "./Graphics/OpenGL/OpenAPI.cpp"