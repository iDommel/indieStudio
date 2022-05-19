#include "../include/model.hpp"
#include "raylib.h"
#include <iostream>

model::model(const char *fileName)
{
    Model model1 = LoadModel(fileName);
    Texture2D texture = LoadTexture("turret_diffuse.png");
    model1.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

    models = &model1;
}

model::~model()
{
    UnloadModel(*models);
}

void model::draw(Vector3 position, float scale, Color tint)
{
    DrawModel(*models, position, scale, tint);
}