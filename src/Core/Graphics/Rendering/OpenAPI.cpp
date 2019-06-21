#include "Perceus/Core/Graphics/Rendering/Events/EventHandler.h"
#include "Perceus/Core/Graphics/Rendering/Events.h"

#include "Perceus/Core/Graphics/Rendering/Shaders/Shader.h"
#include "Perceus/Core/Graphics/Rendering/Shaders/ShaderProgram.h"

#include "Perceus/Core/Graphics/Rendering/OpenAPI.h"
#include "Perceus/Core/Graphics/Rendering/Buffer.h"
#include "Perceus/Core/Graphics/RawModel.h"
#include "Perceus/Core/Graphics/ForwardRenderer.h"
#include "Perceus/Core/Graphics/Window.h"
#include "Perceus/Util/Log.h"

#include "Perceus/Data/Vector.h"

#include <math.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace pcs
{
namespace rend
{
    void window_close_callback(GLFWwindow* window)
    {
        EventHandler::get().pushEvent<WindowClosedEvent>();
    }

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        /**/ if (action == GLFW_PRESS)
            EventHandler::get().pushEvent<KeyPressEvent>(key);
        else if (action == GLFW_RELEASE)
            EventHandler::get().pushEvent<KeyReleaseEvent>(key);
        else if (action == GLFW_REPEAT)
            EventHandler::get().pushEvent<KeyDownEvent>(key);
    }

    bool OpenAPI::initialize()
    {
        if (!glfwInit())
            return false;

        return true;
    }

    bool OpenAPI::terminate()
    {
        glfwTerminate();

        return true;
    }

    int OpenAPI::makeWindow(Window* window)
    {
        *window->getAPILoc() = (void*)glfwCreateWindow(window->getSize().x, window->getSize().y, "Test", NULL, NULL);

        if (!window)
        {
            return (int)WindowStatus::WINDOW_CREATION_FAILED;
        }

        glfwMakeContextCurrent((GLFWwindow*)*window->getAPILoc());

        if (glewInit() != GLEW_OK)
        {
            PS_CORE_ERROR("Failure to initialize OpenGL");
            return (int)WindowStatus::API_INIT_FAILED;
        }

        PS_CORE_INFO("OpenGL Initialized Successfully");
        PS_CORE_INFO("Running OpenGL version {0}", glGetString(GL_VERSION));
        
        glfwSetWindowCloseCallback((GLFWwindow*)*window->getAPILoc(), window_close_callback);
        glfwSetKeyCallback((GLFWwindow*)*window->getAPILoc(), key_callback);

        return (int)WindowStatus::OK;
    }

    int OpenAPI::destroyWindow(Window* window)
    {
        glfwDestroyWindow((GLFWwindow*)*window->getAPILoc());

        return true;
    }

    bool OpenAPI::shouldClose(Window* window) const
    {

        return glfwWindowShouldClose((GLFWwindow*)*window->getAPILoc());
    }

    bool OpenAPI::swapBuffers(Window* window) const
    {
        glfwSwapBuffers((GLFWwindow*)*window->getAPILoc());

        return true;
    }

    bool OpenAPI::pollEvents(Window* window) const
    {
        glfwPollEvents();

        return true;
    }

    bool OpenAPI::resizeWindow(Window* window, unsigned int width, unsigned int height) const
    {
        glfwSetWindowSize((GLFWwindow*)*window->getAPILoc(), width, height);
        glViewport(0, 0, width, height); 

        return true;
    }

    double OpenAPI::getTime() const
    {
        return glfwGetTime();
    }

    void OpenAPI::test() const
    {
        static int frame;

        //BufferArray bufferArray = BufferArray();
        //bufferArray.bindBuffer(BufferIndex::Vertices, 2, vertices);

        //bufferArray.getBuffer(BufferIndex::Vertices).bind();

        //glDrawArrays(GL_TRIANGLES, 0, 3);

        //bufferArray.getBuffer(BufferIndex::Vertices).unbind();

        //glBegin(GL_TRIANGLES);
//
        //glColor3f(1, 0, 0);
        //glVertex2f(-.5f, -.5f);
//
        //glColor3f(1, 1, 0);
        //glVertex2f(.5f, -.5f );
//
        //glColor3f(1, 0, 1);
        //glVertex2f(0, .5f);
//
        //glEnd();

        frame++;
    }

    bool OpenAPI::clear(Color color) const
    {
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        return true;
    } 

    bool OpenAPI::renderInstanced(unsigned int vertexCount, unsigned int count)
    {
        renderCalls++;

        glDrawElementsInstanced(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, nullptr, count);

        PS_CORE_DEBUG("Rendering {0} objects ({1} vertices)", count, vertexCount * count);

        getObjectCount() += count;
        getVertexCount() += vertexCount * count;

        //glDrawArrays(GL_TRIANGLES, 0, vertexCount);
        return true;
    }

    void OpenAPI::makeBuffer(Buffer* buffer) const
    {
        glGenBuffers(1, &buffer->getID());

        PS_CORE_DEBUG("Vertex Buffer ({0}) created", buffer->getID());
    }

    void OpenAPI::destroyBuffer(Buffer* buffer) const
    {
        glDeleteBuffers(1, &buffer->getID());

        PS_CORE_DEBUG("Vertex Buffer ({0}) destroyed", buffer->getID());
    }

    void rawDataBind(unsigned int bytesize, const void* data)
    {
        glBufferData(GL_ARRAY_BUFFER, bytesize, data, GL_DYNAMIC_DRAW);
    }

    void OpenAPI::bindBufferMatrixData(Buffer* buffer, std::vector<Mat4f> &matrices) const
    {
        // True and index so we can bypass the attrib pointer and divisor
        buffer->bind();
        rawDataBind(matrices.size() * 4 * 4 * sizeof(float), &matrices[0]);
        buffer->unbind();

        unsigned int index = buffer->getIndex();
        
        glEnableVertexAttribArray(index + 0);
        glEnableVertexAttribArray(index + 1);
        glEnableVertexAttribArray(index + 2);
        glEnableVertexAttribArray(index + 3);

        buffer->bind();
        glVertexAttribPointer(index + 0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4 * 4, (void*)(0));
        glVertexAttribPointer(index + 1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4 * 4, (void*)(sizeof(float) * 4));
        glVertexAttribPointer(index + 2, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4 * 4, (void*)(sizeof(float) * 8));
        glVertexAttribPointer(index + 3, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4 * 4, (void*)(sizeof(float) * 12)); 

        glVertexAttribDivisor(index + 0, 1);
        glVertexAttribDivisor(index + 1, 1);
        glVertexAttribDivisor(index + 2, 1);
        glVertexAttribDivisor(index + 3, 1);
        PS_CORE_DEBUG("Loaded {0} model matrices to vertex attributes {1}-{2}", matrices.size(), index, index + 3);
        
    }

    void OpenAPI::unbindBuffer(BufferType type) const
    {
        GLenum t = GL_ARRAY_BUFFER;
        
        if (type == BufferType::Index) 
        {
            PS_CORE_DEBUG("Unbinding index buffer"); 
            t = GL_ELEMENT_ARRAY_BUFFER;
        }
        else
        {
            PS_CORE_DEBUG("Unbinding vertex buffer");
        }
        
        glBindBuffer(t, 0);
    }

    void OpenAPI::bindBuffer(Buffer* buffer, BufferType type) const
    {
        GLenum t = GL_ARRAY_BUFFER;
        
        if (type == BufferType::Index) t = GL_ELEMENT_ARRAY_BUFFER;

        PS_CORE_DEBUG("Binding buffer {0}: {1}", buffer->getID(), BufferArray::getBufferName(buffer->getIndex()));

        glBindBuffer(t, buffer->getID());
    }

    void OpenAPI::bindBufferData(unsigned int bytesize, const void* data, unsigned int members, unsigned int index, bool divided, BufferType type) const
    {
        GLenum t = GL_ARRAY_BUFFER;

        if (type == BufferType::Index) 
        {
            t = GL_ELEMENT_ARRAY_BUFFER;
            PS_CORE_DEBUG("Binding {0} indicies to buffer {2}", bytesize / 4, members, index);
        }
        else
        {
            PS_CORE_DEBUG("Binding {0} bytes of data with {1} members to buffer {2}", bytesize, members, index);
        }

        glBufferData(t, bytesize, data, GL_STATIC_DRAW);

        if (type != BufferType::Index)
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, members, GL_FLOAT, GL_FALSE, 0, 0);
        }

        if (!divided)
        {
            glVertexAttribDivisor(index, 1);
        }
    }

    void OpenAPI::makeBufferArray(BufferArray* array) const
    {
        glGenVertexArrays(1, &array->getID());

        PS_CORE_INFO("Buffer Array ({0}) created", array->getID());
    }

    void OpenAPI::destroyBufferArray(BufferArray* array) const
    {
        glDeleteVertexArrays(1, &array->getID());

        PS_CORE_WARN("Buffer Array ({0}) destroyed", array->getID());
    }

    bool OpenAPI::makeProgram(ShaderProgram* program) const
    {
        program->getID() = glCreateProgram();
        PS_CORE_INFO("Created shader program ({0}) successfully", program->getID());

        return true;
    }
    
    bool OpenAPI::linkProgram(ShaderProgram* program) const
    {
        int result = 0;
        int infoLogLength;

        unsigned int vertexID   = program->getShader(ShaderType::Vertex  ).getID();
        unsigned int fragmentID = program->getShader(ShaderType::Fragment).getID();

        // Attach shaders and link program
        glAttachShader(program->getID(), vertexID);
        glAttachShader(program->getID(), fragmentID);
        glLinkProgram(program->getID());

        // Check the info log
        glGetProgramiv(program->getID(), GL_LINK_STATUS, &result);
        glGetProgramiv(program->getID(), GL_INFO_LOG_LENGTH, &infoLogLength);
        
        if (infoLogLength > 0)
        {
            std::vector<char> errorMessage(infoLogLength + 1);
            glGetProgramInfoLog(program->getID(), infoLogLength, nullptr, &errorMessage[0]);
            PS_CORE_ERROR("Error linking shader program ({0}): {1}", program->getID(), std::string(&errorMessage[0]));
            return false;
        }

        PS_CORE_INFO("Shader program ({0}) linked successfully", program->getID());

        // Finally detach the shaders from the program
        glDetachShader(program->getID(), vertexID);
        glDetachShader(program->getID(), fragmentID);

        return true;
    }

    void OpenAPI::useProgram(unsigned int id) const
    {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        PS_CORE_DEBUG("Using shader program {0}", id);
        glUseProgram(id);
    }

    bool OpenAPI::destroyProgram(ShaderProgram* program) const
    {
        PS_CORE_WARN("Shader program ({0}) destroyed", program->getID());
        glDeleteProgram(program->getID());
        return true;
    }

    bool OpenAPI::makeShader(Shader* shader) const
    {
        GLenum type;

        switch (shader->getType())
        {
            case ShaderType::Vertex:
                type = GL_VERTEX_SHADER;
                break;

            case ShaderType::Fragment:
                type = GL_FRAGMENT_SHADER;
                break;
        }

        shader->getID() = glCreateShader(type);

        PS_CORE_INFO("{0} Shader ({1}) Created Successfully", shader->getStatusValue((int)shader->getType()), shader->getID());

        return true;
    }

    bool OpenAPI::compileShader(Shader* shader, const char* source) const
    {
        glShaderSource(shader->getID(), 1, &source, nullptr);
        glCompileShader(shader->getID());

        int result = 0;
        int infoLogLength;

        glGetShaderiv(shader->getID(), GL_COMPILE_STATUS, &result);
        glGetShaderiv(shader->getID(), GL_INFO_LOG_LENGTH, &infoLogLength);
        if (infoLogLength > 0)
        {
            std::vector<char> errorMessage(infoLogLength + 1);
            glGetShaderInfoLog(shader->getID(), infoLogLength, nullptr, &errorMessage[0]);
            PS_CORE_ERROR("Error compiling {0} shader ({1}): {2}", 
                shader->getStatusValue((int)shader->getType()), shader->getID(), std::string(&errorMessage[0]));

            return false;
        }

        PS_CORE_INFO("Successfully compiled {0} shader ({1})",
            shader->getStatusValue((int)shader->getType()), shader->getID());

        return true;
    }

    bool OpenAPI::destroyShader(Shader* shader) const
    {
        PS_CORE_DEBUG("{0} shader ({1}) destroyed", shader->getStatusValue((int)shader->getType()), shader->getID());
        glDeleteShader(shader->getID());
        return true;
    }
}
}