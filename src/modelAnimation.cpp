#include "raylib.h"
#include "modelAnimation.hpp"

indie::ModelAnimation::ModelAnimation(const char *fileName, unsigned int *animsCount)
{
    anims = LoadModelAnimations(fileName, animsCount);
}

indie::ModelAnimation::~ModelAnimation()
{

}

void indie::ModelAnimation::updateModelAnimation(Model model, int frame)
{
    ::UpdateModelAnimation(model, anims[0], frame);
}

void indie::ModelAnimation::unloadModelAnimation()
{
    UnloadModelAnimation(anims[0]);
}

bool indie::ModelAnimation::isValid(Model model)
{
    return (IsModelAnimationValid(model, anims[0]));
}

int indie::ModelAnimation::getFrameCount()
{
    return (anims[0].frameCount);
}