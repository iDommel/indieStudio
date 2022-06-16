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
        for (auto &index : sceneManager.getSceneTypeList()) {
            for (auto &entity : sceneManager.getScene(index)[IEntity::Tags::CALLABLE]) {
                auto listener = Component::castComponent<EventListener>((*entity)[IComponent::Type::EVT_LISTENER]);
                if (listener)
                    _listeners[(int)index].push_back(listener);
            }
        }
    }

    void EventSystem::update(SceneManager &sceneManager, uint64_t)
    {
        for (auto &listener : _listeners[(int)sceneManager.getCurrentSceneType()]) {
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
            bool wasPressed = false;
            if (it.second.pressed && Window::isKeyPressed(it.first)) {
                it.second.pressed(manager);
                wasPressed = true;
            }
            if (it.second.down && Window::isKeyDown(it.first)) {
                it.second.down(manager);
                wasPressed = true;
            }
            if (it.second.released && Window::isKeyReleased(it.first)) {
                wasPressed = false;
                it.second.released(manager);
            }
            if (it.second.up && wasPressed && Window::isKeyUp(it.first)) {
                it.second.up(manager);
                wasPressed = false;
            }
        }
    }

    void EventSystem::handleMouse(SceneManager &manager, std::shared_ptr<EventListener> listener)
    {
        for (auto &it : listener->getMouseMappings()) {
            Vector2 pos = Window::getMousePosition();
            if (it.second._pressed && Window::isMouseButtonPressed(it.first)) {
                it.second._pressed(manager, pos);
                break;
            }
            if (it.second._down && Window::isMouseButtonDown(it.first)) {
                it.second._down(manager, pos);
                break;
            }
            if (it.second._released && Window::isMouseButtonReleased(it.first)) {
                it.second._released(manager, pos);
                break;
            }
            if (Window::isMouseButtonUp(it.first)) {
                it.second._up(manager, pos);
                break;
            }
        }
    }

    void EventSystem::handleGamepad(SceneManager &manager, std::shared_ptr<EventListener> listener, int nb)
    {
        for (auto &it : listener->getGamepadMappings(nb)) {
            if (it.second.pressed && Window::isGamepadButtonPressed(nb, it.first)) {
                it.second.pressed(manager);
                break;
            }
            if (it.second.down && Window::isGamepadButtonDown(nb, it.first)) {
                it.second.down(manager);
                break;
            }
            if (it.second.released && Window::isGamepadButtonReleased(nb, it.first)) {
                it.second.released(manager);
                break;
            }
        }
    }

    void EventSystem::handleGamepadSticks(SceneManager &, std::shared_ptr<EventListener> listener, int nb)
    {
        for (auto &it : listener->getGamepadStickMappings(nb)) {
            if (it.second)
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
            _listeners[(int)SceneManager::getCurrentSceneType()].push_back(listener);
        }
    }

    void EventSystem::unloadEntity(std::shared_ptr<IEntity> entity)
    {
        if (entity->hasTag(IEntity::Tags::CALLABLE)) {
            auto currentListeners = _listeners[(int)SceneManager::getCurrentSceneType()];
            std::shared_ptr<EventListener> listener = Component::castComponent<EventListener>((*entity)[Component::Type::EVT_LISTENER]);
            auto it = std::find(currentListeners.begin(), currentListeners.end(), listener);
            if (it != currentListeners.end()) {
                currentListeners.erase(it);
            }
        }
    }
}