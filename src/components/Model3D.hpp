/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Model3D.hpp
*/

#ifndef MODEL_3D_HPP_
#define MODEL_3D_HPP_

#include "Component.hpp"
#include "Model.hpp"

namespace indie
{
    class Model3D : public Component
    {
    public:
        /**
         * @brief Construct a new Model3D component
         * @param modelPath Path to the model
         * @param texturePath Path to the model texture
         */
        Model3D(const std::string &modelPath, const std::string &texturePath = "")
            : Component(Type::MODEL), _modelPath(modelPath), _texturePath(texturePath){_isInitialized = true;};

        std::string &getModelPath() { return _modelPath; };
        std::string &getTexturePath() { return _texturePath; };

    private:
        std::string _modelPath;
        std::string _texturePath;
    };
}

#endif /* !MODEL_3D_HPP_ */