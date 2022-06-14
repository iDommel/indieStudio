/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** collideSystem
*/

#include <raylib.h>

#include "CollideSystem.hpp"
#include "GraphicSystem.hpp"
#include "Position.hpp"
#include "Sprite.hpp"
#include "Rect.hpp"

#include <iostream>

namespace indie {
    void CollideSystem::preInit(SceneManager &sceneManager)
    {
        auto collidables = sceneManager.getCurrentScene()[IEntity::Tags::COLLIDABLE];
        std::shared_ptr<indie::Rect> rect = nullptr;
        std::shared_ptr<indie::Model> model = nullptr;
        std::shared_ptr<indie::Position> pos = nullptr;
        std::shared_ptr<indie::IComponent> maybeUninitialized = nullptr;

        for (auto &collidable : collidables) {
            if ((*collidable)[IComponent::Type::VECTOR] == nullptr || (*collidable)[IComponent::Type::HITBOX] == nullptr)
                continue;
            if ((pos = Component::castComponent<Position>((*collidable)[IComponent::Type::VECTOR])) != nullptr &&
            (maybeUninitialized = (*collidable)[IComponent::Type::HITBOX]) != nullptr &&
            (!maybeUninitialized->isInitialized())) {
                if ((*collidable)[IComponent::Type::RECT] == nullptr && (*collidable)[IComponent::Type::MODEL] == nullptr)
                    throw std::runtime_error("Uninitialized collidable entity has no rect or model");
                if ((rect = Component::castComponent<Rect>((*collidable)[IComponent::Type::RECT])) != nullptr) {
                    Vector2 pos2d = { pos->x, pos->y };
                    Rectangle toUpdateRect = { rect->left, rect->top, rect->width, rect->height };
                    maybeUninitialized = std::make_shared<Hitbox>(toUpdateRect, pos2d);
                } else if ((model = Component::castComponent<Model>((*collidable)[IComponent::Type::MODEL])) != nullptr) {
                    Vector3 pos3d = { pos->x, pos->y, pos->z };
                    maybeUninitialized = std::make_shared<Hitbox>(model->getBoundingBox(), pos3d);
                }
            }
        }
    }

    void CollideSystem::init(SceneManager &sceneManager)
    {
        auto collidables = sceneManager.getCurrentScene()[IEntity::Tags::COLLIDABLE];
        std::shared_ptr<indie::Hitbox> hitbox = nullptr;
        std::shared_ptr<indie::IComponent> maybeCollider = nullptr;

        std::cout << "CollideSystem::init" << std::endl;
        if (collidables.empty())
            return;
        preInit(sceneManager);
        for (auto collidable : collidables) {
            if (!collidable || (maybeCollider = (*collidable)[IComponent::Type::HITBOX]) == nullptr || !maybeCollider->isInitialized())
                continue;
            hitbox = Component::castComponent<Hitbox>((*collidable)[IComponent::Type::HITBOX]);
            if (hitbox->is3D())
                _collidables3D.push_back(std::make_pair(collidable, hitbox));
            else
                _collidables2D.push_back(std::make_pair(collidable, hitbox));
        }
    }

    void CollideSystem::destroy()
    {
        std::cout << "CollideSystem::destroy" << std::endl;
        _collidables3D.clear();
        _collidables2D.clear();
    }

    void CollideSystem::loadEntity(std::shared_ptr<IEntity> entity)
    {
        std::shared_ptr<indie::Hitbox> hitbox = nullptr;
        std::shared_ptr<indie::IComponent> maybeCollider = nullptr;

        if (!entity || (maybeCollider = (*entity)[IComponent::Type::HITBOX]) == nullptr || !maybeCollider->isInitialized())
            return;
        hitbox = Component::castComponent<Hitbox>((*entity)[IComponent::Type::HITBOX]);
        if (hitbox->is3D())
            _collidables3D.push_back(std::make_pair(entity, hitbox));
        else
            _collidables2D.push_back(std::make_pair(entity, hitbox));
    }

    void CollideSystem::unloadEntity(std::shared_ptr<IEntity> entity)
    {
        for (auto it = _collidables3D.begin(); it != _collidables3D.end(); ++it)
            if (it->first == entity) {
                _collidables3D.erase(it);
                return;
            }
        for (auto it = _collidables2D.begin(); it != _collidables2D.end(); ++it)
            if (it->first == entity) {
                _collidables2D.erase(it);
                return;
            }
    }

    std::vector<std::shared_ptr<IEntity>> CollideSystem::getColliders(std::shared_ptr<IEntity> entity) const
    {
        std::shared_ptr<Hitbox> hitbox = nullptr;
        std::vector<std::shared_ptr<IEntity>> colliders;

        if (!entity || (hitbox = Component::castComponent<Hitbox>((*entity)[IComponent::Type::HITBOX])) == nullptr)
            return colliders;
        for (auto &collidable : _collidables3D)
            if (collidable.first != entity)
                if (check3DCollision(collidable.second, hitbox))
                    colliders.push_back(collidable.first);
        return colliders;
    }

    /// ------- 3D -------

    BoundingBox CollideSystem::makeBBoxFromSizePos(const Vector3 &size, const Vector3 &pos) const
    {
        const Vector3 &min = {pos.x, pos.y, pos.z};
        const Vector3 &max = {pos.x + size.x, pos.y + size.y, pos.z + size.z};
        BoundingBox box = {min, max};

        return box;
    }

    BoundingBox &CollideSystem::UpdateBBox(BoundingBox &box, const Vector3 &pos) const
    {
        box.min = {pos.x + box.min.x, pos.y + box.min.y, pos.z + box.min.z};
        box.max = {pos.x + box.max.x, pos.y + box.max.y, pos.z + box.max.z};
        return box;
    }

    BoundingBox CollideSystem::makeUpdatedBBox(const BoundingBox &box, const Vector3 &pos) const
    {
        Vector3 min = { pos.x + box.min.x, pos.y + box.min.y, pos.z + box.min.z };
        Vector3 max = { pos.x + box.max.x, pos.y + box.max.y, pos.z + box.max.z };
        BoundingBox updatedBox = {min, max};

        return updatedBox;
    }

    bool CollideSystem::check3DCollision(std::shared_ptr<Hitbox> box1, std::shared_ptr<Hitbox> box2) const
    {
        return (check3DCollision(box1->getBBox(), box2->getBBox()));
    }

    bool CollideSystem::check3DCollision(const BoundingBox &box1, const BoundingBox &box2) const
    {
        return CheckCollisionBoxes(box1, box2);
    }

    bool CollideSystem::check3DCollision(const BoundingBox &box, const Vector3 &center, float radius) const
    {
        return CheckCollisionBoxSphere(box, center, radius);
    }

    bool CollideSystem::check3DCollision(const Vector3 &center, float radius, const BoundingBox &box) const
    {
        return CheckCollisionBoxSphere(box, center, radius);
    }

    bool CollideSystem::check3DCollision(const Vector3 &center, float radius, const Vector3 &center2, float radius2) const
    {
        return CheckCollisionSpheres(center, radius, center2, radius2);
    }

    /// ------- 2D -------

    Rectangle &CollideSystem::updateRect(Rectangle &rect, const Vector2 &pos) const
    {
        rect.x = pos.x;
        rect.y = pos.y;
        return rect;
    }

    Rectangle CollideSystem::makeUpdatedRect(const Rectangle &rect, const Vector2 &pos) const
    {
        Rectangle updatedRect = {
            (int) pos.x + rect.x,
            (int) pos.y + rect.y,
            rect.width,
            rect.height
        };

        return updatedRect;
    }

    Rectangle CollideSystem::getRectangleOf(const Image &image, float threshold) const
    {
        return GetImageAlphaBorder(image, threshold);
    }

    bool CollideSystem::check2DCollision(std::shared_ptr<Hitbox> box1, std::shared_ptr<Hitbox> box2) const
    {
        return (check2DCollision(box1->getRect(), box2->getRect()));
    }

    bool CollideSystem::check2DCollision(const Rectangle &rect1, const Rectangle &rect2) const
    {
        return CheckCollisionRecs(rect1, rect2);
    }

    bool CollideSystem::check2DCollision(const Rectangle &rect, const Vector2 &center, float radius) const
    {
        return CheckCollisionCircleRec(center, radius, rect);
    }

    bool CollideSystem::check2DCollision(const Vector2 &center, float radius, const Rectangle &rect) const
    {
        return CheckCollisionCircleRec(center, radius, rect);
    }

    bool CollideSystem::check2DCollision(const Vector2 &center1, float radius1, const Vector2 &center2, float radius2) const
    {
        return CheckCollisionCircles(center1, radius1, center2, radius2);
    }

    bool CollideSystem::check2DCollision(const Vector2 &point, const Rectangle &rect) const
    {
        return CheckCollisionPointRec(point, rect);
    }

    bool CollideSystem::check2DCollision(const Rectangle &rect, const Vector2 &point) const
    {
        return CheckCollisionPointRec(point, rect);
    }

    bool CollideSystem::check2DCollision(const Vector2 &point, const Vector2 &center, float radius) const
    {
        return CheckCollisionPointCircle(point, center, radius);
    }

    bool CollideSystem::check2DCollision(const Vector2 &center, float radius, const Vector2 &point) const
    {
        return CheckCollisionPointCircle(point, center, radius);
    }
}
