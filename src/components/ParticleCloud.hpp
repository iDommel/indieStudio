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
#include <random>

struct Vector3;

namespace indie {

/**
 * @brief Uniformly distributed random number generator
**/
template<typename T>
T random(T range_from, T range_to) {
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<T>    distr(range_from, range_to);
    return distr(generator);
}

class ParticleCloud : public Component {
    public:
        /**
         * @brief Construct a new Particle Cloud object
         * @param start The start position of the cloud
         * @param end The end position of the cloud
         * @param nbParticles The number of particles in the cloud
         * @param curvature The number of bend of each particule (0=straight, 1=curve, 2+=curves)
         * @param dispersion The dispersion of the cloud, like a radius around the followed curve
         * @param lifeTime The lifetime of the cloud, each particule will reach the end vector after this time
        **/
        ParticleCloud(Vector3 start, Vector3 end, double nbParticles, double curvature, double dispersion, float lifeTime);
        ~ParticleCloud();

    protected:
    private:
        std::vector<std::vector<Vector3>> _bezierCurves;
        float _lifeTime = 0;
        float _timeToLive;
};
}

#endif /* !PARTICLECLOUD_HPP_ */
