/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** ParticleCloud
*/

#include "raylib.h"
#include "ParticleCloud.hpp"

namespace indie {
ParticleCloud::ParticleCloud(Vector3 start, Vector3 end, double nbParticles,
double curvature, double dispersion, float lifeTime):
_timeToLive(lifeTime)
{
    float x = 0;
    float y = 0;
    float z = 0;

    _bezierCurves.resize(nbParticles);
    for (double i = 0; i < nbParticles; i++) {
        _bezierCurves[i].resize(curvature + 2);
        _bezierCurves[i][0] = start;
        for (double j = 1; j < curvature + 1; j++) {
            x = random(start.x, end.x);
            y = random(start.y, end.y);
            z = random(start.z, end.z);
            _bezierCurves[i][j] = Vector3(x, y, z);
        }
        _bezierCurves[i][curvature + 2] = end;
    }
}

ParticleCloud::~ParticleCloud()
{
}
}
