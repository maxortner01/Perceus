R"(

#version 330 core
layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 l_normal;
layout (location = 2) in vec2 texC;
layout (location = 3) in vec4 color;
layout (location = 4) in vec3 tangent;
layout (location = 5) in mat4 model;

out vec3 norm;
out vec3 pos;
out vec4 col;
out vec2 tex;
out mat4 modelMat;
out mat3 tbn;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    vec4 modelPosition = vec4(vertex, 1.0) * model;
    gl_Position = modelPosition * view * projection;

    modelMat = model;
    norm = normalize(l_normal).xyz;
    pos  = modelPosition.xyz;
    col  = color;
    tex  = texC;

    vec3 tang   = normalize(model * vec4(tangent, 1.0)).xyz;
    vec3 bitang = normalize(cross(tang, norm));

    tbn = mat3(
        tang,
        bitang,
        norm
    );
}

)"