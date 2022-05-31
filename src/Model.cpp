#include "Model.hpp"
#include "raylib.h"
#include <iostream>

using namespace indie;

indie::Model::Model(const std::string &modelFile, const std::string &textureFile)
{
    ::Model mode = LoadModel(modelFile.c_str());
    Texture2D texture = LoadTexture(textureFile.c_str());
    mode.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    ptr = std::make_unique <::Model> (mode);
}

indie::Model::~Model()
{
    
}

void indie::Model::unload()
{
    UnloadModel(*ptr.get());
}

void indie::Model::draw(Vector3 position, Color tint, float scale)
{
    DrawModel(*ptr.get(), position, scale, tint);
}

void indie::Model::drawRotate(Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)
{
    DrawModelEx(*ptr.get(), position, rotationAxis, rotationAngle, scale, tint);
}