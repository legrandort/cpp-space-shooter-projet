#include <space-shooter/scenes/menu.hpp>

#include <space-shooter/ecs/systems/change_system.hpp>

#include <space-shooter/ecs/ecs.hpp>

#include <iostream>

namespace space_shooter {

    void menuGame(ecs::Manager& manager) {

        manager.registerEntity<ecs::BackgroundEntity>(
            manager.gameState().config.path_to_textures / "menubackground.png",
            1500,
            900
        );
        

        manager.registerSystem<ecs::RenderingSystem>();
        manager.registerSystem<ecs::InputSystem>();
        manager.registerSystem<ecs::ChangeSystem>();

    }
} // namespace space_shooter