/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Radar
*/

#ifndef RADAR_HPP_
#define RADAR_HPP_

#include "Component.hpp"

struct BoundingBox;
struct Vector3;

namespace indie
{
    class AVector;
    class Radar : public Component
    {
    public:
        /**
         * @brief Construct a new Radar object using a bounding box retrieved from a model and his position
         * @param box Bounding box retrieve with model->getBBox()
         * @param pos Position of the model
         * @return Radar
         **/
        Radar(BoundingBox box, Vector3 pos);
        /**
         * @brief Construct a new Radar object using a bounding box already updated with a position
         * @param box Bounding box retrieve with CollideSystem::makeUpdatedBBox function
         * @return Radar
         **/
        Radar(BoundingBox box);

        /// @brief Shift the 3D hitbox
        Radar &operator+=(const AVector shift);
        /// @brief Shift the 3D hitbox
        Radar &operator-=(const AVector shift);

        /// @brief Get the 3D BoundingBox (WARNING-> use 3d funtions on 3d hitbox only)
        BoundingBox getBBox(void) const;
        void setBBox(BoundingBox box);

    protected:
    private:
        std::unique_ptr<BoundingBox> _box = nullptr;
    };
}

#endif /* !RADAR_HPP_ */
