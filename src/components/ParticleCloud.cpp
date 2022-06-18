/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** ParticleCloud
*/

#include "raylib.h"
#include "ParticleCloud.hpp"
#include <iostream>

namespace indie {
ParticleCloud::ParticleCloud(Vector3 start, Vector3 end, double nbParticles,
double curvature, double dispersion, float lifeTime):
Component(Type::PARTICLES), _timeToLive(lifeTime)
{
    Vector3 pos = {0, 0, 0};

    for (double i = 0; i < nbParticles; i++) {
        std::vector<Vector3> particleParams;
        particleParams.push_back(end);
        for (double j = curvature; j > 0; j--) {
            pos.x = random(start.x, end.x);
            pos.y = random(start.y, end.y);
            pos.z = random(start.z, end.z);
            particleParams.push_back(pos);
        }
        particleParams.push_back(start);
        _bezierCurves.push_back(particleParams);
    }
}

static Vector3 getPt(Vector3 one, Vector3 two, float percent)
{
    Vector3 result = {0, 0, 0};

    result.x = one.x + ((two.x - one.x) * percent);
    result.y = one.y + ((two.y - one.y) * percent);
    result.z = one.z + ((two.z - one.z) * percent);
    return (result);
}

static Vector3 computeBeziers(std::vector<Vector3> curveParams, float percent)
{
    auto p1 = getPt(curveParams[0], curveParams[1], percent);
    auto p2 = getPt(curveParams[1], curveParams[2], percent);
    auto pos = getPt(p1, p2, percent);

    // if (curveParams.size() > 3)
    return (pos);
}

std::vector<Vector3> ParticleCloud::getPos(void) const
{
    std::vector<Vector3> positions;

    for (auto &curve : _bezierCurves)
        positions.push_back(computeBeziers(curve, (_lifeTime / (_timeToLive * 1.0f))));
    return positions;
}

bool ParticleCloud::isAlive(void) const
{
    return _timeToLive >= _lifeTime;
}

void ParticleCloud::addTime(uint64_t time)
{
    _lifeTime += time;
}

ParticleCloud::~ParticleCloud()
{
}
}
