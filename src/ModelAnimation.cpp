#include "raylib.h"
#include "ModelAnimation.hpp"

indie::ModelAnimation::ModelAnimation(const std::string &fileName, unsigned int *animsCount)
{
    anims = LoadModelAnimations(fileName.c_str(), animsCount);
    std::cout << "Anims count:" << *animsCount << std::endl;
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
    // _isLoaded = false;
}

void indie::ModelAnimation::unloadModelAnimation()
{
    UnloadModelAnimation(anims[0]);
    _isLoaded = false;
}

bool indie::ModelAnimation::isValid(::Model model)
{
    return (IsModelAnimationValid(model, anims[0]));
}

int indie::ModelAnimation::getFrameCount()
{
    return (anims[0].frameCount);
}