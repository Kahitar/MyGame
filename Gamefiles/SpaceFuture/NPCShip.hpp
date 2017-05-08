#ifndef NPCSHIP_HPP
#define NPCSHIP_HPP

#include "Spaceship.hpp"


class NPCShip : public Spaceship
{
    public:
        NPCShip(std::string texturePath, sf::Vector2f position);
        ~NPCShip();

        void update(Framework &frmwrk);
        void handle(Framework &frmwrk);
        void render(Framework &frmwrk);
    protected:
};

#endif // NPCSHIP_HPP
