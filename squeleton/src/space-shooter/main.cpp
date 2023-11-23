// PROJECT HEADER HERE
#include <space-shooter/ecs/ecs.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/version.hpp>

// EXTERNAL HEADERS HERE
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

// SYSTEM HEADER HERE
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <string>

int main() {
  const auto game_config = space_shooter::GameConfig{
      .title = "Space Shooter",
      .window_width = 1500,
      .window_height = 900,
      .assets_path = space_shooter::SPS_PATH_TO_ASSETS,
      .frame_rate = space_shooter::FrameRate::VERTICAL_SYNC //
  };

  auto manager = space_shooter::ecs::Manager(game_config);

  auto *window = manager.gameState().rendering_window.get();
  auto clock = sf::Clock{};

  /*sf::Texture texture;
  sf::Texture texture2; 

  auto path = (manager.gameState().config.path_to_textures / "playership.png").string();
  auto path2 = (manager.gameState().config.path_to_textures / "enemyship.png").string();
 
  if (!texture.loadFromFile(path))
      return EXIT_FAILURE;
  if (!texture2.loadFromFile(path2)) 
      return EXIT_FAILURE;

  sf::Sprite sprite(texture);
  sf::Sprite sprite2(texture2);
  sprite.setPosition(650,600);
  sprite.setScale(0.5, 0.5);
  sprite2.setPosition(300, 300);
  sprite2.setScale(0.5, 0.5);*/

  while (window->isOpen() && manager.gameState().running) {
    auto event = sf::Event{};
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window->close();
    }

    window->clear();

    // call update on all registered systems
    manager.update(clock.restart());

    window->display();
  }

  return 0;
}
