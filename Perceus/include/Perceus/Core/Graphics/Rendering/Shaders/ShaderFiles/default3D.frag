R"(

#version 330 core
out vec3 color;

struct Texture {
    sampler2D texture;
    int exists;
};

uniform Texture texAlbedo;
uniform Texture texNormal;
uniform vec3    camera_position;

in mat4 modelMat;
in vec3 norm;
in vec3 pos;
in vec4 col;
in vec2 tex;
in mat3 tbn;

vec4 getAlbedoColor()
{
    if (texAlbedo.exists == 1)
    {
        return texture(texAlbedo.texture, tex);
    }

    return col;
}

vec3 getNormal()
{
    if (texNormal.exists == 1)
    {
        vec3 normal = texture(texNormal.texture, tex).rgb * 2.0 - 1.0;
        return normalize(normal + norm);
    }

    return normalize(norm);
}

void main()
{
    //vec3 viewDir  = normalize(camera_position - pos);
    vec3 lightDir = vec3(0, 1, 0) - pos;
    vec3 light_color = vec3(1, 1, 1);

    //float specular_strength = 0.5;
    //vec3 reflectDir = reflect(-lightDir, getNormal());
    //float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    //vec3 specular = specular_strength * spec * light_color;

    float diff = max(dot(getNormal(), lightDir), 0.0);
    vec3 diffuse = light_color * diff;
    color = col.xyz * diffuse;

    //color = norm;
    //color = getAlbedoColor();
}

)"