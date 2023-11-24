#include <SFML/Window/Keyboard.hpp>
#include <space-shooter/ecs/systems/change_system.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    ChangeSystem::ChangeSystem() : System{ type_list<InputComponent>{} } {}

    void ChangeSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {

        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            auto& input = e->get<InputComponent>();

            if (input.enter) {
                manager.gameState().switch_to_scene = GameState::Scene::Level;
            }
            
            if (input.escape) {
                manager.gameState().switch_to_scene = GameState::Scene::Menu;
            }
            
        }
    }

} // namespace space_shooter::ecs