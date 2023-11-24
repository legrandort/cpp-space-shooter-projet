#include <space-shooter/scenes/level.hpp>

#include <space-shooter/ecs/systems/rendering_system.hpp>

#include <space-shooter/ecs/entities/background.hpp>

#include <space-shooter/ecs/systems/change_system.hpp>

#include <space-shooter/ecs/ecs.hpp>

namespace space_shooter {

void initLevel(ecs::Manager &manager) {
  // TODO

	manager.registerEntity<ecs::BackgroundEntity>(
		manager.gameState().config.path_to_textures / "background.png",
		1500,
		900
	);

	manager.registerEntity<ecs::PlayerShipEntity>(
		sf::Vector2f{ 650, 600 },
		manager.gameState().config.path_to_textures / "playership.png",
		sf::Vector2f{200, 200}
	);

	manager.registerSystem<ecs::RenderingSystem>();
	manager.registerSystem<ecs::InputSystem>();
	manager.registerSystem<ecs::MovementSystem>();
	manager.registerSystem<ecs::ChangeSystem>();
	
	
}
} // namespace space_shooter
