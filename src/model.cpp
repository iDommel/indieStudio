#include "../include/model.hpp"
#include "raylib.h"
#include <iostream>

indie::Model::Model(const char *fileName)
{
    ::Model mode = LoadModel(fileName);
    Texture2D texture = LoadTexture("turret_diffuse.png");
    mode.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    ptr = std::make_unique <::Model> (mode);
}

indie::Model::~Model()
{
    UnloadModel(*ptr.get());
}

void indie::Model::draw(Vector3 position, float scale, Color tint)
{
    DrawModel(*ptr.get(), position, scale, tint);
}