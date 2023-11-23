#include <space-shooter/scenes/menu.hpp>

namespace space_shooter
{

    void menuGame(ecs::Manager& manager)
    {
        manager.gameState().running = false;
    }

} // namespace space_shooter
