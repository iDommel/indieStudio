/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** ParticleCloud
*/

#ifndef PARTICLECLOUD_HPP_
#define PARTICLECLOUD_HPP_

#include "Component.hpp"
#include "Position.hpp"

#include <vector>

struct Vector3;

namespace indie {
class ParticleCloud : public Component {
    public:
        /**
         * @brief Construct a new Particle Cloud object
         * @param start The start position of the cloud
         * @param end The end position of the cloud
         * @param nbParticles The number of particles in the cloud
         * @param curvature The number of bend of each particule
         * @param dispersion The dispersion of the cloud
         * 
        **/
        ParticleCloud(Vector3 start, Vector3 end, int nbParticles, int curvature, int dispersion, float lifeTime);
        ~ParticleCloud();

    protected:
    private:
        std::vector<std::vector<Vector3>> _bezierCurves;
        float _lifeTime = 0;
        float _timeToLive;
};
}

#endif /* !PARTICLECLOUD_HPP_ */
