#include <Perceus/Core.h>
#include <iostream>

class CoolTriangle : public pcs::Model
{
public:
    using pcs::Model::Model;

    void update(double deltaTime) override
    {
        static int frame;
        
        //getLocation().y += cosf((float)frame / 5000000.f + (getLocation().z * 15.f)) / 100.f;
        getRotation().y += 1.f * deltaTime;

        frame++;
    }
};

class MainScreen : public pcs::Scene
{
    std::vector<pcs::Model*> models;

    pcs::RawModel* rawModel;
    pcs::ShaderProgram program;
    pcs::Camera camera;
    pcs::Texture texture;

protected:
    void render()
    {
        static unsigned int to;
        //setState(pcs::SceneState::FINISHED);


        camera.getLocation().z = -47.f;
        camera.getLocation().z -= .5f;
        //camera.getLocation().y = 5.f;

        pcs::Event* event;
        while (pollEvent(&event))
        {
            if (event->getType() == pcs::EventType::KeyDown)
            {
                pcs::KeyEvent* e = (pcs::KeyEvent*)event;
                std::cout << e->getKey() << std::endl;
            }
        }
        
        pcs::ForwardRenderer::get().render(models, &program, &camera);

        to++;
    }

public:
    MainScreen() :
        program(), camera(90.f)
    {
        pcs::ParserOBJ parser = pcs::ParserOBJ("Client/res/Sword1/Longsword_LP.obj");
        pcs::VertexArray* vertex = parser.parseFile();

        //for (int i = 0; i < vertex->getVertexArray().size(); i++)
        //    vertex->getVertexArray()[i].color = pcs::Color(165, 42, 42);


        rawModel = new pcs::RawModel(*vertex);
        texture.loadFromFile("Client/res/Sword1/color.png");

        rawModel->getTextures().albedo = &texture;
        rawModel->generateIndices(vertex->getVertices());
        delete vertex;
        
        pcs::Model* model = new CoolTriangle(rawModel);
        model->setScale({ .75f, .75f, .75f });
        //model->setScale({ .1f, .1f, .1f });
        model->setRotation({ 0, 0, .25f });
        models.push_back(model);

        //models.resize(5000);
        //for (int i = 0; i < models.size(); i++)
        //{
        //    models[i] = new CoolTriangle(rawModel);
        //    models[i]->setScale({ .1f, .1f, .1f });
        //    models[i]->setLocation(pcs::Vec3f(((rand() % 200) / 100.f - 1.f) * 25.f, ((rand() % 200) / 100.f - 1.f) * 25.f, (rand() % 1000) / 1200.f) * 500.f);
        //    models[i]->getLocation().z += .9f;
        //}

        program.getShader(pcs::ShaderType::Vertex).loadShaderFromString(
            "#version 330 core\n"
            "layout (location = 0) in vec3 vertices;\n"
            "layout (location = 1) in vec3 l_normal;\n"
            "layout (location = 2) in vec2 texC;\n"
            "layout (location = 3) in vec4 color;\n"
            "layout (location = 4) in mat4 model;\n"
            "\n"
            "out vec3 norm;\n"
            "out vec3 pos;\n"
            "out vec4 col;\n"
            "out vec2 tex;"
            "\n"
            "uniform mat4 projection;\n"
            "uniform mat4 view;\n"
            "\n"
            "void main() {\n"
            "  vec4 modelPosition = vec4(vertices, 1) * model;\n"
            "  gl_Position = modelPosition * view * projection;\n"
            "\n"
            "  norm = normalize((vec4(l_normal, 1.0) * model).xyz);\n"
            "  pos = modelPosition.xyz;\n"
            "  col = color;"
            "  tex = texC;"
            "}\n"
        );

        program.getShader(pcs::ShaderType::Fragment).loadShaderFromString(
            "#version 330 core\n"
            "out vec3 color;\n"
            "\n"
            "uniform sampler2D albedo;"
            "uniform vec3 camera_position;"
            ""
            "in vec3 norm;\n"
            "in vec3 pos;\n"
            "in vec4 col;\n"
            "in vec2 tex;"
            "\n"
            "void main() {\n"
            "  vec3 lightDir = normalize(vec3(1, 0, -1));" // * light_color
            "  vec3 light_color = vec3(1, 1, 1);"
            ""
            ""
            "  float specular_strength = 0.5;"
            "  vec3 viewDir = normalize(camera_position - pos);"
            "  vec3 reflectDir = reflect(-lightDir, norm);"
            "  float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);"
            "  vec3 specular = specular_strength * spec * light_color;"
            ""
            "  "
            //"  vec3 norm = normalize(normal);\n"
            "  float diff = max(dot(norm, lightDir), 0.0);"
            //"  color = col.xyz * diff;"
            "  vec3 diffuse = light_color * diff;\n"
            "  color = (diffuse + specular) * texture(albedo, tex).xyz;"
            "}\n"
        );

        program.link();
    }

    ~MainScreen()
    {
        delete rawModel;
    }
};

class Client : public pcs::Application
{
public:
    Client()
    {
        pcs::Scene* scene = new MainScreen();
        pushScene(scene);
    }
};

pcs::Application* pcs::CreateApplication()
{
    return new Client();
}