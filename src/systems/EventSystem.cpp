/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** EventSystem.cpp
*/

#include "EventSystem.hpp"

#include <algorithm>
#include <iostream>

#include "Component.hpp"
#include "EventListener.hpp"
#include "Window.hpp"
namespace indie
{

    void EventSystem::init(SceneManager &sceneManager)
    {
        std::cout << "EventSystem init" << std::endl;
        for (auto &e : sceneManager.getCurrentScene().getEntities()) {
            if (e->hasTag(IEntity::Tags::CALLABLE)) {
                std::shared_ptr<IComponent> tmp = e->getComponents({Component::Type::EVT_LISTENER})[0];
                std::shared_ptr<EventListener> listener = Component::castComponent<EventListener>(tmp);
                _listeners.push_back(listener);
            }
        }
    }

    void EventSystem::update(SceneManager &sceneManager, uint64_t)
    {
        for (auto &listener : _listeners) {
            handleKeyboard(listener);
            handleMouse(listener);
            for (int i = 0; i < _maxGamepads; i++) {
                if (Window::isGamepadAvailable(i)) {
                    handleGamepad(listener, i);
                    handleGamepadSticks(listener, i);
                }
            }
        }
    }

    void EventSystem::handleKeyboard(std::shared_ptr<EventListener> listener)
    {
        for (auto &it : listener->getKeyboardMappings()) {
            if (Window::isKeyPressed(it.first)) {
                it.second.pressed();
                break;
            }
            if (Window::isKeyDown(it.first)) {
                it.second.down();
                break;
            }
            if (Window::isKeyReleased(it.first)) {
                it.second.released();
                break;
            }
        }
    }

    void EventSystem::handleMouse(std::shared_ptr<EventListener> listener)
    {
        for (auto &it : listener->getMouseMappings()) {
            Vector2 pos = Window::getMousePosition();
            if (Window::isMouseButtonPressed(it.first)) {
                it.second._pressed(pos);
                break;
            }
            if (Window::isMouseButtonDown(it.first)) {
                it.second._down(pos);
                break;
            }
            if (Window::isMouseButtonReleased(it.first)) {
                it.second._released(pos);
                break;
            }
        }
    }

    void EventSystem::handleGamepad(std::shared_ptr<EventListener> listener, int nb)
    {
        for (auto &it : listener->getGamepadMappings(nb)) {
            if (Window::isGamepadButtonPressed(nb, it.first)) {
                it.second.pressed();
                break;
            }
            if (Window::isGamepadButtonDown(nb, it.first)) {
                it.second.down();
                break;
            }
            if (Window::isGamepadButtonReleased(nb, it.first)) {
                it.second.released();
                break;
            }
        }

        for (auto &it : listener->getGamepadStickMappings(nb)) {
            it.second(Window::getGamepadAxisMovement(nb, it.first));
        }
    }

    void EventSystem::handleGamepadSticks(std::shared_ptr<EventListener> listener, int nb)
    {
        for (auto &it : listener->getGamepadStickMappings(nb)) {
            it.second(Window::getGamepadAxisMovement(nb, it.first));
        }
    }

    void EventSystem::destroy()
    {
        std::cout << "EventSystem destroy" << std::endl;
    }

    void EventSystem::loadEntity(std::shared_ptr<IEntity> entity)
    {
        if (entity->hasTag(IEntity::Tags::CALLABLE)) {
            std::shared_ptr<IComponent> tmp = entity->getComponents({Component::Type::EVT_LISTENER})[0];
            std::shared_ptr<EventListener> listener = Component::castComponent<EventListener>(tmp);
            _listeners.push_back(listener);
        }
    }

    void EventSystem::unloadEntity(std::shared_ptr<IEntity> entity)
    {
        if (entity->hasTag(IEntity::Tags::CALLABLE)) {
            std::shared_ptr<IComponent> tmp = entity->getComponents({Component::Type::EVT_LISTENER})[0];
            std::shared_ptr<EventListener> listener = Component::castComponent<EventListener>(tmp);
            auto it = std::find(_listeners.begin(), _listeners.end(), listener);
            if (it != _listeners.end()) {
                _listeners.erase(it);
            }
        }
    }

}