# Perceus

Perceus is a lightweight, easy-to-use rendering engine written from the ground up in C++ entirely API independent. In other words, the underlying rendering interface (be it OpenGL, DirectX, etc.) is not hardcoded into the functionality of the engine. Instead, there is an abstract interface that, once implemented with the desired rendering API, allows the engine to utilize new frameworks. I have written an implementation of this interface for testing purposes in the `OpenAPI.cpp` file.

## Compiling

Perceus's compilation process and methods are primitive as I have been playing around with the various utilities to accomplish this. However, the most recent change has been towards cmake. So all you need to do is direct cmake to the `Perceus/build` folder and generate the files.

## Getting Started

Running Perceus is super simple. The entry point exists within the library itself, so all you need to do is write a function called `pcs::CreateApplication` that returns an instance of your application (which needs to be implemented by you) as shown below.

```C++

#include <Perceus/Core.h>

// Here is the client's implementation of an application.
class ClientApp : public pcs::Application
{
public:
    // The constructor for application determines the size of the 
    // window to be created, in this case the window will be 1920
    // by 1080 pixels in size.
    ClientApp() :
        pcs::Application(1920, 1080)
    {

    }
};

// This is the function that Perceus is looking for upon
// initiation of the program.
pcs::Application* pcs::CreateApplication()
{
    return new ClientApp();
}

```

This code will get a window up and running, but to actually render things you need a scene. Scenes are stored within the application as a stack, i.e. the app always renders the top scene. A scene can be implemented like below.

```C++

class MainScene : public pcs::Scene
{
public:
    // Scenes are held within the application, but each scene holds a pointer
    // to its respective parent.
    MainScene(pcs::Application* app) :
        pcs::Scene(app)
    {

    }

    // This is called every frame, the rendering happens automatically
    // so a better name for this method should be update.
    void render() override
    {

    }
};

```

Now, in the constructor of the application, the method `pushScene(...)` can be invoked in order to add the scene to the stack. Now the `render()` function will be called every frame.

## Modeling Structure

Among the forefront of the development of Perceus is the handling of the various models. Therefore, as optomization occurs, this process will change drastically.

However, as of the current version, there are two data structures central to rendering a model. There is the `RawModel` and the `Model`.

### RawModel

The RawModel contains all the vertex, color, normal, texture, etc. data that is contained within a unique model. A RawModel can be constructed from a `pcs::VertexArray` or from a `.obj` file. They are held universally, i.e. they will, by default, exist throughout the entire lifetime of the program. I see this changing in the future, allowing for the ability to link RawModels to scenes that, when left, destroys the RawModel.

### Model

Models are held within scenes in a vector, and are rendered automatically at the end of the `render` method invokation. All Models have a cooresponding RawModel, and where there should only be one RawModel for every loaded model, there can be thousands of Models. The Model class is just transformation information and acts as a singular instance of its attached RawModel that should be rendered in the scene.

## Author

Max Ortner