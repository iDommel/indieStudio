#include "raylib.h"
#include "ModelAnimation.hpp"

indie::ModelAnimation::ModelAnimation(const std::string &fileName)
{
    anims = LoadModelAnimations(fileName.c_str(), &_animsCount);
    _isLoaded = true;
}

indie::ModelAnimation::~ModelAnimation()
{
    if (_isLoaded)
        unloadModelAnimation();
}

void indie::ModelAnimation::updateModelAnimation(indie::Model &model, int frame)
{
    ::UpdateModelAnimation(model.getModel(), anims[0], frame);
}

void indie::ModelAnimation::unloadModelAnimation()
{
    for (unsigned int i = 0; i < _animsCount; ++i)
        UnloadModelAnimation(anims[i]);
    _isLoaded = false;
}

bool indie::ModelAnimation::isValid(::Model model)
{
    return (IsModelAnimationValid(model, anims[0]));
}

int indie::ModelAnimation::getFrameCount()
{
    if (_isLoaded)
        return (anims[0].frameCount);
    return (0);
}