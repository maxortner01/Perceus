#include "Perceus/Util/Parser/ParserOBJ.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include "objloader/OBJ_Loader.h"

#include <iostream>

namespace pcs
{
    std::vector<std::string> split(std::string s, std::string del)
    {
        std::vector<std::string> r;

        size_t pos;
        while ((pos = s.find(del)) != std::string::npos)
        {
            std::string token = s.substr(0, pos);
            r.push_back(token);
            s.erase(0, pos + del.length());
        }

        r.push_back(s);

        return r;
    }

    bool isSpace(std::string s)
    {
        for (int i = 0; i < s.length(); i++)
            if (!std::isspace(s[i]) && s[i] != '\n')
                return false;

        return true;
    }

    void processLine(const char* line, VertexArray* vertex)
    {
        std::string l(line);
        std::vector<std::string> parts = split(line, " ");

        std::vector<Vec3f> vertices;
        std::vector<Vec3f> normals;

        if (parts.size() == 0) return;

        /**/ if (parts[0] == "v")
        {
            // Grab the last three values, these should be the vertices
            Vec3f v;
            v.x = std::stof(parts[parts.size() - 3]);
            v.y = std::stof(parts[parts.size() - 2]);
            v.z = std::stof(parts[parts.size() - 1]);
            
            vertices.push_back(v);
        }
        else if (parts[0] == "vn")
        {
            Vec3f vn;
            vn.x = std::stof(parts[parts.size() - 3]);
            vn.y = std::stof(parts[parts.size() - 2]);
            vn.z = std::stof(parts[parts.size() - 1]);
            
            normals.push_back(vn);
        }
        else if (parts[0] == "f")
        {
            std::cout << "faces: " << line << std::endl;
            for (int i = 1; i < parts.size(); i++)
            {
                std::cout << parts[i] << "---\n"; 

                std::vector<std::string> verts = split(parts[i], "/");
                std::cout << parts[i] << "---\n"; 

                for (int j = 0; j < verts.size(); j++)
                    std::cout << verts[j] << "|";

                Vertex v;

                v.vertex = vertices[std::stoi(verts[0]) - 1];
                v.normal = normals[std::stoi(verts[2]) - 1];

                vertex->pushVertex(v);
            }
        }

    }

    VertexArray* ParserOBJ::parseFile() const
    {
        VertexArray* vertex = new VertexArray();

        //getFileContents(processLine, vertex);
        tinyobj::attrib_t attrib;
        std::vector<tinyobj::shape_t> shapes;
        std::vector<tinyobj::material_t> materials;

        std::string warn;
        std::string err;

        bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, fileLocation);

        if (!warn.empty())
            PS_CORE_WARN("OBJ File Warning: {0}", warn);

        if (!err.empty())
            PS_CORE_ERROR("OBJ File Error: {0}", err);

        if (!ret)
            return vertex;

        for (int s = 0; s < shapes.size(); s++)
        {
            int index_offset = 0;
            for (int f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++)
            {
                int fv = shapes[s].mesh.num_face_vertices[f];

                for (int v = 0; v < fv; v++)
                {
                    Vertex vert;

                    tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
                    vert.vertex.x = attrib.vertices[3 * idx.vertex_index + 0];
                    vert.vertex.y = attrib.vertices[3 * idx.vertex_index + 1];
                    vert.vertex.z = attrib.vertices[3 * idx.vertex_index + 2];

                    vert.normal.x = attrib.normals[3 * idx.normal_index + 0];
                    vert.normal.y = attrib.normals[3 * idx.normal_index + 1];
                    vert.normal.z = attrib.normals[3 * idx.normal_index + 2];

                    vert.tex.x = attrib.texcoords[2 * idx.texcoord_index + 0];
                    vert.tex.y = attrib.texcoords[2 * idx.texcoord_index + 1];

                    vertex->pushVertex(vert);
                }

                index_offset += fv;
            }
        }

        return vertex;
    }
}