#include <space-shooter/ecs/systems/rendering_system.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

RenderingSystem::RenderingSystem()
    : System(
          type_list<TextureComponent, PositionComponent, SpriteComponent>{}) {}

void RenderingSystem::update(const sf::Time & /*delta_time*/,
                             std::vector<Entity *> &entities,
                             Manager &manager) {
  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

     const auto &pos = e->get<PositionComponent>();
     const auto &spr = e->get<SpriteComponent>();
     auto &tex = e->get<TextureComponent>();

    // TODO load texture (if needed) into the texture component
    // TODO then set boolean of component to true
     if (!tex.loaded) {
         auto texturepath = tex.texture_path.string();
         if (!tex.texture.loadFromFile(texturepath)) {};
         tex.loaded = true;
     }

    // TODO build SFML sprite to render the texture
     sf::Sprite sprite(tex.texture);
     sprite.setPosition(pos.x, pos.y);
     sprite.setScale((float)spr.width / (float)tex.texture.getSize().x, (float)spr.height / (float)tex.texture.getSize().y);
    // TODO render the sprite at the correct position via manager -> game state
    // -> rendering window -> draw
     manager.gameState().rendering_window->draw(sprite);
     
  }
}

} // namespace space_shooter::ecs