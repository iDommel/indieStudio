/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** EventSystem.cpp
*/

#include "EventSystem.hpp"

#include <algorithm>

#include "Component.hpp"
#include "EventListener.hpp"
#include "Window.hpp"
namespace indie
{
    void EventSystem::init(SceneManager &sceneManager)
    {
        std::cout << "EventSystem init" << std::endl;
        for (auto &e : sceneManager.getCurrentScene()[IEntity::Tags::CALLABLE]) {
            auto listener = Component::castComponent<EventListener>((*e)[IComponent::Type::EVT_LISTENER]);
            if (listener)
                _listeners.push_back(listener);
        }
    }

    void EventSystem::update(SceneManager &sceneManager, uint64_t)
    {
        for (auto &listener : _listeners) {
            handleKeyboard(sceneManager, listener);
            handleMouse(sceneManager, listener);
            for (int i = 0; i < _maxGamepads; i++) {
                if (Window::isGamepadAvailable(i)) {
                    handleGamepad(sceneManager, listener, i);
                    handleGamepadSticks(sceneManager, listener, i);
                }
            }
        }
    }

    void EventSystem::handleKeyboard(SceneManager &manager, std::shared_ptr<EventListener> listener)
    {
        for (auto &it : listener->getKeyboardMappings()) {
            if (Window::isKeyPressed(it.first)) {
                it.second.pressed(manager, listener->getParent());
                break;
            }
            if (Window::isKeyDown(it.first)) {
                it.second.down(manager, listener->getParent());
                break;
            }
            if (Window::isKeyReleased(it.first)) {
                it.second.released(manager, listener->getParent());
                break;
            }
        }
    }

    void EventSystem::handleMouse(SceneManager &manager, std::shared_ptr<EventListener> listener)
    {
        for (auto &it : listener->getMouseMappings()) {
            Vector2 pos = Window::getMousePosition();
            if (Window::isMouseButtonPressed(it.first)) {
                it.second._pressed(manager, pos);
                break;
            }
            if (Window::isMouseButtonDown(it.first)) {
                it.second._down(manager, pos);
                break;
            }
            if (Window::isMouseButtonReleased(it.first)) {
                it.second._released(manager, pos);
                break;
            }
        }
    }

    void EventSystem::handleGamepad(SceneManager &manager, std::shared_ptr<EventListener> listener, int nb)
    {
        for (auto &it : listener->getGamepadMappings(nb)) {
            if (Window::isGamepadButtonPressed(nb, it.first)) {
                it.second.pressed(manager, listener->getParent());
                break;
            }
            if (Window::isGamepadButtonDown(nb, it.first)) {
                it.second.down(manager, listener->getParent());
                break;
            }
            if (Window::isGamepadButtonReleased(nb, it.first)) {
                it.second.released(manager, listener->getParent());
                break;
            }
        }

        for (auto &it : listener->getGamepadStickMappings(nb)) {
            it.second(Window::getGamepadAxisMovement(nb, it.first));
        }
    }

    void EventSystem::handleGamepadSticks(SceneManager &manager, std::shared_ptr<EventListener> listener, int nb)
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
            std::shared_ptr<EventListener> listener = Component::castComponent<EventListener>((*entity)[Component::Type::EVT_LISTENER]);
            _listeners.push_back(listener);
        }
    }

    void EventSystem::unloadEntity(std::shared_ptr<IEntity> entity)
    {
        if (entity->hasTag(IEntity::Tags::CALLABLE)) {
            std::shared_ptr<EventListener> listener = Component::castComponent<EventListener>((*entity)[Component::Type::EVT_LISTENER]);
            auto it = std::find(_listeners.begin(), _listeners.end(), listener);
            if (it != _listeners.end()) {
                _listeners.erase(it);
            }
        }
    }
}