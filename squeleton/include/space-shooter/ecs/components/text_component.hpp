#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/Graphics/Text.hpp>

#include <filesystem>

namespace space_shooter::ecs {

    struct TextComponent : Component {
        std::filesystem::path text_path;
        sf::Text text;


        TextComponent(const std::string& content, const std::filesystem::path& font_path, int character_size) {
            sf::Font font;
            if (!font.loadFromFile(font_path.string())) {
                throw std::runtime_error("Failed to load font: " + font_path.string());
            }

            text.setFont(font);
            text.setString(content);
            text.setCharacterSize(character_size);
            text.setFillColor(sf::Color::White);
        }
    };

} // namespace space_shooter::ecs